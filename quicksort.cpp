#include<iostream>
using namespace std;
void swap(int* a, int* b)  
{  
    int t=*a; 
    *a=*b;  
    *b=t;  
} 
int partition(int *arr,int start,int end)  
{  
    int pivot=arr[end]; 
    int i =(start-1);  
    for(int j=start; j<=end-1; j++) 
    {  
        if(arr[j]<pivot)  
        {  
            i++; 
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i+1], arr[end]); 
    return (i+1);  
}  
void quicksort(int *arr, int start, int end)  
{  
    if (start<end)  
    {  
        int par = partition(arr,start,end);  
        quicksort(arr,start,par-1);  
        quicksort(arr,par+1,end);  
    }  
} 
int main()
{
	int arr[10]={2,8,6,9,7,0,4,1,3,5};
	quicksort(arr,0,9);
	for(int i=0;i<10;i++)
	cout<<arr[i]<<endl;
}
