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
        string bit;
        cin>>bit;
        vector<char>v;
        v.push_back('1');
        for(i=0;i<bit.size();i++){
            v.push_back(bit[i]);
        }
        v.push_back('0');
        ll last_1,first_0;
        for(i=0;i<v.size();i++){
            if(v[i]=='1') last_1=i;
            if(v[i]=='0'){
                first_0=i;
                break;
            }
        }
        ll ans;
        if(last_1==0&&first_0==(v.size()-1)) ans=first_0-last_1-1;
        else if(last_1==0) ans=first_0-last_1;
        else if(first_0==(v.size()-1)) ans=first_0-last_1;
        else ans=first_0-last_1+1;

        cout<<ans<<line;
    }
    return 0;
}
