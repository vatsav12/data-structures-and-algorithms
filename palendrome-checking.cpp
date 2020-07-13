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
int find_frequency(Node*r,int ele)
{
	if(r == NULL)
	{
		return 0;
	}
	int frequency = find_frequency(r->next,ele);
	if(r->data == ele)
	{
		frequency++;
	}
	return frequency;
}
int find_frequency_n(Node*r,int ele)
{
	//static int count=0;
	if(r == NULL)
	{
		return 0;
	}
	if(r->data == ele)
	{
		return 1+find_frequency_n(r->next,ele);
	}
	return find_frequency_n(r->next,ele);
}
void ispalendrom()
{
	if(root==NULL)
	{
		cout<<"mundu list lo element pettara Hukka"<<endl;
	}
	else
	{
		stack<int> s;
		Node *p=root;
		while(p!=NULL)
		{
			s.push(p->data);
			p = p->next;
		}
		p = root;
		while(p!=NULL)
		{
			//int a = s.pop();
			if(s.top()!=p->data)
			{
			   break;	
			}
			p=p->next;
			s.pop();
		}
		if(p)
		{
			cout<<"It is not a palendrome"<<endl;
			
		}
		else
		{
			cout<<"it is a palendrome"<<endl;
		}
	}
}
void reverse(Node **p)
{
	if(p == NULL)
	{
		cout<<"Nothing to reverse"<<endl;
	}
	else
	{
		Node *prev = NULL,*curr = *p,*next;
		while(curr!=NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		*p = prev;
	}
}
/*
void ispalendrom_using_reversing()
{
	if(root == NULL)
	{
		cout<<"the list is empty"<<endl;
	}
	else
	{
		Node *slow=root,*fast=root;
		while(fast!=NULL&&fast->next!=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		Node *mid = slow;
		if(f)
		{
			
		}
	}
}
*/
/*
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
*/
bool pal_rec(Node *p)
{
	if(p==NULL)
	{
		return true;
	}
	if(pal_rec(p->next) == false)
	{
		return false;
	}
	
	static Node *s = root;
	if(s->data == p->data)
	{
		s = s->next;
		return true;
	}
	else
	{
		//cout<<"Not a palindrome"<<endl;
		s = s->next;
		return false;
		
	}
}
int main()
{

	append();
	append();
	append();
//	cout<<find_frequency(root,10)<<ends<<find_frequency_n(root,10);
    reverse(&root);
    display();
    ispalendrom();	
    cout<<"the value of the boolean function is"<<ends<<pal_rec(root);
}
