#include <iostream>   
using namespace std;  

typedef int ElemType;
struct QueueNode
{
    ElemType data;
    QueueNode *next;/* data */
};
struct Queue
{
    QueueNode *front;
    QueueNode *rear;/* data */
};

//初始化
Queue *initQueue()
{
    Queue *q = new Queue;
    QueueNode *node = new QueueNode;
    node->data = 0;
    node->next = nullptr;
    q->front = node;
    q->rear = node;
    return q;
}
//判断是否为空
bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}
//入队
void enqueue(Queue *q,ElemType e)
{
    QueueNode *node = new QueueNode;
    node->data = e;
    node->next = nullptr;
    q->rear->next = node;
    q->rear = node;
}

//出队
bool dequeue(Queue *q, ElemType &e)
{
    if(isEmpty(q))
    {
        cout << "空的" << endl;
        return false;
    }
    QueueNode *node = q->front->next;
    e = node->data;
    q->front->next =node->next;
    delete node;
    return true;
}
//获取队头
ElemType getFront(Queue* q)
{
    if (isEmpty(q))
    {
        cout << "空的" << endl;
        return 0;
    }
    return q->front->next->data;
}

int main()
{
    Queue* q = initQueue();
    int n, x;

    cout << "请输入要入队的数字个数：";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "请输入第" << i + 1 << "个数字：";
        cin >> x;
        enqueue(q, x);
    }

    // 出队两个演示
    int e;
    cout << endl << "开始出队：" << endl;

    dequeue(q, e);
    cout << "出队：" << e << endl;

    dequeue(q, e);
    cout << "出队：" << e << endl;

    cout << "当前队头元素：" << getFront(q) << endl;

    return 0;
}