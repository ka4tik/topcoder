
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

class ChocolateDividingEasy
{
    public:
        vector< vector<int> > sums;
        void make_sums(vector< vector<int> > &a)
        {
            int n=a.size();
            int m=a[0].size();
            sums.assign(n,vector<int>(m,0));
            sums[0][0]=a[0][0];
            for(int i=1;i<m;i++)
                sums[0][i]=sums[0][i-1]+a[0][i];
            for(int i=1;i<n;i++)
                sums[i][0]=sums[i-1][0]+a[i][0];

            for(int i=1;i<n;i++)
                for(int j=1;j<m;j++)
                    sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+a[i][j];
        }
        int get_sum(int x1,int y1,int x2,int y2){
            return sums[x2][y2]-(y1-1>=0?sums[x2][y1-1]:0)-(x1-1>=0?sums[x1-1][y2]:0)+((x1-1>=0&&y1-1>=0)?sums[x1-1][y1-1]:0);
        }
        int findBest(vector <string> chocolate)
        {
            vector< vector<int> > a(chocolate.size(),vector<int>(chocolate[0].size(),0));
            for(int i=0;i<chocolate.size();i++)
                for(int j=0;j<chocolate[0].size();j++)
                    a[i][j]=chocolate[i][j]-'0';
            make_sums(a);
            int n=chocolate.size();
            int m=chocolate[0].size();

            int ans=0;
            for(int i=1;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    for(int k=1;k<m;k++)
                    {
                        for(int l=k+1;l<m;l++)
                        {
                            vector<int> t;
                            int x1=0;
                            int y1=0;
                            int x2=i-1;
                            int y2=k-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=i;
                            y1=0;
                            x2=j-1;
                            y2=k-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=j;
                            y1=0;
                            x2=n-1;
                            y2=k-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=0;
                            y1=k;
                            x2=i-1;
                            y2=l-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=i;
                            y1=k;
                            x2=j-1;
                            y2=l-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=j;
                            y1=k;
                            x2=n-1;
                            y2=l-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=0;
                            y1=l;
                            x2=i-1;
                            y2=m-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=i;
                            y1=l;
                            x2=j-1;
                            y2=m-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            x1=j;
                            y1=l;
                            x2=n-1;
                            y2=m-1;
                            t.push_back(get_sum(x1,y1,x2,y2));
                            sort(t.begin(),t.end());

                            ans=max(ans,t[0]);
                        }
                    }
                }
            }
            return ans;
        }
};

