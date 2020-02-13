#include<graphics.h>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void getvalues(int &cox,int &coy,int &coe,string equation1)
{
	int i=0,j;
	if(equation1[0]=='x')
		cox=1;
	else if(equation1[0]=='-' && equation1[1]=='x')
	cox=-1;
	else
	cox=stoi(equation1);
	while(equation1[i]!='x')
	i++;
	for(j=i;equation1[j]!='y';++j){
	}
	if(i+2==j)
	coy=1;
	else if(equation1[i+1]=='-' && equation1[i+2]=='j')
		coy=-1;
	else
	coy=stoi(equation1.substr(i+1,j-1));
	for(;equation1[j]!='=';++j){
	}
	coe=stoi(equation1.substr(j+1,equation1.length()));
}
void findxbyy(int cox,int coy,int coe,float &x1,float &x2){
	float cox2=cox;
	coy=coy*-1;
	x1=(coe+coy)/cox2;
	x2=(coe-(coy*2))/cox2;
}
void solveequat(int &cox1,int &coy1,int &coe1,int &cox2,int &coy2,int &coe2,float &cox3,float &coy3)
{
	float coe3,cox4,coy4,coe4;
	cox3=cox1*cox2;
	cox4=cox1*cox2;
	coy3=coy1*cox2;
	coy4=coy2*cox1;
	coe3=coe1*cox2;
	coe4=coe2*cox1;
	if((cox3>0 && cox4>0) || (cox3<0 && cox4<0))
	{
		coy3=coy3-coy4;
		coe3=coe3-coe4;
	}
	else if((cox3>0 && cox4<0) || (cox3<0 && cox4>0))
	{
		coy3=coy3+coy4;
		coe3=coe3+coe4;
	}
	coy3=coe3/coy3;
	coy4=coy1*coy3;
	cox3=(coe1-coy4)/cox1;
}
void simplify_fraction(int &num,int &denom)
{
 for(int i=denom;i>=2;i--)
 {
  if(num%i==0 && denom%i==0)
  {
   num=num/i;
   denom=denom/i;
  }
 }
}
void fracpart(float &cox,int &i,int &j)
{
	double fractional_part= cox-floor(cox);
 	for(i=0.1,j=10;;i/=10,j*=10)
 	{
  	if(fractional_part>= i )
  	{
  		i=cox * j;
	simplify_fraction(i, j);
   	break;
  	}
 }
}
int main()
{
	string equation1,equation2;
	cout<<"Please enter an equation in the form of ax+by=c\n If you don't follow this format the result will ";
	cout<<"be ambigious.\n";
	cin >> equation1;
	cout<<"Enter 2nd eq.\n";
	cin >> equation2;
	float e1x1,e1y1=1,e1x2,e1y2=2;
	int cox1,coy1,coe1;
	int cox2,coy2,coe2;
	float e2x1,e2y1=1,e2x2,e2y2=2;
	getvalues(cox1,coy1,coe1,equation1);
	getvalues(cox2,coy2,coe2,equation2);
	findxbyy(cox1,coy1,coe1,e1x1,e1x2);
	findxbyy(cox2,coy2,coe2,e2x1,e2x2);
	initwindow(800,600,"Graph");
	line(0,300,getmaxx(),300);
	line(400,0,400,getmaxy());
	line(e1x1*100,e1y1*100,e1x2*100,e1y2*100);
	line(e2x1*100,e2y1*100,e2x2*100,e2y2*100);
	float cox3,coy3;
	int i,j,i2,j2;
	solveequat(cox1,coy1,coe1,cox2,coy2,coe2,cox3,coy3);
	fracpart(cox3,i,j);
	fracpart(coy3,i2,j2);
	cout<<"\nFinal answer is in the form (x,y).\n\n";
	cout<<"("<<i<<"/"<<j<<" , "<<i2<<"/"<<j2<<")   OR ( "<<cox3<<" , "<<coy3<<" )"<<endl;
	cout<<"If you solve this yourself you may get a different fraction.\n";
	cout<<" But on converting that fraction into decimal you'll get the same decimal answer.\n\n\n";
	system("pause");
}
