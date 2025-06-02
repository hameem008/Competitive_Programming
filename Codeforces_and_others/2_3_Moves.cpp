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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
       
    ll t,i,j,a,n;
    cin>>t;
    while (t--){
        cin>>n;
        if(n<0) n=-n;
        if(n==0||n==1){
            if(n==0) cout<<0<<line;
            else if(n==1) cout<<2<<line;
            continue;
        }
        if(n%3==0) cout<<n/3<<line;
        else if(n%3==1) cout<<(n-4)/3+2<<line;
        else cout<<(n+1)/3<<line;
    }
    return 0;
}
