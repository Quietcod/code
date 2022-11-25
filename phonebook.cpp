#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct node
{
    char name;
    int number;
    node *next;
};
node *head = NULL, *newnode, * temp;
int len = 0; 

//creation of linked list 
void c_node(){    
    newnode = new node; 
    cout<<"Enter Name:" <<endl;
    cin>> newnode -> name;

    cout<< "Enter Number:"<<endl;
    cin>>newnode -> number;
    newnode -> next = NULL;
    if (head == NULL)
    {
    head = newnode;
    temp = newnode;
    }
    else 
    {
        temp -> next = newnode;
        temp = newnode;
    }
    
}
void display() 
{
    if (head == NULL)
    {
        cout<<"Contact List is Empty"<<endl;
    }
    else
    {
        node *trav = head;
        while(trav!=NULL)
        {
            cout<<"\n\t\t Full Name :"<< trav->name<<endl;
            cout<<"\t\t Phone Number :"<< trav->number<<endl;
            trav = trav->next;
            len++;
        }

        cout<<"Total Contacts in the List ="<< len <<endl;
    }
}
void search_contact()
{
    node *search_node = head;
        string srch;
        int count = 1;
        cout<<"Enter the Desired Contact you want to Search:";
        cin >> srch;
        bool found = false; 
        if (head == NULL)
        {
            cout<<"\n List is Empty "<<endl; 
        }    
        else
            {
                while (search_node !=NULL)
                {
                    if(search_node->name || search_node->number)
                {
                    cout<<"\n\t\t Full Name:"<< search_node->name<<endl;
                    cout<<"\n\t\t Phone Number: "<<search_node->number<<endl;
                    found = true;
                    break;
                }
                search_node = search_node->next;
                cout;
            }
        }
        if(found==true)
        {
            cout<<"\t\t Index of the Contact = "<<count<<endl;
        }
        else
        {
            cout<<"Desired Contact not found "<<endl;
        }
}

void at_given() //deletion function
{
    int pos;
    node *next_node;
    temp = head;
    cout<<"Enter your desired position from where you want to Delete Contact:"<<endl;
    cin>>pos;
    if (head== NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else if (pos > len)
    {
        cout<<"Invalid Position"<<endl;
    }
    
    else if (pos == 0)
    {
        temp = head;
        head = head -> next;
        delete temp;
        cout<<"Contact has been Deleted"<<endl;
    }    
    else 
    {
        for (int i = 1; i<pos; i++)
        {
            temp = temp -> next;
        }
        next_node = temp -> next;
        temp -> next = next_node -> next;
        delete next_node; 
        cout<<"Contact has been Deleted"<<endl;
    }                
}                    
void clear_all() 
{
    if (head == NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        temp = head;
        while(head!=NULL)
        {
            head=head->next;
            delete temp;
        }
        cout<<"\n\t\t All Contacts has been Deleted"<<endl;
    }
}
void menu()
{
    cout<<"Enter 1 to add Contact "<<endl;
    cout<<"Enter 2 to Display all Contact "<<endl;
    cout<<"Enter 3 to Search Contact "<<endl;
    cout<<"Enter 4 to Delete a Contact from where you want "<<endl;
    cout<<"Enter 5 to Clear all Records"<<endl;   
}

int main()
{
    int op;
    while (true)
    {
        menu();
        cin>>op;
        switch(op)
        {
            case 1:
                c_node();
                break;
            case 2:
                len = 0;
                display();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                at_given();
                break;
            case 5:
                clear_all();
                break;
            default:
                cout<<"Invalid Option "<<endl;
        }
    }
return 0;
}
