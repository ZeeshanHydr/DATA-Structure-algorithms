#include<iostream>
using namespace std;
struct node {
	int data;
	node* ptr;
	node(int d, node* p) {
		data = d;
		ptr = p;
	}
	node(int d) {
		data = d;
		ptr = nullptr;
	}
	int getvalue() {
		return data;
	}
};
class linklist {
protected:
	node* start;
public:
	linklist() {
		start = nullptr;
	}
	node* getstart(){
		return start;
	}
	int size(){
		int a=0;
		node* tmp=start;
		while(tmp!=nullptr)
		{
			++a;
			tmp=tmp->ptr;
		}
		return a;
	}
	int insert(int d) {
		node* m=new node(d);
		if (start == nullptr)
		{
			start = m;
			m = nullptr;
			return 0;
		}
		node* tmp = start;
		while (tmp != nullptr)
		{
			if (tmp->ptr == nullptr)
			{
				tmp->ptr = m;
				tmp = nullptr;
				return 0;
			}
			tmp = tmp->ptr;
		}	
		tmp = nullptr;
	}
	int deletel() {
		if (start == nullptr)
			return 0;
		node* tmp = start;
		node* tmp2 = start->ptr;
		while (tmp2 != nullptr)
		{
			tmp = tmp2;
			tmp2 = tmp2->ptr;
			if (tmp2->ptr == nullptr)
			{
				tmp->ptr = nullptr;
				tmp = nullptr;
				tmp2 = nullptr;
				return 0;
			}
		}
		tmp = nullptr;
		tmp2 = nullptr;
	}
	node* search(int d) {
		if (start == nullptr)
			return 0;
		node* tmp = start;
		while (tmp != nullptr) {
			if (tmp->data == d)
			{
				return tmp;
			}
			tmp = tmp->ptr;
		}	
		tmp = nullptr;
		return 0;
	}
	node* searchanddel(int d) {
		if (start == nullptr)
			return 0;
		node* tmp = start;
		if (start->data == d)
		{
			start = nullptr;
			return tmp;
		}
		node* tmp2;
		while (tmp != nullptr) {
			tmp2 = tmp->ptr;
			if (tmp2!=nullptr && tmp2->data == d)
			{
				tmp->ptr = tmp2->ptr;
				tmp = nullptr;
				return tmp2;
			}
			tmp = tmp->ptr;
		}
		tmp = nullptr;
		return 0;
	}
	void sort(){
	int temp,nos=1;	
	node* n2;node* j;
	while(nos>0)
	{
		nos=0;
		for(j=start;j!=nullptr && j->ptr!=nullptr;j=j->ptr)
		{
			n2=j->ptr;
			if(j->data>n2->data)
			{
				temp=j->data;
				j->data=n2->data;
				n2->data=temp;
				++nos;
				
			}
		}
	}
	j=nullptr;
	n2=nullptr;
	}
	void print() {
		node* tmp = start;
		int a=1;
		while (tmp != nullptr)
		{
		    if(a==1)
			cout<<endl<<tmp->data<<"  -> ";
			else
			cout <<" | "<<tmp->data;
			tmp = tmp->ptr;
			a++;
		}
		tmp = nullptr;
	}
	int getnelement(int n)
		{
			node* tmp=start;
			for(int i=1;i<n && tmp->ptr!=nullptr;++i)
			{
				tmp=tmp->ptr;
				}
				return tmp->getvalue();	
		}
		bool delnelement(int n)
		{
			node* tmp=start;
			node* tmp2=start;
			if(n==1 && start!=nullptr)
			{
				start=start->ptr;
				return true;
			}
			for(int i=1;i<n && tmp2!=nullptr;++i)
			{
				tmp=tmp2;
				tmp2=tmp2->ptr;
			}
			tmp->ptr=tmp2->ptr;
			return true;
		}
};
//int main() {
//	linklist l;
//	l.insert(10);
//	l.insert(30);
//	l.insert(25);
//	l.insert(15);
//	l.insert(5);
//	l.insert(20);
//	l.print();
//	cout<<"\n\n\n";
//	l.sort();
//	l.print();
//	cout<<"\n\n\n";
//	l.searchanddel(25);
//	l.print();
//}
