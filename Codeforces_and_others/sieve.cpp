#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;

vector<bool> v(1e5 + 1, true);

void sieve()
{
    v[0] = v[1] = false;
    for (int i = 2; i <= 1e5; i++)
    {
        if (v[i] == true)
        {
            for (int j = 2 * i; j <= 1e5; j = j + i)
            {
                v[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll count = 0;
    for (int i = 0; i <= 1e5; i++)
    {
        if (v[i])
            count++;
    }
    cout << count << endl;
    return 0;
}