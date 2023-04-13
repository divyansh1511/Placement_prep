#include<bits/stdc++.h>
using namespace std;

int highestScore(vector<vector<string> > &A) {
    unordered_map<string , vector<int>> mp;
    for(int i=0;i<A.size();i++){
        mp[A[i][0]].push_back(stoi(A[i][1]));
    }
    int ans = 0;
    for(auto it : mp){
        int n = it.second.size();
        int sum = 0;
        for(auto a : it.second){
            sum += a;
        }
        ans = max(ans , sum/n);
    }
    return ans;
}

int main(){

}