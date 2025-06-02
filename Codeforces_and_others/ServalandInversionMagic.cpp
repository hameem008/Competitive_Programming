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
    string str;
    cin >> str;
    string strev(str.begin(), str.end());
    reverse(strev.begin(), strev.end());
    ll cnt = 0;
    vector<ll> check;
    for (i = 0; i < n; i++)
    {
        if (str[i] != strev[i])
            cnt++;
        else
        {
            if (cnt != 0)
                check.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt != 0)
        check.push_back(cnt);
    if ((check.size() == 2 && check[0] == check[1]) || check.size() == 0 || check.size() == 1)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
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