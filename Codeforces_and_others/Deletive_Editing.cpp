#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    string str1, str2;
    cin >> str1 >> str2;
    vector<ll> vstr1(26, 0), vstr2(26, 0);
    for (i = 0; i < str1.size(); i++)
    {
        vstr1[str1[i] - 'A']++;
    }
    for (i = 0; i < str2.size(); i++)
    {
        vstr2[str2[i] - 'A']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (vstr1[i] < vstr2[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    vector<ll> ans;
    for (i = str2.size() - 1; i >= 0; i--)
    {
        for (j = str1.size() - 1; j >= 0; j--)
        {
            if (str2[i] == str1[j])
            {
                ans.push_back(j);
                str1[j] = '0';
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}