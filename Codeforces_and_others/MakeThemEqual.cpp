#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m = 0, n, p;
    // solve stars
    char ch;
    cin >> n >> ch;
    string str;
    cin >> str;
    ll cnt = 0;
    for (i = 1; i <= n; i++)
    {
        if (str[i - 1] == ch)
        {
            m = i;
            cnt++;
        }
    }
    if (cnt == n)
    {
        cout << 0 << endl;
    }
    else if (m <= n / 2)
    {
        cout << 2 << endl;
        cout << n - 1 << gap << n << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << m << endl;
    }
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