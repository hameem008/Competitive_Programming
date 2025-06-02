#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> v;

bool isSorted(ll l, ll r)
{
    bool ans = true;
    for (int i = l; i < r; i++)
    {
        if (v[i] > v[i + 1])
        {
            ans = false;
            break;
        }
    }
    return ans;
}

bool isSortedReverse(ll l, ll r)
{
    bool ans = true;
    for (int i = l; i < r; i++)
    {
        if (v[i] < v[i + 1])
        {
            ans = false;
            break;
        }
    }
    return ans;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    v.clear();
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back(p);
    }
    ll max = *max_element(v.begin(), v.end());
    ll min = *min_element(v.begin(), v.end());
    ll minIndex;
    ll maxIndex;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == max)
        {
            maxIndex = i;
        }
    }
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == min)
        {
            minIndex = i;
        }
    }
    if (isSorted(0, n - 1))
    {
        cout << "YES" << endl;
        return;
    }
    if (isSortedReverse(0, n - 1))
    {
        cout << "YES" << endl;
        return;
    }
    if (isSortedReverse(0, minIndex) && isSorted(minIndex, n - 1))
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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