#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

bool isDiverse(map<char, ll> &mp)
{
    ll ans = 0;
    for (auto x : mp)
    {
        if (x.second != 0)
            ans++;
    }
    for (auto x : mp)
    {
        if (x.second != 0 && x.second > ans)
            return false;
    }
    return true;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string str;
    cin >> n;
    cin >> str;
    ll ans = 0;
    for (i = n >= 100 ? 100 : n; i >= 1; i--)
    {
        map<char, ll> mp;
        for (j = 0; j < i; j++)
        {
            mp[str[j]]++;
        }
        if (isDiverse(mp))
            ans++;
        k = 1;
        while ((k + i - 1) < n)
        {
            mp[str[k - 1]]--;
            mp[str[k + i - 1]]++;
            if (isDiverse(mp))
                ans++;
            k++;
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}