#include<iostream>
#include<vector>
using namespace std;
class insertsort
{
	private:
		vector<int> v;
		int totEle;
	public:
		insertsort(int max)
		{
			totEle = 0;
			v.resize(max);
		}
		void display(){
			for(int i=0;i<totEle;++i)
			{
				cout<<"Index: "<<i+1<<" Value: "<<v[i]<<endl;
			}
		}
		void insertsorting()
		{
			int in,out;
			for(out=0;out<totEle;++out)
			{
				int temp=v[out];
				in=out;
				while(in>0 && v[in-1]>=temp)
				{
					v[in]=v[in-1];
					in--;
				}
				v[in]=temp;
			}
		}
		void insert(int value)
		{
		v[totEle]=value;
		totEle++;
	    }
	    int linfind(int value)
		{
			for(int i=0;i<totEle;++i)
			{
				if(v[i]==value)
				return i;
			}
		}	 
		int binfind(int value)
		{
		int upperb=totEle-1;
		int lowerb=0;
		int ind=(lowerb+upperb)/2;
		while(ind>-1)
		{
		if(v[ind]>value)
		upperb=ind-1;
		if(v[ind]<value)
		lowerb=ind+1;
		ind=(lowerb+upperb)/2;
		if(v[ind]==value)
		return ind;
		}
		return -1;
		}   
		bool deletev(int value)
		{
			int ind=binfind(value);
			if(ind==-1)
			return false;
			else
			{
				for(int i=ind;i<totEle;++i)
				v[i]=v[i+1];
			}
			totEle--;
			return true;
		}
};
int main(){
	insertsort oa(20);
	cout<<"Enter 10 no.\n";
	int a;
	for(int i=0;i<10;++i)
	{
		cin>>a;
		oa.insert(a);
	}
	oa.insertsorting();
	oa.display();
}
