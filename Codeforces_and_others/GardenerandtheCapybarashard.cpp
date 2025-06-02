#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    string str;
    cin >> str;
    n = str.size();
    if (str[0] == str[n - 1])
    {
        cout << str[0] << gap;
        for (i = 1; i < n - 1; i++)
        {
            cout << str[i];
        }
        cout << gap;
        cout << str[n - 1] << endl;
    }
    else
    {
        bool flag = false;
        for (i = 1; i < n - 1; i++)
        {
            if (str[i] == 'a')
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            for (j = 0; j < i; j++)
            {
                cout << str[j];
            }
            cout << gap;
            cout << str[i] << gap;
            for (j = i + 1; j < n; j++)
            {
                cout << str[j];
            }
            cout << endl;
        }
        else
        {
            cout << str[0] << gap;
            for (i = 1; i < n - 1; i++)
            {
                cout << str[i];
            }
            cout << gap;
            cout << str[n - 1] << endl;
        }
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