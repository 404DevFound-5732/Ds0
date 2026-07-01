#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
#define MAXSIZE 100
typedef struct 
{
    ElemType *elem;
    int length;
}Sqlist;

void InitList_Sq(Sqlist &L)
{
    L.elem=new ElemType[MAXSIZE];
    L.length=0;
}
int GetElem(Sqlist L,int i,ElemType &e)
{
    if(i<1||i>L.length) return 0;
    e=L.elem[i-1];
    return 1;
}
int LocateElem(Sqlist L,ElemType e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e) return i+1;
    }
    return 0;
}
int ListInsert(Sqlist &L,int i,ElemType e)
{
    if(i<1||i>L.length+1 || L.length >= MAXSIZE) return 0;
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    ++L.length;
    return 1;
}
int ListDelete(Sqlist &L,int i,ElemType &e)
{
    if(i<1||i>L.length) return 0;
    e=L.elem[i-1];
    for (int j=i;j<L.length;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    --L.length;
    return 1;
}
void PrintList(Sqlist L)
{
    for(int i =0;i<L.length;i++)
    {
        cout << L.elem[i] << " ";
    }
    cout<<endl;
}
int main()
{
    Sqlist L;
    InitList_Sq(L);
    cout <<"初始化成功"<< endl;
    ListInsert(L,1,10);
    ListInsert(L,2,30);
    ListInsert(L,3,30);
    cout << "插入元素后: ";
    PrintList(L);
    
    int val;
    GetElem(L, 2, val);
    cout << "第2个元素：" << val << endl;

    int pos = LocateElem(L, 30);
    cout << "元素30的位序：" << pos << endl;

    int delVal;
    ListDelete(L, 2, delVal);
    cout << "删除的元素：" << delVal << endl;
    cout << "删除后顺序表：";
    PrintList(L);

    delete[] L.elem;
    return 0;
}