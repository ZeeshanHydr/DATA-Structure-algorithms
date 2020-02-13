#include<iostream>
using namespace std;
class node{
	private:
		int data;
	public:
		node* leftchild;
		node* rightchild;
		node(int d):data(d),leftchild(nullptr),rightchild(nullptr){
		}
		int getdata()
		{return data;		}
		void setdata(int d)
		{data=d;		}
		void displaynode(){
			cout<<endl<<data<<endl;
		}
};
class tree{
	private:
		node* root;
	public:
		tree():root(nullptr){
		}
		node* getroot(){
			return root;
		}
		void insertnode(int d)
		{
			if(root==nullptr)
			root=new node(d);
			else
			{
				node* ptr=root;
				while(ptr!=nullptr)
				{
					if(ptr->getdata()>d && ptr->leftchild!=nullptr)
					ptr=ptr->leftchild;
					else if(ptr->getdata()<d && ptr->rightchild!=nullptr)
					ptr=ptr->rightchild;
					else 
					break;
				}
				if(ptr->getdata()>d)
				ptr->leftchild=new node(d);
				else if(ptr->getdata()<d)
				ptr->rightchild=new node(d);
				ptr=nullptr;
			}
		}
		bool findnode(int d,node* parentn,node* n){
			node* ptr=root;
			node *ptr2=root;
			while(ptr!=nullptr)
			{
					if(ptr2->getdata()==d)
					{
						parentn=ptr;
						n=ptr2;
						ptr2=nullptr;
						ptr=nullptr;
						return true;
					}
				else if(ptr->getdata()>d)
				{
				ptr=ptr2;
				ptr2=ptr->leftchild;
				}
				else if(ptr->getdata()<d)
				{
				ptr=ptr2;
				ptr2=ptr->rightchild;	
				}
			}
				parentn=nullptr;
				n=nullptr;
				ptr2=nullptr;
				ptr=nullptr;
				return false;
		}
	void preorder(node* _root) {
	 if(_root != nullptr) 
	 	{ 
		 cout<<_root->getdata()<<"  ";
	  preorder(_root->leftchild);
		 preorder(_root->rightchild);
	 	}
	}
	void inorder(node* _root) { 
	if(_root != nullptr) 
		{ 
		inorder(_root->leftchild);   
	 	cout << _root->getdata()<<"  ";    
	 	inorder(_root->rightchild);    
	  	}
	}
	void postorder(node* _root) { 
	if(_root != nullptr) 
		{ 
		postorder(_root->leftchild);   
	 	postorder(_root->rightchild);
		cout << _root->getdata()<<"  ";    
	  	}
	}
	void displaytree()
		{
			preorder(root);
		}
	node* findMin(node* root1)
	{
	while(root1->leftchild!=nullptr) 
	root1=root1->leftchild;
	return root1;
	}
	node* deletenode(node* root1,int data) {
		if(root1 == nullptr) 
			return root1; 
		else if(data<root1->getdata()) 
			root1->leftchild = deletenode(root1->leftchild,data);
		else if (data>root1->getdata()) 
			root1->rightchild = deletenode(root1->rightchild,data);	
		else {
			if(root1->leftchild == nullptr && root1->rightchild == nullptr) { 
				delete root1;
				root1=nullptr;
		}
		else if(root1->leftchild == nullptr) {
			node *temp = root1;
			root1 = root1->rightchild;
			delete temp;
		}
		else if(root1->rightchild == nullptr) {
			node *temp = root1;
			root1 = root1->leftchild;
			delete temp;
		}
		else { 
			node *temp = findMin(root1->rightchild);
			root1->setdata(temp->getdata());
			root1->rightchild = deletenode(root1->rightchild,temp->getdata());
		}
	}
	return root1;
}
};
int main(){
	tree vtree;
	vtree.insertnode(34);					
	vtree.insertnode(25);					
	vtree.insertnode(36);									
	vtree.insertnode(46);
	vtree.insertnode(35);
	vtree.insertnode(23);
	vtree.insertnode(27);
/*
             34
          /     \
        25       36
       /  \    /   \
      23  27  35   46
*/
	vtree.displaytree();
	vtree.deletenode(vtree.getroot(),36);
	vtree.displaytree();
}



