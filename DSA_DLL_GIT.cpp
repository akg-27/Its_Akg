#include <iostream>
using namespace std;

// Details of Node using Structure
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *start = NULL; // Start pointer points at start of DLL
Node *tail = NULL;  // Tail pointer points end of DLL

// Function to create New Node
Node *createNode()
{
    Node *temp = new Node;
    cout << "\nEnter any value for New Node :";
    cin >> temp->data;
    temp->next = NULL;
    temp->prev = NULL;

    return (temp);
}

// Function to add New Node at Last
void add_last()
{
    Node *t = createNode();

    if (start == NULL)
    {
        cout << "\nAdded";
        start = t;
        tail = t;
    }
    else
    {
        cout << "\nAdded";
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
}

// Function to add New Node at First
void add_first()
{
    Node *t = createNode();

    if (start == NULL)
    {
        cout << "\nAdded";
        start = t;
        tail = t;
    }
    else
    {
        cout << "\nAdded";
        start->prev = t;
        t->next = start;
        start = t;
    }
}

// Display Doubley Linked List in Forward Direction
void display_frwd()
{
    Node *t = start;
    if (start == NULL)
        cout << "\nLinked List is Empty  :(";
    cout << endl;
    while (t != NULL)
    {
        cout << t->data << " --> ";
        t = t->next;
    }
    cout << endl;
}

// Display  Doubley Linked List in Backward Direction
void dispaly_bckwrd()
{
    Node *t = tail;
    if (tail == NULL)
        cout << "\nLinked List is Empty  :(";
    cout << endl;
    while (t != NULL)
    {
        cout << t->data << " --> ";
        t = t->prev;
    }
    cout << endl;
}

// Search Node in Doubley Linked list
void search_ele()
{
    cout << "Enter the element to be searched :";
    int n;
    cin >> n;
    int flag = 0, c = 0;
    Node *temp = start;
    while (temp != NULL)
    {
        c++;
        if (temp->data == n)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
        cout << "\n"
             << n << " is present at " << c;
    else
        cout << "\n"
             << n << " is not present";
}

// Insert Node in between  Doubley Linked list
void insert_btwn()
{
    Node *t = createNode();

    if (start == NULL)
    {
        cout << "\nLinked List has been Created  :)";
        start = t;
        tail = t;
    }
    else if (t->data < start->data)
    {
        cout << "\nNew Node has been inserted Successfully  :)";
        t->next = start;
        start->prev = t;
        start = t;
    }
    else if (t->data >= tail->data)
    {
        cout << "\nNew Node has bee inserted Successfully  :)";
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
    else
    {
        Node *temp = start;

        while (temp->next != NULL)
        {
            if (temp->next->data < t->data)
                temp = temp->next;
            else
                break;
        }

        cout << "\nNew Node has bee inserted Successfully  :)";
        t->next = temp->next;
        t->prev = temp;
        temp->next = t;
        t->next->prev = t;
    }
}

// Delete Node  between Doubley Linked list
void delete_btwn(int n)
{
    if (start == NULL)
        cout << "\nSorry..Linked List is Empty..!!";
    else if (start->data == n)
    {
        Node *temp = start;
        start = start->next;
        start->prev = NULL;
        delete (temp);
    }
    else if (tail->data == n)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete (temp);
    }
    else
    {
        Node *temp = start;
        int flag = 0;
        while (temp->next != NULL)
        {
            if (temp->data == n)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 0)
            cout << n << " is not present in our list";
        else
        {
            cout << "\n"
                 << n << " has been deleted";
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete (temp);
        }
    }
}

// Funtion To Reverse Doubley Linked List
void rev_list()
{
    Node *cur = start;
    Node *Temp = NULL;

    if (start == NULL)
        cout << "\nLinked List is Empty  :(";
    else
    {
        cout << "\nLinked List has been Reversed";
        while (cur != NULL)
        {
            Temp = cur->prev;
            cur->prev = cur->next;
            cur->next = Temp;
            cur = cur->prev;
        }
        Temp = start;
        start = tail;
        tail = Temp;
    }
}

// MENU of Operations in Doubley Linked List
void menu()
{
    cout << "\n\t\tALL DOUBLE LINKED LIST OPERATIONS\t\t\n";
    cout << "\n1. Create New Node at Last";
    cout << "\n2. Create New Node at First";
    cout << "\n3. Display Linked List in Forward order";
    cout << "\n4. Display Linked List in Backward order";
    cout << "\n5. Search Node in Linked List";
    cout << "\n6. Insert New Node in between Linked List";
    cout << "\n7. Delete Node in between Linked List";
    cout << "\n8. Reverse Linked List";
    cout << "\n9. Exit";
}
// MAIN STARTS
int main()
{
    int ch, n;

    while (1)
    {
        menu();
        cout << "\nEnter your Choice :";
        cin >> ch;

        if (ch == 9)
            exit(0);

        Node *p = start;

        switch (ch)
        {
        case 1:
            add_last();
            break;
        case 2:
            add_first();
            break;
        case 3:
            display_frwd();
            break;
        case 4:
            dispaly_bckwrd();
            break;
        case 5:
            search_ele();
            break;
        case 6:
            insert_btwn();
            break;
        case 7:
            cout << "Enter Node to be Deleted :";
            int n;
            cin >> n;
            delete_btwn(n);
            break;
        case 8:
            rev_list();
            break;
        default:
            cout << "Invalid Choice..!!";
        }
    }
    return 0;
}
// MAIN ENDS