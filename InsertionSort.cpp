// Author: Nathan Maynard
// Course: CSC 112 Section B (Fall 2019)
// Project: Project 6 - InsertionSort
// Due Date: 3:30pm, Oct. 31, 2019

#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
using namespace std;

int main() {

    int seed;
    int limit;
    int iter = 1;

    cout << "Please type the seed as an integer" << endl;
    cin >> seed;
    cout << "The length of the vector/linked list will start at 100 and " << endl <<
            "will increase by another 100 each iteration" << endl;
    cout << "How many iterations would you like to run?" << endl;
    cin >> limit;
    srand(seed);

    while (iter <= limit) {
        LinkedList list;
        vector<int> v(100 * iter);

        // generate vector of random integers
        for (int i = 0; i < v.size(); i++) {
            v[i] = rand() % 100;
        }

        // Copy Unsorted Values to Linked List
        for (int i = 0; i < v.size(); i++) {
            list.Append(v[i]);
        }

        // binary insertion sort
        clock_t start_insertionSort = clock();
        insertionSort(v, v.size());
        clock_t end_insertionSort = clock();

        // check if sorted
        for (int i = 1; i < v.size(); i++) {
            assert(v[i-1] <= v[i]);
        }

        // print out sorted list
        cout << "Sorted Vector:" << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // FINISH ME

        // Sort Linked List
        clock_t start_listInsertionSort = clock();
        list.ListInsertionSort();
        clock_t end_listInsertionSort = clock();

        // Print Sorted Linked List
        cout << "Sorted Linked List:" << endl;
        list.PrintList();
        cout << endl;

        // Calc Times
        double elapsed_insertionSort = double(end_insertionSort - start_insertionSort) / CLOCKS_PER_SEC;
        double elapsed_listInsertionSort = double(end_listInsertionSort - start_listInsertionSort) / CLOCKS_PER_SEC;

        // Print Elapsed Times
        cout << endl << "Elapsed Time for vector insertionSort() with " << (100 * iter) << " elements: " << elapsed_insertionSort;
        cout << endl << "Elapsed Time for linked list listInsertionSort() with " << (100 * iter) << " elements: " << elapsed_listInsertionSort << endl;
        cout << endl;

        iter++;
    }
}