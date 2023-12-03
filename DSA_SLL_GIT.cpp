#include <iostream>
using namespace std;

// Details of Node using Structure
struct Node
{
    int data;
    Node *next;
};
Node *start = NULL; // Start pointer points at start of DLL

// Function to create New Node
Node *createNode()
{
    Node *temp = new Node;
    cout << "\nEnter any value for new node :";
    cin >> temp->data;
    temp->next = NULL;

    return (temp);
}

// Function to add New Node at Last
void add_last()
{
    Node *t = createNode();
    if (start == NULL)
        start = t;
    else
    {
        Node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = t;
    }
}

// Function to add New Node at First
void add_first()
{
    Node *t = createNode();
    if (start == NULL)
        start = t;
    else
    {
        t->next = start;
        start = t;
    }
}

// Display Singley Linked List
void display()
{
    Node *t = start;
    cout << endl;
    while (t != NULL)
    {
        cout << t->data << " --> ";
        t = t->next;
    }
    cout << endl;
}

// Search Node in Singley Linked list
void search_ele()
{
    cout << "\nEnter the element to be searched :";
    int t;
    cin >> t;
    int flag = 0, c = 0;
    Node *temp;
    temp = start;
    while (temp != NULL)
    {
        c++;
        if (temp->data == t)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
        cout << "\n"
             << t << " is present at " << c;
    else
        cout << "\n"
             << t << " is not present ";
}

// Insert Node in between Singley Linked list
void insert_btwn()
{
    Node *t = createNode();
    if (start == NULL)
        start = t;
    else if (t->data < start->data)
    {
        t->next = start;
        start = t;
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
        t->next = temp->next;
        temp->next = t;
    }
}

// Delete Node  between Singley Linked list
void delete_btwn(int n)
{
    if (start == NULL)
        cout << "Linked List is empty";
    else
    {
        Node *temp = start;
        int flag = 0;
        while (temp->next != NULL)
        {
            if (temp->next->data == n)
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
            cout << n << " has been deleted";
            Node *temp1 = temp->next;
            temp->next = temp1->next;
            delete (temp1);
        }
    }
}

// To print Singley Linked List in Reverse order
void rev_odr(Node *p)
{
    if (p == NULL)
        return;
    else
    {
        rev_odr(p->next);
        cout << p->data << " --> ";
    }
}

// Funtion To Reverse Singley Linked List
void rev_list()
{
    Node *cur = start;
    Node *left = NULL;
    Node *right = NULL;

    while (cur != NULL)
    {
        right = cur->next;
        cur->next = left;
        left = cur;
        cur = right;
    }
    start = left;
}

// MENU of Operations in Singley Linked List
void menu()
{
    cout << "\n\t\tALL SINGLE LINKED LIST OPERATIONS\t\t\n";
    cout << "\n1. Create New Node at Last";
    cout << "\n2. Create New Node at First";
    cout << "\n3. Display Linked List";
    cout << "\n4. Search Node in Linked List";
    cout << "\n5. Insert New Node in between Linked List";
    cout << "\n6. Delete Node in between Linked List";
    cout << "\n7. Print Linked List in reverse order";
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
            display();
            break;
        case 4:
            search_ele();
            break;
        case 5:
            insert_btwn();
            break;
        case 6:
            cout << "Enter Node to be Deleted :";
            cin >> n;
            delete_btwn(n);
            break;
        case 7:
            rev_odr(p);
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