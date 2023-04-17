#include<bits/stdc++.h>
using namespace std;

int findPeak(vector<int> v){
    int i = 0 , j = v.size() - 1;
    while (i < j)
    {
        int mid = i + (j-i)/2;
        if (v[mid] < v[mid+1])
        {
            i = mid+1;
        }
        else
        {
            j = mid;
        }        
    }
    return i;
}

int firsthalf(vector<int> v , int st , int end , int k){
    int i = st , j = end;
    while (i <= j)
    {
        int mid = i + (j-i)/2;
        if (v[mid] == k)
        {
            return mid;
        }
        else if (v[mid] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return -1;
}

int secondhalf(vector<int> v , int st , int end , int k){
    int i = st , j = end;
    while (i <= j)
    {
        int mid = i + (j-i)/2;
        if (v[mid] == k)
        {
            return mid;
        }
        else if (v[mid] < k)
        {
            j = mid-1;
        }
        else
        {
            i = mid+1;
        }
    }
    return -1;
}

int SearchInBitnoicArr(vector<int> v , int k){
    int peak = findPeak(v);
    int a = firsthalf(v , 0 , peak-1 , k);
    if (a != -1)
    {
        return a;
    }
    int n = v.size();
    int b = secondhalf(v , peak , n-1 , k);
    return b;
}

int main(){

}