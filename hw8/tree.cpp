#include "tree.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Constructor for a TreeNode.
// By default, the tree is a leaf, so its children point to
// nullptr, but you may override with actual pointers to other nodes.
TreeNode::TreeNode(key_type k, value_type v, TreeNode* l, TreeNode* r){
    key_ = k;
    value_ = v;
    left_ = l;
    right_ = r;
}

// return key in current node
key_type TreeNode::get_key() const{
    return this -> key_;
} 

// return value in current node
value_type TreeNode::get_value() const{
    return this -> value_;
} 

  // get_child(dir):
  // if dir='L', return left child
  // if dir='R', return right child
  // note that dir needs to be a CHAR and not a STRING
  // if the indicated child is nullptr, return nullptr
  // if dir= any other char, return nullptr
TreeNode* TreeNode::get_child(char dir){
    
    // return left_ or right_ if R or L is input and the node exists, otherwise
    // return nullptr
    if (dir == 'L'){
        if (left_ != nullptr){
            return left_;
        }
        return nullptr;
        
    }
    else if (dir == 'R'){
        if (right_ != nullptr){
            return right_;
        }
        return nullptr;
    }
    
    // if the input char isn't R or L
    else {
        return nullptr;
    }
}
// Destructor for a TreeNode. 
// LEAVE AS IS
TreeNode::~TreeNode(){
    std::cout << "node with value: " << this -> get_key() << " destroyed." << std::endl;
}

// deletes a heap-allocated tree
// and ALL of its children, children's children, etc
void TreeNode::destroy_tree() {
    
    // runs destroy tree on the current node's children if they exist
    if (this -> right_ != nullptr){
        right_ -> destroy_tree();
    }
    if(this -> left_ != nullptr){
        left_ -> destroy_tree();
    }
    
    // once all nodes below have been deleted, 
    // delete current node
    delete this;   
}




  //////////////////////////////////////////////////////////////////////////////
// path_to: return a string representing the path taken from a given tree root
// to a given key in the tree. For each left child taken along the path, the
// string contains an 'L' character, and 'R' for a right child, in order.
// So for example for the following tree (only keys depicted, values omitted):
/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6   3
          /
         9
*/
// path_to(tree, 9) will return "LRL", path_to(tree, 3) will return "RL", and
// path_to(126) will return "".
//
// If the key isn't found in the tree, path_to should return the string "-".
//
// If multiple matches to key exist in the tree, return the path to the
// leftmost match. For the tree above, path_to(tree, 12) returns "LL"

std::string TreeNode::path_to_help(key_type k){
    
    // 2 strings for 2 possible directions from a node
    std::string lpath = "";
    std::string rpath = "";
    
    // base case 1: if the node key matches k, return "F"
    // signifying a node has been found and allowing the
    // string to map the path from the root to the 
    if (key_ == k){
        return "F";
    }

    // if there is a node to the left, recurse on it. Since
    // we're returning the leftmost node in the tree if two
    // have the same key, we start on the left
    if (this -> left_ != nullptr){
        lpath = this -> left_ -> path_to_help(k);
    }
    
    // otherwise, this node is the last one on the left
    else {
        lpath = "";
    }

    // only add strings if the path isn't an empty string. 
    // the only way this is possible is if we've found the key
    // and returned "F", so the only nonempty string returned
    // will be the path to the correct node
    if (lpath != ""){
        return "L" + lpath;
    }

    // same thing but in the right direction
    if (this -> right_ != nullptr){
        rpath = this -> right_ -> path_to_help(k);
    }
    
    else {
        rpath = "";
    }

    if (rpath != ""){
        return "R" + rpath;
    }

    // base case 2: if the node has no left or right children and
    // hasn't returned "F", then it isn't the node. Returning an
    // empty string means no Ls or Rs can be added to it, so 
    // only a path to a found node will eventually be output
    return "";
}

std::string TreeNode::path_to(key_type k){
    std::string str;
    // if the key is the root, return empty string
    if (this -> key_ == k){
        str = "";
    }
    
    // otherwise string = whatever is returned by path_to_help()
    else{
        str = this -> path_to_help(k);
    }

    // loop through the string, if F is found that means a node was discovered 
    // in the tree, and the letters before F are the path to it. Delete F
    // from the string before returning it
    for(int i = 0; i < str.length(); i++){
        if (str[i] == 'F'){
            
            str.erase(i);
            return str;
        }
    }
    
    // otherwise, F wasn't found in the string, meaning the node isn't in the tree. 
    // With the way path_to_help() is structured, the string is empty. Instead
    // return the "-" expected if the node isn't in the tree
    str = "-";
    return str;
}

// 
//////////////////////////////////////////////////////////////////////////////
// node_at: Follow a path from the current TreeNode and return the node that is
// at the end of the path. For example, for the root of the tree above,
// root.node_at("LR") will return a pointer to the TreeNode whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)

// hint: recall that in C++, 'this' gives a pointer to the current object
TreeNode* TreeNode::node_at(std::string path){
    
    // set current to make things easier
    TreeNode* current = this;
    
    // checks each index of the string
    for (int i = 0; i < path.length(); i++){
        
        // if the index is L
        if (path[i] == 'L'){
            // move current to its left child if it exists. Otherwise, 
            // return nullptr
            if (current -> left_ != nullptr){
                current = current -> left_;
            }
            else{
                return nullptr;
            }
            
        }
        // if the index is R
        else if (path[i] == 'R'){
            // move current to its right child if it exists. Otherwise, 
            // return nullptr
            if (current -> right_ != nullptr){
                current = current -> right_;
            }
            else{
                return nullptr;
            }
        }
        
        // otherwise, the index is not L or R, return nullptr
        else{
            return nullptr;
        }
    }
    
    // if haven't hit any return nullptrs, return the current string
    // since it's at the location specified
    return current;
}



