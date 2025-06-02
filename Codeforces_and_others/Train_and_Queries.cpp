#include <bits/stdc++.h>
#define line "\n"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, i, j, a, b, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<ll> vect(n);
        multimap<ll, ll> mlmp;
        for (i = 0; i < n; i++)
        {
            cin >> vect[i];
            mlmp.insert(make_pair(vect[i], i));
        }
        sort(vect.begin(), vect.end());
        for (i = 0; i < k; i++)
        {
            cin >> a >> b;
            bool ap = binary_search(vect.begin(), vect.end(), a);
            bool bp = binary_search(vect.begin(), vect.end(), b);
            if (ap == false || bp == false)
            {
                cout << "NO" << line;
                continue;
            }
            auto it1 = mlmp.lower_bound(a);
            auto it2 = mlmp.upper_bound(b);
            it2--;
            if (it1->second < it2->second)
                cout << "YES" << line;
            else
                cout << "NO" << line;
        }
    }
    return 0;
}