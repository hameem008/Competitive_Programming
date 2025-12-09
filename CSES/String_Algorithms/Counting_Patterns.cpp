#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define gap ' '
typedef long long ll;
typedef long double lld;
const ll infinite = INT64_MAX;

string str;
vector<int> suffix_array;
class SuffixArray
{
public:
    SuffixArray();
    ~SuffixArray();
    virtual void makeSuffixArray() = 0;
    virtual bool addStringFromFile(string);
    virtual bool addString(string);
    vector<int> makeLCPArray();
    int findLongestCommonStrand(const unsigned int);
    int calcParentString(int);
    void printSuffixArray();

protected:
    const int maxAlphabetSize = 256;
    int numStrings;
    vector<int> *suffixArray;
    vector<int> *str;
    template <typename T>
    void printVector(vector<T> v);
    template <typename T>
    void printSubStringVector(vector<T> v, int offset, int length);
};

SuffixArray::SuffixArray()
{
    numStrings = 0;
    suffixArray = new vector<int>;
    str = new vector<int>;
}

SuffixArray::~SuffixArray()
{
    delete suffixArray;
    delete str;
}

bool SuffixArray::addString(string inputString)
{
    for (auto it = inputString.cbegin(); it != inputString.cend(); it++)
        str->push_back(*it);
    numStrings += 1;
    return true;
}

bool SuffixArray::addStringFromFile(string fileName)
{
    ifstream fin(fileName, ios::binary);
    if (!fin)
    {
        cerr << "Could not read file from: " << fileName << endl;
        return false;
    }
    fin.unsetf(ios::skipws);
    fin.seekg(0, ios::end);
    streampos length = fin.tellg();
    fin.seekg(0, ios::beg);
    str->reserve(length);
    int i = 0;
    char *temp = new char;
    while (i < length)
    {
        fin.read(temp, sizeof(*temp));
        str->push_back(reinterpret_cast<unsigned char &>(*temp));
        i++;
    }
    delete temp;
    numStrings += 1;
    return true;
}

vector<int> SuffixArray::makeLCPArray()
{
    int length = suffixArray->size();
    vector<int> lcp(length, 0);
    vector<int> invertedSuffixArray(length, 0);
    int l = 0;
    for (int i = 0; i < length; i++)
        invertedSuffixArray[(*suffixArray)[i]] = i;
    for (int i = 0; i < length - 1; i++)
    {
        int k = invertedSuffixArray[i];
        int j = (*suffixArray)[k - 1];
        while ((*str)[i + l] == (*str)[j + l])
            l += 1;
        lcp[k] = l;
        if (l > 0)
            l -= 1;
    }
    return lcp;
}

int SuffixArray::findLongestCommonStrand(const unsigned int k)
{
    if (k < 1 || k > numStrings)
    {
        cout << "Given invalid k-value: " << k << endl;
    }
    vector<int> lcp = makeLCPArray();
    unsigned int length = lcp.size();
    set<int> offsets;
    unsigned int window1 = numStrings;
    unsigned int window2 = numStrings;
    map<int, int> suffixSourcesMap;
    suffixSourcesMap[calcParentString((*suffixArray)[window1])] += 1;
    int max = 0;
    deque<int> window;
    auto decrementIndex = [](map<int, int> &map, int index)
    {
        if (map[index] - 1 <= 0)
            map.erase(index);
        else
            map[index] -= 1;
    };
    auto updateMaxValue = [&](int index1, int index2)
    {
        if ((*str)[index1] == (*str)[index2])
        {
            if (lcp[window.front()] > max)
            {
                max = lcp[window.front()];
                offsets.clear();
                offsets.insert(index1);
            }
            else if (lcp[window.front()] == max)
            {
                offsets.insert(index2);
            }
        }
    };
    while (window1 < length && window2 < length)
    {
        int suffix1 = (*suffixArray)[window1];
        int suffix2 = (*suffixArray)[window2];
        if (suffixSourcesMap.size() >= k)
        {
            updateMaxValue(suffix1, suffix2);
            decrementIndex(suffixSourcesMap, calcParentString(suffix1));
            window1 += 1;
            if (window.front() <= window1)
                window.pop_front();
        }
        else if (++window2 < length)
        {
            suffixSourcesMap[calcParentString((*suffixArray)[window2])] += 1;
            while (!window.empty() && lcp[window.back()] >= lcp[window2])
                window.pop_back();
            window.push_back(window2);
        }
    }
    int suffix2 = *suffixArray->crbegin();
    while (++window1 < length && suffixSourcesMap.size() >= k)
    {
        int suffix1 = (*suffixArray)[window1];
        decrementIndex(suffixSourcesMap, calcParentString(suffix1 - 1));
        if (window.front() <= window1)
            window.pop_front();
        updateMaxValue(suffix1, suffix2);
    }
    for (auto it = offsets.begin(); it != offsets.end(); it++)
        printSubStringVector(*str, *it, max);
    return max;
}

