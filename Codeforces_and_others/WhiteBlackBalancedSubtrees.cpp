#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

ll cnt;

pair<ll, ll> countColor(ll vertex, vector<vector<ll>> &tree, pair<ll, ll> ans, string &str)
{
    for (auto x : tree[vertex])
    {
        pair<ll, ll> dum;
        if (str[x] == 'W')
            dum = {1, 0};
        else
            dum = {0, 1};
        pair<ll, ll> temp = countColor(x, tree, dum, str);
        ans.first += temp.first;
        ans.second += temp.second;
    }
    if (ans.first == ans.second)
        cnt++;
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<vector<ll>> tree(n);
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a;
        tree[a - 1].push_back(i);
    }
    string str;
    cin >> str;
    cnt = 0;
    pair<ll, ll> dum;
    if (str[0] == 'W')
        dum = {1, 0};
    else
        dum = {0, 1};
    countColor(0, tree, dum, str);
    cout << cnt << endl;
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