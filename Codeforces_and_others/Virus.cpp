#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> m;
    vector<ll> v;
    for (i = 0; i < m; i++)
    {
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    vector<ll> ans;
    ans.push_back(n - v.back() + v.front() - 1);
    for (i = 0; i < v.size() - 1; i++)
    {
        ans.push_back(v[i + 1] - v[i] - 1);
    }
    sort(ans.begin(), ans.end());
    ll d = 0, answer = 0;
    if (ans.back() == 1)
    {
        d = 2;
        answer = ans.back();
        ans.pop_back();
    }
    while (ans.size() != 0)
    {
        ll plus = ans.back() - d * 2 - 1;
        if (plus == 0)
            answer++;
        else if (plus > 0)
            answer += plus;
        else
            break;
        ans.pop_back();
        d += 2;
    }
    cout << n - answer << endl;
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