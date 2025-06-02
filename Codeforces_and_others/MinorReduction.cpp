#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> str;
    n = str.size();
    vector<ll> v;
    for (auto x : str)
        v.push_back(x - '0');
    flag = false;
    for (i = n - 1; i > 0; i--)
    {
        if (v[i] + v[i - 1] >= 10)
        {
            flag = true;
            ll sum = v[i] + v[i - 1];
            v[i] = sum % 10;
            v[i - 1] = sum / 10;
            break;
        }
    }
    if (!flag)
    {
        v[1] = v[0] + v[1];
        for (i = 1; i < n; i++)
            cout << v[i];
        cout << endl;
    }
    else
    {
        for (i = 0; i < n; i++)
            cout << v[i];
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