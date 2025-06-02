#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> parrents(n);
    vector<vector<ll>> tree(n);
    vector<bool> included(n, false);
    ll root;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        a--;
        if (i != a)
            tree[a].push_back(i);
        else
            root = i;
        parrents[i] = a;
    }
    vector<ll> leafNodes;
    for (i = 0; i < n; i++)
    {
        if (tree[i].size() == 0)
            leafNodes.push_back(i);
    }
    vector<vector<ll>> ans;
    for (i = 0; i < leafNodes.size(); i++)
    {
        ll currNode = leafNodes[i];
        vector<ll> dum;
        while (!included[currNode])
        {
            included[currNode] = true;
            dum.push_back(currNode);
            if (currNode == parrents[currNode])
            {
                break;
            }
            currNode = parrents[currNode];
        }
        reverse(dum.begin(), dum.end());
        ans.push_back(dum);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x.size() << endl;
        for (auto y : x)
            cout << y + 1 << gap;
        cout << endl;
    }
    cout << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}