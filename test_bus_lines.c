#include "test_bus_lines.h"
#include <string.h>

#define NUM_1 1

//these are the functions to test if the array is sorted
//or not, there is a test for distance, duration and name
//and there is also a function that checks if the original array
//is equal to the array after it is sorted


int is_sorted_by_distance (const BusLine *start, const BusLine *end) {
    const BusLine *current = start;
    while (current < end - NUM_1) {
        if((*current).distance > (*(current+NUM_1)).distance ) {
            return 0;
        }
        current++;
    }
    return NUM_1;
}

int is_sorted_by_duration (const BusLine *start, const BusLine *end) {
    const BusLine *current = start;
    while (current < end - NUM_1) {
        if((*(current)).duration > (*(current+NUM_1)).duration ) {
            return 0;
        }
        current++;
    }
    return NUM_1;
}

int is_sorted_by_name (const BusLine *start, const BusLine *end) {
    const BusLine *current = start;
    while (current < end - NUM_1) {
        if(strcmp((*current).name, (*(current+NUM_1)).name ) > 0) {
            return 0;
        }
        current++;
    }
    return NUM_1;
}


int is_equal(const BusLine *start_sorted,
             const BusLine *end_sorted,
             const BusLine *start_original,
             const BusLine *end_original) {
    long sorted_count = end_sorted - start_sorted;
    long original_count = end_original - start_original;

    if (sorted_count != original_count) {
        return 0;
    }
    int matched = 0;
    for (const BusLine *sorted = start_sorted; sorted < end_sorted; sorted++) {
        int found = 0;
        for (const BusLine *original = start_original;
            original < end_original; original++) {
            if (strcmp(sorted->name, original->name) == 0) {
                found = NUM_1;
                break;
            }
        }
        if (found) {
            matched++;
        } else {
            return 0;
        }
    }
    return NUM_1;
}



