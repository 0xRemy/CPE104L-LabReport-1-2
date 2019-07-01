#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

const (maxnum) = 100;

struct Node
{
    int info;
    char name[maxnum];
    char address[maxnum];
    char phone[maxnum];
    Node *next;
};

    typedef Node address;

//prototypes
    void addList ();
    void deleteList ();
    void print ();
    void listName ();
    void Cancel();


Node *Head = NULL;


void addList()
{
            //loxal Variable
            address *Name = new address;
            std::cout << " Enter the name of the person ";
            std::cin >> Name -> name;
            std::cout << " Enter the persons address ";
            std::cin >> Name -> address;
            std::cout << " Enter the persons telephone number ";
            std::cin >> Name -> phone;

            Name -> next= Head;
            Head = Name;

}

void deleteList() //remove a name
    {

            address *nxt;
            address *prv;
            char delName[maxnum];

                std::cout << "\nEnter the name you want to delete: ";
                std::cin >> delName[maxnum];

                    if (Head == NULL)
                        {
                            std::cout << "No list to delete from\n";
                            return;
                        }

                    if (strcmp(Head->name, delName) == 0)
                        {
                            nxt= Head;
                            Head= Head->next;
                            delete nxt;
                            return;
                        }

                prv = Head;

                    while (prv -> next != NULL) // look for the name
                            {
                                if (strcmp(prv -> next -> name,delName) == 0) //if name is found
                                    {
                                        nxt= prv -> next;
                                        prv -> next = nxt -> next;
                                        delete nxt;
                                        return;
                                    }

                                        prv= prv -> next;
                            }
                    std::cout << " Name not found\n ";
}

void print()
        {
            char name[maxnum];
            address *SearchName;
                std::cout << "Please enter the name you want to look up: ";
                std::cin >> name[maxnum];
                SearchName = Head;

            while (SearchName != NULL)
            {
                    if (strcmp(SearchName->name, name) == 0)
                    {
                        std::cout << "Address: "<< SearchName->address << std::endl;
                        std::cout << "Telephone No.  " << SearchName->phone << std::endl;
                        return;
                    }

                SearchName = SearchName->next;
            }
            std::cout << "No record\n";
        }

void listName()
    {
        address *ListofName;
        std::cout << "All the names in the address book: " << std::endl;
        ListofName = Head;
            while (ListofName != NULL)
                {
                    std::cout << ListofName->name << std::endl;
                    ListofName = ListofName->next;
                }
    }

void Cancel() // frees list memory
{
    address *quit;

    while(Head != NULL)
        {
            quit = Head; // Store the head
            Head= Head->next; // Move on
            delete quit;
        }
}

int main()
{
    char input;

    while (1)
    {

        std::cout << "\n(A)dd a person\n(D)elete a person\n(P)rint an entry\n(L)ist all names\n(Q)uit\n";
        std::cin >> input;

            switch(toupper(input))
                {
                    case 'A' || 'a':
                    addList();
                    break;

                    case 'D' || 'd':
                    deleteList();
                    break;

                    case 'P' || 'p':
                    print();#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

const (maxnum) = 100;

struct Node
{
    int info;
    char name[maxnum];
    char address[maxnum];
    char phone[maxnum];
    Node *next;
};

    typedef Node address;

//prototypes
    void addList ();
    void deleteList ();
    void print ();
    void listName ();
    void Cancel();


Node *Head = NULL;


void addList()
{
            //loxal Variable
            address *Name = new address;
            std::cout << " Enter the name of the person ";
            std::cin >> Name -> name;
            std::cout << " Enter the persons address ";
            std::cin >> Name -> address;
            std::cout << " Enter the persons telephone number ";
            std::cin >> Name -> phone;

            Name -> next= Head;
            Head = Name;

}

void deleteList() //remove a name
    {

            address *nxt;
            address *prv;
            char delName[maxnum];

                std::cout << "\nEnter the name you want to delete: ";
                std::cin >> delName[maxnum];

                    if (Head == NULL)
                        {
                            std::cout << "No list to delete from\n";
                            return;
                        }

                    if (strcmp(Head->name, delName) == 0)
                        {
                            nxt= Head;
                            Head= Head->next;
                            delete nxt;
                            return;
                        }

                prv = Head;

                    while (prv -> next != NULL) // look for the name
                            {
                                if (strcmp(prv -> next -> name,delName) == 0) //if name is found
                                    {
                                        nxt= prv -> next;
                                        prv -> next = nxt -> next;
                                        delete nxt;
                                        return;
                                    }

                                        prv= prv -> next;
                            }
                    std::cout << " Name not found\n ";
}

void print()
        {
            char name[maxnum];
            address *SearchName;
                std::cout << "Please enter the name you want to look up: ";
                std::cin >> name[maxnum];
                SearchName = Head;

            while (SearchName != NULL)
            {
                    if (strcmp(SearchName->name, name) == 0)
                    {
                        std::cout << "Address: "<< SearchName->address << std::endl;
                        std::cout << "Telephone No.  " << SearchName->phone << std::endl;
                        return;
                    }

                SearchName = SearchName->next;
            }
            std::cout << "No record\n";
        }

void listName()
    {
        address *ListofName;
        std::cout << "All the names in the address book: " << std::endl;
        ListofName = Head;
            while (ListofName != NULL)
                {
                    std::cout << ListofName->name << std::endl;
                    ListofName = ListofName->next;
                }
    }

void Cancel() // frees list memory
{
    address *quit;

    while(Head != NULL)
        {
            quit = Head; // Store the head
            Head= Head->next; // Move on
            delete quit;
        }
}

int main()
{
    char input;

    while (1)
    {

        std::cout << "\n(A)dd a person\n(D)elete a person\n(P)rint an entry\n(L)ist all names\n(Q)uit\n";
        std::cin >> input;

            switch(toupper(input))
                {
                    case 'A':
                    addList();
                    break;

                    case 'D' :
                    deleteList();
                    break;

                    case 'P' :
                    print();
                    break;

                    case 'L' :
                    listName();
                    break;

                    case 'Q':
                    Cancel();
                    return (0);

                    default:
                    std::cout <<"Error Message";
                }
        }
}
av
                    break;

                    case 'L' || 'l':
                    listName();
                    break;

                    case 'Q' || 'q':
                    Cancel();
                    return (0);

                    default:
                    std::cout <<"Error Message";
                }
        }
}
