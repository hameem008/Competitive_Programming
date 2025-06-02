#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> v(n + 1);
    // vector<ll> print;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        v[a] = i;
        // print.push_back(a);
    }
    ll ans = n / 2;
    if (ans != 0)
    {
        if (n % 2 == 0)
        {
            if (v[n / 2] < v[n / 2 + 1])
            {
                ans--;
                ll curr_low = v[n / 2], curr_high = v[n / 2 + 1];
                for (i = n / 2 - 1, j = n / 2 + 2; j <= n; i--, j++)
                {
                    if (v[i] < curr_low && v[j] > curr_high)
                    {
                        curr_low = v[i];
                        curr_high = v[j];
                        ans--;
                    }
                    else
                        break;
                }
            }
        }
        else
        {
            if (v[n / 2] < v[n / 2 + 2] && (v[n / 2 + 1] > v[n / 2] && v[n / 2 + 1] < v[n / 2 + 2]))
            {
                ans--;
                ll curr_low = v[n / 2], curr_high = v[n / 2 + 2];
                for (i = n / 2 - 1, j = n / 2 + 3; j <= n; i--, j++)
                {
                    if (v[i] < curr_low && v[j] > curr_high)
                    {
                        curr_low = v[i];
                        curr_high = v[j];
                        ans--;
                    }
                    else
                        break;
                }
            }
        }
    }
    // for (auto x : print)
    //     cout << x << gap;
    // cout << "ans: ";
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