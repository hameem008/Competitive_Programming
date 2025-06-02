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
    flag = true;
    if (n % 2 != 0)
        cout << "YES" << endl;
    else
    {
        while (1)
        {
            if (v.size() == 2)
            {
                if (v[0] > v[1])
                    flag = false;
                break;
            }
            else
            {
                if (v[v.size() - 1] >= v[v.size() - 2])
                {
                    v[v.size() - 3] = v[v.size() - 3] + (v[v.size() - 1] - v[v.size() - 2]);
                    v.pop_back();
                    v.pop_back();
                }
                else
                {
                    v[v.size() - 3] = v[v.size() - 3] - (v[v.size() - 2] - v[v.size() - 1]);
                    v.pop_back();
                    v.pop_back();
                }
            }
        }
        flag ? cout << "YES" << endl : cout << "NO" << endl;
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