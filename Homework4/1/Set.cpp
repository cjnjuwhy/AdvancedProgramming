#include"Set.h"
//所有的创建和删除Set都使用erase和add完成
//这样对其进行计数就变得十分方便
Set::Set(){
	head = nullptr;
	len = 0;
}

Set::Set(const Set& set): Set(){
	//this->Set(); you can't use this to construct the instance.
	Node* q = set.head;
	while(q != nullptr){
		add(q->data);
		q = q->next;
	}
}

Set::Set(int elements[], int length):Set(){
	for(int i=0; i<length; i++){
		add(elements[i]);
	}
}

Set::~Set(){
	while(head != nullptr){
		Node* p = head;
		head = head->next;
		delete p;
	}
}

int Set::size(){
	return len;
}
//链表的操作与删除需要特别注意，在考虑清楚之后再动手
void Set::add(int element){
	if(contains(element)) return;
	Node* p = head;
	if(p == nullptr){
		head = new Node(element);
		len++;
	}
	else{
		while(p->next != nullptr){
			if(p->data > element) break;
			else p = p->next;
		}
		if(p->data < element){
			Node* q = new Node(element);
			q->next = p->next;
			p->next = q;
		}
		else{
			Node* q = new Node(p->data);
			q->next = p->next;
			p->data = element;
			p->next = q;
		}
		len++;
	}

}

bool Set::erase(int element){
	if(!contains(element))return false;
	Node* p = head;
	if(p == nullptr) return false;
	if(p->data == element){
		head = head->next;
		delete p;
		len--;
		return true;
	}
	Node* q = p->next;
	while(q != nullptr){
		if(q->data > element) break;
		else if(q->data == element){
			p->next = q->next;
			delete q;
			len--;
			return true;
		}
		else{
			p = p->next;
			q = q->next;
		}
	}
	return false;
}

bool Set::contains(int element){
	Node* p = head;
	while(p!=nullptr){
		if(p->data > element) break;
		else if (p->data == element)return true;
		else
			p = p->next;
	}
	return false;
}

ostream & operator<<(ostream &os,const Set &rset){
	Node* p = rset.head;
	if (!rset.len){
		os << "Empty";
		return os;
	}
	while(p != nullptr){
		os << p->data << " ";
		p = p->next;
	}
	return os;
}

Set& Set::operator =(const Set& set){
	if(&set == this) return *this;
	head = nullptr; len = 0;
	Node* q = set.head;
	while(q != nullptr){
		add(q->data);
		q = q->next;
	}
	return *this;
}

Set operator +(const Set &lset, const Set &rset){
	Set temp(lset);
	Node* p = rset.head;
	while(p != nullptr){
		temp.add(p->data);
		p = p->next;
	}
	return temp;
}

Set& Set::operator +=(const Set &rset){
	*this = *this + rset;
	return *this;
}

Set operator -(const Set &lset, const Set &rset){
	Set temp(lset);
	Node* p =rset.head;
	while(p != nullptr){
		temp.erase(p->data);
		p = p->next;
	}
	return temp;
}

Set& Set::operator -=(const Set &rset){
	*this = *this - rset;
	return *this;
}

Set operator &(const Set &lset, const Set &rset){
	Set temp1(lset);
	Set temp2(lset);
	temp1 -= rset;
	temp2 -= temp1;
	return temp2;
}

Set operator |(const Set &lset, const Set &rset){
	return lset+rset;
}

bool operator ==(const Set &lset, const Set &rset){
	Set temp1(lset);
	Set temp2(rset);
	temp1 -= rset;
	temp2 -= lset;
	if(temp1.size() == 0 && temp2.size() == 0)return true;
	else return false;
}
bool operator !=(const Set &lset, const Set &rset){
	return !(lset==rset);
}

bool operator >=(const Set &lset, const Set &rset){
	Set temp(rset);
	temp = temp - lset;
	if(temp.size() == 0) return true;
	else
		return false;
}
bool operator >(const Set &lset, const Set &rset){
	if(lset!=rset && lset>=rset)
		return true;
	else return false;
}
bool operator <=(const Set &lset, const Set &rset){
	Set temp(lset);
	temp -= rset;
	if(temp.size() == 0) return true;
	else return false;
}
bool operator <(const Set &lset, const Set &rset){
	if(lset != rset && lset <= rset)
		return true;
	else return false;
}
/*-------------------------------------
* new和delete的重载参考的是书上的写法
* 通过静态的成员变量预定义一个较大的连续空间
* 初始的时候，逐个分配这些空间，由于有一个
* Set*类型的成员变量，可以将这些空间通过链表的
* 形式串起来，p_free指向当前可用的第一个空间
* 这样不断地归还和申请，使用的始终是预定义好的空间
-------------------------------------*/

//define private:	static Set *p_free;
//		 			Set * next;
Set *Set::p_free = NULL;
static void * Set::operator new(size_t size){
	Set *p;
	if (p_free == NULL){
		p_free = (Set *)malloc(size*100);
		for(p=p_free; p!=p_free+100-1; p++)
			p->next = p+1;
		p->next = NULL;
	}
	p = p_free;
	p_free = p_free->next;
	return p;
}
static void Set::operator delete(void *p, size_t size){
	((Set *)p)->next = p_free;
	p_free = (Set *)p;
}

