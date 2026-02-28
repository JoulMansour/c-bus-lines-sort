#include "sort_bus_lines.h"

#include <stdlib.h>

#define NUM_1 1

//these functions sort the array given, the distance and duration
//are sorted using the quicksort function that calls for the partition
//and swap functions. the names are sorted using bubble sort that calls
//for the swap function

void swap(BusLine *a, BusLine *b) {
    BusLine temp = *a;
    *a = *b;
    *b = temp;
}

BusLine *partition(BusLine *start, BusLine *end, SortType sort_type) {
    BusLine *i = start - 1;
    BusLine *pivot = end; // Pivot is the last element
    if (sort_type == DISTANCE) {
        for (BusLine *j = start; j < end; j++) {
            if (j->distance <= pivot->distance) {
                i++;
                swap(i, j);
            }
        }
    } else if (sort_type == DURATION) {
        for (BusLine *j = start; j < end; j++) {
            if (j->duration <= pivot->duration) {
                i++;
                swap(i, j);
            }
        }
    }
    swap(i + 1, pivot);
    return i + 1;
}


void quick_sort(BusLine *start, BusLine *end, SortType sort_type) {
    if (start < end) {
        // Partition the array and get the pivot
        BusLine *pivot = partition(start, end - 1, sort_type);

        // Recursively sort the two partitions
        quick_sort(start, pivot, sort_type);
        quick_sort(pivot + 1, end, sort_type);
    }
}




void bubble_sort (BusLine *start, BusLine *end) {
    int i, j;
    long num_of_lines = end - start;
    for (i = 0; i < num_of_lines - NUM_1; i++) {
        for (j = 0; j < num_of_lines - i - NUM_1; j++) {
            if (strcmp((start + j)->name, (start + j + NUM_1)->name) > 0) {
                swap(start + j, start + j + NUM_1);
            }
        }
    }
}



