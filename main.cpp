// CRUD  Linked list
#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
}LinkedList;

Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode; 
}
void CreateList(LinkedList list)
{
    list.head = nullptr;
    list.tail = nullptr;
}

bool isEmpty(LinkedList &list)
{
    if(list.head == nullptr || list.tail == nullptr)
    {
        return true;
    }
    return false;
}
Node* Search(LinkedList &list, const int x)
{
    if(isEmpty(list))
    {
        return nullptr;
    }
    Node *node = list.head;
    while (node != nullptr && node->data != x)
    {
        node = node->next;
    }
    if (node != nullptr)
    {
        return node;
    }
    return nullptr;  
}

void AddHead(LinkedList &list, Node *node)
{
    if(node == nullptr)
    {
        return;
    }
    if(isEmpty(list))
    {
        list.head = node;
        list.tail = node;
        return;
    }
    Node* existNode = Search(list, node->data);
    if(existNode == nullptr)
    {
        node->next = list.head;        
        list.head = node;
    }
}

void AddTail(LinkedList &list, Node *node)
{
    if(node == nullptr)
    {
        return;
    }
    if(isEmpty(list))
    {
        list.head = node;
        list.tail = node;
        return;
    }
    Node* existNode = Search(list, node->data);
    if(existNode == nullptr)
    {
        list.tail->next = node;
        list.tail = node;
    }
}
int GetListLength(LinkedList &list)
{
    int count = 0;
    if(isEmpty(list))
    {
        return 0;
    }
    Node *node = list.head;
    while (node != nullptr )
    {
        count++;
        node = node->next;
    }
    return count;  
}

Node* GetNodeAtIndex(LinkedList &list, const int index)
{
    if(isEmpty(list))
    {
        return nullptr;
    }
    Node *node = list.head;
    int count = 0;
    while (node != nullptr && count != index)
    {
        node = node->next;
        count++;
    }
    if (node != nullptr && count == index)
    {
        return node;
    }
    return nullptr;  
}
int GetIndexNode( LinkedList &list, const Node *node)
{
    if(node == nullptr)
    {
        return -1;
    }
    int index = 0;
    Node* findNode = list.head;
    while (findNode != nullptr && findNode->data != node->data)
    {
        index++;
        findNode = findNode->next;
    }
    if(findNode == nullptr)
    {
        index = -1;
    }
    return index;
}

int RemoveHead(LinkedList &list)
{
    if(isEmpty(list))
    {
        return 1;
    }
    Node* nodeHead = list.head;
    list.head = nodeHead->next;
    if(list.head == nullptr)
    {
        list.tail = nullptr;
    }
    delete nodeHead;
    return 0;
}
int RemoveTail(LinkedList &list)
{
    if(isEmpty(list))
    {
        return 1;
    }
    int length = GetListLength(list);
    if(length == 1 )
    {
        RemoveHead(list);
    }
    if( length > 1)
    {
        Node* nodeBeforeTail = GetNodeAtIndex(list, length - 2);
        delete list.tail;
        nodeBeforeTail->next = nullptr;
        list.tail = nodeBeforeTail;
    }
    return 0;
}
int RemoveNode(LinkedList &list, const int x)
{
    if(isEmpty(list))
    {
        return 1;
    }
    Node *node = list.head;
   
    while (node != nullptr && node->next->data != x)
    {
        node = node->next;
    }
    Node *deleteNode = node->next;

    if (deleteNode == nullptr)
    {
        return 1;
    }
    
    if( deleteNode == list.head)
    {
        RemoveHead(list);
        return 0;
    }
    
    node->next = deleteNode->next;
    delete deleteNode;
    return 0;
}
int InsertNodeAfter(LinkedList &list, Node* newNode, Node* pivot)
{
    if(isEmpty(list) || newNode == nullptr || pivot == nullptr)
    {
        return 1;
    }

    int index = GetIndexNode(list, pivot);
    if( index == -1)
    {
        return 1;
    }
    Node* existNode = Search(list, newNode->data);
    if(existNode == nullptr)
    {
        newNode->next = pivot->next;
        pivot->next = newNode;
    }
    return 0;
}
void PrintList(LinkedList &list)
{
    Node* node = list.head;
    while (node != nullptr)
    {
        cout << node->data << endl;
        node = node->next;
    }
}
template <typename T>
void Swap(T &nodeA, T &nodeB)
{
    T temp = nodeA;
    nodeA = nodeB;
    nodeB = temp;
    return;
}
void SelectedSort( LinkedList &list, bool isAsc = true)
{
    Node* temp1 = list.head;
    int minValue = -1;
    while (temp1 != nullptr)
    {
        minValue = temp1->data;
        Node* temp2 = temp1->next;
        Node* selectedNode = nullptr;
        while (temp2 != nullptr)
        {
            if(isAsc)
            {
                if(minValue > temp2->data)
                {
                    minValue = temp2->data;
                    selectedNode = temp2;
                }
            }
            else
            {
                if(minValue < temp2->data)
                {
                    minValue = temp2->data;
                    selectedNode = temp2;
                }
            }
            
            temp2 = temp2->next;
        }
        if(selectedNode != nullptr)
        {
            Swap(selectedNode->data, temp1->data);
        }
        temp1 = temp1->next;
    }
}
void BubbleSort( LinkedList &list, bool isAsc = true)
{
    Node* temp1 = list.head;
    while (temp1 != nullptr)
    {
        Node* temp2 = temp1->next;
        while (temp2 != nullptr)
        {
            if(isAsc)
            {
                if(temp1->data > temp2->data)
                {
                    Swap(temp1->data, temp2->data);
                }
            }
            else
            {
                if(temp1->data < temp2->data)
                {
                    Swap(temp1->data, temp2->data);
                }
            }
            
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
} 

int main()
{
    LinkedList list;
    CreateList(list);
    Node *Node1 = CreateNode(4);
    AddHead(list, Node1);
    AddHead(list, CreateNode(5));
    AddHead(list, CreateNode(8));
    AddHead(list, CreateNode(2));
    AddHead(list, CreateNode(15));
    AddHead(list, CreateNode(3));
    AddHead(list, CreateNode(25));
    AddHead(list, CreateNode(3));
    // BubbleSort(list);
    SelectedSort(list);
    PrintList(list);
}