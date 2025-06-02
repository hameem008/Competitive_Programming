#include<bits/stdc++.h>
#define line '\n'
using namespace std;
typedef long long ll;

#define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1 arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1 arg1, Args... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
       
    ll t,i,j,k,a,b,m,n;
    cin>>t;
    while (t--){
        cin>>n>>k;
        vector<set<ll>>vs(k);
        vector<ll>v(n);
        for(i=0;i<n;i++){
            cin>>v[i];
        }
        for(i=0;i<n;i++){
            vs[i%k].insert(v[i]);
        }
        ll ans=0;
        for(i=0;i<k;i++){
            auto it=vs[i].end();
            it--;
            ans+=*it;
        }
        cout<<ans<<line;
    }
    return 0;
}
