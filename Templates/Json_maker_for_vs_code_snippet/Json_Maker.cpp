#include <iostream>
using namespace std;
int main()
{
    FILE *fin, *fout;
    fin = freopen("Template_In.cpp", "r", stdin);
    fout = freopen("Template_Out.json", "w", stdout);
    cout << "\"";
    string s;
    while (!feof(fin))
    {
        getline(cin, s);
        if (s == "\n")
        {
        }
        else
        {
            cout << s;
        }
        cout << "\\" << "r" << "\\" << "n";
    }
    cout << "\"";
    fclose(fin);
    fclose(fout);
    return 0;
}
