#include"head.h"
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
// 输入一个数组，转换为一条单链表
ListNode* createLinkedList(vector<int>& arr)
{
    if (arr.empty())
    {
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++)
    {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}
class LinkedList
{
private:
    ListNode* head;
public:
    LinkedList(): head(NULL) {}
    ~LinkedList()
    {
        ListNode* current = head;
        while (current != NULL)
        {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }
    void append(int val)
    {
        ListNode* NewNode = new ListNode(val);
        if (head == NULL)
        {
            head = NewNode;
        }
        else
        {
            ListNode* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = NewNode;
        }
    }

    void prepend(int val)
    {
        ListNode* NewNode = new ListNode(val);
        NewNode->next = head;
        head = NewNode;
    }

    void deleteNode(int val)
    {
        ListNode* current = head, * prev = NULL;
        while (current->val != val)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
    }

    void findNode(int val)
    {
        ListNode* current = head;
        while (current->val != val && current->next != NULL)
        {
            current = current->next;
        }
        if (current->val == val)
        {
            cout << val << " is fund" << endl;
        }
        else
        {
            cout << val << " isn't fund" << endl;
        }
    }
    void printList()
    {
        ListNode* current = head;
        while (current != NULL)
        {
            cout << current->val << "->";
            current = current->next;
        }
        cout << "None"<<'\n';
    }
};

struct DoublyListNode
{
    int val;
    DoublyListNode* next, * prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};
class DoublyLinkedList
{
private:
    DoublyListNode* head;
public:
    DoublyLinkedList() : head(NULL) {}
    ~DoublyLinkedList()
    {
        DoublyListNode* current = head;
        while (current != NULL)
        {
            DoublyListNode* next = current->next;
            delete current;
            current = next;
            head = NULL;
        }
    }

    void prepend(int val)
    {
        DoublyListNode* NewNode = new DoublyListNode(val);
        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
    }

    void append(int val)
    {
        DoublyListNode* NewNode = new DoublyListNode(val);
        if (head == NULL)
        {
            head = NewNode;
        }
        else
        {
            DoublyListNode* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = NewNode;
            NewNode->prev = current;
        }
    }

    void DeleteNode(int val)
    {
        DoublyListNode* current = head, * prev = NULL;
        while (current->val != val)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        current->next->prev = prev;
        delete current;
    }

    void reverse()
    {
        DoublyListNode* prev = NULL;
        DoublyListNode* curr = head;
        while (curr != NULL)
        {
            DoublyListNode* next = curr->next;
            curr->next = prev;
            if (prev != NULL)
            {
                prev->prev = curr;
            }
            curr->prev = next;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void PrintList()
    {
        DoublyListNode* curr = head;
        while (curr != NULL)
        {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << "None" << endl;
    }
};
int main()
{
    DoublyLinkedList list;
    for (int i = 1; i <= 10; i++)
    {
        list.append(i);
    }
    list.reverse();
    list.reverse();
    list.PrintList();
    return 0;
}
