#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

class Solution
{
public:
    vector<vector<string>> ret;
    vector<int> container;
    string buildString(int start_index, int end_index, string &s)
    {
        string str;
        for (int i = start_index; i <= end_index; i++)
        {
            str.push_back(s[i]);
        }
        return str;
    }
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (1)
        {
            if (s[i] != s[j])
                return false;
            if (i == j || i + 1 == j)
                return true;
            i++, j--;
        }
    }
    void rec(int sz, string &s)
    {
        if (sz == 0)
        {
            int st = 0;
            vector<string> vs;
            for (auto x : container)
            {
                vs.push_back(buildString(st, st + x - 1, s));
                st += x;
                if (!isPalindrome(vs.back()))
                    return;
            }
            ret.push_back(vs);
            return;
        }

        for (int i = 1; i <= sz; i++)
        {
            container.push_back(i);
            rec(sz - i, s);
            container.pop_back();
        }
    }
    vector<vector<string>> partition(string &s)
    {
        rec(s.size(), s);
        return ret;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}