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
    string str;
    cin >> str;
    ll zero = 0, one = 0;
    for (i = 0; i < n; i++)
    {
        if (str[i] == '0')
            zero++;
        else
            one++;
    }
    ll current_max = 0, temp_max = 1;
    char current_char = str[0];
    for (i = 1; i < n; i++)
    {
        if (current_char == str[i])
            temp_max++;
        else
        {
            current_char = str[i];
            if (current_max < temp_max)
                current_max = temp_max;
            temp_max = 1;
        }
    }
    if (current_max < temp_max)
        current_max = temp_max;
    if ((zero * one) > (current_max * current_max))
        cout << zero * one << endl;
    else
        cout << current_max * current_max << endl;
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