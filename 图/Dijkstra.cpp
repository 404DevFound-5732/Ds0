#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
const int N=505;
int dis[N],g[N][N];
bool st[N];
int n,m;

int dijkstra()
{
    memset(dis,inf,sizeof dis);
    dis[1]=0;
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j] && (t==-1 || dis[t]>dis[j])) t=j;
        }
        st[t]=true;

        for(int j=1; j<=n;j++)
        {
            dis[j]=min(dis[j],dis[t]+g[t][j]);
        }
    }
    if (dis[n]==inf) return -1;
    return dis[n];
}

int main()
{
    cin>>n>>m;
    memset(g,inf,sizeof g);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    cout<<dijkstra()<<endl;
    return 0;
}