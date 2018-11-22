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
	if (identity == "ѧ��") {
		temp = "ѧ��" + name + ",";
		if (in) {
			if (!result) {
				temp += "��Чˢ��,";
			}
			temp =temp + time + ",";
			if (!result) {
				temp += "δ��ϵ¥.";
			}
			else
				temp += "��ϵ¥.";
		}
		else {
			temp = temp + time + "," + "��ϵ¥.";
		}
	}
	else if (identity == "��ʦ") {
		temp = "��ʦ" + name + ",";
		if (in) {
			if (result) {
				if (method) { // in through face
					temp = temp + "��Ч����ʶ��," + time + "," + "��ϵ¥.";
				}
				else {
					temp = temp + "��Ч����ʶ��," + "��Чˢ��," + time + "," + "��ϵ¥.";
				}
			}
			else {
				temp = temp + "��Ч����ʶ��," + "��Чˢ��," + time + "," + "δ��ϵ¥.";
			}
			
		}
		else {
			temp = temp + time + "," + "��ϵ¥.";
		}
	}
	return temp;
}
