#include<iostream>
#include<limits.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data=0;
        next=NULL;
        prev=NULL;
    } 

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

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

    void CountNth(int num);

    void max();

    void min();
};

void Linkedlist::PrintList()
{
    if(head==NULL)
        return;
    
    Node* temp = head;
    cout<<"List: ";
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

void Linkedlist::newFront(int num)
{
    Node* new_node = new Node(num);
    Node* temp=head;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=head;
        new_node->prev=new_node;
        return;
    }

    while(temp->next!=head)
        temp=temp->next;

    head->prev=new_node;
    new_node->next=head;
    head=new_node;
    new_node->prev=temp;
    temp->next=new_node;
}

void Linkedlist::newEnd(int num)
{
    Node* new_node=new Node(num);
    Node* temp=head;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=head;
        new_node->prev=new_node;
        return;
    }

    while(temp->next!=head)
        temp=temp->next;

    new_node->prev=temp;
    temp->next=new_node;
    head->prev=new_node;
    new_node->next=head;
}

void Linkedlist::CountNth(int data)
{
    int count = 0;
    Node* temp=head;
    if(head == NULL)
        return;
    while(temp->next!=head)
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
    if(temp->data=data)
        count++;

    cout<<data<<": "<<count<<endl;
}

void Linkedlist::search(int data)
{
    Node* temp = head;
    if(head==NULL)
        return;

    while(temp->next!=head)
    {   
        if(temp->data==data)
        {
            cout<<"Element found";
            return;
        }
        else
        {
            temp=temp->next;
        }
    }
    if( temp->data == data)
    {
        cout<<"Element found";
        return;
    }
    else
    {
        cout<<"Element not found!";
        return;
    }
}

void Linkedlist::length()
{
    if(head == NULL)
        return;
    
    int count=0;
    Node* temp = head;
    while(temp->next!=head)
    {
        count++;
        temp = temp->next;
    }
    count++;

    cout<<"Length: ";
    cout<<count;
}

void Linkedlist::Nth(int num)
{
    if(head==NULL)
        return;
    Node* temp = head;
    int count = 0;
    
    while (temp->next!=head) 
    {
        if (count  == num-1)
        {    
            cout<<temp->data;
            return;
        }
        count++;
        temp = temp->next;
    }
    if (count  == num-1)
    {    
        cout<<temp->data;
        return;
    }
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
    {
        cout<<"list empty";
        return;
    }
    int min=INT_MAX;
    Node* temp=head;
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

void Linkedlist::del(int num)
{
    if(head == NULL)
        return;
    
    Node* temp = head;
    Node* pre = NULL;
    while(temp->data != num)
    {
        if(temp->next==head)
        {
            cout<<"List doesn't have node with value = "<<num<<endl;
            return;
        }
        pre=temp;
        temp=temp->next;
    }
    if(temp->next==head && pre==NULL)
    {
        head=NULL;
        return;
    }
    if(temp==head)
    {
        pre=head->prev;

        head = head->next;

        pre->next=head;
        head->prev = pre;

        temp->next=NULL;
        temp->prev=NULL;
    }
    else if (temp->next==head)
    {
        pre->next=head;
        head->prev=pre;
        temp->next=NULL;
        temp->prev=NULL;
    }
    else
    {
        Node* nex = temp->next;

        pre->next = nex;
        nex->prev = pre;
        temp->next=NULL;
        temp->prev=NULL;
    }
}

int main()
{
    Linkedlist list;

    list.newFront(3);
    list.newFront(2);
    list.newFront(7);
    list.newEnd(10);
    list.newEnd(5);
    list.newEnd(6);

    list.del(7);
    list.PrintList();
}
    