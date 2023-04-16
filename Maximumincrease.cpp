#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0;i<n;i++){
        cin>>vec[i];
    }

    int len = 1;
    vector<int> tmp;
    tmp.push_back(vec[0]);
    for(int i = 1;i<n;i++){
        if(vec[i]>tmp.back()){
            tmp.push_back(vec[i]);
            len++;
        }
        else{
            tmp.clear();
            len = 0;
            tmp.push_back(vec[i]);
        }
    }
    cout<<tmp.size()<<" ";
    return 0;

}