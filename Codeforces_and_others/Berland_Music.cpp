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
       cin>>n;
       vector<ll>v(n);
       for(i=0;i<n;i++){
        cin>>v[i];
       } 
       string bit;
       cin>>bit;
       ll cnt=count(bit.begin(),bit.end(),'0');
       set<ll>set0,set1;
       for(i=1;i<=cnt;i++){
        set0.insert(i);
       }
       for(i=cnt+1;i<=n;i++){
        set1.insert(i);
       }
       map<ll,ll>ans;
       for(i=0;i<n;i++){
        if(bit[i]=='0'){
            set<ll>::iterator it=set0.lower_bound(v[i]);
            if(it==set0.end()) it--; 
            ans.insert(make_pair(v[i],*it));
            set0.erase(*it);
        }
        else{
            set<ll>::iterator it=set1.lower_bound(v[i]);
            if(it==set1.end()) it--;
            ans.insert(make_pair(v[i],*it));
            set1.erase(*it);
        }
       }
       for(i=0;i<n;i++){
        auto it=ans.find(v[i]);
        cout<<it->second<<" ";
       }
       cout<<line;
    }
    return 0;
}
