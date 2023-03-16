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

node* reve(node* head){
    node* curr = head;
    node* tmp = NULL;
    node* prev = NULL;

    while (curr != NULL)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    
    return prev;
}

bool isPalindrome(node* head){
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* tmp = slow->next;
    slow->next = NULL;
    tmp = reve(tmp);
    while (head != NULL && tmp != NULL)
    {
        if (head->data != tmp->data)
        {
            return false;
        }
        head = head->next;
        tmp = tmp->next;
    }
    return true;
}

int main(){
    node* head = takeinput();
    cout<<isPalindrome(head)<<endl;
}