int SuffixArray::calcParentString(int suffixOffset)
{
    if (suffixOffset > (*suffixArray)[0])
    {
        cerr << "Offset is out of range: " << suffixOffset << endl;
        return -1;
    }
    if (numStrings <= 1)
        return numStrings;
    int high = numStrings - 1;
    int low = 0;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if ((*suffixArray)[mid] == suffixOffset)
            return numStrings - mid;
        if ((*suffixArray)[mid] > suffixOffset)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (suffixOffset > (*suffixArray)[mid])
        mid--;
    return numStrings - mid;
}

template <typename T>
void SuffixArray::printVector(vector<T> v)
{
    suffix_array.clear();
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << ' ';
    cout << endl;
}

template <typename T>
void SuffixArray::printSubStringVector(vector<T> v, int offset, int length)
{
    if (offset + length <= v.size())
    {
        for (auto i = offset; i < offset + length; i++)
            cout << (char)v.at(i) << ' ';
        cout << endl;
    }
    else
    {
        cerr << "Given offset & length for SubVector Print out of range" << endl;
        cerr << "Offset: " << offset << endl;
        cerr << "Length: " << length << endl;
        cerr << "Vector Size: " << v.size() << endl;
    }
}

void SuffixArray::printSuffixArray()
{
    cout << "Suffix Array : ";
    printVector(*suffixArray);
}

class SAIS : public SuffixArray
{
public:
    SAIS() {};
    void makeSuffixArray();
    bool addStringFromFile(string);
    bool addString(string);

private:
    void SAIS_SA(vector<int> &, vector<int> &target, vector<int> &);
    vector<int> fillBucket(vector<int> &, int alphabetSize);
    vector<bool> fillLTypeArray(const vector<int> &);
    vector<int> findBucketHeads(vector<int> &);
    vector<int> findBucketTails(vector<int> &);
    vector<int> guessLMSSort(const vector<int> &, vector<int> &bucketSizes, const vector<bool> &Ltype);
    vector<int> LMSsort(const vector<int> &, vector<int> &bucketSizes, const vector<bool> &Ltype, vector<int> &sumArray, vector<int> &sumOffsets);
    int summariseSuffixArray(const vector<int> &, vector<int> &, const vector<bool> &, vector<int> &targetSummarySource, vector<int> &targetSummaryOffset);
    vector<int> makeSummarySuffixArray(vector<int> &, int);
    void inducedSortL(const vector<int> &, vector<int> &, vector<int> &, const vector<bool> &);
    void inducedSortS(const vector<int> &, vector<int> &, vector<int> &, const vector<bool> &);
    bool isLMSChar(unsigned int offset, const vector<bool> &);
    bool isLMSSubstringsEqual(const vector<int> &, const vector<bool> &, unsigned int, unsigned int);
};

bool SAIS::addStringFromFile(string fileName)
{
    if (numStrings + 1 > 1)
        return false;
    SuffixArray::addStringFromFile(fileName);
    return true;
}

bool SAIS::addString(string inputString)
{
    if (numStrings + 1 > 1)
        return false;
    SuffixArray::addString(inputString);
    return true;
}

void SAIS::makeSuffixArray()
{
    vector<int> bucket = fillBucket(*str, maxAlphabetSize);
    SAIS_SA(*str, *suffixArray, bucket);
    suffix_array = *suffixArray;
}

vector<int> SAIS::fillBucket(vector<int> &string, int alphabetSize)
{
    vector<int> bucketSize(alphabetSize, 0);
    for (int i = 0; i < string.size(); i++)
        bucketSize[string[i]]++;
    return bucketSize;
}

vector<bool> SAIS::fillLTypeArray(const vector<int> &string)
{
    vector<bool> target(string.size() + 1, false);
    *target.rbegin() = false;
    if (string.size() == 0)
        return target;
    *(target.rbegin() + 1) = true;
    for (int i = target.size() - 3; i >= 0; i--)
    {
        if (string[i] > string[i + 1])
            target[i] = true;
        else if (string[i] == string[i + 1] && target[i + 1])
            target[i] = true;
        else
            target[i] = false;
    }
    return target;
}

