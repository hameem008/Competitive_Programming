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
    string str1, str2;
    cin >> n;
    cin >> str1;
    cin >> str2;
    ll cat1 = 0, cat2 = 0;
    for (auto x : str1)
        if (x == '1')
            cat1++;
    for (auto x : str2)
        if (x == '1')
            cat2++;
    ll ans = 0;
    ll mismatch = 0;
    if (cat1 > cat2)
    {
        i = 0;
        while (cat1 != cat2)
        {
            if (str1[i] == '1' && str2[i] == '0')
            {
                str1[i] = '0';
                cat1--;
                ans++;
            }
            i++;
        }
        for (i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
                mismatch++;
        }
    }
    else if (cat1 == cat2)
    {
        for (i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
                mismatch++;
        }
    }
    else if (cat1 < cat2)
    {
        i = 0;
        while (cat1 != cat2)
        {
            if (str1[i] == '0' && str2[i] == '1')
            {
                str1[i] = '1';
                cat1++;
                ans++;
            }
            i++;
        }
        for (i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
                mismatch++;
        }
    }
    cout << mismatch / 2 + ans << endl;
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