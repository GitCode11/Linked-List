#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};
int length(node* head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
void insertathead(node*&head,int data)
{
    node* newnode=new node(data);
    newnode->next=head;
    head=newnode;
}
void insertattail(node*&head,int data)
{
    node* newnode=new node(data);
    if(head==NULL)
    {
        head=newnode;
        return;                 // O R
        //insertathead(head,data);
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertatmid(node*&head,int data,int pos)
{
    if(pos==1 || head==NULL)
    {
        insertathead(head,data);
        return;
    }
    else if(pos==(length(head)+1))
    {
        insertattail(head,data);
        return;
    }
    else
    {
        int i=1;
        node* temp=head;
        node* newnode=new node(data);
        while(i<(pos-1))
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deleteatpos(node*&head,int pos)
{
    if(head==NULL)              // IF LL DOESN'T EXIST
    {
        return;
    }
    else if(pos==1)                // DELETING THE HEAD
    {
        node*temp=head;
        head=head->next;
        delete temp;
    }
    else if(pos==(length(head)+1))      //DELETING THE TAIL
    {
        node*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
        }
        node * q=(temp-1);
        q->next=NULL;
        delete temp;
    }
    else                                // DELETING IN MID POS
    {
        int i=1;
        node* temp=head;
        while(i<(pos-1))
        {
            temp=temp->next;
            i++;
        }
        node* q=temp->next;
        temp->next=q->next;
        delete q;
    }
}
bool searchrecursive(node * head,int key)
{
    if(head==NULL)              // B A S E  C A S E
    {
        return false;
    }
    if(head->data==key)
    {
        return true;
    }
    else                        // R E C U R S I V E  C A S E
        return searchrecursive(head->next,key);
}
bool searchiterative(node * head,int key)
{
    while(head!=NULL)
    {
        if(head->data==key)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}

int midpoint(node*head)
{
    node*fast=head;
    node*slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
void createll(node*& head)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertattail(head,data);
        cin>>data;
    }
}
void reversell(node*&head)
{
    node* curr=head;
    node* prev=NULL;
    node* newptr;
    while(curr!=NULL)
    {
        newptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=newptr;
    }
    head=prev;
}

void print(node* head)      //Passed by value so won't change the head in main()
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
}
istream& operator>>(istream &is,node* &head)        // O P E R A T O R  O V E R L O A D I N G
{
    createll(head);
    return is;
}
ostream& operator<<(ostream &os,node* head)
{
    print(head);
    return os;
}

int main()
{
    /*node* head=NULL;
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    insertattail(head,4);
    insertattail(head,8);
    insertatmid(head,5,5);
    deleteatpos(head,5);
    //createll(head);
    //print(head);
    cin>>head;
    cout<<head<<endl;
    //reversell(head);
    //cout<<head<<endl;
    cout<<midpoint(head)<<endl;*/
    return 0;
}
