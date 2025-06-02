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
    vector<ll> va(n), vb(n);
    for (auto &x : va)
        cin >> x;
    for (auto &x : vb)
        cin >> x;
    vector<ll> duma = va;
    sort(duma.begin(), duma.end());
    multiset<pair<ll, ll>> msp, mspr, fixed;
    multiset<ll> ms(vb.begin(), vb.end());
    for (auto x : duma)
    {
        auto it = ms.begin();
        if (*it < x)
        {
            msp.insert({x, *it});
            mspr.insert({*it, x});
            ms.erase(it);
        }
    }
    if (msp.size() < k)
    {
        cout << "NO" << endl;
        return;
    }
    flag = true;
    while (msp.size() != k)
    {
        auto it1 = msp.begin();
        auto it2 = mspr.lower_bound({it1->first, 0});
        if (it2 == mspr.end())
        {
            auto it3 = ms.lower_bound(it1->first);
            if (it3 == ms.end())
            {
                flag = false;
                break;
            }
            else
            {
                ms.insert(it1->second);
                fixed.insert({it1->first, *it3});
                ms.erase(it3);
                mspr.erase(mspr.find({it1->second, it1->first}));
                msp.erase(it1);
            }
        }
        else
        {
            pair<ll, ll> p1 = *it1, p2 = *it2;
            fixed.insert({it1->first, it2->first});
            a = it2->second;
            b = it1->second;

            msp.erase(it1);
            mspr.erase(it2);

            swap(p1.first, p1.second);
            mspr.erase(mspr.find(p1));

            swap(p2.first, p2.second);
            msp.erase(msp.find(p2));

            msp.insert({a, b});
            mspr.insert({b, a});
        }
    }
    if (!flag)
    {
        cout << "NO" << endl;
        return;
    }
    vector<pair<ll, ll>> vp(msp.begin(), msp.end());
    msp.clear();
    for (auto x : vp)
    {
        auto it = ms.begin();
        if (it != ms.end() && *it < x.second)
        {
            msp.insert({x.first, *it});
            ms.erase(it);
            ms.insert(x.second);
        }
        else
        {
            msp.insert(x);
        }
    }
    vector<ll> ans(n, 0);
    for (i = 0; i < n; i++)
    {
        auto it = msp.lower_bound({va[i], 0});
        if (it != msp.end() && it->first == va[i])
        {
            ans[i] = it->second;
            msp.erase(it);
            continue;
        }
        auto it1 = fixed.lower_bound({va[i], 0});
        if (it1 != fixed.end() && it1->first == va[i])
        {
            ans[i] = it1->second;
            fixed.erase(it1);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            auto it = ms.lower_bound(va[i]);
            if (it == ms.end())
                it--;
            ans[i] = *it;
            ms.erase(it);
        }
    }
    ll cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (va[i] > ans[i])
        {
            cnt++;
        }
    }
    if (cnt != k)
        flag = false;
    if (flag)
    {
        cout << "YES" << endl;
        for (auto x : ans)
            cout << x << gap;
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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