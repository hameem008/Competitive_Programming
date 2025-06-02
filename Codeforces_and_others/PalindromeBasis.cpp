#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
ll mod = 1e9 + 7;

bool checkPalindrome(ll n)
{
    vector<ll> a;
    while (n)
    {
        a.push_back(n % 10);
        n /= 10;
    }
    vector<ll> b(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

vector<ll> allPalin;
void palindrome()
{
    for (int i = 1; i <= 4 * 1e4; i++)
    {
        if (checkPalindrome(i))
            allPalin.push_back(i);
    }
}

ll dp[500][40008];
ll calc(ll num, ll ind)
{
    if (num == 0)
        return 1;
    if (ind < 0 || num < 0)
        return 0;

    if (dp[ind][num] == -1)
    {
        ll ways = 0;
        ways = calc(num, ind - 1) + calc(num - allPalin[ind], ind);
        dp[ind][num] = ways % mod;
    }

    return dp[ind][num];
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    cout << calc(n, allPalin.size() - 1) << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    palindrome();
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 40008; j++)
        {
            dp[i][j] = -1;
        }
    }

    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}