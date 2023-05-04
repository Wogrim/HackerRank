// each list shares the same x # of tail nodes

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

///////////////////////////////////
// MY CODE START

int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    //constraint: lists are not empty
    //constraint: lists do merge
    // find how long each list is
    int n1 = 0;
    SinglyLinkedListNode *p1 = head1;
    while (p1 != nullptr)
    {
        n1++;
        p1 = p1->next;
    }
    int n2 = 0;
    SinglyLinkedListNode *p2 = head2;
    while (p2 != nullptr)
    {
        n2++;
        p2 = p2->next;
    }
    //if we move 2 pointers at the same time such that they will reach the
    //end of the list at the same time, the pointer on the longer list
    //will need a head start
    if(n1>n2)
    {
        p1 = head1;
        for(int headstart = n1-n2;headstart>0;headstart--)
            p1 = p1->next;
        p2 = head2;
    }
    else
    {
        p1 = head1;
        p2 = head2;
        for (int headstart = n2-n1; headstart > 0; headstart--)
            p2 = p2->next;
    }
    //move both pointers until they're pointing to the same node
    while(p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    //now they're equal at the merge point
    return p1->data;
}

// MY CODE END
///////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++)
    {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

        SinglyLinkedListNode *ptr1 = llist1->head;
        SinglyLinkedListNode *ptr2 = llist2->head;

        for (int i = 0; i < llist1_count; i++)
        {
            if (i < index)
            {
                ptr1 = ptr1->next;
            }
        }

        for (int i = 0; i < llist2_count; i++)
        {
            if (i != llist2_count - 1)
            {
                ptr2 = ptr2->next;
            }
        }

        ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
