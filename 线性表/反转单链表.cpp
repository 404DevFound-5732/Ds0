//题目给出一串数字，首先，你需要把这些数字构造成一个单链表，然后将此单链表反转。

#include <iostream>   
using namespace std;  
//数组拟单链表
//单链表
struct Lnode
{
    int data;
    Lnode *next;
      /* data */
};

int main()
{
    Lnode *L=new Lnode;
    L->next = nullptr;

    int x;
    while(cin>>x)
    {
        Lnode *p = new Lnode;
        p->data=x;
        p->next=L->next;
        L->next=p;
    }
    while (L->next)
    {
        cout<<L->next->data<<" ";
        L->next=L->next->next;   /* code */
    }
    cout<<"None"<<endl;
    return 0;
    
}
