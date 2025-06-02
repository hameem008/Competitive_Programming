#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;

bool check(string a, string b)
{
    string dum1, dum2;
    for (int i = 6; i <= 9; i++)
    {
        dum1.push_back(a[i]);
    }
    dum1.push_back(a[3]);
    dum1.push_back(a[4]);
    dum1.push_back(a[0]);
    dum1.push_back(a[1]);
    dum1.push_back(a[11]);
    dum1.push_back(a[12]);
    dum1.push_back(a[14]);
    dum1.push_back(a[15]);
    dum1.push_back(a[17]);
    dum1.push_back(a[18]);

    for (int i = 6; i <= 9; i++)
    {
        dum2.push_back(b[i]);
    }
    dum2.push_back(b[3]);
    dum2.push_back(b[4]);
    dum2.push_back(b[0]);
    dum2.push_back(b[1]);
    dum2.push_back(b[11]);
    dum2.push_back(b[12]);
    dum2.push_back(b[14]);
    dum2.push_back(b[15]);
    dum2.push_back(b[17]);
    dum2.push_back(b[18]);

    if (dum1 > dum2)
        return true;
    else
        return false;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    cin >> n;
    vector<vector<string>> v;
    for (i = 0; i < n; i++)
    {
        string str1, str2, str3, str4;
        cin >> str1 >> str2 >> str3 >> str4;
        vector<string> dum;
        dum.push_back(str1);
        dum.push_back(str2);
        dum.push_back(str3);
        dum.push_back(str4);
        v.push_back(dum);
    }
    vector<ll> erase;
    unordered_map<string, pair<string, ll>> mp;
    for (i = 0; i < n; i++)
    {
        auto it = mp.find(v[i][1]);
        if (it != mp.end())
        {
            if (check(it->second.first, v[i][0]))
            {
                erase.push_back(i);
            }
            else
            {
                erase.push_back(it->second.second);
                mp.erase(it);
                mp.insert({v[i][1], {v[i][0], i}});
            }
        }
        else
        {
            mp.insert({v[i][1], {v[i][0], i}});
        }
    }

    sort(erase.begin(), erase.end());
    reverse(erase.begin(), erase.end());
    for (i = 0; i < erase.size(); i++)
    {
        v.erase(v.begin() + erase[i]);
    }

    // for (i = 0; i < v.size(); i++)
    // {
    //     for (j = 0; j < 4; j++)
    //     {
    //         cout << v[i][j] << gap;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    map<string, ll> birth;
    map<string, ll> blood;
    for (i = 0; i < v.size(); i++)
    {
        string str;
        str.push_back(v[i][2][6]);
        str.push_back(v[i][2][7]);
        str.push_back(v[i][2][8]);
        str.push_back(v[i][2][9]);
        string bd = v[i][3];
        blood[bd]++;
        birth[str]++;
    }
    cout<<"A+ "<<blood["A+"]<<endl;
    cout<<"A- "<<blood["A-"]<<endl;
    cout<<"AB+ "<<blood["AB+"]<<endl;
    cout<<"AB- "<<blood["AB-"]<<endl;
    cout<<"B+ "<<blood["B+"]<<endl;
    cout<<"B- "<<blood["B-"]<<endl;
    cout<<"O+ "<<blood["O+"]<<endl;
    cout<<"O- "<<blood["O-"]<<endl;
    for (auto it : birth)
    {
        cout << it.first << gap << it.second << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}