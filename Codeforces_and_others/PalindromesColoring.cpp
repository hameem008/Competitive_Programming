#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    string str;
    cin >> str;
    map<char, ll> mp;
    for (auto x : str)
        mp[x]++;
    ll doubles = 0, singles = 0;
    for (auto x : mp)
    {
        if (x.second % 2 == 0)
        {
            doubles += x.second / 2;
        }
        else
        {
            singles++;
            doubles += (x.second - 1) / 2;
        }
    }
    vector<ll> ans(k, 0);
    ll fact = doubles / k;
    for (i = 0; i < k; i++)
    {
        ans[i] = fact * 2;
    }
    singles += (doubles % k) * 2;
    i = 0;
    while (i < k)
    {
        if (singles == 0)
            break;
        singles--;
        ans[i]++;
        i++;
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
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