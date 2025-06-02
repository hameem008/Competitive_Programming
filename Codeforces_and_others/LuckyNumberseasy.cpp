#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT32_MAX;

vector<ll> sup_lucky_nums;
void fun(vector<ll> &v)
{
    if (v.size() % 2 == 0)
    {
        ll cnt_4 = 0, cnt_7 = 0;
        for (auto x : v)
        {
            if (x == 4)
                cnt_4++;
            else if (x == 7)
                cnt_7++;
        }
        if (cnt_4 == cnt_7)
        {
            ll num = 0;
            for (auto x : v)
            {
                num = num * 10 + x;
            }
            sup_lucky_nums.push_back(num);
        }
    }
    if (v.size() < 10)
    {
        v.push_back(4);
        fun(v);
        v.pop_back();
        v.push_back(7);
        fun(v);
        v.pop_back();
    }
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    for (auto x : sup_lucky_nums)
    {
        if (x >= n)
        {
            cout << x << endl;
            break;
        }
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> dum;
    fun(dum);
    sort(sup_lucky_nums.begin(), sup_lucky_nums.end());
    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}