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

node* add2number(node* h1 , node* h2){
    int carry = 0;
    node* newnode = new node(-1);
    node* h = newnode;
    while (h1 != NULL || h2 != NULL || carry != 0)
    {
        int sum = carry;
        if (h1 != NULL)
        {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2 != NULL)
        {
            sum += h2->data;
            h2 = h2->next;
        }
        newnode->next = new node(sum%10);
        carry = sum/10;
        newnode = newnode->next;
    }
    return h->next;
}

int main(){
    node* h1 = takeinput();
    node* h2 = takeinput();
    node* ans = add2number(h1 , h2);
    print(ans);
}