#include<bits/stdc++.h>
using namespace std;

int Triplet(vector<string> &v){
    int n = v.size();
    int i = 0 , j = n-1;
    sort(v.begin() , v.end());

    while (j-i >= 2)
    {
        int mid = (i+j)/2;
        double a = stof(v[i]);
        double b = stof(v[mid]);
        double c = stof(v[j]);

        double sum = a+b+c;
        if (sum > 2)
        {
            j--;
        }
        else if (sum < 1)
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main(){
    vector<string> v = {"0.6", "0.7", "0.8", "1.2", "0.4"};
    cout<<Triplet(v)<<endl;
}