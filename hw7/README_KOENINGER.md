## Homework 7

To compile this code, run the following command: 

```g++ hw7.cpp test.cpp -o test```

### 1(a). vec
- **where** the vec struct can be found in hw7.h
- **how** stores an int* arr, int length, and int capacity
- **notes** none

### 1(b). vec_init()
- **where** the code for vec_init() can be found in hw7.c and hw7.h
- **how** initializes a vec with an array of 4 integers, length 4, and capacity 4
- **notes** none 

### 1(c). vec_destroy
- **where** the code for vec_destroy can be found in hw7.c and hw7.h
- **how** deallocates a vec's array, then the vec itself
- **notes** none

### 1(d). vec_print and vec_dprint()
- **where** the code for vec_print and vec_dprint() can be found in hw7.c and hw7.h
- **how** vec_print() loops through a vec's array using the vec's length to know how far to go, printing each value in the array it sees
- **how** vec_dprint() does the same thing, but uses capacity instead of length in the loop. also prints the vec's length and capacity
- **notes** none

### 1(e). vec_reallocate()
- **where** the code for vec_reallocate() can be found in hw7.c and hw7.h
- **how** allocates a new array double the size of the input vec's array and copies the values of the input vec's arrays into the new array. replaces the input vec's array with the bigger one, and deallocates the old array
- **notes** none

### 1(f). vec_append()
- **where** the code for vec_append() can be found in hw7.c and hw7.h
- **how** if the input vec has equivalent length and capacity (no more room for new ints in the array), runs vec_reallocate() on it. then, regardless of length and capacity, adds 1 to length and places the input int in the next position in the array
- **notes** none

### 2(a). pt
- **where** the struct for pt can be found in hw7.h
- **how** stores 2 doubles, x and y, and represents a point on a grid
- **notes** none

### 2(b). dist()
- **where** the code for dist() can be found in hw7.c and hw7.h
- **how** runs the distance formula on 2 input pts, and returns the distance as a double
- **notes** none

### 2(c). make_grid()
- **where** the code for make_grid() can be found in hw7.c and hw7.h
- **how** creates a 2 dimensional grid by using nested vectors, and places a pt in each position in the grid whose x and y values correspond to its position in the grid
- **notes** none

### 2(d). piCalc()
- **where** the code for piCalc() can be found in hw7.c and hw7.h
- **how** approximates pi using a grid. initializes a grid of side length n, with pts in every spot in the grid. loops through every pt, running dist() on the pt and another pt at the center of the grid. if the distance is <= 1/2n, meaning the point is within the circle of radius 1/2n, add 1 to the area. once calculations have been run on all pts, use the area calculated and radius of 1/2n to solve the equation for area of a circle for pi, which is returned as a double.
- **notes** none