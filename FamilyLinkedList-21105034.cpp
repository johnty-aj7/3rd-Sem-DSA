#include <iostream>
#include <string>
#include "familyclass.h"

using namespace std;

//Specify size of family ; input name ; and age of every member

Family *takeinputand_appendatlast() 
   
   {
    int n;
    cout << "Enter the size of the family: ";
    
    cin >> n;
               cout << endl;

    Family *head = NULL;
    
    Family *nxt = NULL;
    
    Family *previous = NULL;

    for (int i = 1; i <= n; i++)
    
    {
        string s;
        
        cout << "enter " << i << "th family member's name : ";
              cin >> s;

        int age;
        
        cout << "Enter " << i << "th family memeber's age : ";
              cin >> age;

        Family *newmem = new Family(s, age);

        if (head == NULL)
        {
            head = newmem;
            nxt = newmem;
            previous = newmem;
        }
        else
        
        {
            previous->next = newmem;
            
            newmem->prev = previous;
            
            nxt = newmem;
            
            previous = nxt;
        }
    }
    return head;
}

//remove family member

Family *remove_element_from_index_i(Family *head, int i)
{
    if (head == NULL)
    {
        return head;
    }
    Family *temp = head;
    if (i == 0)
    {
        temp = temp->next;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    else
    {
        int count = 0;
        Family *temp1 = head;
        Family *temp2 = NULL;

        while (count < (i - 1))
        {
            temp1 = temp1->next;
            count++;
        }
        Family *to_be_deleted = temp1->next;
        temp2 = to_be_deleted->next;
        temp1->next = temp2;
        temp2->prev = temp1;

        delete to_be_deleted;
        return head;
    }
}

// pront every member of the family

void printdoubleLL(Family *head)
   {
  
  
  Family *temp = head;
    cout << endl
         << "FAMILY TREE--" << endl;
    while (temp != NULL)
    {
        cout << "Mem name : " << temp->name << " "
             << "Mem age : " << temp->age << endl;
        temp = temp->next;
    }
}

int main()

{

    // TAke input and append it at the end of list
    
    Family *head = takeinputand_appendatlast();
    printdoubleLL(head);

    // Remove a family memeber
    
    int i;
    cin >> i;
    Family *remo = remove_element_from_index_i(head, i);
    printdoubleLL(remo);
}
