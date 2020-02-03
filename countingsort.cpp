#include<iostream>
using namespace std;
void countingsort(int *arr,int range,int size)
{
	int arr2[range+1]={0};int j=0,i;
	for(i=0;i<size;i++)
		arr2[arr[i]]++;
	for(i=0;i<range;i++)
	{
		while(arr2[i]>0)
		{
			arr[j]=i;
			arr2[i]--;
			j++;
		}
	}
}
int main(){
	int size=20;
	int arr[size];
	for(int i=0;i<size;i++)
	cin>>arr[i];
	countingsort(arr,100,size);
	for(int i=0;i<size;i++)
	cout<<arr[i]<<"  ";
}
