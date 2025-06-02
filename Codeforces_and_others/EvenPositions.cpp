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
    vector<pair<char, ll>> v;
    for (i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        v.push_back({ch, i});
    }
    ll diya = 0;
    while (v.size() > 2)
    {
        pair<char, ll> one, two, three;
        three = v.back();
        v.pop_back();
        two = v.back();
        v.pop_back();
        one = v.back();
        v.pop_back();
        if (one.first == ')')
        {
            diya -= two.second;
            diya += three.second;
            v.push_back(one);
        }
        else if (one.first == '(')
        {
            diya -= one.second;
            diya += two.second;
            v.push_back(three);
        }
    }
    diya -= v.front().second;
    diya += v.back().second;
    cout << diya << endl;
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