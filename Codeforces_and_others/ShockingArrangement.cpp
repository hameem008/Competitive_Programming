#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    if (v.front() != v.back())
    {
        cout << "Yes" << endl;
        vector<ll> pos, neg;
        ll sum = 0;
        for (auto x : v)
        {
            if (x < 0)
                neg.push_back(x);
            else
                pos.push_back(x);
        }
        i = 0, j = 0;
        vector<ll> ans;
        while (n--)
        {
            if (sum >= 0)
            {
                sum += neg[i];
                ans.push_back(neg[i]);
                i++;
            }
            else
            {
                sum += pos[j];
                ans.push_back(pos[j]);
                j++;
            }
        }
        for (auto x : ans)
            cout << x << gap;
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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