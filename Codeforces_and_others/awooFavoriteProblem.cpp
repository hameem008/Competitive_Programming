#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    string str, des;
    cin >> str;
    cin >> des;
    set<ll> ai, bi, ci;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
            ai.insert(i + 1);
        else if (str[i] == 'b')
            bi.insert(i + 1);
        else
            ci.insert(i + 1);
    }
    ll a_count = 0, b_count = 0, c_count = 0;
    for (i = 0; i < des.size(); i++)
    {
        if (des[i] == 'a')
            a_count++;
        else if (des[i] == 'b')
            b_count++;
        else if (des[i] == 'c')
            c_count++;
    }
    if (ai.size() != a_count || bi.size() != b_count || ci.size() != c_count)
    {
        cout << "NO" << endl;
        return;
    }
    for (i = 0; i < des.size(); i++)
    {
        ll ch;
        if (ai.find(i + 1) != ai.end())
            ch = 'a';
        else if (bi.find(i + 1) != bi.end())
            ch = 'b';
        else if (ci.find(i + 1) != ci.end())
            ch = 'c';
        if (des[i] == 'a')
        {
            if (ch == 'a')
            {
                ai.erase(ai.begin());
            }
            else if (ch == 'b')
            {
                cout << "NO" << endl;
                return;
            }
            else if (ch == 'c')
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (des[i] == 'b')
        {
            if (ch == 'a')
            {
                if (ci.size() == 0)
                {
                    ai.erase(ai.begin());
                    ai.insert(*bi.begin());
                    bi.erase(bi.begin());
                }
                else
                {
                    ll b_lowi = *bi.begin();
                    ll c_lowi = *ci.begin();
                    if (b_lowi > c_lowi)
                    {
                        cout << "NO" << endl;
                        return;
                    }
                    else
                    {
                        ai.erase(ai.begin());
                        ai.insert(*bi.begin());
                        bi.erase(bi.begin());
                    }
                }
            }
            else if (ch == 'b')
            {
                bi.erase(bi.begin());
            }
            else if (ch == 'c')
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (des[i] == 'c')
        {
            if (ch == 'a')
            {
                cout << "NO" << endl;
                return;
            }
            else if (ch == 'b')
            {
                if (ai.size() == 0)
                {
                    bi.erase(bi.begin());
                    bi.insert(*ci.begin());
                    ci.erase(ci.begin());
                }
                else
                {
                    ll a_lowi = *ai.begin();
                    ll c_lowi = *ci.begin();
                    if (c_lowi > a_lowi)
                    {
                        cout << "NO" << endl;
                        return;
                    }
                    else
                    {
                        bi.erase(bi.begin());
                        bi.insert(*ci.begin());
                        ci.erase(ci.begin());
                    }
                }
            }
            else if (ch == 'c')
            {
                ci.erase(ci.begin());
            }
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