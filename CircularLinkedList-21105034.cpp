
//Aaryan Abbot
//ECE
//21105034



//Q1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput_circular_LL()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

   
    while (data != -1)
    {
        Node *newnode = new Node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    tail->next = head;
    return head;
}

void print_circular_LL(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;

    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


void insert_at_tail(Node *&head, int k)
{
    if (head == NULL)
    {
        Node *newnode = new Node(k);
        head = newnode;
    }

    Node *newnode = new Node(k); // node to inserted at last has been created.

  
    Node *temp1 = head;
    Node *tail = head;
    tail = tail->next;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    
    tail->next = newnode;
    newnode->next = head;
}

// INSERTING THE NODE AT THE FRONT OF THE LINED LIST.
void insert_at_head(Node *&head, int k)
{
    if (head == NULL)
    {
        Node *newnode = new Node(k);
        head = newnode;
        return;
    }

   
    Node *newnode = new Node(k);

    
    Node *tail = head;

    while (tail->next != head)
    {
        tail = tail->next;
    }

    tail->next = newnode;
    newnode->next = head;
    head = newnode;
}

int main()
{
    // CREATING A LINKED LIST.
    Node *head = takeinput_circular_LL();
    print_circular_LL(head);
    cout << endl;

    // INSERTING ELEMENTS AT THE HEAD.
    insert_at_tail(head, 10);
    print_circular_LL(head);
    cout << endl;

    // INSERTING ELEMENTS AT THE TAIL.
    insert_at_head(head, 20);
    print_circular_LL(head);
}



/*
Q2

1. It is used to manage the computing resources of a computer.
2. Other Data Structures can be implemented using the Circular Linked List.
3. Used in the implementation of heap.
4.They are also used streaming video.  
*/
