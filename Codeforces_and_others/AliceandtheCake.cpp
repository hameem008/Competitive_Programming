#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag = true;
    // solve starts
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll sum = 0;
    for (auto x : v)
        sum += x;
    multiset<ll> main = {sum};
    ll now = n - 1;
    while (main.size() != 0)
    {
        auto it = main.find(v[now]);
        if (it != main.end())
        {
            main.erase(it);
            now--;
        }
        else if (*(--main.end()) < v[now])
        {
            flag = false;
            break;
        }
        else
        {
            ll large = *(--main.end());
            if (large % 2 == 0)
            {
                main.insert(large / 2);
                main.insert(large / 2);
            }
            else
            {
                main.insert(large / 2);
                main.insert(large / 2 + 1);
            }
            main.erase((--main.end()));
        }
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;
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