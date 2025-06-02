#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<ll> powerOf2;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    if (n == 1)
    {
        cout << 3 << endl;
        return;
    }
    for (i = 0; i < 31; i++)
    {
        if (n % powerOf2[i] != 0)
            break;
    }
    i--;
    if (n / powerOf2[i] == 1)
        cout << powerOf2[i] + 1 << endl;
    else
        cout << powerOf2[i] << endl;

    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i <= 31; i++)
    {
        powerOf2.push_back(pow(2, i));
    }
    ll t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
        solve(I);
    return 0;
}