#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
 node* create_node(int v)
 {
     node* newnode=new node();
     newnode->data=v;
     newnode->next=NULL;
     return newnode;
 }
 void insert_beg(node*& head,int v)
 {
    node* newnode=create_node(v);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return;
    }
    newnode->next=head;
    head=newnode;
    cout<<v<<" inserted at beginning\n";
 }
 void insert_end(node*& head,int v)
 {
     node* newnode=create_node(v);
     if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        return;
    }
     node* temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;
     }
     temp->next=newnode;
     newnode->next=NULL;
     cout<<v<<"inserted at end\n";
 }
 void insert_pos(node*& head,int v,int p)
 {
     if(p<=0)
     {
         cout<<"invalid position";
         return;
     }
     node* newnode=create_node(v);
     if(p==1)
     {
        newnode->next=head;
        head=newnode;
        return;
     }
     node* temp=head;
     for(int i=1;i<p-1 && temp!=NULL;i++)
     {
        temp=temp->next;
     }
     if(temp==NULL)
     {
         cout<<"out range cannot insert";
         return;
     }
     newnode->next=temp->next;
     temp->next=newnode;
     cout<<v<<"added in position\n"<<p;
 }
 void delete_beg(node*& head)
 {
    if(head==NULL)
    {
        cout<<"list is empty cannot perform deletion";
        return;
    }
    node* temp=head;
    head=temp->next;
    cout<<temp->data<<"deleted from list";
    delete temp;
 }
 void delete_end(node*& head)
 {
    if(head==NULL)
    {
        cout<<"list is empty cannot perform deletion";
        return;
    }
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;

 }
 void delete_pos(node*&  head,int p)
 {
    node* temp=head;
    if(p<=0)
    {
        cout<<"invalid position";
        return;
    }
    if(p==1)
    {
        delete_end(head);
        return;
    }
    for(int i=1;i<p-1&&temp->next!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        cout<<"position out of range";
    }
    delete temp->next;
    temp->next=NULL;
 }
 void display(node* head)
 {
    node* temp=head;
     while(temp!=NULL)
     {
        cout<<temp->data;
        temp=temp->next;
     }
 }
int main()
{
    node* head=NULL;
    int x=-1,v,p;
    while(x!=0)
    {
        cout<<"enter 1 for insert at beginning\nenter 2 for insert at     end\nenter 3 for insert at given position\n\nenter 4 for deletion at beginning\nenter 5 for deletion at end\nenter 6 for deletion at given position\nenter 7 for display\nenter 0 for stop\n";
        cout<<"enter:";
        cin>>x;
        if(x<0||x>4)
        {
            cout<<"wrong choice\n";
        }
        switch(x)
        {
            case 1:
                     cout<<"enter the value to be inserted:";
                    cin>>v;
                    insert_beg(head,v)    ;
                    break;
            case 2:
                     cout<<"enter the value to be inserted:";
                    cin>>v;
                    insert_end(head,v) ;
                    break;
            case 3:
                     cout<<"enter the value to be inserted:";
                    cin>>v;
                    cout<<"enter the position:";
                    cin>>p;
                    insert_pos(head,v,p)   ;
                    break;
            case 4:
                    delete_beg(head);
                    break;
            case 5:
                    delete_end(head);
                    break;
            case 6:
                    cout<<"enter the position:";
                    cin>>p;
                    delete_pos(head,p);
                    break;
            case 7:
                    display(head);
                    break;
            default:
                        cout<<"execution stopped";
        }
    }
    return 0;
}