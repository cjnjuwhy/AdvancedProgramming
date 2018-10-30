#include "RecurveList.h"

int List::Max(ListNode * f)
{
	ListNode *p = f;
	int max = p->data;
	while (p != NULL) {
		if (p->data > max)
			max = p->data;
		p = p->link;
	}
	return max;
}

int List::Num(ListNode * f)
{
	ListNode *p = f;
	int num = 0;
	while (p != NULL) {
		num++;
		p = p->link;
	}
	temp = num;
	return num;
}

float List::Avg(ListNode * f, int & n)
{
	float all=0;
	ListNode *p = f;
	while (p != NULL) {
		all += p->data;
		p = p->link;
	}
	return all/n;
}

ListNode * List::NewNode(const int item)
{
	ListNode *temp = new ListNode(item);
	return temp;
}

void List::NewList(const int retvalue)
{
	int x;
	int count = 0;
	while (cin >> x) {
		if (x == retvalue)
			break;
		if (count == 0) {
			first = NewNode(x);
			current = first;
		}
		else {
			current->link = NewNode(x);
			current = current->link;
		}
		count++;
	}
}

void List::PrintList()
{
	ListNode* temp = first;
	while (temp!=nullptr) {
		cout << temp->data << " ";
		temp = temp->link;
	}
}

int List::GetMax()
{
	return Max(first);
}

int List::GetNum()
{
	return Num(first);
}

float List::GetAvg()
{
	return Avg(first, temp);
}
