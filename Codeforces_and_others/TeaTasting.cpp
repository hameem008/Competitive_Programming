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
    vector<ll> tea(n), tester(n);
    for (auto &x : tea)
        cin >> x;
    for (auto &x : tester)
        cin >> x;
    vector<ll> presum(n);
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += tester[i];
        presum[i] += sum;
    }
    ll sa, red = 0;
    vector<ll> precof(n, 0);
    vector<ll> ans(n, 0);
    for (i = 0; i < n; i++)
    {
        sa = tea[i] + red;
        ll ind = upper_bound(presum.begin() + i, presum.end(), sa) - presum.begin();
        if (ind == n)
        {
            precof[i]++;
        }
        else if (ind == i)
        {
            ans[i] += tea[i];
        }
        else
        {
            precof[i]++;
            precof[ind]--;
            ans[ind] += tea[i] - (presum[ind - 1] - red);
        }
        red += tester[i];
    }
    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += precof[i];
        precof[i] = sum;
    }
    for (i = 0; i < n; i++)
    {
        ans[i] += precof[i] * tester[i];
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