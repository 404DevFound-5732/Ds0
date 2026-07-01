//实现一个数据结构，维护一张表（最初只有一个元素 1）。
//需要支持下面的操作，其中 x 和 y 都是 1 到 10^6 范围内的正整数，
//且保证任何时间表中所有数字均不相同，操作数量不多于 10^5：
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int ne[maxn];

//插入
void insert()
{
    int x,y;
    cin>>x>>y;
    ne[y]=ne[x];
    ne[x]=y;
}
//查找
void find()
{
    int x;
    cin>>x;
    cout<<ne[x]<<endl;
}
//删除
void del()
{
    int x;
    cin>>x;
    ne[x]=ne[ne[x]];
}
//主函数
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int op;
        cin>>op;
        switch(op)
        {
            case 1:insert();break;
            case 2:find();break;
            case 3:del();break;
        }
    }
}