#include<iostream>
#include<ctime>
#include<windows.h>
#include<stdlib.h>
using namespace std;
template<class datatype>
class queue{
	private:
		datatype *arr;
		int front;
		int rear;
		int size;
		int noe;
	public:
		queue(){
	arr = new datatype[8];
	rear=-1;
	front=-1;
	size=8;
	noe=0;
}
	queue(int a){
	size = a;
	rear=-1;
	front=-1;
	arr = new datatype[a];
	noe=0;
}
bool isEmpty(){
	if(noe==0)
	return true;
	else
	return false;
}
bool isFull(){
	if(noe==size)
	return true;
	else
	return false;
}
int getsize(){
	return noe;
}
bool enque(datatype a){
	if(!isFull())
	{
		arr[(++front)%size]=a;
		++noe;
		
		return true;
	}
	return false;
}
bool peek(datatype& a){
	if(!isEmpty())
	{
		a=arr[rear];
		return true;
	}
	return false;
}
bool deque(datatype& a){
	if(!isEmpty())
	{
		a=arr[(++rear)%size];
		--noe;
		return true;
	}
	return false;
}
void printque()
{
	if(!isEmpty())
	{
		for(int i=rear+1;i<=front;++i)
		{
			cout<<arr[(i)%size]<<endl;
		}
	}
}
};
int main(){
	int a,b;
	queue <int>q(100);
	while(0==0)
	{
	Sleep(1500);
	srand(time(0));
	a=rand()%17;
	for(int i=0; i<a;++i)
	q.enque(i);
	a=rand()%10;
	for(int i=0; i<a;++i)
	q.deque(b);
	cout<<"\n\t\t-------------Size of queue--------------"<<
	"\n\n\t\t\t\t"<<q.getsize()<<endl;
//	q.printque();
	}
}
