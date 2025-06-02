#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string a, b;
    cin >> a;
    cin >> b;
    if (a[0] == b[0])
    {
        cout << "YES" << endl;
        cout << a[0] << '*' << endl;
        return;
    }
    else if (a.back() == b.back())
    {
        cout << "YES" << endl;
        cout << '*' << a.back() << endl;
        return;
    }
    string ans = "*";
    for (i = 0; i < a.size() - 1; i++)
    {
        for (j = 0; j < b.size() - 1; j++)
        {
            if (a[i] == b[j] && a[i + 1] == b[j + 1])
            {
                ans.push_back(a[i]);
                ans.push_back(a[i + 1]);
                break;
            }
        }
        if (ans.size() != 1)
            break;
    }
    ans.push_back('*');
    if (ans.size() == 2)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << ans << endl;
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