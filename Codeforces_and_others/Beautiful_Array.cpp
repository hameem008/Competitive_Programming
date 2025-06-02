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
       
    ll t,i,j,k,a,b,s,m,n;
    cin>>t;
    while (t--){
        cin>>n>>k>>b>>s;
        if((b*k>s)||(s>=((b+1)*k+(n-1)*(k-1)))){
            cout<<-1<<line;
            continue;
        }
        ll a[n];
        for(i=0;i<n;i++){
            a[i]=0;
        }
        if(s>=(b+1)*k){
            a[0]=(b+1)*k-1;
            s=s-(b+1)*k+1;
            for(i=1;i<n;i++){
                s=s-k+1;
                if(s<0){
                    a[i]=s+k-1;
                    break;
                }
                a[i]=k-1;
            }
        }
        else a[0]=s;
        sort(a,a+n);
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<line;
    }
    return 0;
}
