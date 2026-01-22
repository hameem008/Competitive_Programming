#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        vector<int> a(n, 0);
        vector<int> res;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (a[j] % 2 == 0)
                res.push_back(1);
            else
                res.push_back(0);
        }
        int j = 0;
        if (res[0] == 0)
        {
            for (; j < res.size(); j++)
            {
                if (res[j] == 1)
                {

                    break;
                }
            }
        }
        cout << "Case " << i << ": ";
        for (; j < res.size(); j++)
        {
            cout << res[j];
        }
        cout << "\n";
    }
}