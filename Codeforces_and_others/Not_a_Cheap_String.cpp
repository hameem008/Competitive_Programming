#include<bits/stdc++.h>
#include<stdio.h>
#define line "\n"
using namespace std;
typedef long long ll;

// #define debugging(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char* name, Arg1 arg1) { cout << name << " : " << arg1 << endl; }
// template <typename Arg1, typename... Args>
// void __f(const char* names, Arg1 arg1, Args... args)
// {
//     const char* comma = strchr(names+1, ',');
//     cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
// }

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL); 

    ll t,i,j,a,n;
    cin>>t;
    char c;
    scanf("%c",&c);
    while (t--){
        vector<char>vect;
        while(1){
            char ch;
            scanf("%c",&ch);
            if(ch=='\n') break;
            vect.push_back(ch);
        }
        ll n;
        cin>>n;
        ll sum=0;
        for(i=0;i<vect.size();i++){
            sum=sum+vect[i]-96;
        }
        if(sum<=n){
            for(i=0;i<vect.size();i++){
                cout<<vect[i];
            }
            cout<<line;
            scanf("%c",&c);
            continue;
        }
        multimap<ll,char>mm1;
        multimap<char,ll>mm2;
        for(i=0;i<vect.size();i++){
            mm1.insert(make_pair(i,vect[i]));
            mm2.insert(make_pair(vect[i],i));
        }
        a=vect.size();
        while(1){
            auto it2=mm2.end();
            it2--;
            sum=sum-(it2->first-96);
            auto it1=mm1.find(it2->second);
            mm1.erase(it1);
            mm2.erase(it2);
            a--;
            if(sum<=n) break;
        }
        if(a==0){
            cout<<line;
            scanf("%c",&c);
            continue;
        }
        auto it1=mm1.begin();
        for(i=0;i<a;i++){
            cout<<it1->second;
            it1++;
        }
        cout<<line;
        scanf("%c",&c);
    }
    return 0;
}
