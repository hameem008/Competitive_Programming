#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    set<ll> s;
    for (i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    s.erase(1);
    vector<ll> ans;
    ans.push_back(1);
    while (s.size())
    {
        ll num = *s.begin();
        ans.push_back(num);
        s.erase(s.begin());
        while (1)
        {
            num *= 2;
            if (num > n)
                break;
            if (s.find(num) != s.end())
            {
                ans.push_back(num);
                s.erase(num);
            }
        }
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