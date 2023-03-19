#include<bits/stdc++.h>
using namespace std;

class stackusingarr{
    public:
    int* arr;
    int capacity;
    int lastelementindex;
    
    stackusingarr(){
        arr = new int[20];
        capacity = 20;
        lastelementindex = -1;
    }

    void push(int a){
        if (lastelementindex == capacity-1)
        {
            int* newarr = new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                newarr[i] = arr[i];
            }
            arr = newarr;
            delete[] newarr;
        }
        arr[++lastelementindex] = a;
    }

    void pop(){
        if (lastelementindex == -1)
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        lastelementindex--;
    }

    int top(){
        if (lastelementindex == -1)
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        return arr[lastelementindex];
    }
};

int main(){

}