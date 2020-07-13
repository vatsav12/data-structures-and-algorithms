#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		bool visited = false;
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
void find_loop()
{
	Node *p =root;
	unordered_set<Node*>s;
	while(p!=NULL)
	{ 
       if(s.find(p)==s.end())
       {
       	s.insert(p);
       	
       }
	   else
	   {
	   	cout<<"loop milgaya"<<endl;
	   	break;
	   }
	   p = p->next;
	}	
}
void find_loop_visited()
{
	Node *p;
	p = root;
	while(p!=NULL)
	{
		if(p->visited == true)
		{
			cout<<"lopp dorikesindi"<<endl;
			break;
		}
		else
		{
			p->visited = true;
			p = p->next;
		}
	}
}
void find_loop_floyd()
{
	Node *fast=root,*slow=root,*p = root;
	while(fast->next!=NULL&&fast!=NULL&&slow!=NULL)
	{
		if(fast == slow)
		{
			cout<<"loop found"<<endl;
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
		
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

int main()
{

	append();
	append();
	append();
	Node *p=root;
	p->next->next->next = root;
	//display();
	find_loop();
	find_loop_visited();
	find_loop_floyd();
	//cout<<find_frequency(root,10)<<ends<<find_frequency_n(root,10);
	
}
