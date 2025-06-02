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
        cin>>n>>k;
        int a[n];
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        if(k%2!=0){
            cout<<"YES"<<line;
            for(i=0;i<n;i=i+2){
                cout<<a[i]<<" "<<a[i+1]<<line;
            }
        }
        else if(k%4!=0){
            cout<<"YES"<<line;
            for(i=0;i<n;i=i+2){
                if((a[i+1]+k)%4==0) cout<<a[i+1]<<" "<<a[i]<<line;
                else cout<<a[i]<<" "<<a[i+1]<<line;
            }
        }
        else cout<<"NO"<<line;
    }
    return 0;
}
