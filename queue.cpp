#include<iostream>
#include<string>
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
	int size=10;
   queue <int>qa(size);
   qa.enque(7);
   qa.enque(5);
   qa.enque(1);
   qa.enque(4);
   qa.enque(6);
   qa.enque(8);
   qa.enque(2);
   qa.enque(9);
   qa.enque(3);
   qa.enque(7);
   qa.printque();
}
