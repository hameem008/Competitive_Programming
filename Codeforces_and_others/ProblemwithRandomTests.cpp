#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    string str;
    cin >> str;
    vector<ll> index_of_zero;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            index_of_zero.push_back(i);
    }
    if (index_of_zero.size() == 0)
    {
        cout << str << endl;
        return;
    }
    ll one_cnt = 0;
    flag = false;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            flag = true;
        }
        else
            flag = false;
        if (flag)
            one_cnt++;
        if (!flag && one_cnt > 0)
            break;
    }
    if (!one_cnt)
    {
        cout << 0 << endl;
        return;
    }
    vector<ll> ans = {infinite};
    for (i = 1; i <= one_cnt; i++)
    {
        vector<ll> dum;
        for (auto x : index_of_zero)
        {
            if (str[x - i] == '1')
                dum.push_back(x);
        }
        dum.push_back(infinite);
        ans = min(ans, dum);
    }
    ans.pop_back();
    for (auto x : ans)
        str[x] = '1';
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
            break;
    }
    for (; i < str.size(); i++)
        cout << str[i];
    cout << endl;
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