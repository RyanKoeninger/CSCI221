#include <iostream>
using namespace std;
#include "lab8.hpp"
#include <memory>



class Node{
    uint32_t value;
    Node* next;
    
    public: 
        Node(uint32_t val, Node* n){
            value = val;
            next = n;
            cout << "Node added with value " << val << endl;
        }
        
        ~Node(){
            cout << "Node deleted or something \n";
        }
        
        void append(uint32_t v){
            if (this -> next == nullptr){
                Node* newnode = new Node(v, nullptr);
                this -> next = newnode;
            }
            else{
                this -> next -> append(v);
            }
        }
        
        void print(){
            cout << this -> value << " ";
            if (this -> next){
                this -> next -> print();
            }
        }

        

};

class LL{
    Node* first;

    public:
        void append(uint32_t v){
            if (this -> first == nullptr){
                Node* newnode = new Node(v, nullptr);
                this -> first = newnode;
            }    
            else {
                this -> first -> append(v);
            }
            
        }
        void print(){
            cout << "[ ";
            if (this -> first){
                this -> first -> print();
            }
            cout << "]\n";
        }

        void delete(){
            if (this -> first){
                cout << "deleted node with value " << this -> value << endl;
                this -> first -> delete();
            }
        }
        

};

LL* bigMake(uint32_t v, uint32_t n){
    LL* newll = new LL();
    for (int i = 0; i < n; i++){
        newll -> append(v);
    }
    return newll;
}

int main(){
    LL* ll1 = new LL();

    ll1 -> append(4);
    ll1 -> append(5);
    ll1 -> append(6);
    
    ll1 -> print();

    delete ll1;

    LL* ll2 = bigMake(5,5);

    ll2 -> print();
    

    return 0;
}


