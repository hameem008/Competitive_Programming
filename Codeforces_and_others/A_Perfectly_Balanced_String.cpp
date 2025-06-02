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
        string str;
        cin>>str;
        set<char>s;
        for(i=0;i<str.size();i++){
            s.insert(str[i]);
        }
        ll var=s.size();
        map<char,set<ll>>m;
        set<ll>sl;
        for(auto it=s.begin();it!=s.end();it++){
            m.insert(make_pair(*it,sl));
        }
        for(i=0;i<str.size();i++){
            auto IT=m.find(str[i]);
            IT->second.insert(i);
        }
        bool ans=true;
        auto It=m.begin();
        for(i=0;i<var;i++){
            auto it1=It->second.begin();
            auto it2=It->second.begin();
            it2++;
            for(j=0;j<It->second.size()-1;j++){
                if((*it2-*it1)<var){
                    ans=false;
                    break;
                }
                it1++;
                it2++;
            }
            It++;
            if(!ans) break;
        }
        if(ans) cout<<"YES"<<line;
        else cout<<"NO"<<line;
    }
    return 0;
}
