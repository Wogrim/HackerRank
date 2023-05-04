// compare heads of 2 linked lists, remove smaller

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

//////////////////////////////////////////
// MY CODE START

SinglyLinkedListNode *mergeLists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    // constraint: both lists have at least 1 node
    SinglyLinkedListNode *newHead, *newTail;
    // first node
    if (head1->data < head2->data)
    {
        newHead = newTail = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = newTail = head2;
        head2 = head2->next;
    }
    // new list has inaccurate tail->next but a waste of time to set to nullptr
    // while both lists are not empty, merge them
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data < head2->data)
        {
            newTail->next = head1;
            head1 = head1->next;
        }
        else
        {
            newTail->next = head2;
            head2 = head2->next;
        }
        newTail = newTail->next;
    }
    // one of the lists is now empty, just point the tail of the new list to the other
    if (head1 == nullptr)
        newTail->next = head2;
    else
        newTail->next = head1;
    return newHead;
}

// MY CODE END
//////////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++)
    {
        SinglyLinkedList *llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++)
        {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList *llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++)
        {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode *llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
