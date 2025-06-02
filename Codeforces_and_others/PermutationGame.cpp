#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    vector<ll> check;
    for (i = 1; i <= n; i++)
        check.push_back(i);
    ll first = 0, second = 0;
    for (i = 0; i < n; i++)
    {
        if (check[i] == v[i])
            first++;
    }
    reverse(check.begin(), check.end());
    for (i = 0; i < n; i++)
    {
        if (check[i] == v[i])
            second++;
    }
    if (first == n - 2 && n != 3)
        cout << "First" << endl;
    else if (second == n - 2 && n != 3)
        cout << "Second" << endl;
    else
        cout << "Tie" << endl;
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