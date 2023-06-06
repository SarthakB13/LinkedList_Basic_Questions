# include <iostream>
# include <assert.h>
# include <limits.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Linkedlist
{
	Node* head;
public:
	Linkedlist() { head = NULL; }

	void newNode(int data);

	void newNodelast(int data);
	
	void newNodefirst(int data);

	void print();

	void length();

	void search(int data);

	void del(int data);

	void Nth(int key);

	void CountNth(int num);

	void max();

	void min();
};

void Linkedlist::print()
{
	Node* temp = head;

    while(temp->next != head)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}

void Linkedlist::length()
{
	Node* temp = head;
	int count=0;
	while(temp->next != head)
	{
		count++;
		temp=temp->next;
	}
	count++;
	cout<<endl;
	cout<<count;
}

void Linkedlist::newNode(int data)
{
	Node* new_node = new Node(data);
	head = new_node;
	new_node->next = new_node;
}

void Linkedlist::newNodelast(int data)
{
	Node* new_node = new Node(data);
	Node* temp = head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->next=head;
}

void Linkedlist::newNodefirst(int data)
{
	Node* new_node = new Node(data);
	Node* temp = head;
	while(temp->next != head)
	{
		temp=temp->next;
	}
	new_node->next=head;
	head=new_node;
	temp->next=head;
}

void Linkedlist::search(int data)
{
	if(head == NULL)
		return;
	
	Node* temp = head;
	while(temp->next != head)
	{
		if( temp->data == data )
		{
			cout<<"Element Found";
			return;
		}
		else{
			temp=temp->next;
		}
	}
	if(temp->data==data)
	{
		cout<<"Element Found";
		return;
	}
	cout<<"Element not found";
}

void Linkedlist::del(int key)
{
	Node* temp = head;
	Node* prev = NULL;

	if(head==NULL)
		return;

	if(temp->data==key)
	{
		prev=head;
		while(temp->next!=head)
            temp=temp->next;
		head=prev->next;
		prev->next=NULL;
		temp->next=head;
	}

	if(temp->data==key && temp->next==head)
	{
		temp->next=NULL;
		head=NULL;
	}

	while(temp->next != head)
	{
		if(temp->data == key)
		{
			prev->next = temp->next;
			temp->next = NULL;
			return;
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
	if(temp->data==key)
	{
		prev->next=head;
		temp->next=NULL;
	}
}

void Linkedlist::Nth(int key)
{
	Node* temp = head;

	int count = 0;

	while (temp->next != head)
	{
		if (count == key-1)
		{
			cout<<temp->data;
			return;
		}
		count++;
		temp=temp->next;
	}
	if(count == key-1)
	{
		cout<<temp->data;
		return;
	}

}

void Linkedlist::CountNth(int num)
{
	Node* temp = head;
	if(head == NULL)
		return;

	int count=0;
	while(temp->next != head)
	{
		if(temp->data == num)
		{
			count++;
			temp = temp->next;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(temp->data==num)
	{
		count = count+1;
	}

	cout<<"count: "<<count<<endl;
}

void Linkedlist::max()
{
	if(head == NULL)
		return;
	int max=0;
	Node* temp=head;

	while(temp->next!=head)
	{
		if(temp->data >= max)
		{
			max=temp->data;
			temp=temp->next;
		}
		else
			temp=temp->next;
	}
	if(temp->data >= max)
		max=temp->data;
	
	cout<<max<<endl;
}

void Linkedlist::min()
{
	if(head==NULL)
		return;
	int min=INT_MAX;
	Node* temp = head;
	while(temp->next!=head)
	{
		if(temp->data <= min)
		{
			min=temp->data;
			temp=temp->next;
		}
		else
			temp=temp->next;
	}
	if(temp->data <= min)
		min=temp->data;
	
	cout<<min<<endl;
}

int main()
{
	Linkedlist list;

	list.newNode(8);
	list.newNodefirst(7);
	list.newNodefirst(6);
	list.newNodefirst(9);
	list.newNodelast(4);
	list.newNodelast(3);
	list.newNodelast(-1);
	
	list.print();
	list.min();
}