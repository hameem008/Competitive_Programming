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
ll process(ll v,ll a)
{
    if(v>=a) return (v-a);
    else return (a-v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
       
    ll t,i,j,x,n;
    cin>>t;
    while (t--){
        cin>>n;
        cin>>x;
        vector<ll>vect(n);
        for(i=0;i<n;i++){
            cin>>vect[i];
        }
        sort(vect.begin(),vect.end());
        ll v=vect[0]+x,cnt=0;
        for(i=0;i<n;i++){
            if(process(v,vect[i])>x){
                cnt++;
                v=vect[i]+x;
            }
        }
        cout<<cnt<<line;
    }
    return 0;
}
