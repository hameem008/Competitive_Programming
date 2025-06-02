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
    vector<bool> ans(n / 2 + 1, false);
    ans[0] = true;
    for (i = 1; i <= n / 2; i++)
    {
        ll cnt = 0;
        for (j = 0; j + i < n; j++)
        {
            if (str[j] == str[i + j] || str[j] == '?' || str[j + i] == '?')
            {
                cnt++;
                if (cnt >= i)
                    ans[i] = true;
            }
            else
            {
                cnt = 0;
            }
        }
    }
    ll max_ans = 0;
    for (i = 0; i <= n / 2; i++)
    {
        if (ans[i])
        {
            max_ans = i;
        }
    }
    cout << max_ans * 2 << endl;
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