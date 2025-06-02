#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n >> k;
    string str;
    cin >> str;
    pair<ll, ll> range1, range2 = {26, 26};
    vector<ll> v;
    set<char> s;
    for (auto x : str)
    {
        if (s.find(x) == s.end())
        {
            s.insert(x);
            v.push_back(x - 'a');
        }
    }
    if (v[0] - k <= 0)
    {
        range1.first = 0;
        k = k - v[0];
    }
    else
    {
        range1.first = v[0] - k;
        k = 0;
    }
    range1.second = v[0];
    vector<char> hash(26);
    for (i = 0; i < 26; i++)
        hash[i] = 'a' + i;
    for (auto x : v)
    {
        if (x >= range1.first && x <= range1.second)
        {
            hash[x] = 'a' + range1.first;
        }
        else if (x > range1.second && k > 0)
        {
            if (x - k <= range1.second)
            {
                k = k - (x - range1.second);
                range1.second = x;
                hash[x] = 'a' + range1.first;
            }
            else
            {
                range2.second = x;
                range2.first = x - k;
                k = 0;
            }
        }
        if (x >= range2.first && x <= range2.second)
        {
            hash[x] = 'a' + range2.first;
        }
    }
    for (auto &x : str)
    {
        x = hash[x - 'a'];
    }
    cout << str << endl;
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