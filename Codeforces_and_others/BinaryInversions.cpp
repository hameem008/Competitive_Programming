#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> v;
vector<ll> preCalc;

ll inv(ll n)
{
    ll inversion = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            inversion += preCalc[i];
    }
    return inversion;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, cnt, p;
    // solve stars
    v.clear();
    preCalc.clear();
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back(p);
    }
    ll firstZeroIndex = -1, lastOneIndex = -1;
    cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 1)
            cnt++;
        preCalc.push_back(cnt);
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            firstZeroIndex = i;
            break;
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (v[i] == 1)
        {
            lastOneIndex = i;
            break;
        }
    }
    set<ll> ans;
    ans.insert(inv(n));
    if (lastOneIndex != -1)
    {
        v[lastOneIndex] = 0;
        preCalc.clear();
        cnt = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] == 1)
                cnt++;
            preCalc.push_back(cnt);
        }
        ans.insert(inv(n));
        v[lastOneIndex] = 1;
    }
    if (firstZeroIndex != -1)
    {
        v[firstZeroIndex] = 1;
        preCalc.clear();
        cnt = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] == 1)
                cnt++;
            preCalc.push_back(cnt);
        }
        ans.insert(inv(n));
        v[firstZeroIndex] = 0;
    }
    cout << *(--ans.end()) << endl;
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