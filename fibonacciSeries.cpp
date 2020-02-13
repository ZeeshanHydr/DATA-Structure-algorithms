#include<iostream>
using namespace std;
void fibonaccifinder(unsigned long long*arr,int n)
{
	arr[0]=0;
	arr[1]=1;
	for(int i=0;i<=n-2;++i)
	{
		arr[i+2]=arr[i]+arr[i+1];
	}
}
int main()
{
	int size=20;
	unsigned long long arr[size];
	fibonaccifinder(arr,size);
	for(int i=0;i<size;i++)
	cout<<"\t"<<arr[i]<<"\t\t\t\t Index:"<<i+1<<"\n";
}
