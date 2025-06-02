#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string a, b;
    cin >> a;
    cin >> b;
    ll length = a.size() + b.size();
    ll ans = length;
    for (i = 0; i < b.size(); i++)
    {
        j = i;
        ll cnt = 0;
        for (k = 0; k < a.size(); k++)
        {
            if (j == b.size())
                break;
            if (a[k] == b[j])
            {
                cnt++;
                j++;
            }
        }
        ans = min(ans, length - cnt);
    }
    cout << ans << endl;
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