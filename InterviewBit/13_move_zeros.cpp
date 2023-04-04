#include<bits/stdc++.h>
using namespace std;

vector<int> PerfectPeak(vector<int> v){
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            if (i != j)
            {
                swap(v[i] , v[j]);
            }
            j++;
        }
    }
    return v;
}

int main(){

}