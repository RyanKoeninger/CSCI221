#include "manager.hpp"
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

const int TINY_SZ = 9; // size of a tiny chunk (8 bytes + 1 byte header)
const int BIG_SZ = 65; // size of a big chunk (64 bytes + 1 byte header)


// the sManager constructor should initialize the member variables
// according to the provided arguments: ntiny gives the number of 
// tiny chunks in the 'heap', and nbig the number of big chunks.
//
// The constructor should also determine how large a capacity_ is necessary
// the desired number of tiny chunks and big chunks, and then heap allocate
// mem_ as a char array of the appropriate size.
//
// Finally, if the debug flag is enabled, the constructor should
// initialize every character in the array to '_'.
sManager::sManager(int ntiny, int nbig, bool debug) {
    ntiny_ = ntiny;
    nbig_ = nbig;
    capacity_ = (ntiny * TINY_SZ) + (nbig * BIG_SZ);
    mem_ = new char[capacity_];
    debug_ = debug;
    if (debug){
        for (int i = 0; i < capacity_; i++){
            mem_[i] = '-';
        }
    }
    init_headers();
}



// don't leak memory from mem_
sManager::~sManager() {
cout << "deletedn\n";
}

// This function should set the header of each chunk in the
// 'heap' as 'F' for Free. 
// After you write this function, call it at the end of the constructor
// (so that all chunks are free when an sManager object is constructed).
void sManager::init_headers() {
    int ctr = 0;
    for (int i = 0; i <= ntiny_ * TINY_SZ; i += TINY_SZ){
        mem_[i] = 'F';
        ctr = i;
    }
    for (int j = ctr; j <= nbig_ * BIG_SZ; j+= BIG_SZ){
        mem_[j] = 'F';
    }
}


// print out the contents of mem_
// (consider including linebreaks every 80 characters or so)
void sManager::print() {
    for (int i = 0; i < capacity_; i++){
        cout << mem_[i];
    }
    cout << endl;
}

// return index (in mem_ array) of the first free tiny chunk.
// if none are free return -1
// if debug_ flag is true, print "ff_tiny(): " along with the returned index
int sManager::ff_tiny() {
    for (int i = 0; i < ntiny_ * TINY_SZ; i+= TINY_SZ){
        if (mem_ [i] == 'F'){
            if (debug_){
                cout << "ff_tiny(): " << i << endl;
            }
            return i;
            
        }
    }
    return -1;
}

// (find first big)
// return index of the first free big chunk.
// if none are free return -1
// if debug_ flag is true, print "ff_big(): " along with the returned index
int sManager::ff_big() {
    for (int i = ntiny_ * TINY_SZ; i < nbig_ * BIG_SZ; i+= BIG_SZ){
        if (mem_ [i] == 'F'){
            if (debug_){
                cout << "ff_big(): " << i << endl;
            }
            return i;
            
        }
    }
    return -1;
}



// given nbytes, find a free chunk of size *at least* nbytes
// (i.e. if all small chunks are Allocated and salloc(3) is called, we should allocate a big chunk if one is available)
// switch its header to 'A' for Allocated
// and return a /pointer/ to the usable memory in the chunk
// (the pointer should NOT point to the header)
// if no chunk of size at least nbytes is available, return nullptr
// hint: this should use ff_tiny and ff_big as helper functions
char* sManager::salloc(int nbytes) {
    int ans = -1;
    if (nbytes < TINY_SZ){
        ans = ff_tiny();
    }
    if (nbytes < BIG_SZ && ans == -1){
        ans = ff_big();
    }
    if (ans != -1){
        mem_[ans] = 'A';
        return mem_ + ans + 1;
    }
    return nullptr;
}

// given a pointer to an allocated chunk,
// switch its header to 'F' for Free
// if debug_ flag is true, print the /index/ of the received pointer
// (included in starter code)
void sManager::sfree(char* ptr) {
    *(ptr - 1) = 'F';
    if (debug_){
        cout << "index: " << ptr - mem_ << endl;
    }
}




// sUniquePtr methods:
// create a smart pointer that interfaces with the sManager class

// store a pointer allocated from an sManager object, 
// and also a pointer to that sManager object.
sUniquePtr::sUniquePtr(char* p, sManager* m) {
    ptr_ = p;
    m_ = m;
}

// deallocate (from the sManager) the stored pointer
// when this object is destroyed
sUniquePtr::~sUniquePtr() {
    m_ -> sfree(ptr_);
    cout << "pointer deallocated\n";
}

// return the wrapped pointer
char* sUniquePtr::get() {
    return ptr_;
}



// STL problems

// print out each value in a std::list<int>
// hint: you will need to use the list's iterator to do this
void print_list(std::list<int> & ls) {
    
    // print the first bracket
    cout << "[ ";
    
    // set current to the first value
    list<int>::iterator curr = ls.begin();

    // loop through, printing each value
    while (curr != ls.end()){
        cout << *curr << " ";
        
        // iterate
        curr++;
    }
    cout << "]";
}   


// write a function that replaces every instance of 
// old_value with new_value inside of a std::list<int>,
// accessed via iterators
void replace_specific(list<int>::iterator start, 
                   list<int>::iterator end, 
                   int old_value, 
                   int new_value) 
{
    // set an iterator to the beginning of the list
    list<int>::iterator curr = start;

    // moves through the list, turning all instances of old_value to new_value
    while (curr != end){
        if (*curr == old_value){
            *curr = new_value;
        }
        
        // iterate
        curr++;
    }
}


// write a function that does the same thing, but generic to type
// (use a template)


// Write a function that returns true if the number 13
// is in a given std::set<int>.
// use a Standard Template Library inbuilt function to do so
// (mostly this is just to make sure you know how to look up and apply basic tools from the STL)
bool is_unlucky(std::set<int> & s){
    
    // returns an iterator that's the result of std::find()
    set<int>::iterator it = std::find(s.begin(),s.end(),13);
    
    // if 13 isn't in the set find() will return the end iterator of the set
    if (it != s.end()) {
        return true;
        }

    return false;
}

// SOFT OPTIONAL:
// write a function that replaces every even value in an STL list with 0
// do this by writing a Predicate class that determines whether a value is even,
// and use it to call the STL function replace_if()
void zero_evens(list<int> & ls) {
    std::replace_if(ls.begin(), ls.end(), isEven(), 0);
}

// SOFT OPTIONAL:
// write a function that does the same, but only starts
// zeroing the even numbers AFTER it has gone through 3 even numbers.
// Do this only using a Predicate class, and a call to replace_if.
void zero_evens_after_three(list<int> & ls) {
    std::replace_if(ls.begin(), ls.end(), isEven3(), 0);
}