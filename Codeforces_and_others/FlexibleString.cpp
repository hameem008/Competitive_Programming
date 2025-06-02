#pragma GCC optimizer("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef int ll;
typedef long double lld;

vector<string> subsetgen(vector<char> &v)
{
    int n = v.size();
    int subset_cnt = (1 << n);
    vector<string> subsets;
    for (int mask = 0; mask < subset_cnt; mask++)
    {
        string subset="";
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                subset.push_back(v[i]);
        }
        subsets.push_back(subset);
    }
    return subsets;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, p, q;
    long long n;
    bool flag;
    // solve starts
    cin >> n >> k;
    string stra, strb;
    cin >> stra;
    cin >> strb;
    set<char> s;
    for (i = 0; i < n; i++)
    {
        if (stra[i] != strb[i])
        {
            s.insert(stra[i]);
        }
    }
    if (s.size() <= k)
    {
        cout << n * (n + 1) / 2 << endl;
        return;
    }
    vector<char> v(s.begin(), s.end());
    vector<string> allSubset = subsetgen(v);
    vector<string> dsub;
    for (i = 0; i < allSubset.size(); i++)
    {
        if (allSubset[i].size() == k)
            dsub.push_back(allSubset[i]);
    }
    long long maxans = -1e15;
    for (auto &x : dsub)
    {
        vector<bool> hash(26, false);
        for (auto y : x)
        {
            hash[y - 'a'] = true;
        }
        long long cnt = 0;
        long long temp = 0;
        for (i = 0; i < n; i++)
        {
            if (stra[i] != strb[i])
            {
                if (!hash[stra[i] - 'a'])
                {
                    temp += cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
                else
                {
                    cnt++;
                }
            }
            else
            {
                cnt++;
            }
        }
        temp += cnt * (cnt + 1) / 2;
        maxans = max(temp, maxans);
    }
    cout << maxans << endl;
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