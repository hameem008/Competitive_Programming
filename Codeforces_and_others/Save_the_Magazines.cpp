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
    string str;
    cin >> str;
    vector<ll> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll current_0 = -1;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            current_0 = i;
            break;
        }
    }
    if (current_0 == -1)
    {
        ll sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += v[i];
        }
        cout << sum << endl;
        return;
    }
    vector<pair<ll, multiset<ll>>> vs;
    multiset<ll> min;
    vector<ll> wontadd;
    for (i = current_0 + 1; i < n; i++)
    {
        if (str[i] == '0')
        {
            if (min.size() != 0)
            {
                vs.push_back({v[current_0], min});
                min.clear();
                current_0 = i;
            }
            else
            {
                wontadd.push_back(v[current_0]);
                current_0 = i;
            }
        }
        else
        {
            min.insert(v[i]);
        }
    }
    if (current_0 == n - 1)
        wontadd.push_back(v[current_0]);
    else
        vs.push_back({v[current_0], min});
    for (i = 0; i < vs.size(); i++)
    {
        if (vs[i].second.size() > 0)
        {
            auto it = vs[i].second.begin();
            if (*it < vs[i].first)
            {
                wontadd.push_back(*it);
            }
            else
                wontadd.push_back(vs[i].first);
        }
    }
    ll total_sum = 0;
    for (i = 0; i < v.size(); i++)
    {
        total_sum += v[i];
    }
    ll neg = 0;
    for (i = 0; i < wontadd.size(); i++)
    {
        neg += wontadd[i];
    }
    cout << total_sum - neg << endl;
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