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
       
    ll t,i,j,k,a,b,m,n,q;
    cin>>t;
    while (t--){
        cin>>n>>q;
        vector<ll>v1(n);
        for(i=0;i<n;i++){
            cin>>v1[i];
        }
        vector<ll>v2(q);
        for(i=0;i<q;i++){
            cin>>v2[i];
        }
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        vector<ll>v1_sum(n);
        map<ll,ll>m;
        ll sum=0;
        for(i=0;i<n;i++){
            sum=sum+v1[i];
            m.insert(make_pair(sum,i));
        }
        auto end=m.end();
        end--;
        for(i=0;i<q;i++){
            if(end->first<v2[i]){
                cout<<-1<<line;
                continue;
            }
            if(m.begin()->first>v2[i]){
                cout<<1<<line;
                continue;
            }
            auto it=m.lower_bound(v2[i]);
            cout<<it->second+1<<line;
        }
    }
    return 0;
}
