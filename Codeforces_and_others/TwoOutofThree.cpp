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
    vector<ll> freq(101, 0);
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        v[i - 1] = a;
        freq[a]++;
    }
    set<ll> s;
    for (i = 0; i < 101; i++)
    {
        if (freq[i] > 1)
        {
            s.insert(i);
        }
        if (s.size() == 2)
            break;
    }
    if (s.size() < 2)
    {
        cout << -1 << endl;
        return;
    }
    ll num_1 = *s.begin(), num_2 = *(++s.begin());
    vector<ll> ans(n, 1);
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == num_1)
        {
            if (j % 2 == 0)
            {
                ans[i] = 1;
            }
            else if (j % 2 != 0)
            {
                ans[i] = 2;
            }
            j++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] == num_2)
        {
            if (j % 2 == 0)
            {
                ans[i] = 1;
            }
            else if (j % 2 != 0)
            {
                ans[i] = 3;
            }
            j++;
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