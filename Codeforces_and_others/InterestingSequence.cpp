#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

vector<ll> bin_rep(ll n)
{
    vector<ll> ans;
    while (n)
    {
        if (n & 1)
            ans.push_back(1);
        else
            ans.push_back(0);
        n /= 2;
    }
    if (ans.size() == 0)
        ans.push_back(0);
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    vector<ll> bin_n = bin_rep(n), bin_k = bin_rep(k);
    if (bin_k.size() == bin_n.size() || k == 0)
    {
        vector<ll> ans;
        bin_k.push_back(0);
        bin_n.push_back(0);
        reverse(bin_k.begin(), bin_k.end());
        reverse(bin_n.begin(), bin_n.end());
        ll lim = bin_n.size();
        for (i = 0; i < lim; i++)
        {
            if (bin_k[i] == bin_n[i])
            {
                ans.push_back(bin_k[i]);
            }
            else
            {
                if (bin_k[i] == 1 && bin_n[i] == 0)
                {
                    cout << -1 << endl;
                    return;
                }
                else if (bin_k[i] == 0 && bin_n[i] == 1)
                {
                    ans[i - 1] = 1;
                    ans.push_back(0);
                    break;
                }
            }
        }
        while (ans.size() != lim)
        {
            ans.push_back(0);
        }
        reverse(ans.begin(), ans.end());
        m = 0;
        for (i = 0; i < lim; i++)
        {
            if (ans[i] == 1)
            {
                m += powl(2, i);
            }
        }
        if ((n & m) == k && n <= m)
            cout << m << endl;
        else
            cout << -1 << endl;
    }
    else
        cout << -1 << endl;
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