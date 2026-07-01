//给定一个父字符串 s 和子字符串 p，请按照从前向后的顺序，请求出 p 在 s 中所有出现的起始位置。

#include <bits/stdc++.h>   
using namespace std;  

const int N=1e6+5;
int ne[N];

void getNext(string t)
{
    int len=t.length();
    int i=0,j=-1;
    ne[0]=-1;
    while(i<len)
    {
        if(j==-1||t[i]==t[j])
        {
            i++,j++;
            ne[i]=j;
        }
        else j=ne[j];
    }
}
void KMP(string s,string t)
{
    int lens=s.length(),lent=t.length();
    int i=0,j=0;
    while(i<lens&&j<lent)
    {
        if(j==-1||s[i]==t[j])
        {
            i++,j++;
        }else j=ne[j];
        if(j==lent)
        {
            cout<<i-j+1<<" ";
            j=ne[j];
        }
    }
}
int main()
{
    string s,t;
    getline(cin,s);
    getline(cin,t);
    getNext(t);
    KMP(s,t);
    return 0;
}