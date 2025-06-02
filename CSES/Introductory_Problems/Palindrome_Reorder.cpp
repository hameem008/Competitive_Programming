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
    vector<ll> v(26, 0);
    for (auto x : str)
    {
        v[x - 'A']++;
    }
    string ans;
    k = -1;
    ll k_cnt = 0;
    for (i = 0; i < 26; i++)
    {
        if (v[i] > 0 && v[i] % 2 == 0)
        {
            for (j = 0; j < v[i] / 2; j++)
            {
                ans.push_back(i + 'A');
            }
        }
        else if (v[i] > 0 && v[i] % 2 != 0)
        {
            k = i;
            k_cnt++;
        }
    }
    if (k_cnt > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (k > -1)
    {
        for (j = 0; j < v[k]; j++)
        {
            ans.push_back('A' + k);
        }
    }
    for (i = 25; i >= 0; i--)
    {
        if (v[i] > 0 && v[i] % 2 == 0)
        {
            for (j = 0; j < v[i] / 2; j++)
            {
                ans.push_back(i + 'A');
            }
        }
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
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}