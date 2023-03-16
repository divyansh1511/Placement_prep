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

node* IntersectingPoint(node* h1 , node* h2){
    int n = 0;
    node* tmp = h1;
    while (tmp != NULL)
    {
        n++;
        tmp = tmp->next;
    }
    int m = 0;
    tmp = h2;
    while (tmp != NULL)
    {
        m++;
        tmp = tmp->next;
    }
    if (n > m)
    {
        for (int i = 0; i < (n-m); i++)
        {
            h1 = h1->next;
        }
    }
    else if (m > n)
    {
        for (int i = 0; i < (m-n); i++)
        {
            h2 = h2->next;
        }
    }
    while (h1 != NULL)
    {
        if (h1 == h2)
        {
            return h1;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

int main(){
    
}