#include<iostream>
#include"linklist.cpp"
using namespace std;
class stack{
	private:
		linklist l;
	public:
		stack():l(){
		}
		void push(int d)
		{
			l.insert(d);
		}
		bool isEmpty(){
			if(l.size()==0)
			return true;
			return false;
		}
		bool pop(int &b){
			if(isEmpty())
			{
				return false;
			}
			else
			{
				int a=l.size();
				b=l.getnelement(a);
				l.delnelement(a);
				return true;
			}
		}
		int peek(){
			int a=l.size();
			return l.getnelement(a);
		}
};
int main(){
	stack s;
	s.push(5);
	s.push(3);
	s.push(4);
	int a;
	s.pop(a);
	cout<<a;
	s.pop(a);
	cout<<a;
	cout<<s.peek();
	s.pop(a);
	cout<<a;
	if(s.pop(a))
	cout<<a;
}
