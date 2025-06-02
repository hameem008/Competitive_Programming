#include <bits/stdc++.h>
using namespace std;

vector<vector<long double>> shortest_distance;
vector<vector<long double>> graph;
void floydwarshall(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                shortest_distance[u][v] = max(shortest_distance[u][v], shortest_distance[u][i] * shortest_distance[i][v]);
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n;
    map<string, int> mp;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        mp[str] = i;
    }
    graph.assign(n + 1, vector<long double>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        graph[i][i] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        string str1, str2;
        long double ld;
        cin >> str1 >> ld >> str2;
        graph[mp[str1]][mp[str2]] = ld;
        // graph[mp[str2]][mp[str1]] = 1 / ld;
    }
    shortest_distance = graph;
    floydwarshall(n);
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (shortest_distance[i][i] > 1)
            flag = true;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
}