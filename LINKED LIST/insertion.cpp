using namespace std;
#include<iostream>

class Node
{
    int data;
    Node *next;

    public:
    Node()                        // Default Constructor
    {
        data=0;
        next=NULL;
    }

    // Function definition inside the class makes them inline
    void insert();
    void insert_beg();
    void insert_end();
    void insert_loc(int pos);
    void display();
};

Node *head;

void Node::insert()
{
    cout<<"Enter the Data:";
    cin>>data;
    Node *temp;
    Node *newnode=new Node();
    newnode->data=data;
    // newnode->next=NULL;     NOT required since we already assigned null in the constructor part
    if(head==NULL)
        head=temp=newnode;     //Points to the 1st node
    else
    {
        temp->next=newnode;
        temp=newnode;         //Keeps the address of the node to link it with the next node
    }
}

void Node::insert_beg()
{
    cout<<"Enter the Data:";
    cin>>data;
    Node *newnode=new Node();
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}

void Node::insert_end()
{
    cout<<"Enter the Data:";
    cin>>data;
    Node *temp;
    Node *newnode=new Node();
    newnode->data=data;
    temp=head;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void Node::insert_loc(int pos)
{
    cout<<"Enter the Data:";
    cin>>data;
    Node *temp;
    Node *newnode=new Node();
    newnode->data=data;
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    temp=head;
    for(int i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    newnode->data=temp->data;
    newnode->next=temp->next;
    temp->data=data;
    temp->next=newnode;
}

void Node::display()
{
    Node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;

    }
}
int main()
{
    int n,ch,pos;
    head=NULL;
    Node ob;
    cout<<"Enter The No. Of Nodes To Be Created :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ob.insert();
    }
    while(1)
    {
        cout<<"\n\nEnter Your Choice\n";
        cout<<"1.Insert Node At The Beginning\n";
        cout<<"2.Insert Node At The End\n";
        cout<<"3.Insert Node At The Given Position\n";
        cout<<"4.Display The List\n";
        cout<<"5.Exit\n";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
            ob.insert_beg();
            break;

            case 2:
            ob.insert_end();
            break;

            case 3:
            cout<<"Enter The Position :";
            cin>>pos;
            ob.insert_loc(pos);
            break;

            case 4:
            ob.display();
            break;

            case 5:
            exit(0);

            default:
            cout<<"Invalid Choice!\n";
        }
    }

    return 0;
}
