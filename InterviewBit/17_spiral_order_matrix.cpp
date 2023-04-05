#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> SpiralMatrix(int a){
    vector<vector<int>> v(a , vector<int>(a));
    int i = 0 , j = 0 , k = 0;
    int c = 1;
    int n = a , m = a;
    while (i < n && j < m)
    {
        for(k = j;k<m;k++){
            v[i][k] = c;
            c++;
        }
        i++;
        for(k = i;k<n;k++){
            v[k][m-1] = c;
            c++;
        }
        m--;
        if (j < m)
        {
            for(k = m-1;k>=j;k--){
                v[n-1][k] = c;
                c++;
            }
            n--;
        }
        if (i < n)
        {
            for(k = n-1;k>=0;k--){
                v[k][j] = c;
                c++;
            }
            j++;
        }
    }
    return v;
}

int main(){
    vector<vector<int>> v = SpiralMatrix(2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}