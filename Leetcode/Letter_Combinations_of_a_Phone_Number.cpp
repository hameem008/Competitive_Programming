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
    vector<string> ret;
    string con;
    void rec(string &s, int index)
    {
        if (index == s.size())
        {
            ret.push_back(con);
            return;
        }

        if (s[index] == '2')
        {
            for (char ch = 'a'; ch <= 'c'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
        else if (s[index] == '3')
        {
            for (char ch = 'd'; ch <= 'f'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
        else if (s[index] == '4')
        {
            for (char ch = 'g'; ch <= 'i'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
        else if (s[index] == '5')
        {
            for (char ch = 'j'; ch <= 'l'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
        else if (s[index] == '6')
        {
            for (char ch = 'm'; ch <= 'o'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
        else if (s[index] == '7')
        {
            for (char ch = 'p'; ch <= 's'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
        else if (s[index] == '8')
        {
            for (char ch = 't'; ch <= 'v'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
        else if (s[index] == '9')
        {
            for (char ch = 'w'; ch <= 'z'; ch++)
            {
                con.push_back(ch);
                rec(s, index + 1);
                con.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size())
            rec(digits, 0);
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
    cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}