#include<iostream>
#include"linklist.cpp"
using namespace std;
class queue{
	private:
		linklist l;
	public:
		queue():l(){
		}
		void enque(int d){
			l.insert(d);
		}
		bool isEmpty(){
			if(l.size()==0)
			return true;
			return false;
		}
		bool deque(int &b){
			if(isEmpty())
			{
				return false;
			}
			else
			{
				b=l.getnelement(1);
				l.delnelement(1);
				return true;
			}
		}
		int peek(){
			return l.getnelement(1);
		}
};
int main(){
	queue q;
	q.enque(5);
	q.enque(4);
	q.enque(3);
	int a;
	q.deque(a);
	cout<<a;
	q.deque(a);
	cout<<a;
	cout<<q.peek();
	q.deque(a);
	cout<<a;
}
