#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,j;
    cin>>n>>m>>j;
    vector<vector<long long int>> mat(n+1,vector<long long int>(n+1,1e18));
    for(int i = 0;i<m;i++){
        int a,b;
        long long int c;
        cin>>a>>b>>c;
        mat[a][b] = min(mat[a][b],c);
        mat[b][a] = min(mat[a][b],c);
    }

    for(int i = 0;i<=n;i++) mat[i][i] = 0;
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j= 1;j<=n;j++){
                mat[i][j] = min(mat[i][j] ,mat[i][k] + mat[k][j]);
            }
        }
    }
    
    for(int i = 0;i<j;i++){
        int q1,q2;
        cin>>q1>>q2;
        if(mat[q1][q2] == 1e18){
            cout<<-1<<endl;
        }
        else{
            cout<<mat[q1][q2]<<endl;
        }
    }
}