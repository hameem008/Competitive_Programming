#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
vector<ll> divisors;

void calc()
{
    ll N = 1e6 + 8;
    divisors.assign(N + 1, 0);
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; i * j < N; j++)
        {
            divisors[i * j]++;
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    cout << divisors[n] << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calc();
    ll T = 1;
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}