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
    if (n == 1)
        cout << 1 << endl;
    else if (n % 2 != 0)
        cout << -1 << endl;
    else
    {
        i = 1, j = n - 2;
        ll limit = n / 2 - 1;
        vector<ll> divis;
        vector<ll> ans;
        ans.push_back(n);
        ans.push_back(n - 1);
        ll sum = 2 * n - 1;
        while (limit--)
        {
            divis.push_back(i);
            divis.push_back(j);
            i++, j--;
        }
        flag = true;
        for (auto x : divis)
        {
            if (flag)
            {
                ll mul = (sum / n + 1) * n + x;
                ans.push_back(mul - sum);
                sum = mul;
                flag = false;
            }
            else
            {
                ll mul = (sum / n) * n + x;
                ans.push_back(mul - sum);
                sum = mul;
                flag = true;
            }
        }
        for (auto x : ans)
            cout << x << gap;
        cout << endl;
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