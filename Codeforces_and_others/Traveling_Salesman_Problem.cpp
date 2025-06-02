#include<bits/stdc++.h>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
       
    ll t,i,j,a,n;
    cin>>t;
    while (t--){
        cin>>n;
        int x,y;
        vector<int>posx,posy,negx,negy;
        posx.push_back(0);
        posy.push_back(0);
        negx.push_back(0);
        negy.push_back(0);
        for(i=0;i<n;i++){
            cin>>x>>y;
            if(x<0) negx.push_back((-x));
            else if(x>0) posx.push_back(x);
            if(y<0) negy.push_back((-y));
            else if(y>0) posy.push_back(y);
        }
        int maxposx=0,maxposy=0,maxnegx=0,maxnegy=0;
        cout<<2*(*max_element(posx.begin(),posx.end())+*max_element(negx.begin(),negx.end())+*max_element(posy.begin(),posy.end())+*max_element(negy.begin(),negy.end()))<<line;
    }
    return 0;
}
