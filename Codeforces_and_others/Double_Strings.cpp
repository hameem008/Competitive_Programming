#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<pair<string, string>> splitString(string s)
{
    int i = 1;
    vector<pair<string, string>> ans;
    while (s.size() - i)
    {
        string part1(s.begin(), s.begin() + i);
        string part2(s.begin() + i, s.end());
        ans.push_back({part1, part2});
        i++;
    }
    return ans;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    // solve starts
    cin >> n;
    vector<string> v;
    set<string> s;
    for (i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
        s.insert(str);
    }
    vector<int> ans(n, 0);
    for (i = 0; i < n; i++)
    {
        for (auto x : splitString(v[i]))
        {
            if (s.find(x.first) != s.end() && s.find(x.second) != s.end())
            {
                ans[i] = 1;
                break;
            }
        }
    }
    for (auto x : ans)
        cout << x;
    cout << endl;
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