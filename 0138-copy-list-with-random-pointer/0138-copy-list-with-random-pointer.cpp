/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //COPY NODE SIMPLE 
        //Connect the next and random
        //idea is oldnode-> newnode
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> mp;

        Node *temp=head;
        while(temp!=NULL){
            //copynode 
            mp[temp]=new Node(temp->val);
            //new node is craeted and value  is copied from temp of value
            temp=temp->next;
        }

        //2.connecting part
        temp=head;
        while(temp!=NULL){
            //A'.next=B'
            mp[temp]->next =mp[temp->next];
            //A'.random=C'
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
        
    }
};