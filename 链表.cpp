#include <iostream>   
using namespace std;  
typedef int ElemType;

// 链表节点结构体
struct Node
{
    ElemType data;
    Node* next;
};
//初始化
Node* initList()
{
    Node* head = new Node;
    head->next = nullptr;
    return head;
}
//尾插法
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
//获取尾节点
Node* get_tali(Node *L)
{
    Node* p = L;
    while (p->next != nullptr)
    {
        p = p->next;/* code */
    }
    return p;
}
//删除指定位置
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
        cout <<"删除失败，位置错误" << endl;
        return false;
    }
    Node* q = p->next;
    p->next = q->next;
    delete q;
    return true;
}
//释放链表
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
    cout << "请输入节点个数: ";
    cin >> n;
    cout << "请输入" << n <<" 个数据：" <<endl;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tali = insertTali(tali, x);
    }
    cout << "当前链表为：";
    listNode(list);

    int pos;
    cout <<"请输入要删除的位置：";
    cin >> pos;
    deleteNode(list, pos);
    cout <<"删除后链表为：";
    listNode(list);
    freeList(list);
    return 0;
}