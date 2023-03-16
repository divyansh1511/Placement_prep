#include<bits/stdc++.h>
using namespace std;

int LongestConsequtiveSequence(int arr[] , int n){
    sort(arr , arr+n);
    int c = 1;
    int mx = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i-1]+1)
        {
            c++;
        }
        else
        {
            mx = max(mx , c);
            c = 1;
        }
    }
    return mx;
}

int Longest_m2(int arr[] , int n){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (!s.count(arr[i]-1))
        {
            int currnum = arr[i];
            int c = 1;

            while (s.count(currnum+1))
            {
                currnum++;
                c++;
            }
            
            mx = max(mx , c);
        }
    }
    return mx;
}

int main(){
    int arr[] = {100, 200 , 1 , 3 , 2 , 4};
    cout<<LongestConsequtiveSequence(arr , 6)<<endl;
}