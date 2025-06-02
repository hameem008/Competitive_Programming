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
        multiset<ll>ms;
        for(i=0;i<n;i++){
            cin>>v[i];
            ms.insert(v[i]);
        }
        multimap<ll,ll>mmp;
        ll total_time=0;
        for(i=1;;i++){
            auto it1=ms.end();
            it1--;
            mmp.insert(make_pair(*it1,i));
            total_time=total_time+(*it1)*i;
            ms.erase(it1);
            if(ms.size()==0) break;
            auto it2=ms.end();
            it2--;
            mmp.insert(make_pair(*it2,-i));
            total_time=total_time+(*it2)*i;
            ms.erase(it2);
            if(ms.size()==0) break;
        }
        cout<<2*total_time<<line;
        cout<<0<<" ";
        for(i=0;i<n;i++){
            auto IT=mmp.find(v[i]);
            cout<<IT->second<<" ";
            mmp.erase(IT);
        }
        cout<<line;
    }
    return 0;
}
