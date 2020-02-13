#include<iostream>
#include<fstream>
using namespace std;
class queue{
	private:
		int *arr;
		int front;
		int rear;
		int size;
		int noe;
	public:
		queue(){
	arr = new int[8];
	rear=-1;
	front=-1;
	size=8;
	noe=0;
}
	queue(int a){
	size = a;
	rear=-1;
	front=-1;
	arr = new int[a];
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
bool enque(int a){
	if(!isFull())
	{
		arr[(++front)%size]=a;
		++noe;
		
		return true;
	}
	return false;
}
bool peek(int& a){
	if(!isEmpty())
	{
		a=arr[rear];
		return true;
	}
	return false;
}
bool deque(int& a){
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
void producer(){
	ofstream file("jobs.txt" ,ios::out | ios::trunc);
	cout<<"\n\t\tEnter Jobs, press -1 to terminate!\n";
	int a=0;
	while(a!=-1 && file)
	{
		cin>>a;
		if(a!=-1)
		file<<a<<endl;
	}
	file.close();
}
void remqueue(queue a)
{
	int b;
	ofstream file("jobs.txt" , ios::out | ios::trunc);
	while(!a.isEmpty())
	{
	a.deque(b);
	file<<b<<endl;
	}
	file.close();
}
int consumer() {
	ifstream file("jobs.txt" , ios::in);
	int size=0;
	int b;
	while(file>>b)
    	++size;
	queue q(size);
	char a='Y';
	while(file>>b)
		q.enque(b);
	file.close();
	while (a == 'Y' || a == 'y')
	{
		cout<<"\n\t\t\tYou want to get a job?\n\n\t\tY-Yes.";
		cin>>a;
		if(!q.isEmpty() && a=='y' || a=='Y')
		{
		q.deque(b);
		cout<<b<<endl;
	}
		remqueue(q);
	else if(q.isEmpty() && a=='y' || a=='Y')
	{
	cout<<"No more jobs available.\n";
	return 0;
	}
	}
}
int main(){
   cout<<"\n\n\t\t\t\tWelcome!\n";
   cout<<"\n\t\t\tAre you a? \n\n\t1:Producer \n\t2:Consumer\n";
   int a;
   cin>>a;
   if(a==1)
   producer();
   else if(a==2)
   consumer();
}
