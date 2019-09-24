#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
	int key;
	node* left;
	node *right;
};

node *head=NULL;

int main()
{
	struct node* insertNode(struct node*,int);
	int searchNode(node *,int);
	int inOrder(struct node*);
	int preOrder(node*);
	int postOrder(node*);
	void searchNode1(int );
	void deleteNode(node*,int data);
	node *insertNodeWithoutRecursion(node *,int);

	cout<<"\n insertion with recursion"<<endl;
	head=insertNode(head,50);
	insertNode(head,55);
	insertNode(head,40);
	insertNode(head,60);
	insertNode(head,25);
	insertNode(head,53);
	//insertNode(head,100);

	cout<<"\n insertion Without recursion"<<endl;
	insertNodeWithoutRecursion(head,100);

	/*head=insertNodeWithoutRecursion(head,50);
	insertNodeWithoutRecursion(head,55);
	insertNodeWithoutRecursion(head,40);
	insertNodeWithoutRecursion(head,60);
	insertNodeWithoutRecursion(head,25);
	insertNodeWithoutRecursion(head,53);*/


	cout<<"\nIn-Order traversal\n";
	inOrder(head);

	cout<<"\nPre-Order traversal\n";
	preOrder(head);


	cout<<"\nPost-Order traversal\n";
	postOrder(head);

	cout<<"\nSearching Node with recursion\n";
	int check=searchNode(head,100);
	cout<<"\n data"<<check<<endl;
	if(check==1)
	{
		cout<<"\ndata is present"<<endl;
	}
	else
	{
		cout<<"\ndata is not present"<<endl;
	}
	
	cout<<"\nSearching without recursion"<<endl;
	searchNode1(30);

	return 0;
}

struct node * insertNode(struct node* root,int key)
{
	if(root==NULL)
	{
		
		root=new node();
		root->key=key;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else
	{
		if(root->key <= key)
		{
			root->right=insertNode(root->right,key);
		}
		else
		{
			root->left=insertNode(root->left,key);;
		}
		return root;
	}
}

struct node * insertNodeWithoutRecursion(struct node* root,int key)
{
	node *temp=NULL;
	while(root)
	{

		if(root->key <= key)
		{
			
			temp=root;
			root=root->right;
		}
		else
		{
			temp=root;
			root=root->left;
		}
	}

	if(root==NULL)
	{
		root=new node();
		root->key=key;
		root->left=NULL;
		root->right=NULL;
		if(temp)
		{
			if(temp->key<=key)
			{
				temp->right=root;
			}
			else
			{
				temp->left=root;
			}
			return root;
		}
	}
	
}

void inOrder(node *root)
{
	
	if(root)
	{		
		inOrder(root->left);
		cout<<"\n root->data= "<<root->key<<"\n";
		inOrder(root->right);	
	}

}

void preOrder(node *root)
{
	
	if(root)
	{		
		cout<<"\n root->data= "<<root->key<<"\n";
		inOrder(root->left);
		inOrder(root->right);	
	}
}

void postOrder(node *root)
{
	if(root)
	{		
		inOrder(root->left);
		inOrder(root->right);	
		cout<<"\n root->data="<<root->key<<"\n";
	}
}

int searchNode(node * head,int data)
{
	static int flag=0;
	if(head)
	{
		if(head->key==data)
		{
			flag=1;
			return flag;
		}

		if(head->key<=data)
		{
			searchNode(head->right,data);
		}	
		else
		{
			searchNode(head->left,data);
		}

	}
	return flag;
	

}

void searchNode1(int data) //without recursion
{
	node *temp=head;
	int flag=0;
	while(temp)
	{	
		if(temp->key==data)
		{
			cout<<"temp->data:data is present"<<endl;
			flag=1;
			break;		
		}

		if(temp->key<=data)
		{
			cout<<" temp->right ";
			temp=temp->right;

		}	
		else
		{
			cout<<" temp->left ";
			temp=temp->left;
		}

	}
	if(!flag)
	{
		cout<<"\n\ndata is not present"<<endl;
		
	}

}

void deleteNode(node* root,int data)
{
	if(root->key==data)
	{
		temp
	}
}