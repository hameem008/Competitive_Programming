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
       
    ll t,i,j,k,a,b,m,n;
    cin>>t;
    while (t--){
        char ara[4];
        cin>>ara[0]>>ara[1]>>ara[2]>>ara[3];
        sort(ara,ara+4);
        if((ara[0]==ara[1]&&(ara[1]==ara[2])&&(ara[2]==ara[3]))){
            cout<<0<<line;
        }
        else if((((ara[0]==ara[1])&&(ara[1]==ara[2]))||((ara[1]==ara[2])&&(ara[2]==ara[3])))||((ara[0]==ara[1])&&(ara[2]==ara[3]))){
          
          cout<<1<<line;
        }
        else if((ara[0]==ara[1])||(ara[1]==ara[2])||(ara[2]==ara[3])){
            cout<<2<<line;
        }
        else cout<<3<<line;
    }
    return 0;
}
