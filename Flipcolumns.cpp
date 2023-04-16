#include<bits/stdc++.h>
using namespace std;
int main(){
    /*ios::sync_with_studio(false);
    cin.tie(nullptr);*/
    int n,m,k;
    cin>>n>>m>>k;
    map<string,int> mp;
    for(int i = 0;i<n;i++){
        string temp = " "; 
        for(int i = 0;i<m;i++){
            char a ;
            cin>>a;
            temp+=a;
        }
        mp[temp]++;
    }
    int ans = INT_MIN;
    for(auto it:mp){
        int cntzero = 0;
        for(int i = 0;i<it.first.size();i++){
            if(it.first[i] == '0')cntzero++;
        }
        cout<<" count zero :::"<<cntzero<<" ::ans:: "<<ans<<'\n';
        if((cntzero-k)%2 == 0 && cntzero<=k){
            ans = max(ans,it.second);
        }
    }
    cout<<ans<<endl;
    return 0;
}