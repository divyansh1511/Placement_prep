#include<bits/stdc++.h>
using namespace std;

bool isrectangle(int a , int b , int c , int d){
    map<int,int> mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    if (mp.size() == 2)
    {
        for(auto it : mp){
            if (it.second != 2)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main(){

}