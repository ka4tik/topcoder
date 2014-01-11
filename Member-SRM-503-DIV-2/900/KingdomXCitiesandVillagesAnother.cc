
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

class KingdomXCitiesandVillagesAnother
{
    public:
#define iii pair< double,pair<int,int> >
#define ii pair<int,int>
#define ll long long
        struct disjointset {
            int *root, *rank, n;
            disjointset(int sz) {
                root = new int[sz+1];
                rank = new int[sz+1];
                n = sz;
            }
            void init() {
                for(int i = 1; i <= n; i++) {
                    root[i] = i;
                    rank[i] = 0;
                }
            }
            int find(int u) {
                if(u != root[u]) root[u] = find(root[u]);
                return root[u];
            }
            bool iscycle(int u,int v)
            {
                u=find(u);
                v=find(v);
                if(u==v) return 1;
                else return 0;
            }
            void merge(int u, int v) {
                int pu = find(u);
                int pv = find(v);
                if(rank[pu] > rank[pv]) root[pv] = pu;
                else root[pu] = pv;
                if(rank[pu]==rank[pv]) rank[pv]++;
            }
        };
        double dist(ll x1,ll y1,ll x2,ll y2)
        {
            return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
        double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY)
        {
            vector<int> X,Y,t;
            for(int i=0;i<cityX.size();i++)
                X.push_back(cityX[i]);
            for(int i=0;i<cityY.size();i++)
                Y.push_back(cityY[i]);
            for(int i=0;i<cityY.size();i++)
                t.push_back(1);
            for(int i=0;i<villageX.size();i++)
                X.push_back(villageX[i]);
            for(int i=0;i<villageY.size();i++)
                Y.push_back(villageY[i]);
            for(int i=0;i<villageY.size();i++)
                t.push_back(0);
            int n=X.size();
            vector<iii> edges;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    edges.push_back(iii(dist(X[i],Y[i],X[j],Y[j]),ii(i+1,j+1)));
                }
            }
            disjointset dj(n);
            dj.init();
            for(int i=0;i<cityX.size();i++)
            {
                for(int j=i+1;j<cityX.size();j++)
                {
                    dj.merge(i+1,j+1);
                }
            }

            sort(edges.begin(),edges.end());
            double cost=0;
            for(int i=0;i<edges.size();i++)
            {
                int u=edges[i].second.first;
                int v=edges[i].second.second;
                if(!dj.iscycle(u,v))
                {
                    cost+=edges[i].first;
                    dj.merge(u,v);
                }
            }
            return cost;
        }
};

