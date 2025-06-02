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
    cin >> a >> b;
    string str1, str2;
    cin >> str1;
    cin >> str2;
    ll cons = 0;
    for (i = 0; i < a - 1; i++)
    {
        if (str1[i] == str1[i + 1])
            cons++;
    }
    for (i = 0; i < b - 1; i++)
    {
        if (str2[i] == str2[i + 1])
            cons++;
    }
    if (cons == 0)
        cout << "YES" << endl;
    else if (cons == 1)
    {
        if (str1.back() == str2.back())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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