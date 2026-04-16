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
    bool checkValidString(string s)
    {
        vector<int> left, star;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                left.push_back(i);
            else if (s[i] == '*')
                star.push_back(i);
            else if (s[i] == ')')
            {
                if (left.size())
                    left.pop_back();
                else if (star.size())
                    star.pop_back();
                else
                    return false;
            }
        }
        while (left.size())
        {
            if (star.size() == 0)
                return false;
            if (left.back() > star.back())
                return false;
            left.pop_back();
            star.pop_back();
        }
        return true;
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}