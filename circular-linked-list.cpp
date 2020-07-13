#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
};

Node *root = NULL;
Node *temp = NULL;
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
		temp = t;
	}
	else
	{
		Node *p;
		p = root;
		temp->next = t;
		t->prev = temp;
		t->next = p;
		p->prev = t;
		temp = temp->next;
	}
}

void display(Node *p)
{
	Node *temp = p;
    do
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}while(temp!=p);
}


int main()
{
	append();
	append();
	append();
	append();
	append();
	append();
	append();
	append();
	append();
	append();
	display(root->next->next);
}
