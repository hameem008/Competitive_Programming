#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

ll n, one_cnt = 0;
void rec(string &str)
{
    if (str.size() == n)
    {
        cout << str << endl;
        return;
    }

    if (one_cnt % 2 == 0)
    {
        str.push_back('0');
        rec(str);
        str.pop_back();

        one_cnt++;
        str.push_back('1');
        rec(str);
        str.pop_back();
        one_cnt--;
    }
    else
    {
        one_cnt++;
        str.push_back('1');
        rec(str);
        str.pop_back();
        one_cnt--;

        str.push_back('0');
        rec(str);
        str.pop_back();
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, p, q;
    bool flag;
    // solve starts
    cin >> n;
    string str;
    rec(str);
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