#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<ll> v;
    if (n % 4 == 0)
    {
        i = 0;
        n /= 4;
    }
    else if (n % 4 == 1)
    {
        i = 8;
        v.push_back(0);
        n--;
        n /= 4;
    }
    else if (n % 4 == 2)
    {
        i = 16;
        v.push_back(1);
        v.push_back(10);
        v.push_back(4);
        v.push_back(11);
        v.push_back(8);
        v.push_back(12);
        n -= 6;
        n /= 4;
    }
    else if (n % 4 == 3)
    {
        i = 8;
        v.push_back(1);
        v.push_back(3);
        v.push_back(2);
        n -= 3;
        n /= 4;
    }

    while (n--)
    {
        v.push_back(i);
        v.push_back(i + 2);
        v.push_back(i + 6);
        v.push_back(i + 4);
        i += 8;
    }

    for (auto x : v)
        cout << x << gap;
    cout << endl;
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