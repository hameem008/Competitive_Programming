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
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    deque<ll> a, b;
    for (i = 0; i < n; i += 2)
    {
        a.push_back(v[i]);
    }
    for (i = 1; i < n; i += 2)
    {
        b.push_back(v[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> merge;
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            merge.push_back(a.front());
            a.pop_front();
        }
        else
        {
            merge.push_back(b.front());
            b.pop_front();
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        if (merge[i] > merge[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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