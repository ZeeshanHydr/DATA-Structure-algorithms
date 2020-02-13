#include<iostream>
using namespace std;
int factorial(int n){
	if(n==1 || n==0)
	return 1;
	else
	return n*factorial(n-1);
}
int addarr(int *arr,int size)
{
	int n=0;
	if(size==1)
	return arr[0];
	else if(size==0)
	return 0;
	else 
	return arr[n]+addarr(arr+n+1,size-1);
}
int main(){
//	int n=10;
//	cout<<factorial(n);
int size=45;
	int arr[size];
	for(int i=0;i<size;++i)
	arr[i]=i+1;
	cout<<addarr(arr+0,size);
}
