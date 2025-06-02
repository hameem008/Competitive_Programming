#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q, s, r;
    // solve starts
    cin >> n >> s >> r;
    multiset<ll> ans;
    ans.insert(s - r);
    for (i = 0; i < r; i++)
    {
        ans.insert(1);
    }
    while (ans.size() != n)
    {
        auto it1 = ans.begin();
        auto it2 = ++ans.begin();
        ans.insert(*it1 + *it2);
        ans.erase(it1);
        ans.erase(it2);
    }
    while (*(--ans.end()) > s - r)
    {
        a = *ans.begin() + *(--ans.end()) - s + r;
        ans.erase((--ans.end()));
        ans.erase((ans.begin()));
        ans.insert(a);
        ans.insert(s - r);
    }
    for (auto x : ans)
        cout << x << gap;
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