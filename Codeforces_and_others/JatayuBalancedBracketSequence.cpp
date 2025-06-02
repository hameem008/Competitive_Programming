#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    string str;
    cin >> n;
    cin >> str;
    vector<ll> v;
    ll cnt = 0;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else
        {
            if (cnt != 0)
                v.push_back(cnt);
            cnt = 0;
        }
    }
    cout << accumulate(v.begin(), v.end(), 0LL) - v.size() + 1 << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}