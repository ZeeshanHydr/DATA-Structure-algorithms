 #include<iostream>
#include<string>
using namespace std;
template<class datatype>
class stack{
	private:
		datatype *arr;
		int top;
		int capacity;
	public:
		stack(){
	arr = new datatype[10];
	top=-1;
	capacity=10;
}
	stack(int a){
	capacity = a;
	top=-1;
	arr = new datatype[a];
}
bool isEmpty(){
	if(top==-1)
	return true;
	else
	return false;
}
bool isFull(){
	if((top+1)==capacity)
	return true;
	else
	return false;
}
bool push(datatype a){
	if(!isFull())
	{
		arr[++top]=a;
		return true;
	}
	return false;
}
bool peek(datatype& a){
	if(!isEmpty())
	{
		a=arr[top];
		return true;
	}
	return false;
}
bool pop(datatype& a){
	if(!isEmpty())
	{
		a=arr[top--];
		return true;
	}
	return false;
}
};
int main(){
//	stack <int>s1(30);
//	int v;
//	if(!(s1.push(25)))
//	cout<<"Can't Push..\n";
//	if(!(s1.push(12)))
//	cout<<"Can't Push..\n";
//	if(!(s1.push(41)))
//	cout<<"Can't Push..\n";
//	if(!(s1.push(32)))
//	cout<<"Can't Push..\n";
//	if(!(s1.pop(v)))
//	cout<<"Can't Pop..\n";
//	else
//	cout<<v<<endl;
//	if(!(s1.push(15)))
//	cout<<"Can't Push..\n";
//	if(!(s1.push(44)))
//	cout<<"Can't Push..\n";
//	int a=0;
//	cout<<"Enter numbers and -1 to terminate.\n";
//	while(a!=-1)
//	{
//		cin>>a;
//		if(a!=-1)
//		s1.push(a);
//	}
//	while(!s1.isEmpty())
//	{
//		s1.pop(a);
//		cout<<a<<endl;
//	}
//	stack <int>s2;
//	stack <int>s3;
//	while(!s1.isEmpty())
//	{
//		s1.pop(a);
//		s2.push(a);
//	}
//	while(!s2.isEmpty()){
//		s2.pop(a);
//		s3.push(a);
//	}
//	while(!s3.isEmpty()){
//		s3.pop(a);
//		s1.push(a);
//	}
//	while(!s1.isEmpty())
//	{
//		s1.pop(a);
//		cout<<a<<endl;
//	}
char a;
	string s1;
	cout<<"Enter problem.\n";
	getline(cin,s1);
	stack <char>st(s1.length());
	for(int i=0;i<s1.length();++i)
	{
		if(s1[i]=='[' || s1[i]=='{' || s1[i]=='(')
		st.push(s1[i]);
		else if(s1[i]==']' || s1[i]=='}' || s1[i]==')'){
			if(st.isEmpty())
			{
			cout<<"Invalid problem.\n";
		return 0;}
			st.peek(a);
			if(a=='('&& s1[i]==')' ||a=='{'&& s1[i]=='}' ||a=='['&& s1[i]==']' )
			st.pop(a);
		}
	}
	if(!st.isEmpty())
	{
		cout<<"Invalid problem.\n";
	}
	else
	cout<<"Valid!!!\n";
}
