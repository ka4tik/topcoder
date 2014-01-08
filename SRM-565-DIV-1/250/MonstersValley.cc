#include<bits/stdc++.h>
using namespace std;
class MonstersValley
{
    public:
        int minimumPrice(vector<long long> dread,vector<int> price)
        {
            int n=price.size();
            long long dp[n][2*n+1];
            for(int i=0;i<n;i++)
                for(int j=0;j<=2*n;j++)
                    dp[i][j]=0;

            dp[0][price[0]]=dread[0];

            for(int i=1;i<n;i++)
            {
                for(int j=0;j<=2*n;j++)
                {
                    if(dp[i-1][j]>=dread[i])
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][j]);
                    }

                    if(dp[i-1][j]!=0&&j+price[i]<=2*n)
                        dp[i][j+price[i]]=max(dp[i][j+price[i]],dp[i-1][j]+dread[i]);

                }


            }

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=2*n;j++)
                {
                    cout<<dp[i][j]<<" ";

                }
                cout<<endl;
            }

            int ans=INT_MAX;
            for(int i=0;i<=2*n;i++)
            {
                if(dp[n-1][i]>0)
                    ans=min(ans,i);

            }

            return ans;


        }
};
