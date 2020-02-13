#include<iostream>
#include<vector>
using namespace std;
class orderedarr
{
	private:
		vector<int> v;
		int totEle;
	public:
		orderedarr(int max)
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
		void sort(){
			int min;
			for(int i=0;i<totEle;++i)
			{
			min=v[i];
				for(int j=i;j<totEle;++j)
				{
					if(v[j]<min)
					{
						min=v[j];
							for(int k=j;k>i;--k)
							{
								v[k]=v[k-1];
							}
								v[i]=min;
					}
				}
			}
		}
		void insert(int value)
		{
		v[totEle]=value;
		totEle++;
		sort();
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
	orderedarr oa(20);
	cout<<"Enter 10 no.\n";
	int a;
	for(int i=0;i<10;++i)
	{
		cin>>a;
		oa.insert(a);
	}
	oa.display();
	int ind = oa.binfind(31);
	cout<<"Found 31 at "<<ind+1<<endl;
	ind = oa.linfind(17);
	cout<<"Found 17 at "<<ind+1<<endl;
	cout<<"Deleting 19 and 22\n";
	oa.deletev(19);
	oa.deletev(22);
	oa.display();
}
