#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> allNum;
    vector<vector<ll>> towers;
    for (i = 0; i < n; i++)
    {
        cin >> m;
        vector<ll> v;
        for (j = 0; j < m; j++)
        {
            cin >> a;
            v.push_back(a);
            allNum.push_back(a);
        }
        towers.push_back(v);
    }
    sort(allNum.begin(), allNum.end());
    allNum.push_back(allNum.back() + 1);
    ll split = 0;
    unordered_map<ll, ll> after;
    for (i = 0; i < allNum.size() - 1; i++)
    {
        after.insert({allNum[i], allNum[i + 1]});
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < towers[i].size() - 1; j++)
        {
            if (towers[i][j + 1] != after[towers[i][j]])
            {
                split++;
            }
        }
    }
    cout << split << gap << n + split - 1 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}