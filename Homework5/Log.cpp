#include "Log.h"

Log::Log(string name, string identity, string time, bool in, bool result, bool method)
{
	this->name = name;
	this->identity = identity;
	this->time = time;
	this->in = in;
	this->result = result;
	this->method = method;
}

Log::~Log()
{
}

Log & Log::getLog()
{
	return *this;
}

string Log::showLog()
{
	string temp;
	if (identity == "学生") {
		temp = "学生" + name + ",";
		if (in) {
			if (!result) {
				temp += "无效刷卡,";
			}
			temp =temp + time + ",";
			if (!result) {
				temp += "未进系楼.";
			}
			else
				temp += "进系楼.";
		}
		else {
			temp = temp + time + "," + "出系楼.";
		}
	}
	else if (identity == "老师") {
		temp = "老师" + name + ",";
		if (in) {
			if (result) {
				if (method) { // in through face
					temp = temp + "有效人脸识别," + time + "," + "进系楼.";
				}
				else {
					temp = temp + "无效人脸识别," + "有效刷卡," + time + "," + "进系楼.";
				}
			}
			else {
				temp = temp + "无效人脸识别," + "无效刷卡," + time + "," + "未进系楼.";
			}
			
		}
		else {
			temp = temp + time + "," + "出系楼.";
		}
	}
	return temp;
}
