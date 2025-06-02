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
    bool flag = true;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> ans;
    for (i = n - 1; i >= 0; i--)
    {
        if (i == 0)
            ans.push_back(v[i]);
        else if (v[i] >= v[i - 1])
            ans.push_back(v[i]);
        else
        {
            ans.push_back(v[i]);
            i--;
            break;
        }
    }
    if (i >= 0)
    {
        for (; i >= 0; i--)
        {
            if (v[i] > 9)
            {
                ans.push_back(v[i] % 10);
                ans.push_back(v[i] / 10);
            }
            else
            {
                ans.push_back(v[i]);
            }
        }
    }
    for (i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] < ans[i + 1])
            flag = false;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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