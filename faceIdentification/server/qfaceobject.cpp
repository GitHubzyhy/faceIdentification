#include "qfaceobject.h"

QFaceObject::QFaceObject(QObject *parent)
    : QObject{parent}
{
    // 初始化 seeta 人脸引擎设置
    seeta::ModelSetting FDmodel("D:/Environment/SeetaFace2/bin/model/fd_2_00.dat", seeta::ModelSetting::GPU, 0);
    seeta::ModelSetting PDmodel("D:/Environment/SeetaFace2/bin/model/pd_2_00_pts5.dat", seeta::ModelSetting::GPU, 0);
    seeta::ModelSetting FRmodel("D:/Environment/SeetaFace2/bin/model/fr_2_10.dat", seeta::ModelSetting::GPU, 0);
    // 创建 seeta 人脸引擎对象
    this->fengineptr = new seeta::FaceEngine(FDmodel, PDmodel, FRmodel);

    this->fengineptr->Load("../../database/face.db");
    // fengineptr->Delete(3);删除某个人脸
}

QFaceObject::~QFaceObject()
{
    delete fengineptr;
}
//人脸注册函数
int64_t QFaceObject::face_register(Mat &faceImage)
{
    // 转换 OpenCV Mat 数据到 seeta::SeetaImageData 结构体,数据转换
    SeetaImageData image;
    image.data = faceImage.data;
    image.channels = faceImage.channels();
    image.height = faceImage.rows;
    image.width = faceImage.cols;

    // 调用人脸引擎进行人脸注册
    int64_t faceID = this->fengineptr->Register(image);
    if (faceID >= 0)//失败则返回-1
    {
        // 注册成功后保存人脸数据库
        this->fengineptr->Save("../../database/face.db");
    }
    return faceID;
}
//人脸识别函数
int QFaceObject::face_query(Mat &faceImage)
{
    // 转换 OpenCV Mat 数据到 seeta::SeetaImageData 结构体
    SeetaImageData image;
    image.data = faceImage.data;
    image.channels = faceImage.channels();
    image.height = faceImage.rows;
    image.width = faceImage.cols;

    // 声明相似度变量
    float similaty = 0;

    // 调用人脸引擎进行人脸识别
    int64_t faceID = this->fengineptr->Query(image, &similaty);//运算时间比较长
    //如果人脸可信度大于0.6，发送faceid信号
    if (similaty >= 0.6)
        emit send_faceid(faceID);
    else
        emit send_faceid(-1);
    return faceID;
}
