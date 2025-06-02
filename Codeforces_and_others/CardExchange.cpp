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
    cin >> n >> k;
    vector<ll> freq(101, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
    }
    ll additional = 0;
    for (i = 1; i <= 100; i++)
    {
        if (freq[i] >= k)
        {
            additional += (freq[i] / k) * (k - 1);
            freq[i] = freq[i] % k;
        }
    }
    for (i = 1; i <= 100; i++)
    {
        if (freq[i] > 0)
        {
            if (additional >= k - freq[i])
            {
                additional = additional - (k - freq[i]) + k - 1;
                freq[i] = 0;
            }
        }
    }
    ll rema = accumulate(freq.begin(), freq.end(), 0LL);
    if (additional >= k)
        rema += (k - 1);
    else
        rema += additional;
    cout << rema << endl;
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