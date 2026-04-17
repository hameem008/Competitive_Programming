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
    int string_to_int(string s)
    {
        reverse(s.begin(), s.end());
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
                num = -num;
            else
                num = num + (s[i] - '0') * pow(10, i);
        }
        return num;
    }
    int evalRPN(vector<string> &tokens)
    {
        vector<int> v;
        for (auto x : tokens)
        {
            if (x == "+" || x == "-" || x == "*" || x == "/")
            {
                int b = v.back();
                v.pop_back();
                int a = v.back();
                v.pop_back();
                if (x == "+")
                    v.push_back(a + b);
                else if (x == "-")
                    v.push_back(a - b);
                else if (x == "*")
                    v.push_back(a * b);
                else if (x == "/")
                    v.push_back(a / b);
            }
            else
                v.push_back(string_to_int(x));
        }
        return v.front();
    }
};

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    vector<string> tokens = {"1", "2", "+", "3", "*", "-40", "-"};
    Solution sl;
    cout << (1 + 2) * 3 - (-40) << endl;
    cout << sl.evalRPN(tokens) << endl;
    //  solve ends
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