// IMPORTANT NOTE ABOUT THE REMAINING PROBLEMS:
// This material is important to learn, but it is not worth an excessive amount of suffering.
// I am making these problems worth only 10% of the grade of this homework in total,
// with the intention that if you are not a CS major and you are short for time, you will consider skipping them.
// Even if you ARE a CS major, if this part of the assignment is feeling overwhelming,
// PLEASE skip it and simply promise me that you'll learn it over the summer.


// hint:
// if you get an error like this while implementing BSTNode:
// error: no member named 'insert_help' in 'TreeNode'
//        return left_->insert_help();
// 
// Try casting the TreeNode pointer to a BSTNode pointer
// e.g. we would replace the above line with:
// return ((BSTNode*) left_)->insert_help();


// Constructor for BSTNodes
// This will NOT preserve the ordering of the BST
// Only use as a helper function for insert().
// Modify the variables of the new node inside insert()
// in order to attach it to the tree and preserve the ordering.
// LEAVE THIS CODE AS IS
BSTNode::BSTNode(key_type k, value_type v) : TreeNode(k,v) {
    parent_ = nullptr;
}

// static method for creating the root of a BST
// use it for your tests
// LEAVE THIS CODE AS IS
BSTNode* BSTNode::create_root(key_type k, value_type v) {
    BSTNode* root = new BSTNode(k, v);
    return root;
}

// optional: consider using a recursive helper function with this type signature
// to help implement insert().
void BSTNode::insert_help(BSTNode* new_node) {
    
    // if the new node is less than the current node (will end up to the left
    // of it) look to the left
    if (new_node -> key_ < this -> key_){
    
        // if there's a node there, recurse on it
        if (left_ != nullptr){
            ((BSTNode*) left_) -> insert_help(new_node);
        }
        
        // once there is no longer a node there, add a new node and assign its parent
        // to the current node
        else{
            left_ = new_node;
            ((BSTNode*) new_node) -> parent_ = this;
        }
        
    }

    // otherwise, the new node is greater than the current node (ends up to the right
    // of it) look to the right
    else{
        
        // if there's a node there, recurse on it
        if (right_ != nullptr){
            
            ((BSTNode*) right_) -> insert_help(new_node);
        }
        
        // once there is no longer a node there, add a new node and assign its parent to 
        // the current node
        else{
            right_ = new_node;
            ((BSTNode*) new_node) -> parent_ = this;
        }
    }
}


// runs insert_help() after initializing the new node with k and v as its values
void BSTNode::insert(key_type k, value_type v) {
    BSTNode* new_node = new BSTNode(k,v);
    
    this -> insert_help(new_node);
}


    /*
            20
           /   \
          /     \
         8       22
        / \     
      4    12   
          /  \
         10   14
    */

// return a pointer to the node with the minimum key
// in this node's subtree
// for example, if the root node in the above BST is r,
// r->minimum() should return 4
// if the node containing 12 is a,
// then a->minimum() should return 10.


BSTNode* BSTNode::minimum() {
    // set current node to make things easier
    BSTNode* current = this;
    
    // go down the leftmost branch until no longer
    // possible
    while (current -> left_ != nullptr){
        current = ((BSTNode*)current -> left_);
    }
    
    // return the node
    return current;
}

// OPTIONAL (but encouraged, especially for CS majors):
// return a pointer to the node with the smallest key that's greater
// than the current node. If no node in the BST is greater than the current node,
// return nullptr.
// Going back to the BST drawn above, the successor of the node
// containing 4 is (the node containing) 8. The successor of
// 8 is 10, and the successor of 14 is 20. 


// works on 2 main cases: if the node has a child greater than it or it doesn't

// [has bigger child:] moves down and to the right once, then as far down and to the left as possible
// and returns that node

// [doesn't have bigger child:] move up the tree as long as the current node is the right child of its
// parent. Then, check if the parent exists: if not, we've reached the root and the original node
// was the largest in the tree, and nullptr is returned. Otherise, return that parent.

BSTNode* BSTNode::successor() {
    // set current node to make things easier
    BSTNode* current = this;
    
    // if the node has a subtree
    if (current -> right_ != nullptr){
        // go to its first right value
        current = ((BSTNode*)current -> right_);

        // then all the way down the consequent left values 
        while (current -> left_ != nullptr){
            current = ((BSTNode*)current -> left_);
        }
        
        // the bottom node will be the lowest value in the subtree of
        // nodes larger than the original, which is its successor
        return current;
    }
    
    // otherwise, the node is the last in a line
    else{
    
        // move up the tree as long as the node is larger than its parent;
        // while loop is set up this way to avoid seg faults
        while (current -> parent_ != nullptr){
            
            // jump up if node is the right child of its parent
            if (current == ((BSTNode*) current -> parent_ -> right_)){
                current = ((BSTNode*) current -> parent_);
            }
            // otherwise, get out of the loop
            else{
                break;
            }
        }
        
        // if the node doesn't have a parent, the original node is the farthest right in the 
        // tree, meaning it has the highest value. returns nullptr
        if (((BSTNode*)current -> parent_) == nullptr){
            return nullptr;
        }
        
        // otherwise, the current node's parent is the first node with higher value than the 
        // original, which is its successor
        else{
            current = ((BSTNode*) current -> parent_);
            return current;
        }
    }
}