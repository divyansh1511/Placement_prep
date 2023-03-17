#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
}

void helper(string s , int idx , vector<string> tmp , vector<vector<string>> ans){
    if (idx == s.length())
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (isPalindrome(s , idx, i))
        {
            tmp.push_back(s.substr(idx , i-idx+1));
            helper(s , i+1 , tmp , ans);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> tmp;
    helper(s , 0 , tmp , ans);
    return ans;
}

int main(){

}