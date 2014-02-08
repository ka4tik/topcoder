
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

#define REP(I,n)   FOR(I,0,n)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}
#define mod 1000000007
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define mod 1000000007
class BigOEasy
{
    public:
        typedef vector<int> vi;
        typedef vector< vector<int> > vvi;
        vvi matrixUnit(int n)
        {
            vvi res(n,vi(n,0));
            for(int i=0;i<n;i++)
                res[i][i]=1;
            return res;
        }
        vvi matrixMul(const vvi &a, const vvi &b) 
        {
            int n =a.size();
            int m =a[0].size();
            int k =b[0].size();
            vvi res(n,vi(k));
            for (int i=0;i<n;i++)
                for (int j=0;j<k;j++)
                    for (int p=0;p<m;p++)
                        res[i][j]=(res[i][j]+(long long)a[i][p]*b[p][j]);

            return res;
        }
        vvi matrixPow(vvi a,int p)
        {
            int n=a.size();
            if(p==0)
                return matrixUnit(a.size());
            if((p&1))
                return matrixMul(a,matrixPow(a,p-1));
            else
                return matrixPow(matrixMul(a,a),p/2);
        }
        void matrixPrint(vvi a)
        {
            for(int i=0;i<a.size();i++)
            {
                for(int j=0;j<a[i].size();j++)
                {
                    printf("%d ",a[i][j]);
                }
                printf("\n");
            }
        }
        int fibo(int n)
        {
            vvi T=matrixUnit(2);
            T[0][0]=1;
            T[0][1]=1;
            T[1][0]=1;
            T[1][1]=0;
            T=matrixPow(T,n);
            return T[0][0];
        }
        string isBounded(vector <string> graph)
        {
            int n=graph.size();
            vector< vector<int> > reach(n,vector<int>(n,0));
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    reach[i][j]=(graph[i][j]=='Y');

            for(int i=1;i<=100;i++)
            {
                vector< vector<int> > t=matrixPow(reach,i);
                //matrixPrint(t);
                //db(i);
                for(int j=0;j<n;j++)
                {
                    if(t[j][j]>=2)
                        return "Unbounded";
                }
            }
            return "Bounded";
            //for(int k=0;k<n;k++)
            //{
            //for(int i=0;i<n;i++)
            //{
            //for(int j=0;j<n;j++)
            //{
            //reach[i][j] |= reach[i][k] && reach[k][j]; 
            //}
            //}
            //}
            //for(int i=0;i<n;i++)
            //reach[i][i] = 1; 


            //int G = 0; 
            //vector<int> group(n, -1); 
            ////vector<int> groupRepr; 
            //for(int i=0;i<n;i++) { 
            //if (group[i] != -1) 
            //continue; 

            ////groupRepr.push_back(i); 
            ////for(int j=i;j<n;j++)
            //FOR(j, i, n) 
            //if (reach[i][j] && reach[j][i]) { 
            //group[j] = G; 
            //} 
            //G++; 
            //} 
            //db(G);
            //for(int i=0;i<G;i++)
            //{
            //int c=0;
            //for(int j=0;j<n;j++)
            //if(group[j]==i)
            //c++;
            //if(c>=3)
            //return "Unbounded";
            //}
            //return "Bounded";
        }
};

