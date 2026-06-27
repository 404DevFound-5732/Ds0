#include <bits/stdc++.h>
using namespace std;
int flag[101],e[101][101];
int n,m;
int ton;
void dfs(int cur)
{
    cout<<cur<<" ";
    ton++;
    if(ton==n) return;
    for(int i=1;i<=n;i++)
    {
        if(e[cur][i]==1&&flag[i]==0)
        {
            flag[i]=1;
            dfs(i);
        }
    }
    return;
}
int main()
{
    int a,b;
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) e[i][j]=0;
            else e[i][j] = 0x3f3f3f;
        }
    }
    for (int i=1;i<=m;i++)
    {
        cin>>a>>b;
        e[a][b]=1;
        e[b][a]=1;
    }
    flag[1]=1;
    dfs(1);
    return 0;
}


