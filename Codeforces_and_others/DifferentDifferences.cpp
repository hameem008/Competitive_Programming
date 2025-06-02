#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> k >> n;
    ll curr_num = 1;
    ll var_poss = 0;
    for (i = 0; i < n; i++)
    {
        if ((i + 1) * i / 2 <= n - k)
            var_poss = i + 1;
    }
    vector<ll> ans;
    i = 0;
    var_poss++;
    while ((var_poss--) && (ans.size() != k))
    {
        curr_num += i;
        ans.push_back(curr_num);
        i++;
    }
    while (ans.size() != k)
    {
        curr_num++;
        ans.push_back(curr_num);
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

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}