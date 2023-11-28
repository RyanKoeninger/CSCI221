# ifndef HW7_H
# define HW7_H
# include <iostream>
# include <vector>
# include <string>
# include <cmath>

struct vec{
    int* arr;
    int length;
    int capacity;
};

struct pt{
    double x;
    double y;
};

vec* vec_init();

void vec_destroy(vec*);

void vec_print(vec*);

void vec_dprint(vec*);

void vec_reallocate(vec*);

void vec_append(vec*, int);

double dist(pt, pt);

vector< vector<pt> > make_grid(int);

double piCalc(int);
# endif