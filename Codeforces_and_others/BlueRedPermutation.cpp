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
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    string str;
    cin >> str;
    vector<ll> reds, blues;
    vector<ll> nums;
    for (i = 0; i < n; i++)
    {
        nums.push_back(i + 1);
        if (str[i] == 'R')
            reds.push_back(v[i]);
        else if (str[i] == 'B')
            blues.push_back(v[i]);
    }
    sort(reds.begin(), reds.end());
    while (reds.size())
    {
        if (reds.back() <= nums.back())
        {
            nums.pop_back();
        }
        reds.pop_back();
    }
    sort(blues.rbegin(), blues.rend());
    reverse(nums.begin(), nums.end());
    while (blues.size())
    {
        if (blues.back() >= nums.back())
        {
            nums.pop_back();
        }
        blues.pop_back();
    }
    if (nums.size())
        cout << "NO" << endl;
    else
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