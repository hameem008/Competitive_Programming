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
        deque<ll>d;
        for(i=0;i<n;i++){
            cin>>a;
            d.push_back(a);
        }
        if(d[0]==n||d[d.size()-1]==n){
            if(d[0]==n) d.pop_front();
            else d.pop_back();
            reverse(d.begin(),d.end());
            d.push_back(n);
            for(i=0;i<d.size();i++){
                cout<<d[i]<<" ";
            }
            cout<<line;
        }
        else{
            cout<<-1<<line;
        }
    }
    return 0;
}
