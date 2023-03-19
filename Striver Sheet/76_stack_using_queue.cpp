#include<bits/stdc++.h>
using namespace std;

class stackusingqueue{
    public:
    queue<int> q;
    void push(int x){
        q.push(x);
        int n = q.size();
        for (int i = 1; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
};

int main(){

}