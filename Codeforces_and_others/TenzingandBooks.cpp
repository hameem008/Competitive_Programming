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
    cin >> n >> k;
    vector<ll> v1(n + 1), v2(n + 1), v3(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v1[i];
    for (i = 1; i <= n; i++)
        cin >> v2[i];
    for (i = 1; i <= n; i++)
        cin >> v3[i];
    ll cur_know = 0;
    for (i = 1; i <= n; i++)
    {
        if ((k | v1[i]) == k)
        {
            cur_know |= v1[i];
        }
        else
            break;
    }
    for (i = 1; i <= n; i++)
    {
        if ((k | v2[i]) == k)
        {
            cur_know |= v2[i];
        }
        else
            break;
    }
    for (i = 1; i <= n; i++)
    {
        if ((k | v3[i]) == k)
        {
            cur_know |= v3[i];
        }
        else
            break;
    }
    k == cur_know ? cout << "Yes" << endl : cout << "No" << endl;
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