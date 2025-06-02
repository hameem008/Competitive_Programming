#include<bits/stdc++.h>
#define line "\n"
using namespace std;
typedef long long ll;

#define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1 arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1 arg1, Args... args){
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
       
    ll t,i,j,k,a,b,q,m,n;
    cin>>t;
    while (t--){
        cin>>n>>q;
        ll win_ara[n+1];
        for(i=0;i<n+1;i++){
            win_ara[i]=0;
        }
        ll sum_ara[n+1];
        set<ll>s;
        cin>>a;
        s.insert(a);
        for(i=0;i<n-1;i++){
            cin>>a;
            s.insert(a);
            set<ll>::reverse_iterator it=s.rbegin();
            win_ara[*it]++;
        }
        ll sum=0;
        for(i=1;i<n+1;i++){
            sum=sum+win_ara[i];
            sum_ara[i]=sum;
        }
        
    }
    return 0;
}
