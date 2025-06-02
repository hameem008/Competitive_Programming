#include <bits/stdc++.h>
using namespace std;

string generator(int min_length, int max_length)
{
    int length = min_length + rand() % (max_length - min_length + 1);
    string ret;
    for (int i = 0; i < length; i++)
    {
        ret.push_back('a' + rand() % 26);
    }
    return ret;
}

string num_to_string(int n)
{
    string ret;
    while (n)
    {
        ret.push_back(n % 10 + '0');
        n /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void User_Info()
{
    for (int i = 1; i <= 100; i++)
    {
        string str = "INSERT INTO User_Info VALUES ";
        string name = generator(5, 10);
        string bra = "(" + num_to_string(i) + ",'" + name + "@gmail.com','" + name + "pass','" + name + "',NULL,NULL,0,'" + name + "');";
        cout << str << bra << "\n";
    }
}

void follow()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            string str = "INSERT INTO Follow VALUES";
            string bra = str + "(" + num_to_string(i) + "," + num_to_string(j) + ");";
            if (i != j)
                cout << bra << "\n";
        }
    }
}
void comments()
{
    vector<string> cmnt = {"are vy agun agun", "hoff mama", "us bhai us", "khub relatable", "god level sense of humour", "baje hoise", "3rd class jokes", "haste haste more gelam", "tore samne paile pidamu", "bump", "pl bara", "interbal 18 er dristy akorshon korchi", "under rated", "context?", "wth!", "edike kichue na bojha ami", "eta ki silo vy!", "triggered!!", "so real", "vai ki titumir e thaken naki??"};
    int i = 200;
    int id = 1;
    while (i--)
    {
        string str = "INSERT INTO ACTIVITIES VALUES";
        string bra = "(" + num_to_string(id) + "," + num_to_string(rand() % 40 + 1) + "," + num_to_string(rand() % 10 + 1) + ",SYSDATE+" + num_to_string(100 + rand() % 200) + ",'" + cmnt[rand() % cmnt.size()] + "');";
        cout << str << bra << endl;
        id++;
    }
}
// INSERT INTO ACTIVITIES VALUES(1,1,SYSDATE,NULL);
void up_vote()
{
    set<string> s;
    int i = 500;
    while (i--)
    {
        string str = "INSERT INTO Up_Vote VALUES";
        string bra = "(" + num_to_string(rand() % 40 + 1) + "," + num_to_string(rand() % 10 + 1) + ");";
        s.insert(str + bra);
    }
    for (auto x : s)
        cout << x << "\n";
}

int main()
{
    FILE *fout;
    fout = freopen("SQL.txt", "w", stdout);
    comments();
    return 0;
}
// INSERT INTO User_Info VALUES (1,'user1@gmail.com','user1pass','user1',NULL,NULL,0,'user1');