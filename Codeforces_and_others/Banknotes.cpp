#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++)
    {
        v[i] = pow(10, v[i]);
    }
    ll bankNotes = 0, ans = 0;
    vector<ll> num;
    for (i = 0; i < v.size() - 1; i++)
    {
        bankNotes = v[i + 1] / v[i] - 1;
        if (bankNotes <= k)
        {
            k -= bankNotes;
            num.push_back(bankNotes);
        }
        else
            break;
    }
    num.push_back(k + 1);
    for (i = 0; i < num.size(); i++)
    {
        ans += num[i] * v[i];
    }
    cout << ans << endl;
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