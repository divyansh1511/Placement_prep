#include<bits/stdc++.h>
using namespace std;

class queueusingstack{
    public:
    stack<int> s1;
    stack<int> s2;

    void push(int x){
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        if (s1.empty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        s1.pop();
    }

    int top(){
        if (s1.empty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        return s1.top();
    }
};

int main(){

}