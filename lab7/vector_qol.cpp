#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_grid(vector< vector<int> > grid) {
    cout << "[\n";
    for (int i=0; i<grid.size(); i++) {
        cout << "   [";
        for (int j=0; j<grid[i].size(); j++) {
            cout << " " << grid[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    // handles memory allocation/deallocation internally
    vector<int> xs;

    // can add elements dynamically
    for (int i=0; i<7; i++) {
        xs.push_back(i*2); // appends element to the end
    }

    // stores size internally
    cout << "[";
    for (int i=0; i<xs.size(); i++) {
        cout << " " << xs[i] << " ";
    }
    cout << "]\n";

    // can remove elements dynamically
    xs.pop_back(); // removes last element
    xs.pop_back();

    cout << "[";
    for (int i=0; i<xs.size(); i++) {
        cout << " " << xs[i] << " ";
    }
    cout << "]\n";

    // generic to type
    vector<string> words;
    words.push_back("the");
    words.push_back("quick");
    words.push_back("brown");
    words.push_back("fox");

    cout << "[";
    for (int i=0; i<words.size(); i++) {
        cout << " " << words[i] << " ";
    }
    cout << "]\n";

    // we can even store vectors in vectors
    // this stores a grid of numbers:
    vector< vector<int> > g; // initialize outer vector
    for (int i=0; i<5; i++) {
        vector<int> row; // initialize inner vector
        for (int j=0; j<5; j++) {
            row.push_back(i*j);
        }
        g.push_back(row); // place inner vector inside outer vector
    }

    print_grid(g);


    return 0;
}