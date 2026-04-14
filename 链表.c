#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}Node;

//初始化
Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
int insertHead(Node* L,ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p; 
}

//遍历
void listNode(Node *L)
{
    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
//获取末尾节点
Node *get_tali(Node* L)
{
    Node* p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
    
}

//尾插法
Node *insterTail(Node *tail, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;

}

//在指定位置插入
int insterNode(Node *L, int pos,ElemType e)
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//删除并释放
int deleNode(Node* L,int pos)
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)//p不存在
        {
            return 0;
        }
    }
    if (p->next == NULL)//p后面没有节点
    {
        printf("error");
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}
//释放链表
void freeList(Node* L)
{
    Node *p = L;
    Node *q;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next =NULL;
}


int main()
{
    Node *list = initList();
    Node *tali = get_tali(list);
    tali = insterTail(tali ,10);
    tali = insterTail(tali ,44);
    tali = insterTail(tali ,33);
    tali = insterTail(tali ,23);
    listNode(list);
    deleNode(list, 2);
    listNode(list);
}