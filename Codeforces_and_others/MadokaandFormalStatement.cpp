#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    a.push_back(a[0]);
    b.push_back(b[0]);
    bool flag = true;
    for (i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;
        else if (a[i] < b[i])
        {
            if (b[i] > b[i + 1] + 1)
            {
                flag = false;
                break;
            }
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
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