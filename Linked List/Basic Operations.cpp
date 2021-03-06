#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node();
};
Node::Node()
{
    data=0;
    next=NULL;
}

class LinkedList
{
    public:
    Node *start;
    Node *last;
    void insertion(int);
    void insert_at_head(int);
    void insert_after(int,int);
    void print_list();
    void deletion(int);
    int getLength();
    bool search_for_element(int);
    int return_middle_element();
    LinkedList();
};

LinkedList::LinkedList()
{
    start = new Node();
    start->data =INT_MIN;
    last=start;
}

void LinkedList::insertion(int val)
{
    if(last->data==INT_MIN)
    {
        Node *new_node = new Node();
        new_node->data=val;
        start=new_node;
        start->next=NULL;
        last=start;
        //cout<<"Entered at first\n";
        //free(new_node);
    }
    else
    {
        Node *new_node = new Node();
        new_node->data=val;
        last->next=new_node;
        last=new_node;
        //cout<<"Entered at last\n";
        //free(new_node);
    }
    
}
void LinkedList::print_list()
{
    Node *temp = new Node();
    temp=start;
    if(temp->next==NULL)
    {
        cout<<"List is empty\n";
    }
    else
    {
        while(temp)
        {
            if(temp->next)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            else
            {
                cout<<temp->data<<"\n";
                temp=temp->next;
            }
            

        }
        //cout<<"\n";
    }
    //free(temp);
}
void LinkedList::insert_at_head(int val)
{
    Node *new_node = new Node();
    new_node->data=val;
    new_node->next=start;
    start=new_node;
    //free(new_node);
}

void LinkedList::insert_after(int val,int to_be_inserted)
{
    Node *temp = new Node();
    temp=start;
    while(temp->data!=val and temp)
    {
        temp=temp->next;
    }
    if(temp!=NULL and temp->data == val)
    {
        Node *new_node =  new Node();
        new_node->data=to_be_inserted;
        new_node->next=temp->next;
        temp->next=new_node;
    }
    else
    {
        cout<<"The given node doesn't exist\n";
    }
    //free(temp);
    
}

void LinkedList::deletion(int value)
{
    Node *temp = new Node();
    temp=start;
    if(temp->data == value)
    {
        if(temp->next!=NULL)
        {
            start=temp->next;
            return ;
        }
        else
        {
            start=NULL;
            return ;
        }
        
    }
    while(temp->next->data != value and temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next->data == value)
    {
        temp->next=temp->next->next;
    }
    else
    {
        cout<<"Given value doesn't exist\n";
    }
    
}

int LinkedList::getLength()
{
    Node *temp = new Node();
    temp =start;
    int count = 0;
    while(temp)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

bool LinkedList::search_for_element(int value)
{
    Node *temp;
    temp = start;
    while(temp->next!=NULL and temp->data != value)
    {
        temp=temp->next;
    }
    if(temp and temp->data == value)
    {
        return true;
    }
    return false;
}

int LinkedList::return_middle_element()
{
    Node *single_jump=start,*double_jump=start;
    while(double_jump!=NULL and double_jump->next!=NULL)
    {
        single_jump=single_jump->next;
        double_jump=double_jump->next->next;
    }
    return single_jump->data;

}
int main()
{
    LinkedList ll;
    for(int i=0;i<10;i++)
    {
        //cout<<"Value of i "<<i<<"\n";
        ll.insertion(i);
    }
    ll.insert_at_head(11);
    cout<<"Before calling the insert after method\n";
    ll.print_list();
    ll.insert_after(11,12);
    cout<<"After the insert after\n";
    ll.print_list();
    cout<<"Deleting 5\n";
    ll.deletion(5);
    ll.print_list();
    cout<<"Length of given list "<<ll.getLength()<<"\n";
    cout<<"Middle of element is "<<ll.return_middle_element()<<"\n";
    cout<<"Finish\n";
    return 0;
}