vector<int> SAIS::findBucketHeads(vector<int> &bucket)
{
    unsigned int offset = 1;
    unsigned int length = bucket.size();
    vector<int> result(length);
    for (auto i = 0; i < bucket.size(); ++i)
    {
        result[i] = offset;
        offset += bucket[i];
    }
    return result;
}

vector<int> SAIS::findBucketTails(vector<int> &bucket)
{
    unsigned int offset = 1;
    unsigned int length = bucket.size();
    vector<int> result(length);
    for (auto i = 0; i < bucket.size(); ++i)
    {
        offset += bucket[i];
        result[i] = offset - 1;
    }
    return result;
}

bool SAIS::isLMSChar(unsigned int offset, const vector<bool> &Ltype)
{
    if (offset == 0)
        return false;
    if (!Ltype[offset] && Ltype[offset - 1])
        return true;
    return false;
}

bool SAIS::isLMSSubstringsEqual(const vector<int> &string, const vector<bool> &Ltype, unsigned int offset1, unsigned int offset2)
{
    if (offset1 == string.size() || offset2 == string.size())
        return false;
    int i = 0;
    while (true)
    {
        bool firstIsLMS = isLMSChar(i + offset1, Ltype);
        bool secondIsLMS = isLMSChar(i + offset2, Ltype);
        if (i > 0 and firstIsLMS && secondIsLMS)
            return true;
        if (firstIsLMS != secondIsLMS)
            return false;
        if (string[i + offset1] != string[i + offset2])
            return false;
        i += 1;
    }
}

void SAIS::SAIS_SA(vector<int> &string, vector<int> &target, vector<int> &bucket)
{
    vector<bool> LType = fillLTypeArray(string);
    vector<int> guess = guessLMSSort(string, bucket, LType);
    inducedSortL(string, guess, bucket, LType);
    inducedSortS(string, guess, bucket, LType);
    vector<int> summaryString;
    vector<int> summaryOffset;
    int summaryAlphabetSize = summariseSuffixArray(string, guess, LType, summaryString, summaryOffset);
    vector<int> summarySuffixArray = makeSummarySuffixArray(summaryString, summaryAlphabetSize);
    vector<int> finalSuffixArray = LMSsort(string, bucket, LType, summarySuffixArray, summaryOffset);
    inducedSortL(string, finalSuffixArray, bucket, LType);
    inducedSortS(string, finalSuffixArray, bucket, LType);
    target.assign(finalSuffixArray.begin(), finalSuffixArray.end());
}

vector<int> SAIS::guessLMSSort(const vector<int> &string, vector<int> &bucket, const vector<bool> &Ltype)
{
    vector<int> guessSuffixArray(string.size() + 1, -1);
    auto bucketTails = findBucketTails(bucket);
    for (int i = 0; i < string.size(); i++)
    {
        if (isLMSChar(i, Ltype))
        {
            unsigned int bucketIndex = string[i];
            guessSuffixArray[bucketTails[bucketIndex]] = i;
            bucketTails[bucketIndex] -= 1;
        }
    }
    guessSuffixArray[0] = string.size();
    return guessSuffixArray;
}

void SAIS::inducedSortL(const vector<int> &string, vector<int> &target, vector<int> &bucket, const vector<bool> &Ltype)
{
    auto bucketHeads = findBucketHeads(bucket);
    for (auto i = 0U; i < target.size(); i++)
    {
        if (target[i] == -1)
            continue;
        int j = target[i] - 1;
        if (j < 0)
            continue;
        if (!Ltype[j])
            continue;
        unsigned int bucketIndex = string[j];
        target[bucketHeads[bucketIndex]] = j;
        bucketHeads[bucketIndex] += 1;
    }
}

void SAIS::inducedSortS(const vector<int> &string, vector<int> &target, vector<int> &bucket, const vector<bool> &Ltype)
{
    auto bucketTails = findBucketTails(bucket);
    for (int i = target.size() - 1; i >= 0; i--)
    {
        int j = target[i] - 1;
        if (j < 0)
            continue;
        if (Ltype[j])
            continue;
        unsigned int bucketIndex = string[j];
        target[bucketTails[bucketIndex]] = j;
        bucketTails[bucketIndex] -= 1;
    }
}

