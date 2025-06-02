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
        vector<ll>v;
        for(i=0;i<n;i++){
            if(bit[i]=='1') v.push_back(1);
            else v.push_back(0);
        }
        for(i=v.size()-1;i>=0;i--){
            if(v[i]==0) break;
            else v.pop_back();
        }
        ll zero=count(v.begin(),v.end(),0);
        ll one=count(v.begin(),v.end(),1);
        set<ll>si1,si0,ans;
        for(i=0;i<v.size();i++){
            if(v[i]==0) si0.insert(i);
            else si1.insert(i);
        }
        if(zero<one){
            k=one+zero;
            auto it1=si0.begin();
            for(i=0;i<si0.size();i++){
                ans.insert(*it1);
                it1++;
            }
            auto it2=si1.begin();
            for(i=0;i<si1.size();i++){
                ans.insert(*it2);
                it2++;
            }
        }
        else{
            k=2*one;
            auto it3=si1.begin();
            for(i=0;i<si1.size();i++){
                ans.insert(*it3);
                it3++;
            }
            auto it4=si0.rbegin();
            for(i=0;i<si1.size();i++){
                ans.insert(*it4);
                it4++;
            }
        }
        if(k==0) cout<<k<<line;
        else{
            cout<<1<<line;
            cout<<k<<" ";
            auto it5=ans.begin();
            for(i=0;i<ans.size();i++){
                cout<<(*it5)+1<<" ";
                it5++;
            }
            cout<<line;
        }
    }
    return 0;
}
