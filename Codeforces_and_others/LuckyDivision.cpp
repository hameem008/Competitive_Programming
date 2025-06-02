#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> nums;
bool func(ll n)
{
    set<ll> s;
    while (n)
    {
        s.insert(n % 10);
        n /= 10;
    }
    s.erase(4);
    s.erase(7);
    if (s.size() == 0)
        return true;
    return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = false;
    // solve starts
    cin >> n;
    for (auto x : nums)
    {
        if (n % x == 0)
            flag = true;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 1000; i++)
    {
        if (func(i))
            nums.push_back(i);
    }
    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}