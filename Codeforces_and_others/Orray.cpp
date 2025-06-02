#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    multiset<ll> ms;
    vector<ll> ans;
    ll max_or = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        max_or |= a;
        ms.insert(a);
    }
    ll curr_or = *(--ms.end());
    ms.erase(--ms.end());
    ans.push_back(curr_or);
    while (curr_or != max_or)
    {
        ll temp_or = curr_or;
        ll ele = -1;
        for (auto x : ms)
        {
            if (temp_or < (curr_or | x))
            {
                ele = x;
                temp_or = curr_or | x;
            }
        }
        curr_or = temp_or;
        if (ele != -1)
        {
            ans.push_back(ele);
            ms.erase(ms.find(ele));
        }
    }
    for (auto x : ans)
        cout << x << gap;
    for (auto x : ms)
        cout << x << gap;
    cout << endl;
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