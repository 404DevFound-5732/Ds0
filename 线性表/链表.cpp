#include <iostream>   
using namespace std;  
typedef int ElemType;

// ??????????
struct Node
{
    ElemType data;
    Node* next;
};
//?????
Node* initList()
{
    Node* head = new Node;
    head->next = nullptr;
    return head;
}
//¦Â?¾Þ
Node* insertTali(Node* tali, ElemType e)
{
    Node* p = new Node;
    p->data = e;
    p->next = nullptr;
    tali->next = p;
    return p;
}

void listNode(Node* L)
{
    Node* p = L->next;
    while (p!=nullptr)
    {
        cout << p->data << " ";
        p = p->next;/* code */
    }
    cout << endl;
}
//???¦Â???
Node* get_tali(Node *L)
{
    Node* p = L;
    while (p->next != nullptr)
    {
        p = p->next;/* code */
    }
    return p;
}
//??????¦Ë??
bool deleteNode(Node* L, int pos)
{
    Node* p = L;
    int i = 0;
    while(i < pos-1 && p != nullptr)
    {
        p = p->next;
        i++;
    }
    if (p == nullptr || p->next == nullptr)
    {
        cout <<"???????¦Ë?????" << endl;
        return false;
    }
    Node* q = p->next;
    p->next = q->next;
    delete q;
    return true;
}
//???????
void freeList(Node* L)
{
    Node *p =L;
    while (p != nullptr)
    {
        Node *q = p;
        p = p->next;
        delete q;/* code */
    }
    
}
int main()
{
    Node* list = initList();
    Node* tali = get_tali(list);

    int n;
    cout << "???????????: ";
    cin >> n;
    cout << "??????" << n <<" ???????" <<endl;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tali = insertTali(tali, x);
    }
    cout << "??????????";
    listNode(list);

    int pos;
    cout <<"????????????¦Ë???";
    cin >> pos;
    deleteNode(list, pos);
    cout <<"????????????";
    listNode(list);
    freeList(list);
    return 0;
}