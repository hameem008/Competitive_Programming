#include<bits/stdc++.h>
using namespace std;
 
char graph[1001][1001];
bool isVisited[1001][1001];
 
void dfs(int i, int j, int n, int m)
{
    if(i>n||i<1||j>m||j<1||isVisited[i][j])
        return;
    isVisited[i][j]=true;
    dfs(i+1,j,n,m);
    dfs(i,j+1,n,m);
    dfs(i-1,j,n,m);
    dfs(i,j-1,n,m);
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>graph[i][j];
            if(graph[i][j]=='#')
            {
                isVisited[i][j]=true;    
            }
            else 
            {    
                isVisited[i][j]=false;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {        
        for(int j=1;j<=m;j++)
        {
            if(!isVisited[i][j])
            {
                ans++;
                dfs(i,j,n,m);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}