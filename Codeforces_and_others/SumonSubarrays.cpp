#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a = 0, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    ll need;
    for (i = 0; i <= 30; i++)
    {
        if (k == i * (i + 1) / 2)
        {
            break;
        }
        else if (k < i * (i + 1) / 2)
        {
            a = -i * (i - 1) / 2 + k;
            need = 2 * a - 2 * (i - 1) - 1;
            i--;
            break;
        }
    }
    vector<ll> ans;
    for (j = 1; j <= i; j++)
    {
        ans.push_back(2);
    }
    if (a)
    {
        ans.push_back(need);
    }
    while (ans.size() != n)
        ans.push_back(-999);
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