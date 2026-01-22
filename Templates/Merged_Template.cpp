## Base_Template.cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;
void solve(int I, int T) {
    ll i, j, k, a, b, c, d, m, n, p, q; bool flag;
    // solve starts
    // solve ends 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T = 1; cin >> T;
    for (int I = 1; I <= T; I++) solve(I, T);
    return 0; }
## String/Manachers_Algorithm.cpp
vector<int> mancher(string s){string str;str.push_back('%');for(auto x:s){str.push_back('#');str.push_back(x);}str.push_back('#');str.push_back('$');vector<int> p(str.size());int l=0,r=1,n=str.size()-2;for(int i=1;i<=n;i++){p[i]=min(r-i,p[l+(r-i)]);while(str[i-p[i]]==str[i+p[i]])p[i]++;if(i+p[i]>r){l=i-p[i];r=i+p[i];}}return p;}
## String/Prefix_function.cpp
vector<int> prefix_function(string s){int n=s.length(),i,j;vector<int> pi(n);for(i=1;i<n;i++){j=pi[i-1];while(j>0&&s[i]!=s[j])j=pi[j-1];if(s[i]==s[j])j++;pi[i]=j;}return pi;}
## String/Trie.cpp
#define number_of_alphabets 26
class trie_node{public:char end_of_word;trie_node*children[number_of_alphabets];trie_node(){end_of_word=0;for(int i=0;i<number_of_alphabets;i++)children[i]=nullptr;}};
class trie{trie_node*root;bool has_children(trie_node*node){for(int i=0;i<number_of_alphabets;i++)if(node->children[i])return true;return false;}
bool delete_word(trie_node*node,string&word,int depth){if(!node)return false;if(depth==word.length()){if(node->end_of_word){node->end_of_word=0;return !has_children(node);}return false;}int index=word[depth]-'a';if(delete_word(node->children[index],word,depth+1)){delete node->children[index];node->children[index]=nullptr;return !node->end_of_word&&!has_children(node);}return false;}
void destroy(trie_node*node){if(!node)return;for(int i=0;i<number_of_alphabets;i++)if(node->children[i])destroy(node->children[i]);delete node;}
public:trie(){root=new trie_node();}
bool search_word(string word){trie_node*node=root;for(char c:word){int index=c-'a';if(!node->children[index])return 0;node=node->children[index];}return node->end_of_word;}
void insert_word(string word){trie_node*node=root;for(char c:word){int index=c-'a';if(!node->children[index])node->children[index]=new trie_node();node=node->children[index];}node->end_of_word=1;}
void erase_word(string word){delete_word(root,word,0);}
bool starts_with(string prefix){trie_node*node=root;for(char c:prefix){int index=c-'a';if(!node->children[index])return 0;node=node->children[index];}return 1;}
void clear(){destroy(root);root=new trie_node();}
~trie(){destroy(root);}};
## String/Z_function.cpp
vector<int> z_function(string s){int n=s.size();vector<int> z(n);int l=0,r=0,i;for(i=1;i<n;i++){if(i<r)z[i]=min(r-i,z[i-l]);while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;if(i+z[i]>r)l=i,r=i+z[i];}return z;}
## String/String_Hashing.cpp
ll compute_hash(string&s){int p=31,m=1e9+9;ll hash_value=0,p_pow=1;for(char c:s){hash_value=(hash_value+(c-'a'+1)*p_pow)%m;p_pow=(p_pow*p)%m;}return hash_value;}
vector<vector<int>> group_identical_strings(vector<string>&s){int n=s.size();vector<pair<ll,int>> hashes(n);vector<vector<int>> groups;for(int i=0;i<n;i++)hashes[i]={compute_hash(s[i]),i};sort(hashes.begin(),hashes.end());for(int i=0;i<n;i++){if(i==0||hashes[i].first!=hashes[i-1].first)groups.emplace_back();groups.back().push_back(hashes[i].second);}return groups;}
## String/Suffox_Array.cpp
// SAIS sa; sa.addString(str); sa.makeSuffixArray(); sa.makeLCPArray();
vector<int> longest_common_prefix; vector<int> suffix_array;
class SuffixArray{public:SuffixArray();~SuffixArray();virtual void makeSuffixArray()=0;virtual bool addStringFromFile(string);virtual bool addString(string);vector<int> makeLCPArray();int findLongestCommonStrand(const unsigned int);int calcParentString(int);void printSuffixArray();protected:const int maxAlphabetSize=256;int numStrings;vector<int>*suffixArray;vector<int>*str;template<typename T>void printVector(vector<T> v);template<typename T>void printSubStringVector(vector<T> v,int offset,int length);};
SuffixArray::SuffixArray(){numStrings=0;suffixArray=new vector<int>;str=new vector<int>;}SuffixArray::~SuffixArray(){delete suffixArray;delete str;}
bool SuffixArray::addString(string inputString){for(auto it=inputString.cbegin();it!=inputString.cend();it++)str->push_back(*it);numStrings+=1;return true;}
bool SuffixArray::addStringFromFile(string fileName){ifstream fin(fileName,ios::binary);if(!fin){cerr<<"Could not read file from: "<<fileName<<endl;return false;}fin.unsetf(ios::skipws);fin.seekg(0,ios::end);streampos length=fin.tellg();fin.seekg(0,ios::beg);str->reserve(length);int i=0;char*temp=new char;while(i<length){fin.read(temp,sizeof(*temp));str->push_back(reinterpret_cast<unsigned char&>(*temp));i++;}delete temp;numStrings+=1;return true;}
vector<int> SuffixArray::makeLCPArray(){int length=suffixArray->size();vector<int> lcp(length,0);vector<int> invertedSuffixArray(length,0);int l=0;for(int i=0;i<length;i++)invertedSuffixArray[(*suffixArray)[i]]=i;for(int i=0;i<length-1;i++){int k=invertedSuffixArray[i];int j=(*suffixArray)[k-1];while((*str)[i+l]==(*str)[j+l])l+=1;lcp[k]=l;if(l>0)l-=1;}longest_common_prefix=lcp;return lcp;}
int SuffixArray::findLongestCommonStrand(const unsigned int k){if(k<1||k>numStrings){cout<<"Given invalid k-value: "<<k<<endl;}vector<int> lcp=makeLCPArray();unsigned int length=lcp.size();set<int> offsets;unsigned int window1=numStrings;unsigned int window2=numStrings;map<int,int> suffixSourcesMap;suffixSourcesMap[calcParentString((*suffixArray)[window1])]+=1;int max=0;deque<int> window;auto decrementIndex=[](map<int,int>&map,int index){if(map[index]-1<=0)map.erase(index);else map[index]-=1;};auto updateMaxValue=[&](int index1,int index2){if((*str)[index1]==(*str)[index2]){if(lcp[window.front()]>max){max=lcp[window.front()];offsets.clear();offsets.insert(index1);}else if(lcp[window.front()]==max){offsets.insert(index2);}}};while(window1<length&&window2<length){int suffix1=(*suffixArray)[window1];int suffix2=(*suffixArray)[window2];if(suffixSourcesMap.size()>=k){updateMaxValue(suffix1,suffix2);decrementIndex(suffixSourcesMap,calcParentString(suffix1));window1+=1;if(window.front()<=window1)window.pop_front();}else if(++window2<length){suffixSourcesMap[calcParentString((*suffixArray)[window2])]+=1;while(!window.empty()&&lcp[window.back()]>=lcp[window2])window.pop_back();window.push_back(window2);}}int suffix2=*suffixArray->crbegin();while(++window1<length&&suffixSourcesMap.size()>=k){int suffix1=(*suffixArray)[window1];decrementIndex(suffixSourcesMap,calcParentString(suffix1-1));if(window.front()<=window1)window.pop_front();updateMaxValue(suffix1,suffix2);}for(auto it=offsets.begin();it!=offsets.end();it++)printSubStringVector(*str,*it,max);return max;}
int SuffixArray::calcParentString(int suffixOffset){if(suffixOffset>(*suffixArray)[0]){cerr<<"Offset is out of range: "<<suffixOffset<<endl;return -1;}if(numStrings<=1)return numStrings;int high=numStrings-1;int low=0;int mid=0;while(low<=high){mid=low+(high-low)/2;if((*suffixArray)[mid]==suffixOffset)return numStrings-mid;if((*suffixArray)[mid]>suffixOffset)low=mid+1;else high=mid-1;}if(suffixOffset>(*suffixArray)[mid])mid--;return numStrings-mid;}
template<typename T>void SuffixArray::printVector(vector<T> v){for(auto i=v.begin();i!=v.end();i++)cout<<*i<<' ';cout<<endl;}
template<typename T>void SuffixArray::printSubStringVector(vector<T> v,int offset,int length){if(offset+length<=v.size()){for(auto i=offset;i<offset+length;i++)cout<<(char)v.at(i)<<' ';cout<<endl;}else{cerr<<"Given offset & length for SubVector Print out of range"<<endl;cerr<<"Offset: "<<offset<<endl;cerr<<"Length: "<<length<<endl;cerr<<"Vector Size: "<<v.size()<<endl;}}
void SuffixArray::printSuffixArray(){cout<<"Suffix Array : ";printVector(*suffixArray);}
class SAIS:public SuffixArray{public:SAIS(){};void makeSuffixArray();bool addStringFromFile(string);bool addString(string);private:void SAIS_SA(vector<int>&,vector<int>&,vector<int>&);vector<int> fillBucket(vector<int>&,int);vector<bool> fillLTypeArray(const vector<int>&);vector<int> findBucketHeads(vector<int>&);vector<int> findBucketTails(vector<int>&);vector<int> guessLMSSort(const vector<int>&,vector<int>&,const vector<bool>&);vector<int> LMSsort(const vector<int>&,vector<int>&,const vector<bool>&,vector<int>&,vector<int>&);int summariseSuffixArray(const vector<int>&,vector<int>&,const vector<bool>&,vector<int>&,vector<int>&);vector<int> makeSummarySuffixArray(vector<int>&,int);void inducedSortL(const vector<int>&,vector<int>&,vector<int>&,const vector<bool>&);void inducedSortS(const vector<int>&,vector<int>&,vector<int>&,const vector<bool>&);bool isLMSChar(unsigned int,const vector<bool>&);bool isLMSSubstringsEqual(const vector<int>&,const vector<bool>&,unsigned int,unsigned int);};
bool SAIS::addStringFromFile(string fileName){if(numStrings+1>1)return false;SuffixArray::addStringFromFile(fileName);return true;}
bool SAIS::addString(string inputString){if(numStrings+1>1)return false;SuffixArray::addString(inputString);return true;}
void SAIS::makeSuffixArray(){vector<int> bucket=fillBucket(*str,maxAlphabetSize);SAIS_SA(*str,*suffixArray,bucket);suffix_array=*suffixArray;}
vector<int> SAIS::fillBucket(vector<int>&string,int alphabetSize){vector<int> bucketSize(alphabetSize,0);for(int i=0;i<string.size();i++)bucketSize[string[i]]++;return bucketSize;}
vector<bool> SAIS::fillLTypeArray(const vector<int>&string){vector<bool> target(string.size()+1,false);*target.rbegin()=false;if(string.size()==0)return target;*(target.rbegin()+1)=true;for(int i=target.size()-3;i>=0;i--){if(string[i]>string[i+1])target[i]=true;else if(string[i]==string[i+1]&&target[i+1])target[i]=true;else target[i]=false;}return target;}
vector<int> SAIS::findBucketHeads(vector<int>&bucket){unsigned int offset=1;unsigned int length=bucket.size();vector<int> result(length);for(auto i=0;i<bucket.size();++i){result[i]=offset;offset+=bucket[i];}return result;}
vector<int> SAIS::findBucketTails(vector<int>&bucket){unsigned int offset=1;unsigned int length=bucket.size();vector<int> result(length);for(auto i=0;i<bucket.size();++i){offset+=bucket[i];result[i]=offset-1;}return result;}
bool SAIS::isLMSChar(unsigned int offset,const vector<bool>&Ltype){if(offset==0)return false;if(!Ltype[offset]&&Ltype[offset-1])return true;return false;}
bool SAIS::isLMSSubstringsEqual(const vector<int>&string,const vector<bool>&Ltype,unsigned int offset1,unsigned int offset2){if(offset1==string.size()||offset2==string.size())return false;int i=0;while(true){bool firstIsLMS=isLMSChar(i+offset1,Ltype);bool secondIsLMS=isLMSChar(i+offset2,Ltype);if(i>0 and firstIsLMS&&secondIsLMS)return true;if(firstIsLMS!=secondIsLMS)return false;if(string[i+offset1]!=string[i+offset2])return false;i+=1;}}
void SAIS::SAIS_SA(vector<int>&string,vector<int>&target,vector<int>&bucket){vector<bool> LType=fillLTypeArray(string);vector<int> guess=guessLMSSort(string,bucket,LType);inducedSortL(string,guess,bucket,LType);inducedSortS(string,guess,bucket,LType);vector<int> summaryString;vector<int> summaryOffset;int summaryAlphabetSize=summariseSuffixArray(string,guess,LType,summaryString,summaryOffset);vector<int> summarySuffixArray=makeSummarySuffixArray(summaryString,summaryAlphabetSize);vector<int> finalSuffixArray=LMSsort(string,bucket,LType,summarySuffixArray,summaryOffset);inducedSortL(string,finalSuffixArray,bucket,LType);inducedSortS(string,finalSuffixArray,bucket,LType);target.assign(finalSuffixArray.begin(),finalSuffixArray.end());}
vector<int> SAIS::guessLMSSort(const vector<int>&string,vector<int>&bucket,const vector<bool>&Ltype){vector<int> guessSuffixArray(string.size()+1,-1);auto bucketTails=findBucketTails(bucket);for(int i=0;i<string.size();i++){if(isLMSChar(i,Ltype)){unsigned int bucketIndex=string[i];guessSuffixArray[bucketTails[bucketIndex]]=i;bucketTails[bucketIndex]-=1;}}guessSuffixArray[0]=string.size();return guessSuffixArray;}
void SAIS::inducedSortL(const vector<int>&string,vector<int>&target,vector<int>&bucket,const vector<bool>&Ltype){auto bucketHeads=findBucketHeads(bucket);for(auto i=0U;i<target.size();i++){if(target[i]==-1)continue;int j=target[i]-1;if(j<0)continue;if(!Ltype[j])continue;unsigned int bucketIndex=string[j];target[bucketHeads[bucketIndex]]=j;bucketHeads[bucketIndex]+=1;}}
void SAIS::inducedSortS(const vector<int>&string,vector<int>&target,vector<int>&bucket,const vector<bool>&Ltype){auto bucketTails=findBucketTails(bucket);for(int i=target.size()-1;i>=0;i--){int j=target[i]-1;if(j<0)continue;if(Ltype[j])continue;unsigned int bucketIndex=string[j];target[bucketTails[bucketIndex]]=j;bucketTails[bucketIndex]-=1;}}
int SAIS::summariseSuffixArray(const vector<int>&string,vector<int>&guessArray,const vector<bool>&Ltype,vector<int>&targetSummaryString,vector<int>&targetSummaryOffset){vector<int> lmsNames(string.size()+1,-1);int currentName=0;lmsNames[guessArray[0]]=currentName;int lastLMSSuffixOffset=guessArray[0];for(int i=1;i<guessArray.size();i++){int suffixOffset=guessArray[i];if(!isLMSChar(suffixOffset,Ltype))continue;if(!isLMSSubstringsEqual(string,Ltype,lastLMSSuffixOffset,suffixOffset))currentName+=1;lastLMSSuffixOffset=suffixOffset;lmsNames[suffixOffset]=currentName;}for(int i=0;i<lmsNames.size();i++){if(lmsNames[i]!=-1){targetSummaryOffset.push_back(i);targetSummaryString.push_back(lmsNames[i]);}}return currentName+1;}
vector<int> SAIS::makeSummarySuffixArray(vector<int>&summaryString,int summaryAlphabetSize){if(summaryAlphabetSize==summaryString.size()){vector<int> summarySuffixArray(summaryString.size()+1);summarySuffixArray[0]=summaryString.size();for(int i=0;i<summaryString.size();i++)summarySuffixArray[summaryString[i]+1]=i;return summarySuffixArray;}else{vector<int> bucket=fillBucket(summaryString,summaryAlphabetSize);vector<int> target;SAIS_SA(summaryString,target,bucket);return target;}}
vector<int> SAIS::LMSsort(const vector<int>&string,vector<int>&bucketSizes,const vector<bool>&Ltype,vector<int>&sumSuffixArray,vector<int>&sumOffsets){vector<int> suffixOffsets(string.size()+1,-1);vector<int> bucketTails=findBucketTails(bucketSizes);for(int i=sumSuffixArray.size()-1;i>1;--i){int stringIndex=sumOffsets[sumSuffixArray[i]];int bucketIndex=string[stringIndex];suffixOffsets[bucketTails[bucketIndex]]=stringIndex;bucketTails[bucketIndex]-=1;}suffixOffsets[0]=string.size();return suffixOffsets;}
bool pf_first(int mid,int idx,string&ptrn,string&str){int str_idx=suffix_array[mid]+idx;if(str_idx>=str.size())return false;if(str[str_idx]<ptrn[idx])return false;else return true;}
int first_occurance(int lo,int hi,int idx,string&ptrn,string&str){int mid;while(hi-lo>1){mid=(hi+lo)/2;if(pf_first(mid,idx,ptrn,str))hi=mid;else lo=mid+1;}if(pf_first(lo,idx,ptrn,str))return lo;else if(pf_first(hi,idx,ptrn,str))return hi;else return -1;}
bool pf_last(int mid,int idx,string&ptrn,string&str){int str_idx=suffix_array[mid]+idx;if(str_idx>=str.size())return true;if(str[str_idx]>ptrn[idx])return false;else return true;}
int last_occurance(int lo,int hi,int idx,string&ptrn,string&str){int mid;while(hi-lo>1){mid=(hi+lo)/2;if(pf_last(mid,idx,ptrn,str))lo=mid;else hi=mid-1;}if(pf_last(hi,idx,ptrn,str))return hi;else if(pf_last(lo,idx,ptrn,str))return lo;else return -1;}
void find_sub_string(string&sub_str,string&str){bool flag=true;int first_occ=0,last_occ=suffix_array.size()-1;for(int i=0;i<sub_str.size();i++){int val=first_occurance(first_occ,last_occ,i,sub_str,str);last_occ=last_occurance(first_occ,last_occ,i,sub_str,str);first_occ=val;if(first_occ==-1||last_occ==-1){flag=false;break;}}if(flag)cout<<first_occ<<gap<<last_occ<<endl;else cout<<-1<<endl;}
## Data_Structures/Segment_Tree_2D.cpp
struct Node { ll value; Node() : value(0) {} };
class segment_tree_2D {
private:
ll rows, cols;vector<vector<Node>> tree;
ll combine(ll a, ll b) { return a + b; }
void buildY(ll vx,ll lx,ll rx,ll vy,ll ly,ll ry,const vector<vector<ll>> &arr) {if(ly==ry){ if(lx==rx) tree[vx][vy].value=arr[lx][ly]; else tree[vx][vy].value=combine(tree[vx*2][vy].value,tree[vx*2+1][vy].value); }else{ ll my=(ly+ry)/2; buildY(vx,lx,rx,vy*2,ly,my,arr); buildY(vx,lx,rx,vy*2+1,my+1,ry,arr); tree[vx][vy].value=combine(tree[vx][vy*2].value,tree[vx][vy*2+1].value); } }
void buildX(ll vx,ll lx,ll rx,const vector<vector<ll>> &arr) { if(lx!=rx){ ll mx=(lx+rx)/2; buildX(vx*2,lx,mx,arr); buildX(vx*2+1,mx+1,rx,arr); } buildY(vx,lx,rx,1,0,cols-1,arr); }
ll queryY(ll vx,ll vy,ll tly,ll try_,ll ly,ll ry) { if(ly>ry) return 0; if(ly==tly && try_==ry) return tree[vx][vy].value; ll tmy=(tly+try_)/2; return combine(queryY(vx,vy*2,tly,tmy,ly,min(ry,tmy)),queryY(vx,vy*2+1,tmy+1,try_,max(ly,tmy+1),ry)); }
ll queryX(ll vx,ll tlx,ll trx,ll lx,ll rx,ll ly,ll ry) { if(lx>rx) return 0; if(lx==tlx && trx==rx) return queryY(vx,1,0,cols-1,ly,ry); ll tmx=(tlx+trx)/2; return combine(queryX(vx*2,tlx,tmx,lx,min(rx,tmx),ly,ry),queryX(vx*2+1,tmx+1,trx,max(lx,tmx+1),rx,ly,ry)); }
void updateY(ll vx,ll lx,ll rx,ll vy,ll ly,ll ry,ll x,ll y,ll new_val) { if(ly==ry){ if(lx==rx) tree[vx][vy].value=new_val; else tree[vx][vy].value=combine(tree[vx*2][vy].value,tree[vx*2+1][vy].value); } else{ ll my=(ly+ry)/2; if(y<=my) updateY(vx,lx,rx,vy*2,ly,my,x,y,new_val); else updateY(vx,lx,rx,vy*2+1,my+1,ry,x,y,new_val); tree[vx][vy].value=combine(tree[vx][vy*2].value,tree[vx][vy*2+1].value); } }
void updateX(ll vx,ll lx,ll rx,ll x,ll y,ll new_val) { if(lx!=rx){ ll mx=(lx+rx)/2; if(x<=mx) updateX(vx*2,lx,mx,x,y,new_val); else updateX(vx*2+1,mx+1,rx,x,y,new_val); } updateY(vx,lx,rx,1,0,cols-1,x,y,new_val); }
public:
segment_tree_2D(const vector<vector<ll>> &arr){ rows=arr.size(); cols=arr[0].size(); tree.resize(4*rows); for(ll i=0;i<4*rows;++i) tree[i].resize(4*cols); buildX(1,0,rows-1,arr); }
ll query(ll lx,ll rx,ll ly,ll ry){ return queryX(1,0,rows-1,lx,rx,ly,ry); }
void update(ll x,ll y,ll new_val){ updateX(1,0,rows-1,x,y,new_val); } };
## Data_Structures/Lazy_Segment_Tree.cpp
template<class T> class lazy_segment_tree {
private:
ll N=0,root=1,tla=0,tra=0;vector<T> t,lazy,lazy2;
T combine(T a,T b){ return a+b; }
void push(ll v,ll tl,ll tm,ll tr){ if(lazy[v]>0 && lazy2[v]>0){ t[v*2]=(tm-tl+1)*lazy2[v]+(tm-tl+1)*lazy[v]; lazy2[v*2]=lazy2[v]; lazy[v*2]=lazy[v]; t[v*2+1]=(tr-tm)*lazy2[v]+(tr-tm)*lazy[v]; lazy2[v*2+1]=lazy2[v]; lazy[v*2+1]=lazy[v]; lazy2[v]=0; lazy[v]=0; } else if(lazy[v]>0){ t[v*2]+=(tm-tl+1)*lazy[v]; lazy[v*2]+=lazy[v]; t[v*2+1]+=(tr-tm)*lazy[v]; lazy[v*2+1]+=lazy[v]; lazy[v]=0; } else if(lazy2[v]>0){ t[v*2]=(tm-tl+1)*lazy2[v]; lazy2[v*2]=lazy2[v]; t[v*2+1]=(tr-tm)*lazy2[v]; lazy2[v*2+1]=lazy2[v]; lazy2[v]=0; lazy[v*2]=lazy[v*2+1]=0; } }
void build(vector<T> &a,ll v,ll tl,ll tr){ if(tl==tr) t[v]=a[tl]; else{ ll tm=(tl+tr)/2; build(a,v*2,tl,tm); build(a,v*2+1,tm+1,tr); t[v]=combine(t[v*2],t[v*2+1]); } }
T query(ll v,ll tl,ll tr,ll l,ll r){ if(l>r) return 0; if(l==tl && r==tr) return t[v]; ll tm=(tl+tr)/2; push(v,tl,tm,tr); return combine(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r)); }
void update(ll v,ll tl,ll tr,ll l,ll r,T val,ll op){ if(l>r) return; if(l==tl && r==tr){ if(op==1){ t[v]+=(r-l+1)*val; lazy[v]+=val; } else if(op==2){ t[v]=(r-l+1)*val; lazy[v]=0; lazy2[v]=val; } } else{ ll tm=(tl+tr)/2; push(v,tl,tm,tr); update(v*2,tl,tm,l,min(r,tm),val,op); update(v*2+1,tm+1,tr,max(l,tm+1),r,val,op); t[v]=combine(t[v*2],t[v*2+1]); } }
public:
lazy_segment_tree() {}
lazy_segment_tree(vector<T> &a){ build(a); }
void build(vector<T> &a){ clear(); N=a.size()+1; tla=0,tra=a.size()-1; t.assign(4*N,0); lazy.assign(4*N,0); lazy2.assign(4*N,0); build(a,1,tla,tra); }
T query(ll l,ll r){ return query(root,tla,tra,l,r); }
void update(ll l,ll r,T add_val,ll op){ update(root,tla,tra,l,r,add_val,op); }
void clear(){ t.clear(); lazy.clear(); lazy2.clear(); N=0,tra=0,tla=0; }
~lazy_segment_tree(){ clear(); } };
## Data_Structures/Fenwick_Tree.cpp
template<class T> class fenwick_tree {
private:
int N; vector<T> bit;
T sum(int r){ T ret=0; for(;r>=0;r=(r&(r+1))-1) ret+=bit[r]; return ret; }
public:
fenwick_tree(){} fenwick_tree(vector<T> &a){ build(a); }
void build(vector<T> &a){ N=a.size(); bit.assign(N,0); for(int i=0;i<a.size();i++) add(i,a[i]); }
T sum(int l,int r){ return sum(r)-sum(l-1); }
void add(int pos,int add_val){ for(;pos<N;pos=pos|(pos+1)) bit[pos]+=add_val; } };
## Data_Structures/Disjoint_Set_Union.cpp
class dsu {
private:
int N=0; vector<int> parrents,ranks;
public:
dsu(int n){ build(n); }
void build(int n){ clear(); N=n; parrents.assign(n+1,0); ranks.assign(n+1,0); for(int i=1;i<=n;i++){ parrents[i]=i; ranks[i]=0; } }
int Find(int v){ if(v==parrents[v]) return v; return parrents[v]=Find(parrents[v]); }
void Union(int a,int b){ a=Find(a); b=Find(b); if(a!=b){ if(ranks[a]<ranks[b]) swap(a,b); parrents[b]=a; if(ranks[a]==ranks[b]) ranks[a]++; } }
void clear(){ parrents.clear(); ranks.clear(); N=0; }
~dsu(){ clear(); } };
## Data_Structures/Segment_Tree.cpp
template<class T> class segment_tree {
private:
ll N=0,root=1,tla=0,tra=0; vector<T> t;
T combine(T a,T b){ return a+b; }
void build(vector<T> &a,ll v,ll tl,ll tr){ if(tl==tr) t[v]=a[tl]; else{ ll tm=(tl+tr)/2; build(a,v*2,tl,tm); build(a,v*2+1,tm+1,tr); t[v]=combine(t[v*2],t[v*2+1]); } }
T query(ll v,ll tl,ll tr,ll l,ll r){ if(l>r) return 0; if(l==tl && r==tr) return t[v]; ll tm=(tl+tr)/2; return combine(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r)); }
void update(ll v,ll tl,ll tr,ll pos,T new_val){ if(tl==tr) t[v]=new_val; else{ ll tm=(tl+tr)/2; if(pos<=tm) update(v*2,tl,tm,pos,new_val); else update(v*2+1,tm+1,tr,pos,new_val); t[v]=combine(t[v*2],t[v*2+1]); } }
public:
segment_tree(){} segment_tree(vector<T> &a){ build(a); }
void build(vector<T> &a){ clear(); N=a.size()+1; tla=0,tra=a.size()-1; t.assign(4*N,0); build(a,1,tla,tra); }
T query(ll l,ll r){ return query(root,tla,tra,l,r); }
void update(ll pos,T new_val){ update(root,tla,tra,pos,new_val); }
void clear(){ t.clear(); N=0; tra=0; tla=0; }
~segment_tree(){ clear(); } };
## Searches/Binary_Search.cpp
ll hi, lo, mid;
while (hi - lo > 1) /*FFFFTTT find first true */ { mid = (hi + lo) / 2; if (pf(mid)) hi = mid; else lo = lo + 1; } if (pf(lo)) cout << lo << endl; else cout << hi << endl;
while (hi - lo > 1) /*TTTTFFF find last true */ { mid = (hi + lo) / 2; if (pf(mid)) lo = mid; else hi = hi - 1; } if (pf(hi)) cout << hi << endl; else cout << lo << endl;
## Searches/Ternary_Search.cpp
lld lo, hi;
while (hi - lo > 1e-7) /*finding minimum */ { lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3; lld ans1 = fun(mid1), ans2 = fun(mid2); if (ans1 < ans2) hi = mid2; else if (ans1 > ans2) lo = mid1; else { hi = mid2; lo = mid1; } }
while (hi - lo > 1e-7) /*finding maximum */ { lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3; lld ans1 = fun(mid1), ans2 = fun(mid2); if (ans1 < ans2) lo = mid1; else if (ans1 > ans2) hi = mid2; else { hi = mid2; lo = mid1; } }
## Others/dubug.cpp
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char *names, Arg1 arg1, Args... args) { const char *comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...); }
## Others/All_Subset_Generation.cpp
vector<vector<ll>> subsetgen(vector<ll> &nums) { ll n = nums.size(); ll subsetCount = 1 << n; vector<vector<ll>> subsets; for (ll mask = 0; mask < subsetCount; ++mask) { vector<ll> subset; for (ll i = 0; i < n; ++i) { if (mask & (1 << i)) subset.push_back(nums[i]); } subsets.push_back(subset); } return subsets; }
## Math/Modular_Arithmetic_and_nCr_nPr.cpp
ll binExp(ll a, ll b, ll mod) { if (b == 0) return 1; ll rec = binExp(a, b / 2, mod); if (b % 2 != 0) return ((a % mod) * (rec % mod) % mod) * (rec % mod) % mod; else return (rec % mod) * (rec % mod) % mod; }
ll modMulInv(ll n, ll mod) { return binExp(n, mod - 2, mod) % mod; }
ll abybmod(ll a, ll b, ll mod) { ll ans = a; ans %= mod; ans *= modMulInv(b, mod); ans %= mod; return ans; }
ll nPr(ll n, ll r, ll mod) { ll nfact = 1, n_rfact = 1; for (int i = 1; i <= n; i++) { nfact *= i; nfact %= mod; } for (int i = 1; i <= n - r; i++) { n_rfact *= i; n_rfact %= mod; } ll ans = abybmod(nfact, n_rfact, mod); return ans; }
ll nCr(ll n, ll r, ll mod) { ll nfact = 1, rfact = 1, n_rfact = 1; for (int i = 1; i <= n; i++) { nfact *= i; nfact %= mod; } for (int i = 1; i <= r; i++) { rfact *= i; rfact %= mod; } for (int i = 1; i <= n - r; i++) { n_rfact *= i; n_rfact %= mod; } ll ans = abybmod(nfact, rfact, mod); ans = abybmod(ans, n_rfact, mod); return ans; }
## Math/Matrix_Exponentiation.cpp /*square matrix nXn*/
vector<vector<ll>> matrix_multiplication(vector<vector<ll>> &a, vector<vector<ll>> &b, ll n) { vector<vector<ll>> ans(n, vector<ll>(n, 0)); for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { for (int k = 0; k < n; k++) { ans[i][j] += a[i][k] * b[k][j]; } } } return ans; }
vector<vector<ll>> binExp(vector<vector<ll>> &a, ll b, ll n) { if (b == 1) return a; vector<vector<ll>> ans = binExp(a, b / 2, n); if (b % 2 != 0) { vector<vector<ll>> v = matrix_multiplication(ans, ans, n); return matrix_multiplication(v, a, n); } else return matrix_multiplication(ans, ans, n); }
## Math/Sieve_Algorithm.cpp
const ll N = 1e7 + 1; vector<bool> isPrime(N, true); vector<ll> allPrimes; vector<ll> lowestPrimeFactorOf(N, 0); vector<ll> highestPrimeFactorOf(N, 0);
void calculateSieve() { isPrime[0] = isPrime[1] = false; for (int i = 2; i < N; i++) { if (isPrime[i]) { highestPrimeFactorOf[i] = lowestPrimeFactorOf[i] = i; for (int j = 2 * i; j < N; j += i) { isPrime[j] = false; highestPrimeFactorOf[j] = i; if (lowestPrimeFactorOf[j] == 0) lowestPrimeFactorOf[j] = i; } } } for (int i = 0; i < N; i++) { if (isPrime[i]) allPrimes.push_back(i); } }
vector<ll> getPrimeFactorsOf(ll n) { vector<ll> distinctPrimeFactors; vector<ll> primeFactors; /*if max_element <= 1e7 then use this snippet where N = 1e7 + 1*/ while (n > 1) { ll pf = lowestPrimeFactorOf[n]; distinctPrimeFactors.push_back(pf); while (n % pf == 0) { primeFactors.push_back(pf); n /= pf; } } return distinctPrimeFactors; /*if max_element <= 1e9 then use this snippet where N = 31625 for (int i = 0; i < allPrimes.size(); i++){ll pf = allPrimes[i];if (n % pf == 0){distinctPrimeFactors.push_back(pf);while (n % pf == 0){primeFactors.push_back(pf);n /= pf;}}else if (n < pf)break;}if (n != 1){distinctPrimeFactors.push_back(n);primeFactors.push_back(n);} return distinctPrimeFactors; */ }
## Graph/Graph_Mapping_Matrix_to_Adjacency_List.cpp
vector<vector<ll>> grid_to_arr; vector<pair<ll,ll>> arr_to_grid;
vector<vector<ll>> grid_mapped_arr(ll n,ll m){grid_to_arr.assign(n+1,vector<ll>(m+1,0)); arr_to_grid.assign((n+1)*(m+1),{0,0}); ll k=1; for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){grid_to_arr[i][j]=k; arr_to_grid[k]={i,j}; k++;}} vector<vector<ll>> graph(k); for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){if(i>1)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i-1][j]); if(j>1)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j-1]); if(i<n)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i+1][j]); if(j<m)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i][j+1]); if(i>1&&j>1)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i-1][j-1]); if(i<n&&j>1)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i+1][j-1]); if(i<n&&j<n)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i+1][j+1]); if(i>1&&j<n)graph[grid_to_arr[i][j]].push_back(grid_to_arr[i-1][j+1]);}} return graph;}
## Graph/Least_Common_Ancestor.cpp
pair<ll,ll> func(ll n){ll k=log2(n); return {k,powl(2,k)};} 
vector<vector<ll>> bin_lift; vector<ll> next_child;
void bin_lift_func(ll vertex,vector<vector<ll>> &graph,vector<bool> &isVisited,vector<ll> parv,ll level){isVisited[vertex]=true; if(level>0){for(auto x:parv)bin_lift[vertex].push_back(next_child[x]); pair<ll,ll> pr=func(level); if(pr.second==level)bin_lift[vertex].push_back(1);} for(auto x:graph[vertex]){if(!isVisited[x]){next_child[vertex]=x; bin_lift_func(x,graph,isVisited,bin_lift[vertex],level+1);}}}
ll get_kth_parrent(ll node,ll kth_parrent){while(1){pair<ll,ll> pr=func(kth_parrent); ll pow_2=pr.first,powl_=pr.second; if(powl_==kth_parrent && pow_2<bin_lift[node].size())return bin_lift[node][pow_2]; else if(pow_2<bin_lift[node].size()){node=bin_lift[node][pow_2]; kth_parrent-=powl_;} else return -1;}}
vector<ll> start_time,end_time,level_of; ll time_=0;
void calc_time(ll vertex,vector<vector<ll>> &graph,vector<bool> &isVisited,ll level){isVisited[vertex]=true; level_of[vertex]=level; time_++; start_time[vertex]=time_; for(auto x:graph[vertex]){if(!isVisited[x])calc_time(x,graph,isVisited,level+1);} time_++; end_time[vertex]=time_;}
ll least_common_ancestor(ll u,ll v){if(start_time[u]<=start_time[v]&&end_time[u]>=end_time[v])return u; else if(start_time[v]<=start_time[u]&&end_time[v]>=end_time[u])return v; ll lca=u; while(1){ll dum; for(int i=0;i<bin_lift[lca].size();i++){ll k=bin_lift[lca][i]; if(start_time[k]<start_time[v]&&end_time[k]>end_time[v]){if(i==0)return k; else break;} else dum=k;} lca=dum;} return lca;}
void init(ll n){vector<ll> v; bin_lift.assign(n+1,v); next_child.assign(n+1,0); start_time.assign(n+1,0); end_time.assign(n+1,0); level_of.assign(n+1,0);}
void pre_processing(ll number_of_nodes,vector<vector<ll>> &graph,ll root){init(number_of_nodes); vector<bool> isVIsited(number_of_nodes+1,false); vector<ll> v; bin_lift_func(root,graph,isVIsited,v,0); isVIsited.assign(number_of_nodes+1,false); calc_time(root,graph,isVIsited,0);}
## Graph/Maximum_Flow.cpp
int edmondsKarp(vector<vector<int>> &graph,int source,int sink,vector<vector<int>> &edge_capacity){int n=graph.size(),max_flow=0; while(1){vector<bool> isVisited(n,false); vector<int> parrents(n,0); queue<int> q; isVisited[source]=true; parrents[source]=source; q.push(source); while(q.size()){int vertex=q.front(); q.pop(); for(auto x:graph[vertex]){if(edge_capacity[vertex][x]>0&&!isVisited[x]){q.push(x); isVisited[x]=true; parrents[x]=vertex;}}} if(parrents[sink]==0)break; vector<int> path; int node=sink; while(node!=source){path.push_back(node); node=parrents[node];} path.push_back(source); reverse(path.begin(),path.end()); int bottle_neck=INT32_MAX; for(int i=0;i<path.size()-1;i++)bottle_neck=min(bottle_neck,edge_capacity[path[i]][path[i+1]]); for(int i=0;i<path.size()-1;i++){edge_capacity[path[i]][path[i+1]]-=bottle_neck; edge_capacity[path[i+1]][path[i]]+=bottle_neck;} max_flow+=bottle_neck;} return max_flow;}
## Graph/All_Pairs_Shortest_Path.cpp
vector<vector<int>> shortest_distance,graph;
void floydwarshall(int n){for(int i=1;i<=n;i++){for(int u=1;u<=n;u++){for(int v=1;v<=n;v++){shortest_distance[u][v]=min(shortest_distance[u][v],shortest_distance[u][i]+shortest_distance[i][v]);}}}}
## Graph/Strongly_Connected_Components.cpp
ll time_=0; vector<ll> start_t,end_t; vector<ll> nodes; vector<vector<ll>> all_scc; vector<ll> map_scc_index;
void scc_dfs(ll vertex,vector<vector<ll>> &graph,vector<bool> &isVisited){isVisited[vertex]=true; time_++; start_t[vertex]=time_; for(auto x:graph[vertex])if(!isVisited[x])scc_dfs(x,graph,isVisited); time_++; end_t[vertex]=time_;}
void scc_dfs_2(ll vertex,vector<vector<ll>> &graph,vector<bool> &isVisited){isVisited[vertex]=true; nodes.push_back(vertex); for(auto x:graph[vertex])if(!isVisited[x])scc_dfs_2(x,graph,isVisited);}
void strongly_connnected_components(ll n,vector<pair<ll,ll>> &edge_list){ll i; start_t.assign(n+1,0); end_t.assign(n+1,0); map_scc_index.assign(n+1,0); vector<vector<ll>> graph(n+1),graph_t(n+1); for(auto x:edge_list){graph[x.first].push_back(x.second); graph_t[x.second].push_back(x.first);} vector<bool> isVisited(n+1,false); for(i=1;i<=n;i++)if(!isVisited[i])scc_dfs(i,graph,isVisited); isVisited.assign(n+1,false); vector<pair<ll,ll>> vp; for(i=1;i<=n;i++)vp.push_back({end_t[i],i}); sort(vp.begin(),vp.end()); reverse(vp.begin(),vp.end()); all_scc.push_back(vector<ll>(0)); i=1; for(auto x:vp){if(!isVisited[x.second]){nodes.clear(); scc_dfs_2(x.second,graph_t,isVisited); all_scc.push_back(nodes); for(auto y:nodes)map_scc_index[y]=i; i++;}}}
## Graph/Shortest_Path_Using_BFS.cpp
vector<ll> Parents,Distance; ll Source;
void bfs(ll source,vector<vector<ll>> &graph,vector<bool> &isVisited){Parents.clear(); Distance.clear(); Parents.assign(isVisited.size(),0); Distance.assign(isVisited.size(),0); Source=source; queue<ll> q; isVisited[source]=true; q.push(source); while(q.size()){ll vertex=q.front(); q.pop(); for(auto x:graph[vertex])if(!isVisited[x]){q.push(x); isVisited[x]=true; Parents[x]=vertex; Distance[x]=Distance[vertex]+1;}}}
vector<ll> shortest_path(ll destination){ll source=Source; vector<ll> path; ll node=destination; while(node!=source){path.push_back(node); node=Parents[node];} path.push_back(source); reverse(path.begin(),path.end()); return path;}
## Graph/BFS.cpp
void bfs(ll source,vector<vector<ll>> &graph,vector<bool> &isVisited){queue<ll> q; isVisited[source]=true; q.push(source); while(q.size()){ll vertex=q.front(); q.pop(); for(auto x:graph[vertex])if(!isVisited[x]){q.push(x); isVisited[x]=true;}}}
## Graph/Heavt_Light_Decomposition.cpp
vector<ll> subtree_size,parrent,max_subtree_size; vector<vector<ll>> sgv; vector<pair<ll,ll>> info; vector<segment_tree<ll>> vec_of_sg;
void dfs(ll vertex,vector<vector<ll>> &graph,vector<bool> &isVisited){isVisited[vertex]=true; ll mx_subtree_sz=0; for(auto x:graph[vertex]){if(!isVisited[x]){dfs(x,graph,isVisited); subtree_size[vertex]+=subtree_size[x]; parrent[x]=vertex; if(mx_subtree_sz<subtree_size[x]){max_subtree_size[vertex]=x; mx_subtree_sz=subtree_size[x];}}}} 
void dfs_2(ll vertex,vector<vector<ll>> &graph,vector<bool> &isVisited,ll &ind){isVisited[vertex]=true; ll max_sbtreenode=max_subtree_size[vertex]; if(max_sbtreenode){info[max_sbtreenode].first=ind; info[max_sbtreenode].second=sgv[ind].size(); sgv[ind].push_back(max_sbtreenode); dfs_2(max_sbtreenode,graph,isVisited,ind);} for(auto x:graph[vertex]){if(!isVisited[x]){info[x].first=ind; info[x].second=sgv[ind].size(); sgv[ind].push_back(x); dfs_2(x,graph,isVisited,ind);}} if(graph[vertex].size()==1 && graph[vertex].front()==parrent[vertex])ind++;}
void HLD_preprocessing(vector<vector<ll>> &graph,vector<ll> &valv,ll n,ll root){sgv.assign(n+1,vector<ll>(0)); subtree_size.assign(n+1,1); max_subtree_size.assign(n+1,0); parrent.assign(n+1,0); info.assign(n+1,make_pair(0,0)); vector<bool> isVisited(n+1,false); dfs(root,graph,isVisited); isVisited.assign(n+1,false); ll ind=0; sgv[ind].push_back(root); dfs_2(root,graph,isVisited,ind); for(auto x:sgv){if(x.size()==0)continue; vector<ll> vec=x; for(ll i=0;i<vec.size();i++)vec[i]=valv[vec[i]]; segment_tree<ll> sg(vec); vec_of_sg.push_back(sg);}}
ll HLD_query(ll a,ll b){ll lca=least_common_ancestor(a,b),qr=0; bool flag_a=true,flag_b=true; while(flag_a||flag_b){if(flag_a){ll sg_a=info[a].first,sg_lca=info[lca].first; if(sg_a==sg_lca){qr=max(qr,vec_of_sg[sg_a].query(info[lca].second,info[a].second)); flag_a=false;} else{qr=max(qr,vec_of_sg[sg_a].query(0,info[a].second)); a=parrent[sgv[sg_a][0]];}} if(flag_b){ll sg_b=info[b].first,sg_lca=info[lca].first; if(sg_b==sg_lca){qr=max(qr,vec_of_sg[sg_b].query(info[lca].second,info[b].second)); flag_b=false;} else{qr=max(qr,vec_of_sg[sg_b].query(0,info[b].second)); b=parrent[sgv[sg_b][0]];}}} return qr;}
void HLD_update(ll node,ll val){ll sg_node=info[node].first,pos=info[node].second; vec_of_sg[sg_node].update(pos,val);}
## Graph/Single_Source_Shortest_Path.cpp
vector<int> parrents_dijkstra,distance_dijkstra;
void dijkstra(vector<vector<pair<int,int>>> &graph,int source){int n=graph.size(); parrents_dijkstra.assign(n,-1); distance_dijkstra.assign(n,99999999); distance_dijkstra[source]=0; parrents_dijkstra[source]=source; vector<bool> isDone(n,false); set<pair<int,int>> pq; pq.insert({distance_dijkstra[source],source}); while(pq.size()){pair<int,int> p=*pq.begin(); pq.erase(pq.begin()); int cost=p.first; if(isDone[p.second])continue; isDone[p.second]=true; for(auto x:graph[p.second]){if(cost+x.second<distance_dijkstra[x.first]){distance_dijkstra[x.first]=cost+x.second; parrents_dijkstra[x.first]=p.second; pq.insert({distance_dijkstra[x.first],x.first});}}}}
vector<int> shortest_path_dijkstra(int source,int destination){vector<int> path; int node=destination; while(node!=source){path.push_back(node); node=parrents_dijkstra[node];} path.push_back(source); reverse(path.begin(),path.end()); return path;}
bool isCyclePresent=false; vector<int> parrents_bellman_ford,distance_bellman_ford;
void bellman_ford(vector<pair<pair<int,int>,int>> &edge_list,int source,int n){parrents_bellman_ford.assign(n+1,-1); distance_bellman_ford.assign(n+1,99999999); parrents_bellman_ford[source]=source; distance_bellman_ford[source]=0; int limit=n-1; while(limit--){for(auto x:edge_list)if(distance_bellman_ford[x.first.first]+x.second<distance_bellman_ford[x.first.second]){distance_bellman_ford[x.first.second]=distance_bellman_ford[x.first.first]+x.second; parrents_bellman_ford[x.first.second]=x.first.first;}} vector<int> check=distance_bellman_ford; for(auto x:edge_list)if(distance_bellman_ford[x.first.first]+x.second<distance_bellman_ford[x.first.second]){distance_bellman_ford[x.first.second]=distance_bellman_ford[x.first.first]+x.second; parrents_bellman_ford[x.first.second]=x.first.first;} if(check!=distance_bellman_ford)isCyclePresent=true;}
vector<int> shortest_path_bellman_ford(int source,int destination){vector<int> path; int node=destination; while(node!=source){path.push_back(node); node=parrents_bellman_ford[node];} path.push_back(source); reverse(path.begin(),path.end()); return path;}
## Graph/Bridges_of_a_graph.cpp
void bridgedfs(ll vertex,vector<vector<ll>> &graph,vector<bool> &isVisited,vector<ll> &start,vector<ll> &low,vector<ll> &parrents,ll &timer,vector<pair<ll,ll>> &ret){isVisited[vertex]=true; start[vertex]=timer++; low[vertex]=start[vertex]; for(auto x:graph[vertex]){if(!isVisited[x]){parrents[x]=vertex; bridgedfs(x,graph,isVisited,start,low,parrents,timer,ret);} if(parrents[vertex]!=x)low[vertex]=min(low[vertex],low[x]);} if(low[vertex]>start[parrents[vertex]] && vertex>1)ret.push_back({min(vertex,parrents[vertex]),max(vertex,parrents[vertex])});}
vector<pair<ll,ll>> bridges(vector<vector<ll>> &graph){ll n=graph.size()-1,timer=1; vector<ll> start(n+1,0),low(n+1); vector<ll> parrents(n+1,0); vector<bool> isVisited(n+1,false); vector<pair<ll,ll>> ret; bridgedfs(1,graph,isVisited,start,low,parrents,timer,ret); return ret;}
