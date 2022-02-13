using namespace std;
#include <iostream>

class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }


    void insert();
    void delete_beg();
    void delete_end();
    void delete_loc(int pos);
    void display();
};

Node *head;


void Node::insert()
{
    cout << "Enter the Data:";
    cin >> data;
    Node *temp;
    Node *newnode = new Node();
    newnode->data = data;

    if (head == NULL)
        head = temp = newnode;
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void Node::delete_beg()
{
    Node *temp;
    temp = head;
    head = head->next;
    cout << "Deleted Element :" << temp->data;
    delete (temp);
}

void Node::delete_end()
{
    Node *temp1 = head;
    Node *temp2 = head->next;

    while (temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout << "Deleted Element :" << temp2->data;
    delete(temp2);
    temp1->next = NULL;
}

void Node::delete_loc(int pos)
{
    Node *ptr, *ptr2;
    ptr = head;
    ptr2 = head;
    for(int i = 1; i<pos; i++){
        ptr2 = ptr;
        ptr = ptr->next;
    }
    cout<<"Deleted Element :"<<ptr2->next->data;
    ptr2->next = ptr->next;
}

void Node::display()
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int n, ch, pos;
    head = NULL;
    Node ob;
    cout << "Enter The No. Of Nodes To Be Created :";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ob.insert();
    }
    while (1)
    {
        cout << "\n\nEnter Your Choice\n";
        cout << "1.Delete Node At The Beginning\n";
        cout << "2.Delete Node At The End\n";
        cout << "3.Delete Node At The Given Position\n";
        cout << "4.Display The List\n";
        cout << "5.Exit\n";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            ob.delete_beg();
            break;

        case 2:
            ob.delete_end();
            break;

        case 3:
            cout << "Enter The Position :";
            cin >> pos;
            ob.delete_loc(pos);
            break;

        case 4:
            ob.display();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}
