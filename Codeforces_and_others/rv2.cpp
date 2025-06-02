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
        string bit;
        cin>>bit;
        vector<ll>v,v_sort;
        for(i=0;i<n;i++){
            v.push_back(bit[i]);
            v_sort.push_back(bit[i]);
        }
        sort(v_sort.begin(),v_sort.end());
        k=0;
        set<ll>ans;
        for(i=0;i<n;i++){
            if(v[i]!=v_sort[i]){
                ans.insert(i);
                k++;
            }
        }
        if(k==0) cout<<0<<line;
        else{
            cout<<1<<line;
            cout<<k<<" ";
            auto it=ans.begin();
            for(i=0;i<k;i++){
                cout<<(*it)+1<<" ";
                it++;
            }
            cout<<line;
        }
    }
    return 0;
}
