
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
//bool cmpp(string a,string b)
//{
//if(a.size()<b.size())
//return 1;
//return 0;
//}
class TheLotteryBothDivs
{
    public:
        struct myclass{
            bool operator() (string a,string b)
            {
                return a.size()<b.size();
            }
        } myobject;
        double find(vector <string> good)
        {
            sort(good.begin(),good.end());
            good.erase(unique(good.begin(),good.end()),good.end());
            sort(good.begin(),good.end(),myobject);
            reverse(good.begin(),good.end());
            int n=good.size();
            vector<int> remove(n,0);
            for(int i=0;i<good.size();i++) 
            {
                //db2(i,good[i]);
                for(int j=i+1;j<good.size();j++)
                {
                    string t=good[j];
                    string prev=good[i];
                    reverse(t.begin(),t.end());
                    reverse(prev.begin(),prev.end());
                    int flag=1;
                    for(int k=0;k<t.size();k++)
                        if(prev[k]!=t[k])
                            flag=0;

                    if(flag)
                    {
                        remove[i]=1;
                    }

                }

            }
            vector<string> rem;
            for(int i=0;i<good.size();i++)
                if(!remove[i])
                    rem.push_back(good[i]);

            good=rem;

            int win=0;
            for(int i=0;i<rem.size();i++)
            {
                //db2(i,rem[i]);
                int t=rem[i].size();
                win+=pow(10,(9-t));
            }

            //db(win);
            return double(win)/double(1000000000);
        }
};

