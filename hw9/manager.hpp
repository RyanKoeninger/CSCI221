#pragma once
#include <list>
#include <set>

// memory manager class 
// models a simplified version of the heap,
// with accompanying simplified versions of 
// malloc and free
class sManager {
    bool debug_; // flag indicating debug mode
    char* mem_; // pointer to 'heap' memory
    int ntiny_; // number of tiny chunks in the 'heap'
    int nbig_; // number of big chunks in the 'heap'
    int capacity_; // size of the 'heap' (in bytes)

public:
    // initialize a heap with the desired number of chunks
    sManager(int ntiny=4, int nbig=4, bool debug=true);
    // destructor -- don't leak the heap memory
    ~sManager();

    // initialize header of each chunk to 'F'
    void init_headers();

    // print out each byte in the 'heap' as a character
    void print();
    
    // find the first free tiny chunk and return its index
    int ff_tiny();

    // find the first free big chunk and return its index
    int ff_big();


    // allocate -- should return a char* to a block of at least
    // nbytes bytes. Our simple manager can only allocate blocks
    // of size up to 64 bytes.
    char* salloc(int nbytes);
    // deallocate -- takes a char* previously returned by
    // salloc() and marks the associated chunk as free.
    void sfree(char* ptr);

};


// toy unique_ptr class that works with sManager
class sUniquePtr {
    char* ptr_;
    sManager* m_;
public:
    // store a pointer allocated from an sManager object, 
    // and also a pointer to that sManager object.
    sUniquePtr(char* p, sManager* m);
    // deallocate (from the sManager) the stored pointer
    // when this object is destroyed
    ~sUniquePtr();
    // return the wrapped pointer
    char* get();
};


// STL problems

// prints each value in a std::list<int>
void print_list(std::list<int> & ls);

// replaces every instance of old_value with new_value 
void replace_specific(std::list<int>::iterator start, 
                   std::list<int>::iterator end, 
                   int old_value, 
                   int new_value);

// does the same as replace_specific but generic to type

// template, with iterator and value
template<class MyIter, class V>

// essentially copy-pasted replace_specific()
void replace_generic(MyIter start, MyIter end, V& old_value, V& new_value) {
    MyIter curr = start;

    while (curr != end){
        if (*curr == old_value){
            *curr = new_value;
        }
        curr++;
    }
}


// Write a function that returns true if the number 13
// is in a given std::set<int>.
// use a Standard Template Library inbuilt function to do so
// (mostly this is just to make sure you know how to look up and apply basic tools from the STL)
bool is_unlucky(std::set<int> & s);

// SOFT OPTIONAL:
// write a function that replaces every even value in an STL list with 0
// do this by writing a Predicate class that determines whether a value is even,
// and use it to call the STL function replace_if()
// NOTE: the Predicate class will need to go in this header file.
class isEven{
    public:
        
        // returns whether or not x % 2 = 0
        bool operator()(int x){
            return x % 2 == 0;
        }
};

void zero_evens(std::list<int> & ls);

// SOFT OPTIONAL:
// write a function that does the same, but only starts
// zeroing the even numbers AFTER it has gone through 3 even numbers.
// Do this only using a Predicate class, and a call to replace_if.
class isEven3{
    private:
        
        // counter to keep track of how many evens have been checked
        int ctr_ = 0;
    
    public:
        bool operator()(int x){
            
            // since it's the first 3 evens and not just the first 3
            // numbers, things only happen if x is even
            if (x % 2 == 0){
                
                // iterate and return false if it's the first 3 evens
                if (ctr_ < 3){
                    ctr_ ++;
                    return false;
                }
                
                // otherwise return true: even int that isn't one of the first three
                return true;
            }
            
            // otherwise it's an odd integer
            return false;
        }
};

void zero_evens_after_three(std::list<int> & ls);