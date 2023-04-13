#include<bits/stdc++.h>
using namespace std;

vector<string> fizzbuzz(int n){
    vector<string> ans;
    for (int i = 1; i <= n; i++)
    {
        if (i%3 == 0 && i%5 == 0)
        {
            ans.push_back("Fizz Buzz");
        }
        else if (i%3 == 0)
        {
            ans.push_back("fizz");
        }
        else if (i%5 == 0)
        {
            ans.push_back("Buzz");
        }
        else
        {
            ans.push_back(to_string(i));
        }
    }
    return ans;
}

int main(){

}