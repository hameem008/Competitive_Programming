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
    // mancher's algorithm
    string longestPalindrome(string s)
    {
        int ret = 0;
        string str;
        char percentage = '%', hash_ = '#', dollar = '*';
        str.push_back(percentage);
        str.push_back(hash_);
        for (auto x : s)
        {
            str.push_back(x);
            str.push_back(hash_);
        }
        str.push_back(dollar);
        int l = 0, r = 1, n = str.size() - 2;
        vector<int> p(str.size(), 0);
        for (int i = 1; i <= n; i++)
        {
            p[i] = min(r - i, p[l + r - i]);
            while (str[i - p[i]] == str[i + p[i]])
                p[i]++;
            if (i + p[i] > r)
                l = i - p[i], r = i + p[i];
        }
        for (int i = 0; i <= n + 1; i++)
        {
            cout << p[i];
            ret = max(ret, p[i]);
        }
        cout << endl;
        cout << str << endl;
        string ret_str;
        deque<char> dq;
        for (int i = 1; i <= n; i++)
        {
            if (ret == p[i])
            {
                int j = 1;
                dq.push_back(str[i]);
                while (1)
                {
                    if (str[i - j] == str[i + j])
                    {
                        dq.push_front(str[i - j]);
                        dq.push_back(str[i + j]);
                        j++;
                    }
                    else
                        break;
                }
                break;
            }
        }
        for (auto x : dq)
            if (x != '#')
                ret_str.push_back(x);
        return ret_str;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string s = "abba";
    Solution sl;
    cout << sl.longestPalindrome(s) << endl;
    s = "abcba";
    cout << sl.longestPalindrome(s) << endl;
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