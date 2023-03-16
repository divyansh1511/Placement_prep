#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* takeinput(){
    node* head = NULL;
    node* tail = NULL;

    int data;
    cin>>data;
    while (data != -1)
    {
        node* newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node* head){
    node* tmp = head;
    while (tmp)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

node* merge2sortedLL(node* h1 , node* h2){
    node* newnode = NULL;
    if (h1 == NULL)
    {
        return h2;
    }
    else if (h2 == NULL)
    {
        return h1;
    }
    else if (h1->data < h2->data)
    {
        newnode = h1;
        newnode->next = merge2sortedLL(h1->next , h2);
    }
    else
    {
        newnode = h2;
        newnode->next = merge2sortedLL(h1 , h2->next);
    }
    return newnode;
}

int main(){
    node* h1 = takeinput();
    node* h2 = takeinput();
    node* h = merge2sortedLL(h1 , h2);
    print(h);
}