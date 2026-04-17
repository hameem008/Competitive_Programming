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
    bool isPalindrome(string s)
    {
        string str;
        for (auto x : s)
        {
            if ((x >= 'A' && x <= 'Z'))
                str.push_back(x + 'a' - 'A');
            else if ((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
                str.push_back(x);
        }
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        return rev_str == str;
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    i = 'a' - 'A';
    cout << i << endl;
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