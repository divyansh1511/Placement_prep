#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &a , vector<int> &b){
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[1];
}

int NmeetingsinRoom(int st[] , int end[] , int n){
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({st[i] , end[i]});
    }
    sort(v.begin() , v.end() , cmp);
    int c = 1;
    int end1 = v[0][1];
    for (int i = 1; i < n; i++)
    {
        if (end1 > v[i][0])
        {
            c++;
            end1 = v[i][1];
        }
        else
        {
            end1 = max(end1 , v[i][1]);
        }
    }
    return c;
}

int main(){
    int st[] = {1,3,0,5,8,5};
    int end[] = {2,4,5,7,9,9};
    cout<<NmeetingsinRoom(st , end , 6)<<endl;
}