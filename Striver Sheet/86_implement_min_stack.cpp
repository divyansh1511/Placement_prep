#include<bits/stdc++.h>
using namespace std;

class MinStack{
    public:
    stack<int> s1;
    stack<int> s2;
    void push(int x){
        s1.push(x);
        if (s2.empty() || s2.top() >= x)
        {
            s2.push(x);
        }
    }
    void pop(){
        int a = s1.top();
        s1.pop();
        if (a == s2.top())
        {
            s2.pop();
        }
    }
    int top(){
        return s1.top();
    }
    int getmin(){
        return s2.top();
    }
};

int main(){

}