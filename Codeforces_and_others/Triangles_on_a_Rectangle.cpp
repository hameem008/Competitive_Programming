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
       
    ll t,i,j,k,a,b,m,n,p;
    cin>>t;
    while (t--){
        ll w,h;
        cin>>w>>h;
        cin>>k;
        set<ll>sx1;
        for(i=0;i<k;i++){
            cin>>p;
            sx1.insert(p);
        }
        cin>>k;
        set<ll>sx2;
        for(i=0;i<k;i++){
            cin>>p;
            sx2.insert(p);
        }
        cin>>k;
        set<ll>sy1;
        for(i=0;i<k;i++){
            cin>>p;
            sy1.insert(p);
        }
        cin>>k;
        set<ll>sy2;
        for(i=0;i<k;i++){
            cin>>p;
            sy2.insert(p);
        }
        auto it_first_sx1=sx1.begin();
        auto it_last_sx1=sx1.end();
        it_last_sx1--;
        a=*it_last_sx1-*it_first_sx1;
        auto it_first_sx2=sx2.begin();
        auto it_last_sx2=sx2.end();
        it_last_sx2--;
        b=*it_last_sx2-*it_first_sx2;
        ll max1;
        if(a>b) max1=a*h;
        else max1=b*h;
        auto it_first_sy1=sy1.begin();
        auto it_last_sy1=sy1.end();
        it_last_sy1--;
        a=*it_last_sy1-*it_first_sy1;
        auto it_first_sy2=sy2.begin();
        auto it_last_sy2=sy2.end();
        it_last_sy2--;
        b=*it_last_sy2-*it_first_sy2;
        ll max2;
        if(a>b) max2=a*w;
        else max2=b*w;
        if(max1>max2) cout<<max1<<line;
        else cout<<max2<<line; 
    }
    return 0;
}
