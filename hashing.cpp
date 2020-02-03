#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int mostoccuring(string s)
{
	int arr[256]={0};
	for(int i=0;i<s.length();++i)
	{
		arr[int(s[i])]++;
	}
	int max=arr[0];
	int ind =0;
	for(int i=0;i<256;++i)
	{
		if(arr[i]>max && i!=32)
		{
			max=arr[i];
			ind =i;
		}
	}
	return ind;
}
int main()
{
	string s;
	ifstream file("jobs.txt",ios::in);
	getline(file,s);
	cout<<s<<endl;
	char a = char(mostoccuring(s));
	cout<<char(a)<<endl;
}
