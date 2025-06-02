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
        vector<ll>vect(n);
        for(i=0;i<n;i++){
            cin>>vect[i];
        }
        bool flag=true,result=true;
        for(i=0;i<n-1;i++){
            if(flag==true){
                if(vect[i]<=vect[i+1]) continue;
                else{
                    flag=false;
                    if(i==n-2) break;
                }
            }
            if(flag==false){
                if(vect[i]>=vect[i+1]) continue;
                else{
                    result=false;
                    break;
                }
            }
        }
        if(result==true) cout<<"YES"<<line;
        else cout<<"NO"<<line;
    }
    return 0;
}
