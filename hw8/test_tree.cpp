#include <iostream>
#include <memory>
#include "tree.hpp"

using namespace std;

int main() {
    
    cout << "\nHOMEWORK 8\n\n";
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

    
    
    cout << "---------------TreeNode---------------\n";
    cout << "initialized the unorganized tree depicted in test_tree.cpp\n\n";
    
    TreeNode* a = new TreeNode(9, 0);
    TreeNode* b = new TreeNode(6, 0, a, nullptr);
    TreeNode* c = new TreeNode(12, 0);
    TreeNode* d = new TreeNode(-5, 0, c, b);
    TreeNode* e = new TreeNode(3, 0);
    TreeNode* f = new TreeNode(12, 0, e);
    TreeNode* root = new TreeNode(126, 0, d, f);

    cout << "tests for get_key() and get_value():\n";
    cout << "test 1: a -> get_key() expected 9: " << a -> get_key() << endl;
    cout << "test 2: d -> get_key() expected -5: " << d -> get_key() << endl;
    cout << "test 3: d -> get_value() expected 0: " << d -> get_value() << endl;

    cout << endl;

    cout << "note: in order to avoid seg faults, for the rest of the tests an if/else statement will be used when using results of functions that might return nullptr\n";
    cout << "additionally, the use of get_key() is implied from now on to show values of returned TreeNodes and BSTNodes\n\n";

    cout << "tests for get_child():\n";
    
    cout << "test 1: d -> get_child('L') expected 12: ";
    if (d -> get_child('L') != nullptr){
        cout << d -> get_child('L') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }

    cout << "test 2: d -> get_child('R') expected 6: ";
    if (d -> get_child('R') != nullptr){
        cout << d -> get_child('R') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    
    cout << "test 3: b -> get_child('R') expected DNE: ";
    if (b -> get_child('R') != nullptr){
        cout << b -> get_child('R') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    
    cout << "test 4: d -> get_child('A') expected DNE: ";
    if (d -> get_child('A') != nullptr){
        cout << d -> get_child('A') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }

    cout << "\ntests for path_to() and path_to_help():\n";
    cout << "test 1: path_to(9) expected LRL: " << root -> path_to(9) << endl;
    cout << "test 2: path_to(-5) expected L: " << root -> path_to(-5) << endl;
    cout << "test 3: path_to(1) expected -: " << root -> path_to(1) << endl << endl;

    cout << "tests for node_at():\n";
    
    cout << "test 1: node_at(LRL) expected 9: ";
    if (root -> node_at("LRL") != nullptr){
        cout << root -> node_at("LRL") -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }

    cout << "test 2: node_at(L) expected -5: ";
    if (root -> node_at("L") != nullptr){
        cout << root -> node_at("L") -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }

    cout << "test 3: node_at(RRR) expected DNE: ";
    if (root -> node_at("RRR") != nullptr){
        cout << root -> node_at("RRR") -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }

    cout << "\ntest 1 for destroy_tree(): expected 'node with value <x> destroyed' for each node initialized in the tree\n";
    
    root -> destroy_tree();

    
    
    
    
    cout << "\n---------------BSTree---------------\n";
    cout << "initialized the BST depicted in the test file\n\n";


    

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

    
    // Uncomment this block once you have implemented the BSTNode insert() method
    // it should generate the tree depicted above.
    BSTNode* bstr = BSTNode::create_root(20, 0); // binary search tree root
    bstr->insert(8, 0);
    bstr->insert(22, 0);
    bstr->insert(12, 0);
    bstr->insert(4, 0);
    bstr->insert(10, 0);
    bstr->insert(14, 0);

    cout << "tests for insert() and insert_help():\n";
    cout << "checked by running get_child(L) and get_child(R) on 20, 8, and 4\n\n";
    
    BSTNode* node8 = ((BSTNode*)bstr -> node_at(bstr -> path_to(8)));
    BSTNode* node4 = ((BSTNode*)bstr -> node_at(bstr -> path_to(4)));
    cout << "test 1: children of 20: expected 8 and 22\n";
    
    if (bstr -> get_child('L') != nullptr){
        cout << bstr -> get_child('L') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    if (bstr -> get_child('R') != nullptr){
        cout << bstr -> get_child('R') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    

    cout << "test 2: children of 8: expected 4 and 12\n";
    if (node8 -> get_child('L') != nullptr){
        cout << node8 -> get_child('L') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    if (node8 -> get_child('R') != nullptr){
        cout << node8 -> get_child('R') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }

    cout << "test 3: children of 4: expected DNE x2\n";
    if (node4 -> get_child('L') != nullptr){
        cout << node4 -> get_child('L') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    if (node4 -> get_child('R') != nullptr){
        cout << node4 -> get_child('R') -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    cout << endl;

    BSTNode* node12 = ((BSTNode*)bstr -> node_at(bstr -> path_to(12)));
    cout << "tests for minimum():\n";
    cout << "test 1: minimum() of whole tree expected 4: " << bstr -> minimum() -> get_key() << endl;
    cout << "test 2: minimum() of subtree starting at 12 expected 10: " << node12 -> minimum() -> get_key() << endl << endl;
        
    BSTNode* node22 = ((BSTNode*)bstr -> node_at(bstr -> path_to(22)));
    BSTNode* node14 = ((BSTNode*)bstr -> node_at(bstr -> path_to(14)));
    cout << "tests for successor():\n";
    
    cout << "test 1: successor(12) expected 14: ";
    if (node12 -> successor() != nullptr){
        cout << node12 -> successor() -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    cout << "test 2: successor(14) expected 20: ";
    if (node14 -> successor() != nullptr){
        cout << node14 -> successor() -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    cout << "test 3: successor(22) expected DNE: ";
    if (node22 -> successor() != nullptr){
        cout << node22 -> successor() -> get_key() << endl;
    }
    else{
        cout << "does not exist\n";
    }
    
    cout << endl << "test 2 for destroy_tree(): expected 'node with value <x> destroyed' for each node initialized in the tree\n";
    bstr->destroy_tree();
    return 0;
}