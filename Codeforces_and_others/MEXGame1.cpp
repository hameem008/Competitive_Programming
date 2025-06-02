#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    set<ll> unique, not_unique;
    multiset<ll> ms(v.begin(), v.end());
    for (i = 0; i < n; i++)
    {
        if (ms.count(i) > 1)
        {
            not_unique.insert(i);
        }
        else if (ms.count(i) == 1)
        {
            unique.insert(i);
        }
    }
    set<ll> ans(not_unique.begin(), not_unique.end());
    if (unique.size())
    {
        ans.insert(*unique.begin());
    }
    ll diya = n;
    for (i = 0; i < n; i++)
    {
        if (ans.find(i) == ans.end())
        {
            diya = i;
            break;
        }
    }
    cout << diya << endl;
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