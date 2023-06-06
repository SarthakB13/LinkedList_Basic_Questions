# include <iostream>
# include <assert.h>
# include <limits.h>

using namespace std;

//node class
class Node
{
public:
    int data;
    Node *next;

    //Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
    //parameterised constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

//Linked List class to implement the linked list
class Linkedlist
{
    Node* head;

public: 
    
    Linkedlist() { head = NULL; }
    
    void newFront(int data);

    void newEnd(int data);

    void search(int data);

    void del(int data);

    void length();

    void PrintList();

    void Nth(int num);

    void CountNth(int data);

    void max();

    void min();
};

void Linkedlist::newFront(int data)
{
    Node* new_node = new Node(data);
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    new_node->next = head;
    head = new_node;
}

void Linkedlist::newEnd(int data)
{
    Node* new_node = new Node(data);
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

void Linkedlist::length()
{
    if(head == NULL)
    {
        cout<<"List empty";
        return;
    }

    int count = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp -> next;
    }
    
    cout<<"Length: ";
    cout<<count;
}

void Linkedlist::PrintList()
{
    if(head == NULL)
    {
        cout<<"List Empty";
        return;
    }

    Node* temp = head;
    cout<<"list: ";
    while(temp!=NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<< " " <<endl;
}

void Linkedlist::search(int data)
{
    if(head == NULL)
    {
        cout<<"List empty";
        return;
    }
    Node* temp=head->next;
    while(temp!=NULL)
    {
        if( temp->data == data )
        {
            cout<<"Element found";
            return;
        }
        else
        {
            temp=temp->next;
        }
    }
    cout<<"element not Found";
}

void Linkedlist::del(int data)
{
    Node* temp = head;
    Node* prev = NULL;
    if(head == NULL)
    {
        cout<<"list empty";
        return;
    }

    if(temp->data == data)
    {
        head=temp->next;
        temp->next=NULL;
        return;
    }

    while(temp != NULL)
    {
        if(temp->data == data )
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
    cout<<"Element not found"<<endl;
}

void Linkedlist::Nth(int num)
{
    Node* temp = head;
    int count = 0;
    
    while (temp != NULL) 
    {
        if (count  == num-1)
        {    
            cout<<temp->data;
            return;
        }
        count++;
        temp = temp->next;
    }

}

void Linkedlist::CountNth(int data)
{
    if(head == NULL)
    {
        cout<<"List empty";
        return;
    }
    int count = 0;
    Node* temp=head;
    while(temp!=NULL)
    {
        if( temp->data == data )
        {
            count++;
            temp=temp->next;
        }
        else
        {
            temp=temp->next;
        }
    }
    cout<<data<<": "<<count<<endl;


}

void Linkedlist::max()
{
    if(head == NULL)
    {
        cout<<"List empty";
        return;
    }
    int max=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data >= max)
        {
            max=temp->data;
            temp=temp->next;
        }
        else
            temp=temp->next;
    }
    cout<<max<<endl;
}

void Linkedlist::min()
{
    if(head==NULL)
    {
        cout<<"list empty";
        return;
    }
    int min=INT_MAX;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data <= min)
        {
            min=temp->data;
            temp=temp->next;
        }
        else
            temp=temp->next;
    }
    cout<<min<<endl;
}

int main()
{
    Linkedlist list;

    list.newEnd(3);
    list.newEnd(8);
    list.newEnd(5);
    list.newFront(4);
    list.newFront(6);

    list.Nth(6);
    list.PrintList();

}