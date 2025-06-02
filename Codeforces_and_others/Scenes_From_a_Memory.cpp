#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

bool isPrime(ll n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n;
    string str;
    cin >> str;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        v.push_back(str[i] - 48);
    }
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            cout << 1 << endl;
            cout << v[i] << endl;
            return;
        }
        else if (!isPrime(v[i]))
        {
            cout << 1 << endl;
            cout << v[i] << endl;
            return;
        }
    }
    for (i = 0; i < v.size(); i++)
    {
        for (j = i + 1; j < v.size(); j++)
        {
            if (!isPrime(v[i] * 10 + v[j]))
            {
                cout << 2 << endl;
                cout << v[i] * 10 + v[j] << endl;
                return;
            }
        }
    }
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