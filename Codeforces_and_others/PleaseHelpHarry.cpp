#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    string str = "CSEWART", stin;
    cin >> stin;
    vector<ll> vin;
    for (i = 0; i < str.size(); i++)
    {
        ll cnt = 0;
        for (j = 0; j < stin.size(); j++)
        {
            if (str[i] == stin[j])
                cnt++;
        }
        if (i == 1)
            cnt /= 2;
        vin.push_back(cnt);
        cnt = 0;
    }
    sort(vin.begin(), vin.end());
    n = vin.front();
    for (i = 0; i < n; i++)
    {
        cout << "CSEWARTS";
    }
    cout << endl;
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