#include<bits/stdc++.h>
using namespace std;

class LRUcache{
    public:
    class node{
        public:
        int key;
        int data;
        node* next;
        node* prev;
        node(int key , int data){
            this->key = key;
            this->data = data;
        }
    };

    node* head = new node(-1 , -1);
    node* tail = new node(-1 , -1);

    int cap;
    unordered_map<int,node*> mp;

    LRUcache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode){
        node* tmp = head->next;
        newnode->next = tmp;
        tmp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }

    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void put(int key , int value){
        if (mp.find(key) != mp.end())
        {
            node* currnode = mp[key];
            mp.erase(key);
            deletenode(currnode);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key , value));
        mp[key] = head->next;
    }

    int get(int key){
        if (mp.find(key) != mp.end())
        {
            node* currnode = mp[key];
            int ans = currnode->data;
            mp.erase(key);
            deletenode(currnode);
            addnode(currnode);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
};

int main(){

}