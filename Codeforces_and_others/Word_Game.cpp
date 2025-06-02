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

void input(set<string> &st,ll n){
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(s);
    }
}
ll point(set<string> &main,set<string> &other1,set<string> &other2,ll n){
    ll point=0;
    auto it=main.begin();
    for(int i=0;i<n;i++){
        auto it1=other1.find(*it);
        auto it2=other2.find(*it);
        if((it1!=other1.end())&&(it2!=other2.end())) point+=0;
        else if((it1!=other1.end())||(it2!=other2.end())) point++;
        else point+=3;
        it++;
    }
    return point;
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
        set<string>person1;
        set<string>person2;
        set<string>person3;
        input(person1,n);
        input(person2,n);
        input(person3,n);
        ll person1_point=point(person1,person2,person3,n);
        ll person2_point=point(person2,person1,person3,n);
        ll person3_point=point(person3,person1,person2,n);
        cout<<person1_point<<" "<<person2_point<<" "<<person3_point<<line;
    }
    return 0;
}
