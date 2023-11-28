#include "manager.hpp"
#include <iostream>
#include <set>
using namespace std;

// 8 byte char array to uint64_t
uint64_t chars_to_int64(const char* cs) {
    return *((uint64_t*) cs);
}

int main() {
    // CHECKPOINT: after first 4 functions are implemented, this code:
    cout << "HOMEWORK 9" << endl << endl;
    cout << "---------------sManager---------------\n\n";

    cout << "checkpoint 1: expected empty chunks, designated as free with an F, with small length 9 and big length 65:\n";
    
    
    sManager* m = new sManager();
    m->print();
    
    // should print something like:
    /*
    printing sManager:
    F________F________F________F________F________________________________________________________________
    F________________________________________________________________F__________________________________
    ______________________________F________________________________________________________________
    */

    
    // CHECKPOINT: after implementing salloc, this code:
    
    cout << "\ncheckpoint 2: expected similar result to checkpoint 1, but with 'hi' in the first small chunk and 'bye' in the first big chunk, which should start with A rather than F:\n";
    
    sManager* m2 = new sManager();
    char* arr1 = m2->salloc(2);
    arr1[0] = 'h';
    arr1[1] = 'i';
    char* arr2 = m2->salloc(20);
    arr2[0] = 'b';
    arr2[1] = 'y';
    arr2[2] = 'e';
    m2->print();
    cout << endl;
    
    // should print something like:
    /*
    printing sManager:
    Ahi______F________F________F________Abye_____________________________________________________________
    F________________________________________________________________F__________________________________
    ______________________________F________________________________________________________________
    */

    
    
    // run this test when it seems like salloc and sfree are working 
    cout << "checkpoint 3: expected an sManager with the first few words of 'never gonna give you up' followed by another with the next few words:\n";
    
    sManager* rr = new sManager();
    int64_t* p1 = (int64_t*) rr->salloc(8);
    int64_t* p2 = (int64_t*) rr->salloc(8);
    int64_t* p3 = (int64_t*) rr->salloc(8);
    int64_t* p4 = (int64_t*) rr->salloc(8);
    *p1 = 6872337336494288479; 
    *p2 = 6872318683317757791; 
    *p3 = 6872316445773621087; 
    *p4 = 6877125683847330143; 
    rr->print();
    rr->sfree((char*) p3);
    rr->sfree((char*) p4);
    int64_t* p5 = (int64_t*) rr->salloc(8);
    *p5 = 6872316509913112415;
    int64_t* p6 = (int64_t*) rr->salloc(8);
    *p6 = 7959953343289585529;
    rr->print();
    

    // make sure the block corresponding to p4 is deallocated when
    // the sUniquePtr goes out of scope.
    cout << "\ntest to make sure deallocating sManagers: expected same sManager as previous, followed by indication that a pointer has been deallocated and another sManager where the last tiny section starts with F rather than A.\n";
    {
        sUniquePtr sp = sUniquePtr((char*) p4, rr);
        rr->print();
    }
    
    rr->print();

    

    
    
    
    cout << "\n\n---------------STL problems---------------\n\n";
    
    cout << "print_list will be used to show the results of most other functions\n\n";

    std::list<int> l1 = {1,2,3,4,5};
    
    cout << "tests for replace_specific:\n";
    
    replace_specific(l1.begin(),l1.end(),3,4);
    cout << "replace_specific(start, end, 3, 4): ";
    print_list(l1);
    cout << " expected: [ 1 2 4 4 5 ]\n";


    replace_specific(l1.begin(),l1.end(),4,5);
    cout << "replace_specific(start, end, 4, 5): ";
    print_list(l1);
    cout << " expected: [ 1 2 5 5 5 ]\n\n";
    

    
    cout << "test for replace_generic():\n";
    
    int a = 4;
    int b = 5;
    int c = 3;
    std::list<int> l4 = {1,2,3,4,5};
    
    replace_generic(l4.begin(),l4.end(),a,b);
    cout << "replace_generic(start, end, 4, 5): ";
    print_list(l4);
    cout << " expected: [ 1 2 3 5 5 ]\n";

    replace_generic(l4.begin(),l4.end(),b,c);
    cout << "replace_generic(start, end, 5, 3): ";
    print_list(l4);
    cout << " expected: [ 1 2 3 3 3 ]\n\n";

    
    cout << "tests for is_unlucky:\n";
    cout << "im kinda too lazy to make if-else statements so im simply cout-ing the direct result of the function, so 0 is false and 1 is true\n";
    
    std::set<int> s1 = {1,2,3,4,5};
    cout << "is_unlucky({1,2,3,4,5}): " << is_unlucky(s1) << " expected: 0\n";
    
    std::set<int> s2 = {1,2,13,4,5};
    cout << "is_unlucky({1,2,13,4,5}): " << is_unlucky(s2) << " expected: 1\n\n";


    cout << "tests for zero_evens():\n";

    zero_evens(l1);
    cout << "zero_evens({1,2,5,5,5}): ";
    print_list(l1);
    cout << " expected [ 1 0 5 5 5 ]\n";
    
    std::list<int> l9 = {2,2,2,2,2};
    zero_evens(l9);
    cout << "zero_evens({2,2,2,2,2}): ";
    print_list(l9);
    cout << " expected [ 0 0 0 0 0 ]\n\n";
    
    cout << "tests for zero_evens_after_three():\n";
    
    std::list<int> l2 = {2,2,2,2,2};
    zero_evens_after_three(l2);
    cout << "zero_evens_after_three({2,2,2,2,2}): ";
    print_list(l2);
    cout << " expected [ 2 2 2 0 0 ]\n";
    
    
    std::list<int> l3 = {1,2,3,4,5,6,7,8,9,0};
    zero_evens_after_three(l3);
    cout << "zero_evens_after_three({1,2,3,4,5,6,7,8,9,0}): ";
    print_list(l3);
    cout << " expected [ 1 2 3 4 5 6 7 0 9 0 ]\n";

    return 0;
}