#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
};

Node *root = NULL;

void add_at_head()
{
	Node *t = new Node();
	cout<<"enter the data to be inserted at the beginign of the linked list"<<endl;
	cin>>t->data;
	t->next = NULL;
	t->prev = NULL;
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
	t->prev = NULL;
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
	t->prev = p;
	p->next = t;
}
}
void append()
{
	Node *t = new Node();
    cout<<"enter the data to append"<<endl;
	cin>>t->data;
	t->next = NULL;	
	t->prev = NULL;
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
		t->next = NULL;
		t->prev = p;
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
		Node *p = root;
		while(p!=NULL&&p->data!=ele)
		{
			p = p->next;
		}
		if(p==NULL)
		{
	       cout<<"No element found"<<endl;		
		}
		else
		{
		   cout<<p->data<<ends<<"deleted successfully"<<endl;
		   p->prev->next = p->next;
		   p->next->prev = p->prev;
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
		   p->prev->next = p->next;
		   p->next->prev = p->prev;
			delete p;
		}
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
	cout<<"before deleting "<<endl;
	display();
    delete_node(25);
	delete_node(120);
    delete_at_pos(3);
    cout<<"after deletion at 3"<<endl;
    display();
}
