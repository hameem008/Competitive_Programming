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
        cin>>n>>a>>b;
        if(a!=0&&b!=0){
            cout<<-1<<line;
            continue;
        }

        if(a==0) swap(a,b);
        if(a==0&&b==0){
            cout<<-1<<line;
            continue;
        }
        if(n%a!=1&&a!=1){
            cout<<-1<<line;
            continue;
        }
        vector<ll>v;
        ll replace=2;
        ll cnt=0;
        for(i=0;i<n-1;i++){
            v.push_back(replace);
            cnt++;
            if(cnt==a){
                cnt=0;
                replace=replace+a;
            }
        }
        for(i=0;i<n-1;i++){
            cout<<v[i]<<" ";
        }
        cout<<line;
    }
    return 0;
}
