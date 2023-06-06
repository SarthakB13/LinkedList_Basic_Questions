#include <iostream>
#include <limits.h>
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
    if(head == NULL)
        return;

    Node* temp = head;
    cout<<"List: ";
    while(temp!=NULL)
    {
        cout << temp->data <<" ";
        temp=temp->next;
    }
    cout<< " " <<endl;
}

void Linkedlist::newFront(int data)
{
    Node* new_node = new Node(data);
    if(head==NULL)
    {
        head = new_node;
        return;
    }

    new_node->next = head;
    head = new_node;
    new_node->prev=NULL;
}

void Linkedlist::newEnd(int data)
{
    Node* new_node = new Node(data);
    if(head==NULL)
        return;

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    new_node->prev=temp;
    temp->next=new_node;
}

void Linkedlist::search(int data)
{
    if(head == NULL)
        return;

    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == data)
        {
            cout<<"Element found";
            return;
        }
        else
        {
            temp=temp->next;
        }
    }
    cout<<"Element not found";
}

void Linkedlist::length()
{
    if(head == NULL)
        return;
    
    int count=0;
    Node* temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }

    cout<<"Length: ";
    cout<<count;
}

void Linkedlist::del(int num)
{
    if(head == NULL)
        return;
    Node* pre = NULL;
    Node* cur = head;
    Node* nex = cur->next;

    if(head->data==num)
    {
        head=head->next;
        nex->prev=NULL;
        return;
    }
    while(cur!=NULL)
    {
        if( cur->data == num )
        {
            pre->next=nex;
            nex->prev=pre;
            cur->next=NULL;
            cur->prev=NULL;
            return;
        }
        else
        {
            pre=cur;
            cur=cur->next;
            nex=nex->next;
        }
    }
    cout<<"Element not found";
}

void Linkedlist::Nth(int num)
{
    if(head==NULL)
        return;
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

int main()
{
    Linkedlist list;

    list.newFront(1);
    list.newFront(2);
    list.newFront(6);
    list.newEnd(3);
    list.newEnd(4);
    list.del(6);
    list.PrintList();
}






