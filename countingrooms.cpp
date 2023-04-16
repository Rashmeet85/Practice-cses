#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<char>> &vec,vector<vector<int>> &vis,int n,int m,int nr,int nc){
    queue<pair<int,int>> q;
    q.push({nr,nc});
    vis[nr][nc] =1;
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!q.empty()){
        int noder = q.front().first;
        int nodec = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nrow = noder + dr[i];
            int ncol = nodec + dc[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vec[nrow][ncol] == '.' && vis[nrow][ncol] !=1 ){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> vec(n,vector<char>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    //input complete

    vector<vector<int>> vis(n,vector<int> (m,0));
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && vec[i][j] == '.'){
                count++;
                bfs(vec,vis,n,m,i,j);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}