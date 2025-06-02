#include<bits/stdc++.h>
#define line "\n"
using namespace std;
typedef long long ll;

// #define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char* name, Arg1 arg1) { cout << name << " : " << arg1 << endl; }
// template <typename Arg1, typename... Args>
// void __f(const char* names, Arg1 arg1, Args... args)
// {
//     const char* comma = strchr(names+1, ',');
//     cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
// }

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL); 
       
    ll t,i,j,k,a,b,c,d;
    double m,n;
    cin>>t;
    while (t--){
        cin>>a>>b>>c>>d;
        m=(double)a/b;
        n=(double)c/d;
        if(m==n) cout<<0<<line;
        else if(m==0||n==0||((a*d)%(b*c)==0)||((b*c)%(a*d)==0)) cout<<1<<line;
        else cout<<2<<line;
    }
    return 0;
}
