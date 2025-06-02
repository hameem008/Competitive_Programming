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
    ll max_ele = n;
    if (v.front() == n)
        max_ele = n - 1;
    vector<ll> ans;
    for (i = 0; i < n; i++)
    {
        if (v[i] == max_ele)
            break;
    }
    ll max_ele_ind = i;
    if (max_ele_ind != n - 1)
    {
        for (i = max_ele_ind; i < n; i++)
        {
            ans.push_back(v[i]);
        }
        ans.push_back(v[max_ele_ind - 1]);
        if (max_ele_ind - 2 >= 0)
        {
            for (i = max_ele_ind - 2; i >= 0; i--)
            {
                if (v[i] > v[0])
                    ans.push_back(v[i]);
                else
                    break;
            }
            for (j = 0; j <= i; j++)
            {
                ans.push_back(v[j]);
            }
        }
    }
    else
    {
        ans.push_back(v[max_ele_ind]);
        for (i = max_ele_ind - 1; i >= 0; i--)
        {
            if (v[i] > v[0])
                ans.push_back(v[i]);
            else
                break;
        }
        for (j = 0; j <= i; j++)
        {
            ans.push_back(v[j]);
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