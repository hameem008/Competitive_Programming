#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> v;
ll cnt = 0;

void swapTree(ll n)
{
    if (pow(2, n) == v.size())
        return;
    for (int i = 0, j = pow(2, n); j < v.size(); j += pow(2, n + 1), i += pow(2, n + 1))
    {
        if (v[i] > v[j])
        {
            ll k = i, l = j;
            cnt++;
            for (int q = 0; q < pow(2, n); q++)
            {
                swap(v[k], v[l]);
                k++;
                l++;
            }
        }
    }
    swapTree(n + 1);
}

bool isSorted(ll n)
{
    for (int i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1])
            return false;
    return true;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    v.clear();
    cnt = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back(p);
    }
    swapTree(0);
    if (isSorted(v.size()))
        cout << cnt << endl;
    else
        cout << -1 << endl;
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