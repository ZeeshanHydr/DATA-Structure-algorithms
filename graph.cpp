#include<iostream>
#include<vector>
#include"linklist.cpp"
using namespace std;
class graph{
	private:
		int i;
		vector<linklist> arr;	
	public:		
		graph(){
			i=0;
			arr.resize(i);
		}		
		bool addvortex(int a)
		{
			arr.resize(++i);
			arr[i-1].insert(a);
			return true;
		}
		bool addedge(int v1,int v2){
			bool v11=false;
			bool v22=false;
			int b=-1,a;
			for(a=0;a<i;++a){
				if(arr[a].getnelement(1)==v1)
				{
					b=a;
				v11=true;
				}
				else if(arr[a].getnelement(1)==v2)
				v22=true;
			}
			if(v11 && v22)
			{
				arr[b].insert(v2);
				return true;
			}
			else 
			return false;
		}
		int searchvortex(int d)
		{
			int a;
			for(a=0;a<i;++a){
				if(arr[a].getnelement(1)==d)
					return a;
			}
		}
		bool deleteedge(int v1,int v2){
			int a=searchvortex(v1);
			arr[a].searchanddel(v2);
		}
		bool deletevortex(int d){
			for(int a=0;a<i;++a)
			{
				arr[a].searchanddel(d);
			}
		}
		void displaygraph(){
			for(int a=0;a<i;++a)
			{
				arr[a].print();
			}
		}
};
int main(){
	graph gp;
	gp.addvortex(1);
	gp.addvortex(2);
	gp.addvortex(3);
	gp.addvortex(4);
	gp.addvortex(5);
	gp.addedge(1,3);
	gp.addedge(5,2);
	gp.addedge(5,4);
	gp.addedge(1,4);
	gp.addedge(2,4);
	gp.addedge(3,5);
	gp.addedge(3,2);
	gp.addedge(3,1);
	gp.addedge(4,3);
	gp.displaygraph();
	gp.deletevortex(3);
	gp.deletevortex(1);
	gp.addvortex(1);
	gp.addvortex(3);
	gp.displaygraph();
//	gp.deleteedge(5,2);
//	gp.displaygraph();
}
