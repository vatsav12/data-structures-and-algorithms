#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

Node *root = NULL;

void add_at_head()
{
	Node *t = new Node();
	cout<<"enter the data to be inserted at the beginign of the linked list"<<endl;
	cin>>t->data;
	t->next = NULL;
	if(root==NULL) 
	{
		root = t;
	}
	else
	{
		t->next = root;
		root = t;
	}
	
}
void add_at_position(int pos)
{
	Node *p,*t;
	t = new Node();
	cout<<"enter data to add at given position"<<endl;
	cin>>t->data;
	t->next = NULL;
	p = root;
	for(int i=0;i<pos-1;i++)
	{
		if(p==NULL)
		{
		    break;
		}
		else
		{
			p = p->next;
		}
	}
	if(p==NULL)
	{
		
	}
	else
	{
	
	t->next = p->next;
	p->next = t;
}
}
void append()
{
	Node *t = new Node();
    cout<<"enter the data to append"<<endl;
	cin>>t->data;
	t->next = NULL;	
	if(root == NULL)
	{
		root = t;
	}
	else
	{
		Node *p;
		p = root;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = t;
	}
}
void display()
{
	Node *p;
	p = root;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p = p->next;
	}
}
void find_mid_fs()
{
	if(root == NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		Node *slow=root,*fast=root;
		while(fast!=NULL&&fast->next!=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		cout<<"the middle element is "<<ends<<slow->data;
	}
}
void find_mid_oddeven()
{
	if(root==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		int count=0;
		Node *mid = root;
		Node *p = root;
		while(p->next!=NULL)
		{
			if(count&1)
			{
				mid = mid->next;
			}
			count++;
		    p = p->next;
		}
		cout<<"the middle element is "<<ends<<mid->data;
	}
}
int main()
{
	add_at_head();
	add_at_head();
	add_at_head();
	append();
	append();
	append();
	add_at_position(2);
	find_mid_fs();
	find_mid_oddeven();
}
