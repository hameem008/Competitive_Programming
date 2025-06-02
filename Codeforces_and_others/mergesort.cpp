#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
const ll N = 1e5 + 10;
ll ara[N];

void merge(int l, int r, int mid)
{
    ll l_sz = mid - l + 1;
    ll L[l_sz + 1];
    ll r_sz = r - mid;
    ll R[r_sz + 1];
    for (int i = 0; i < l_sz; i++)
    {
        L[i] = ara[i + l];
    }
    for (int i = 0; i < r_sz; i++)
    {
        R[i] = ara[i + mid + 1];
    }
    L[l_sz] = R[r_sz] = INT_MAX;
    ll l_i = 0, r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            ara[i] = L[l_i];
            l_i++;
        }
        else
        {
            ara[i] = R[r_i];
            r_i++;
        }
    }
}

void mergesort(ll l, ll r)
{
    if (l == r)
        return;
    ll mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
}

void solve(int I)
{
    ll i, j, k, a, b, m = 0, n, p;
    // solve stars
    for (i = 0; i < 5; i++)
    {
        cin >> ara[i];
    }
    mergesort(0, 4);
    for (i = 0; i < 5; i++)
    {
        cout << ara[i] << gap;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}