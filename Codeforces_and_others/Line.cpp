#include<bits/stdc++.h>
#define line "\n"
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
        string st;
        cin>>st;
        ll value=0;
        for(i=0;i<n;i++){
            if(st[i]=='R') value+=n-i-1;
            else if(st[i]=='L') value+=i;
        }
        vector<ll>v;
        for(i=0;i<n;i++){
            if(st[i]=='R'){
                if((-n+2*i+1)>=0) v.push_back(-n+2*i+1);
                else v.push_back(0);
            }
            if(st[i]=='L') if((n-2*i-1)>=0) v.push_back(n-2*i-1);
            else v.push_back(0);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(i=0;i<n;i++){
            value+=v[i];
            cout<<value<<" ";
        }
        cout<<line;
    }
    return 0;
}
