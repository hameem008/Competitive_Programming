#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

void solve(int I)
{
    ll i, j, k, a, b, m, n, p;
    // solve stars
    string str;
    cin >> str;
    char current_char = str[0];
    if (str.size() == 1)
    {
        if (str[0] == 'Y' || str[0] == 'e' || str[0] == 's')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    for (i = 1; i < str.size(); i++)
    {
        if (current_char == 'Y')
        {
            if (str[i] == 'e')
                current_char = str[i];
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (current_char == 'e')
        {
            if (str[i] == 's')
                current_char = str[i];
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else if (current_char == 's')
        {
            if (str[i] == 'Y')
                current_char = str[i];
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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