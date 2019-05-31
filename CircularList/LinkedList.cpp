#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	 int data;
	 struct node *next;
};

class circularList 
{
	private:
		struct node *head;
	public:
		void createList(int);
		void insertAtStart(int);
		void diplayList();
		circularList()
		{
			head=NULL;
		}
};

void circularList::createList(int data)
{
	struct node* temp;
	struct node* parser;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=data;
		head->next=NULL; 
		parser=head;
	}
	else
	{
		temp=(struct  node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		parser->next=temp;
		parser=temp;
	}
	parser->next=head;
}

void circularList::insertAtStart(int data)
{
	struct node* temp;
	struct node* parser;
	if(head==NULL)
	{
		head->data=data;
		head->next=NULL;
	}
	else
	{
		parser=head;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=head;
		do
		{
			parser=parser->next;	
		}while(parser->next!=head);	
		
		head=temp;
		parser->next=head;
	}
}

void circularList::diplayList()
{
	struct node *temp=head;
	do
	{
		cout<<"\ndata:"<<temp->data<<endl;
		temp=temp->next;
	}
	while(temp!= head);

} 

int main(void)
{
	circularList c;
	c.createList(5);
	c.createList(10);
	c.createList(15);
	c.insertAtStart(30);
	c.insertAtStart(40);
	c.createList(20);

	c.diplayList();
}