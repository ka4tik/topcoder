
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

class AstronomicalRecords
{
    public:
#define ll long long
        int dp[55][55];
        bool done[55][55];
        int rec(vector<ll> &A,vector<ll>&B,int i,int j,int n,int m)
        {
            if(i==n||j==m)
                return 0;
            if(done[i][j])
                return dp[i][j];
            int ans=0;
            if(A[i]==B[j])
                ans=max(1+rec(A,B,i+1,j+1,n,m),ans);
            ans=max(ans,max(rec(A,B,i+1,j,n,m),rec(A,B,i,j+1,n,m)));
            done[i][j]=1;
            return dp[i][j]=ans;
        }
        int lcs(vector<ll> A,vector<ll> B)
        {
            int n=A.size();
            int m=B.size();
            for(int i=0;i<55;i++)
                for(int j=0;j<55;j++)
                    done[i][j]=0;
            return rec(A,B,0,0,n,m);
        }
        int minimalPlanets(vector <int> _A, vector <int> _B)
        {
            vector<ll> AA,BB;
            for(int i=0;i<_A.size();i++) AA.push_back(_A[i]);
            for(int i=0;i<_B.size();i++) BB.push_back(_B[i]);
            int ans=AA.size()+BB.size();
            for(int i=0;i<AA.size();i++)
            {
                for(int j=0;j<BB.size();j++)
                {
                    ll a=AA[i];
                    ll b=BB[j];
                    vector<ll> A,B;
                    for(int k=0;k<AA.size();k++)
                        A.push_back(AA[k]*b);
                    for(int k=0;k<BB.size();k++)
                        B.push_back(BB[k]*a);
                    ans=min(ans,int(A.size()+B.size()-lcs(A,B)));
                }
            }
            return ans;
        }
};

