
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

#include<climits>
class GraphWalkWithProbabilities
{
public:
    #define EPS 1E-9
    int gauss (vector < vector<double> > a, vector<double> & ans) {
        int n = (int) a.size();
        int m = (int) a[0].size() - 1;
    
        vector<int> where (m, -1);
        for (int col=0, row=0; col<m && row<n; ++col) {
            int sel = row;
            for (int i=row; i<n; ++i)
                if (abs (a[i][col]) > abs (a[sel][col]))
                    sel = i;
            if (abs (a[sel][col]) < EPS)
                continue;
            for (int i=col; i<=m; ++i)
                swap (a[sel][i], a[row][i]);
            where[col] = row;
    
            for (int i=0; i<n; ++i)
                if (i != row) {
                    double c = a[i][col] / a[row][col];
                    for (int j=col; j<=m; ++j)
                        a[i][j] -= a[row][j] * c;
                }
            ++row;
        }
    
        ans.assign (m, 0);
        for (int i=0; i<m; ++i)
            if (where[i] != -1)
                ans[i] = a[where[i]][m] / a[where[i]][i];
        for (int i=0; i<n; ++i) {
            double sum = 0;
            for (int j=0; j<m; ++j)
                sum += ans[j] * a[i][j];
            if (abs (sum - a[i][m]) > EPS)
                return 0;
        }
    
        for (int i=0; i<m; ++i)
            if (where[i] == -1)
                return INT_MAX;
        return 1;
    }
	double findprob(vector <string> graph, vector <int> win, vector <int> loose, int start)
	{
        int n=graph.size();
        vector< vector<double>  > a;
        a.resize(n);
        for(int i=0;i<a.size();i++)
            a[i].resize(n+1);
        vector<double> out(a.size(),0);
        vector<double> sum(a.size(),0);
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size()-1;j++)
            {
                if(graph[i][j])
                {
                    a[i][j]=(1.00-win[i]/100.00-loose[i]/100.00);
                    if(j==i)
                        a[i][j]-=1;
                    out[i]=out[i]+1;
                    sum[i]+=win[i]/100.00;
                }
                else
                    a[i][j]=0;
            }
        }
        for(int i=0;i<a.size();i++)
        {
            a[i][n]=-sum[i]/out[i];
        }
        vector<double> ans;
        int g=gauss(a,ans);
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }

        return ans[start];
	}
};

