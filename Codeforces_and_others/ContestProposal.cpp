#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    multiset<ll> given, desired;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        given.insert(a);
    }
    for (i = 0; i < n; i++)
    {
        cin >> a;
        desired.insert(a);
    }
    ll cnt = 0;
    while (n--)
    {
        auto it1 = desired.begin();
        auto it2 = given.end();
        it2--;
        if (*it1 < *given.begin())
        {
            cnt++;
            given.erase(it2);
            desired.erase(it1);
        }
        else
        {
            given.erase(given.begin());
            desired.erase(desired.begin());
        }
    }
    cout << cnt << endl;
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