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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> ind(n);
    vector<ll> odd, even;
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            ind[i] = 0;
            even.push_back(v[i]);
        }
        else
        {
            ind[i] = 1;
            odd.push_back(v[i]);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    reverse(odd.begin(), odd.end());
    reverse(even.begin(), even.end());
    vector<ll> ans;
    for (i = 0; i < n; i++)
    {
        if (ind[i] == 0)
        {
            ans.push_back(even.back());
            even.pop_back();
        }
        else if (ind[i] == 1)
        {
            ans.push_back(odd.back());
            odd.pop_back();
        }
    }
    flag = true;
    for (i = 0; i < n - 1; i++)
    {
        if (ans[i] > ans[i + 1])
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