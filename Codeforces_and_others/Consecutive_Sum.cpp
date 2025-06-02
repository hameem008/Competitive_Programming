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
        vector<ll>v;
        for(i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }
        for(i=0,j=k;i<n-k;i++,j++){
            if(v[i]<v[j]) swap(v[i],v[j]);
        }
        ll ans=0,sum;
        for(i=0;i<n-k;i++){
            sum=0;
            for(j=i;j<k+i;j++){
                sum+=v[j];
            }
            if(sum>ans) ans=sum;
        }
        if(n==k){
            ans=0;
            for(i=0;i<n;i++){
                ans+=v[i];
            }
        }
        cout<<ans<<line;
    }
    return 0;
}
