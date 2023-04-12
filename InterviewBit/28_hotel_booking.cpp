#include<bits/stdc++.h>
using namespace std;

bool hotelbooking(vector<int> arr , vector<int> dept , int k){
    sort(arr.begin() , arr.end());
    sort(dept.begin() , dept.end());

    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] < dept[i-k])
        {
            return false;
        }
    }
    return true;
}

int main(){

}