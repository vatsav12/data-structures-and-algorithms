#include<iostream>
#include<bits/stdc++.h>
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
void delete_node(int ele)
{
	if(root == NULL)
	{
		cout<<"no elements to delete_node"<<endl;
	}
	else
	{
		Node *p = root,*prev;
		while(p!=NULL&&p->data!=ele)
		{
			prev = p;
			p = p->next;
		}
		if(p==NULL)
		{
	       cout<<"No element found"<<endl;		
		}
		else
		{
		   cout<<p->data<<ends<<"deleted successfully"<<endl;
		   prev->next = p->next;
		   delete p;	
		}		
	}
}
void delete_at_pos(int pos)
{
	if(root==NULL)
	{
		cout<<"No element to delete"<<endl;
	}
	else
	{
		Node *p = root,*prev;
		for(int i=0;i<pos-1;i++)
		{
			if(p==NULL)
			{
				break;
			}
			else
			{
				prev = p;
				p = p->next;
			}
		}
		if(p==NULL)
		{
			
			cout<<"enter a valid postion"<<endl;
		}
		else
		{
			cout<<"element"<<ends<<p->data<<ends<<"is being delted"<<endl;
			prev->next = p->next;
			delete p;
		}
	}
}
void delete_duplicates()
{
	unordered_set<int> s;
	Node *p=root;
	Node *prev;
	while(p!=NULL)
	{
		if(s.find(p->data)!=s.end())
		{
			Node *q;
			q = p;
			prev->next = p->next;
			p = p->next;
			delete q;
			
		}
		else
		{
			s.insert(p->data);
			prev = p;
			p = p->next;
		}
	}
}
void delete_duplicates_rec(Node *p,Node *prev)
{
	static unordered_set<int> s;
	if(p!=NULL)
	{
	}
	else
	{
		return;
	}
	if(s.find(p->data)!=s.end())
	{
		//cout<<"enterd into the condition"<<endl;
			Node *q;
			q = p;
			prev->next = p->next;
			p = p->next;
			delete q;
		delete_duplicates_rec(p,prev);
	}
	else
	{
		s.insert(p->data);
		prev = p;
	delete_duplicates_rec(p->next,prev);
	}
	
}
int main()
{

	append();
	append();
	append();
    append();
    append();
    append();
    cout<<"before deleting of the duplicate nodes "<<endl;
    display();
    cout<<"after deleting the duplicate nodes "<<endl;
    delete_duplicates_rec(root,NULL);
    display();
    //cout<<"the value of the boolean function is"<<ends<<pal_rec(root);
}