int SAIS::summariseSuffixArray(const vector<int> &string, vector<int> &guessArray, const vector<bool> &Ltype, vector<int> &targetSummaryString, vector<int> &targetSummaryOffset)
{
    vector<int> lmsNames(string.size() + 1, -1);
    int currentName = 0;
    lmsNames[guessArray[0]] = currentName;
    int lastLMSSuffixOffset = guessArray[0];
    for (int i = 1; i < guessArray.size(); i++)
    {
        int suffixOffset = guessArray[i];
        if (!isLMSChar(suffixOffset, Ltype))
            continue;
        if (!isLMSSubstringsEqual(string, Ltype, lastLMSSuffixOffset, suffixOffset))
            currentName += 1;
        lastLMSSuffixOffset = suffixOffset;
        lmsNames[suffixOffset] = currentName;
    }
    for (int i = 0; i < lmsNames.size(); i++)
    {
        if (lmsNames[i] != -1)
        {
            targetSummaryOffset.push_back(i);
            targetSummaryString.push_back(lmsNames[i]);
        }
    }
    return currentName + 1;
}

vector<int> SAIS::makeSummarySuffixArray(vector<int> &summaryString, int summaryAlphabetSize)
{
    if (summaryAlphabetSize == summaryString.size())
    {
        vector<int> summarySuffixArray(summaryString.size() + 1);
        summarySuffixArray[0] = summaryString.size();
        for (int i = 0; i < summaryString.size(); i++)
            summarySuffixArray[summaryString[i] + 1] = i;
        return summarySuffixArray;
    }
    else
    {
        vector<int> bucket = fillBucket(summaryString, summaryAlphabetSize);
        vector<int> target;
        SAIS_SA(summaryString, target, bucket);
        return target;
    }
}

vector<int> SAIS::LMSsort(const vector<int> &string, vector<int> &bucketSizes, const vector<bool> &Ltype, vector<int> &sumSuffixArray, vector<int> &sumOffsets)
{
    vector<int> suffixOffsets(string.size() + 1, -1);
    vector<int> bucketTails = findBucketTails(bucketSizes);
    for (int i = sumSuffixArray.size() - 1; i > 1; --i)
    {
        int stringIndex = sumOffsets[sumSuffixArray[i]];
        int bucketIndex = string[stringIndex];
        suffixOffsets[bucketTails[bucketIndex]] = stringIndex;
        bucketTails[bucketIndex] -= 1;
    }
    suffixOffsets[0] = string.size();
    return suffixOffsets;
}

bool pf_first(int mid, int idx, string &ptrn)
{
    int str_idx = suffix_array[mid] + idx;
    if (str_idx >= str.size())
        return false;
    if (str[str_idx] < ptrn[idx])
        return false;
    else
        return true;
}

int first_occurance(int lo, int hi, int idx, string &ptrn)
{
    int mid;
    while (hi - lo > 1) // FFFFTTT find first true
    {
        mid = (hi + lo) / 2;
        if (pf_first(mid, idx, ptrn))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (pf_first(lo, idx, ptrn))
        return lo;
    else if (pf_first(hi, idx, ptrn))
        return hi;
    else
        return -1;
}

bool pf_last(int mid, int idx, string &ptrn)
{
    int str_idx = suffix_array[mid] + idx;
    if (str_idx >= str.size())
        return true;
    if (str[str_idx] > ptrn[idx])
        return false;
    else
        return true;
}

int last_occurance(int lo, int hi, int idx, string &ptrn)
{
    int mid;
    while (hi - lo > 1) // TTTTFFF find last true
    {
        mid = (hi + lo) / 2;
        if (pf_last(mid, idx, ptrn))
            lo = mid;
        else
            hi = mid - 1;
    }
    if (pf_last(hi, idx, ptrn))
        return hi;
    else if (pf_last(lo, idx, ptrn))
        return lo;
    else
        return -1;
}

void solve(int I, int T)
{
    ll i, j, k, a, b, c, d, m, n, p, q;
    bool flag;
    // solve starts
    string ptrn;
    cin >> str;
    SAIS sa;
    sa.addString(str);
    sa.makeSuffixArray();
    cin >> k;
    vector<string> v_str;
    for (i = 0; i < k; i++)
    {
        cin >> ptrn;
        v_str.push_back(ptrn);
    }
    for (string st : v_str)
    {
        flag = true;
        int first_occ = 0, last_occ = suffix_array.size() - 1;
        for (i = 0; i < st.size(); i++)
        {
            int val = first_occurance(first_occ, last_occ, i, st);
            last_occ = last_occurance(first_occ, last_occ, i, st);
            first_occ = val;
            if (first_occ == -1 || last_occ == -1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << last_occ - first_occ + 1 << endl;
        else
            cout << 0 << endl;
    }
    // solve ends
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    for (int I = 1; I <= T; I++)
        solve(I, T);
    return 0;
}