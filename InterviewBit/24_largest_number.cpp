#include<bits/stdc++.h>
using namespace std;

bool static cmp(int &a , int &b){
    string a1 = to_string(a);
    string b1 = to_string(b);

    return a1+b1 > b1+a1;
}

string LargestNum(vector<int> v){
    sort(v.begin() , v.end() , cmp);
    string ans = "";
    int n = v.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i];
        if (v[i] == 0)
        {
            c++;
        }
    }
    if (c == n)
    {
        return "0";
    }
    return ans;
}

int main(){

}