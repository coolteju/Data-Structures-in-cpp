#include<iostream>

using namespace std;
struct node
{
	int data;
	struct node* next;

};


class LinkedList
{
	private:
		struct node *head;
	public:
		void insertNodeAtFirst(int);
		void insertNodeAtLast(int);
		void insertNodeAtPossition(int ,int );
		void deleteNodeFirst();
		void deleteNodelast();
		void deleteNodeAtPossition(int);
		void displayNode();
		LinkedList()
		{
			head=NULL;
		}
};

void LinkedList:: insertNodeAtFirst(int data)
{
	struct node *temp=new struct node();
		
	if(head==NULL)
	{
		head=new struct node();
		head->data=data;
		head->next=NULL;
	}

	else
	{
		temp->data=data;
		temp->next=head;
		head=temp;
	}
		
}

void LinkedList::insertNodeAtLast(int data)
{
	struct node *temp;
	if(head==NULL)
	{
		
		head=new struct node();
		head->data=data;
		head->next=NULL;
	}
	else
	{
		temp=new struct node();
		struct node *checkLast=new struct node();
		checkLast=head;
		temp->data=data;
		temp->next=NULL;
		while(checkLast->next!=NULL)
		{
			checkLast=checkLast->next;
		}
		checkLast->next=temp;

	}
}

void LinkedList::insertNodeAtPossition(int insert_after_data,int data)
{
	/*if(insert_after_data==0)
	{
		cout<<"\nPrevious node cann't be null";
		return ;
	}*/
	struct node* temp=new struct node();
	struct node* checkNode=head;

	while(checkNode!=NULL)
	{
		if(checkNode->data==insert_after_data)
		{
			temp->data=data;
			temp->next=checkNode->next;
			checkNode->next=temp;
		}
		checkNode=checkNode->next;
	}


}

void LinkedList::deleteNodeFirst()
{
	struct node *temp=new struct node();

	temp=head->next;

	delete(head);

	head=temp;


}

void LinkedList::deleteNodelast()
{
	
	struct node *temp=new struct node();
	struct node *checkNode=new struct node();
	checkNode=head;
	while(checkNode->next->next!=NULL)
	{
		checkNode=checkNode->next;

	}

	temp=checkNode->next;
	cout<<"\ntemp->data :"<<temp->data;
	cout<<"\ntemp->next "<<temp->next;
	
	delete(temp);
	checkNode->next=NULL;

}

void LinkedList::deleteNodeAtPossition(int data)
{
	struct node *temp=new struct node();
	struct node *travrseNode=head;

	while(travrseNode!=NULL)
	{
		if(travrseNode->data==data)
		{
			cout<<"\n in if :: "<<travrseNode->data;
			temp->next=travrseNode->next;
			delete(travrseNode);
			//break;
		}

		temp=travrseNode;
		travrseNode=travrseNode->next;
	}

}
 
void LinkedList::displayNode()
{
	struct node *temp=new struct node();
	temp=head;
	while(temp!=NULL)
	{
		cout<<"\ndata:"<<temp->data<<endl;
		temp=temp->next;
	}
}



int main()
{
	
	LinkedList l1;
	for(int i=1;i<=10;i++)
	{
		l1.insertNodeAtFirst(i);
	}

	//l1.displayNode();

	l1.insertNodeAtFirst(0);
	l1.insertNodeAtLast(12);	

	l1.insertNodeAtPossition(0,11);

	l1.displayNode();

	l1.deleteNodeFirst();
	//l1.deleteNodeFirst();
	cout<<"\nAfter deleting node";
	l1.displayNode();

	cout<<"\nAfter deleting last node";

	l1.deleteNodelast();
	
	l1.displayNode();

	cout<<"\nAfter deleting  node having data 2";
	l1.deleteNodeAtPossition(2);
	l1.displayNode();
	return 0;
}