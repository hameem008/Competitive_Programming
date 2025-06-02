#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, c, d, m, n, p, q;
    bool flag = false;
    // solve starts
    cin >> n;
    vector<string> v(2 * n - 2);
    for (i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    string a, b;
    for (auto x : v)
    {
        if (x.size() == n - 1 && a.size() == 0)
        {
            a = x;
        }
        else if (x.size() == n - 1 && b.size() == 0)
        {
            b = x;
        }
    }
    if (a.size() == 1 && b.size() == 1)
    {
        if (a == b)
            flag = true;
    }
    else
    {
        string str;
        deque<char> dum1(a.begin(), a.end()), dum2(b.begin(), b.end());
        flag = true;
        dum1.pop_front();
        dum2.pop_back();
        if (dum1 != dum2)
            flag = false;
        if (flag)
            str = a[0] + b;
        dum1.clear();
        dum1.assign(b.begin(), b.end());
        dum2.clear();
        dum2.assign(a.begin(), a.end());
        flag = true;
        dum1.pop_front();
        dum2.pop_back();
        if (dum1 != dum2)
            flag = false;
        if (flag)
            str = b[0] + a;
        string strrev = str;
        reverse(strrev.begin(), strrev.end());
        flag = false;
        if (strrev == str)
            flag = true;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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