#include <bits/stdc++.h>
using namespace std;

const int maxn=1e3+5;
int mp[maxn][maxn];
vector<int> v[maxn];

int n,m;
int s,t;
int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>s>>t;
        mp[s][t]=1,mp[t][s]=1;
        v[t].push_back(s),v[s].push_back(t);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<v[i].size()<<" ";
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
