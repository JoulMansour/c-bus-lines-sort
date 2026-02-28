#ifndef EX2_REPO_TESTBUSLINES_H
#define EX2_REPO_TESTBUSLINES_H
// write only between #define EX2_REPO_TESTBUSLINES_H and #endif //EX2_REPO_TESTBUSLINES_H
#include "sort_bus_lines.h"

/**
 * this function tests if the distances are sorted
 * it works by using a while loop
 * where it iterates though all the distances
 * if a distance is bigger than the next distance then the test failed
 * and 0 is returned
 */
int is_sorted_by_distance (const BusLine *start, const BusLine *end);

/**
 * this function tests if the durations are sorted
 * it works by using a while loop
 * where it iterates though all the durations
 * if a duration is bigger than the next duration then the test failed
 * and 0 is returned
 */
int is_sorted_by_duration (const BusLine *start, const BusLine *end);

/**
 * this function tests if the names are sorted
 * it works using a while loop
 * where it iterates through all the names
 * the function uses strcmp to compare between the names
 * if a name is bigger than the next name then the test failed
 * and 0 is returned
 */
int is_sorted_by_name (const BusLine *start, const BusLine *end);

/**
 * this function tests if the original array is equal to the sorted array
 * it does that by first comparing the number of elements in each one
 * if they are not equal, o is returned
 * then the names of the buses are compared in each one using two for loops
 * if a name in the sorted array is not found in the original array
 * 0 is returned
 */
int is_equal (const BusLine *start_sorted,
              const BusLine *end_sorted,
              const BusLine *start_original,
              const BusLine *end_original);
// write only between #define EX2_REPO_TESTBUSLINES_H and #endif //EX2_REPO_TESTBUSLINES_H
#endif //EX2_REPO_TESTBUSLINES_H
