#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

Node *root1 = NULL;
Node *root2 = NULL;
void append(Node **root)
{
	Node *t = new Node();
    cout<<"enter the data to append"<<endl;
	cin>>t->data;
	t->next = NULL;	
	if(*root == NULL)
	{
		*root = t;
	}
	else
	{
		Node *p;
		p = *root;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = t;
	}
}
void display(Node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p = p->next;
	}
}
Node *dummy = NULL;
Node* merge(Node *a,Node *b)
{
	Node *q;
	if(a == NULL)
	{
         dummy = b;
		 return dummy;		
	}
	if(b == NULL)
	{
		dummy = a;
		return dummy;
	}
	while(a!=NULL&&b!=NULL)
	{
		
		Node *t = new Node();
		if(a->data<b->data)
		{
			t->data = a->data;
			a = a->next;
		}
		else if(a->data>b->data)
		{
			t->data = b->data;
			b = b->next;
		}
		else
		{
			t->data = a->data;
			a = a->next;
			b = b->next;
		}
		cout<<"the value of the t->data is "<<ends<<t->data<<endl;
		if(dummy == NULL)
		{
			
			dummy = t;
			q = dummy;
		}
		else
		{
			dummy->next = t;
			dummy = dummy->next;
		}
		//dummy = dummy->next;
		t = NULL;
	}
	if(a == NULL)
	{
		dummy->next = b;
	}
	else
	{
		dummy->next = a;
	}
	return q;
}
int main()
{
     append(&root1);
     append(&root1);
     append(&root1);
     append(&root2);
     append(&root2);
     append(&root2);
     Node *r=merge(root1,root2);
     display(r);
     
}
