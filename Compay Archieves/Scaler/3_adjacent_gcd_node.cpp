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

void PrintLL(node* head){
    node* tmp = head;
    while (tmp)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

node* adjacentNode(node* head){
    node* newnode = head;
    node* ans = newnode;

    while (head->next)
    {
        node* tmp = head->next;
        node* h = new node(__gcd(head->data , head->next->data));
        newnode->next = h;
        h->next = tmp;
        head = tmp;
        newnode = tmp;
    }
    
    return ans;
}

int main(){
    node* head = takeinput();
    PrintLL(head);
    node* tmp = adjacentNode(head);
    PrintLL(tmp);
}