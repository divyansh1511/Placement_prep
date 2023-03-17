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
    while (tmp != NULL)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

node* rotateLL(node* head , int k){
    node* fast = head;
    for (int i = 0; i <= k; i++)
    {
        fast = fast->next;
    }
    node* slow = head;
    node* prev = NULL;
    while (fast != NULL)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    node* tmp = slow->next;
    slow->next = NULL;
    prev->next = head;
    return tmp;
}

int main(){
    node* head = takeinput();
    print(head);
    node* ans = rotateLL(head , 2);
    print(ans);
}