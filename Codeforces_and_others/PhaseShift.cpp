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
    cin >> n;
    string str;
    cin >> str;
    vector<char> v;
    char ch = 'a';
    for (i = 0; i < 26; i++)
    {
        v.push_back(ch);
        ch++;
    }
    map<char, char> mp;
    string ans;
    j = 0;
    for (i = 0; i < str.size(); i++)
    {
        auto it = mp.find(str[i]);
        if (it == mp.end())
        {
            while (v[j] == str[i])
            {
                v.push_back(v[j]);
                j++;
            }
            mp.insert({str[i], v[j]});
            ans.push_back(v[j]);
            j++;
        }
        else
        {
            ans.push_back(it->second);
        }
    }
    cout << ans << endl;
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