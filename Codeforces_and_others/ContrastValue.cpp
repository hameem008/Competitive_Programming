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
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        if (i == 0)
            v.push_back(a);
        else if (v.back() != a)
            v.push_back(a);
    }
    if (v.size() == 1)
        cout << 1 << endl;
    else
    {
        n = v.size();
        if (v[0] > v[1])
            flag = false;
        else
            flag = true;
        ll ans = 1;
        for (i = 1; i < n - 1; i++)
        {
            if (v[i] < v[i + 1] && flag == false)
            {
                ans++;
                flag = true;
            }
            else if (v[i] > v[i + 1] && flag == true)
            {
                ans++;
                flag = false;
            }
        }
        cout << ans + 1 << endl;
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