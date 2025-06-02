#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

ll calcSum(string &str)
{
    ll sum = 0;
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == '1' && str[i + 1] == '1')
        {
            sum += 11;
        }
        else if (str[i] == '0' && str[i + 1] == '1')
        {
            sum += 1;
        }
        else if (str[i] == '1' && str[i + 1] == '0')
        {
            sum += 10;
        }
    }
    return sum;
}

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    cin >> n >> k;
    string str;
    cin >> str;
    ll sum = calcSum(str);
    ll first_one = 1e10, last_one = -1e10;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            first_one = i;
            break;
        }
    }
    for (i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            last_one = i;
            break;
        }
    }
    if (sum <= 10)
    {
        if (sum == 10)
        {
            if (str.size() - 1 <= k)
            {
                sum = 1;
                k -= str.size() - 1;
            }
        }
    }
    else
    {
        if (first_one == 0)
            first_one = 1e10;
        if (last_one == str.size() - 1)
            last_one = -1e10;
        if (str.size() - 1 - last_one <= k)
        {
            if (sum - 10 > 0)
            {
                sum -= 10;
                k -= str.size() - 1 - last_one;
            }
        }
        if (first_one <= k)
        {
            if (sum - 1 > 0)
            {
                sum -= 1;
                k -= first_one;
            }
        }
    }
    cout << sum << endl;
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