#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
ll N = 1e6 + 2;

vector<ll> divisors;
vector<ll> present;
void calc()
{
    divisors.assign(N + 8, 0);
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; i * j < N; j++)
        {
            if (present[i * j])
                divisors[i] += present[i * j];
        }
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    present.assign(N + 8, 0);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        present[a]++;
    }
    calc();
    ll ans = 0;
    for (i = 1; i < N; i++)
    {
        if (divisors[i] > 1)
            ans = i;
    }
    cout << ans << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}