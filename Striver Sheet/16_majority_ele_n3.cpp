#include<bits/stdc++.h>
using namespace std;

vector<int> Majority_element_n3(int arr[] , int n){
    int count1 = 0 , count2 = 0;
    int num1 = -1 , num2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (num1 == arr[i])
        {
            count1++;
        }
        else if (num2 == arr[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            num1 = arr[i];
        }
        else if (count2 == 0)
        {
            num2 = arr[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1)
        {
            count1++;
        }
        if (arr[i] == num2)
        {
            count2++;
        }
    }
    if (count1 > n/3)
    {
        ans.push_back(num1);
    }
    if (count2 > n/3)
    {
        ans.push_back(num2);
    }
    return ans;
}

int main(){
    int arr[] = {1,2,2,3,2};
    vector<int> v = Majority_element_n3(arr , 5);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}