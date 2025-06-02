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
        set<ll>s;
        for(i=0;i<n;i++){
            cin>>a;
            s.insert(a);
        }
        multimap<ll,ll>m;
        ll size=floor(n/2);
        set<ll>::iterator it_cons=s.begin();
        set<ll>::iterator it_var=s.begin();
        it_var++;
        // while(1){
        //     if(size==m.size()) break;
        //     ll b=*it_var%*it_cons;
        //     bool flag=binary_search(s.begin(),s.end(),b);
        //     if(flag==false&&*it_cons!=*it_var){
        //         m.insert(make_pair(*it_cons,*it_var));
        //     }
        //     if(*it_cons==*it_var){
        //         it_cons++;
        //         it_var=s.rbegin();
        //         continue;
        //     }
        //     it_var++;
        // }
        for(i=0;i<size;i++){
            m.insert(make_pair(*it_cons,*it_var));
            it_var++;
        }
        auto it=m.begin();
        for(i=0;i<m.size();i++){
            cout<<it->second<<" "<<it->first<<line;
            it++;
        }
    }
    return 0;
}
