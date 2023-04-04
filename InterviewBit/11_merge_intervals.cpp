#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeInterval(vector<vector<int>> Intervals , vector<int> newinterval){
    Intervals.push_back(newinterval);
    sort(Intervals.begin() , Intervals.end());
    vector<vector<int>> ans;
    ans.push_back(Intervals[0]);
    for (int i = 1; i < Intervals.size(); i++)
    {
        if (ans.back()[1] > Intervals[i][0])
        {
            ans.back()[1] = max(ans.back()[1] , Intervals[i][1]);
        }
        else
        {
            ans.push_back(Intervals[i]);
        }
    }
    return ans;
}

int main(){

}