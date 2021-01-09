#pragma once
#include<iostream>
#include<Windows.h>
#include<opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>
#include<opencv2/xfeatures2d.hpp>
#include<opencv2/xfeatures2d/nonfree.hpp>
using namespace cv;
using namespace std;

class GenshinImpact_AutoMap_Matchs
{
public:
	GenshinImpact_AutoMap_Matchs();
	~GenshinImpact_AutoMap_Matchs();
public:
	GenshinImpact_AutoMap_Matchs(Mat _target);

public:
	void setMode(int flag);

	//ƥ����󣬰���Ҫƥ��ĵ�ͼ��
	void setObject(Mat img);
	//ƥ��Ŀ�꣬�ڸ�ͼ����ƥ��
	void setTarget(Mat img);
	void getKeyPoints();
	void onMatch();
	Point getLocation();

	void test();

private:
	bool isObjectExist = false;
	bool isTargetExist = false;
	Mat object;
	Mat target;
	//0:SURF
	int mode = 0;

	//int minHessian = 200;
	//float ratio_thresh = 0.7f;
	//Ptr<cv::xfeatures2d::SURF> detector;
	//std::vector<KeyPoint> keypoints_object;
	//std::vector<KeyPoint> keypoints_target;
	//Mat descriptors_object;
	//Mat descriptors_target;

	//vector<Point2d> off_obj;
	//vector<Point2d> off_sce;
	int minHessian = 400;
	float ratio_thresh = 0.5f;
	Ptr<cv::xfeatures2d::SURF> detector;
	std::vector<KeyPoint> keypoints_object, keypoints_scene;
	Mat descriptors_object, descriptors_scene;
private:
	void getObjectKeyPoints();
	void getTargetKeyPoints();
};

typedef GenshinImpact_AutoMap_Matchs giAMM;