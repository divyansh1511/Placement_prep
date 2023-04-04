#include<bits/stdc++.h>
using namespace std;

int max_min_ele(int arr[] , int n){
    int a = *max_element(arr , arr+n);
    int b = *min_element(arr , arr+n);

    return a+b;
}

int main(){

}