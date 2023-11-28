# include <iostream>
using namespace std;

# include <vector>
# include <string>
# include <cmath>

# include "hw7.hpp"

// initializes a vec with an initial array size and capacity of 4

vec* vec_init(){
    vec* newv = new vec;
    int* newarr = new int[4];
    newv -> arr = newarr;
    newv -> length = 4;
    newv -> capacity = 4;

    return newv;
}

// deallocates a vec

void vec_destroy(vec* vec){
    delete [] vec -> arr;
    delete vec;
}

// loops through all values of the array, length determined by length, and prints them out

void vec_print(vec* vec){
    for (int i = 0; i < vec -> length; i++){
        cout << vec -> arr[i] << " ";
        
    }
    cout << "\n\n";
}

// gives the values for length and capacity, and prints out all values of the array
// similarly to vec_print() but with length determined by capacity

void vec_dprint(vec* vec){
    cout << "length: "<< vec -> length;
    cout << "\ncapacity: "<< vec -> capacity << "\n";

    cout << "entire array: ";
    for (int i = 0; i < vec -> capacity; i++){
        cout << vec -> arr[i] << " ";
    }
    cout << "\n\n";
}

// copies the array from an input vec, doubles the array's length and vec's capacity, 
// and swaps the old array out for the larger one

void vec_reallocate(vec* vec){
    
    // new array thats twice as large
    int* newarr = new int[2 * vec -> capacity];
    // update capacity
    int cap = vec -> capacity;
    cap *= 2;
    
    // copy each value from the old array to the new one
    for (int i = 0; i < vec -> capacity; i++){
        newarr[i] = vec -> arr[i];
    }
    // deallocate old array and update values
    delete [] vec -> arr;
    vec -> arr = newarr;
    vec -> capacity = cap;
}

// add a value to the end of the array, reallocating it if the vec doesn't have enough space

void vec_append(vec* vec, int new_val){
    if (vec -> length >= vec -> capacity){
        vec_reallocate(vec);
    }

    vec -> arr[vec -> length] = new_val;
    vec -> length += 1;
}

// distance formula with the x and y values of 2 pts, using doubles

double dist(pt p1, pt p2){
    double dx = p1.x - p2.x;

    double dy = p1.y - p2.y;
    
    return sqrt(dx * dx + dy * dy);
}

// makes a grid using nested vectoes and fills the vectors with pts representing points on a graph

vector< vector<pt> > make_grid(int n){
   
    // starts outer vector
    vector< vector<pt> > grid;

    for (int i = 0; i < n; i++){
        // starts inner vector
        vector<pt> row;
        
        for (int j = 0; j < n; j++){
            // for every point in the graph (whole numbers), initialize a pt with those coordinates
            pt newpt;
            newpt.y = i;
            newpt.x = j;
            // add the coordinate to the inner vector
            row.push_back(newpt);
        }
        // add the inner vector to the outer vector
        grid.push_back(row);
    }
    return grid;
}

// initializes a grid with specified size n, uses distance formula to calculate area of circle
// whose radius is 1/2 of the grid by adding to a counter every time a point is within 1/2n of 
// a centerpoint, whose coordinates are 1/2n (center of the grid). Uses the area and radius
// to approximate pi by rearranging A = pi * r^2

double piCalc(int n){
    // initialize grid
    vector< vector<pt> > grid = make_grid(n);

    // initialize centerpoint at the exact center of the grid
    pt centerpt;
    centerpt.x = n/2;
    centerpt.y = n/2;

    // total area as a double to not mess up the math later on
    double tot = n * n;

    // start a counter for area: will go up every time a point is within or on the circle
    double area = 0;
    
    // nested for loops to get every coordinate in the grid
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            
            // intiialize a pt so dist() can be used with it and the centerpoint
            pt x = grid[i][j];
            
            // if the point is within the circle, add 1 to area
            if (dist(centerpt, x) <= 0.5 * n){
                area += 1;
            }
        }
    } 
    
    // equation for area of circle rearranged
    return 4 * (area / tot);
}

