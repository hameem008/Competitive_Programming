#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    bool isM = false;
    bool isM1 = false;
    ll sum = 0;
    for (auto &x : v)
    {
        cin >> x;
        sum += x;
    }
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] == -1 && v[i + 1] == -1)
            isM = true;
        if (v[i] + v[i + 1] == 0)
            isM1 = true;
    }
    if (isM)
        sum += 4;
    else if (isM1)
        sum = sum;
    else
        sum -= 4;
    cout << sum << endl;
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