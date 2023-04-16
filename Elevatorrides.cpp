#include<bits/stdc++.h>
using namespace std;


int32_t main(){

    ios_base::sync_with_stdio(0);cin.tie(0);
    cout.tie(0);
   
    int n,x;cin>>n>>x;
    vector<int> w(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    vector<pair<int,int>> dp(1<<n);
    dp[0]={1,0};    
    for(int mask=1;mask<(1<<n);mask++){
        //to store the best result for a particular mask. Best result means less number of rides 
        pair<int,int> bestResult={INT_MAX,INT_MAX};
        for(int j=0;j<n;j++){
          //   cout<<mask<<"  :  "<<(1<<j)<<" ::"<<(mask & (1<<j))<<endl;
            if(mask &(1<<j)){
               
                auto res = dp[mask^(1<<j)];
                //the jth person can be accommodated in the last ride, we have used, so number of rides remain same
                if(res.second + w[j] <=x  ){
                    res={res.first,res.second+w[j]};
                }
                //the jth person need another new ride
                else{
                    res = {res.first+1, w[j]};
                }
                bestResult=min(bestResult,res);
            }   
            
        }
      //  cout<<"================="<<endl;
        dp[mask] =bestResult;
    }

    //cout<<(1<<n)<<endl;
    cout<< dp[(1<<n)-1].first<<"\n";
    return(0);
}