
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

class SplitIntoPairs
{
public:
	int makepairs(vector <int> A, int X)
	{
        vector<long long> pos,neg,zero;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>0) pos.push_back(A[i]);
        }
        for(int i=0;i<A.size();i++)
        {
            if(A[i]<0) neg.push_back(A[i]);
        }

        for(int i=0;i<A.size();i++)
        {
            if(A[i]==0) zero.push_back(A[i]);
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        long long sum=0,j=0;
        for(int i=0;i<neg.size()&&j<pos.size();i++)
        {
            if(pos[j]*neg[i]>=X)
            {
                sum++;
                pos.erase(pos.begin());
                neg.erase(neg.begin()+i);
                i--;
                j=0;
            }
        }
        if(neg.size()>zero.size())
        {
            sum+=(int)(zero.size());
            int t=(int)(zero.size());
            while(t--)
                neg.erase(neg.begin());
        }
        else
        {
            sum+=(int)(neg.size());
            int t=(int)(neg.size());
            while(t--) zero.erase(zero.begin());
        }
        sum+=(int)(neg.size())/2;
        sum+=(int)(pos.size())/2;
        sum+=(int)(zero.size())/2;
        return sum;
        
	}
};

