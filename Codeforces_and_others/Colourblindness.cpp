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
        string str1,str2;
        cin>>str1;
        cin>>str2;
        vector<int>v1,v2;
        for(i=0;i<n;i++){
            if(str1[i]=='R') v1.push_back(0);
            else v1.push_back(1);
            if(str2[i]=='R') v2.push_back(0);
            else v2.push_back(1);
        }
        bool result=true;
        for(i=0;i<n;i++){
            if(v1[i]!=v2[i]){
                result=false;
                break;
            }
        }
        if(result==true) cout<<"YES"<<line;
        else cout<<"NO"<<line;
    }
    return 0;
}
