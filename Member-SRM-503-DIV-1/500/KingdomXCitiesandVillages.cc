//Accepted

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
#define ii pair<double,double>

using namespace std;

// }}}

#define eps 1e-9
class KingdomXCitiesandVillages
{
    public:
        bool equal(double x,double y)
        {
            return ((x+eps)>y&&(y+eps)>x);
        }
        double dist(double x1,double y1,double x2,double y2)
        {
            return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
        double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY)
        {
            int m=cityX.size();
            int n=villageX.size();

            double expc=0;
            for(int i=0;i<n;i++)
            {
                vector<ii> distances;
                for(int j=0;j<n;j++)
                    if(i!=j)
                        distances.push_back(ii(dist(villageX[i],villageY[i],villageX[j],villageY[j]),0));

                for(int j=0;j<m;j++)
                    distances.push_back(ii(dist(villageX[i],villageY[i],cityX[j],cityY[j]),1));

                sort(distances.begin(),distances.end());

                for(int j=0;j<distances.size();j++)
                {
                    if(distances[j].second)
                    {
                        expc+=(1.00/(j+1))*distances[j].first;
                        break;
                    }
                    expc+=(1.00/((j+1)*(j+2)))*distances[j].first;
                }
            }
            return expc;
        }
};
