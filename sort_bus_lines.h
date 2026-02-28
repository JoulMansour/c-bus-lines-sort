#ifndef EX2_REPO_SORTBUSLINES_H
#define EX2_REPO_SORTBUSLINES_H
// write only between #define EX2_REPO_SORTBUSLINES_H and #endif //EX2_REPO_SORTBUSLINES_H
#include <string.h>
#define NAME_LEN 21
/**
 *This defines a struct named BusLine
 */
typedef struct BusLine
{
    char name[NAME_LEN];
    int distance, duration;
} BusLine;

typedef enum SortType
{
    DISTANCE,
    DURATION
} SortType;

/**
 * this sort function is used to sort the names
 * it works using bubble sort
 */
void bubble_sort (BusLine *start, BusLine *end);

/**
 * this sort function works to sort the distances or durations
 * it works using quick sort
 */
void quick_sort (BusLine *start, BusLine *end, SortType sort_type);

/**
 * this function is called in the quick sort function when sorting
 */
BusLine *partition (BusLine *start, BusLine *end, SortType sort_type);
// write only between #define EX2_REPO_SORTBUSLINES_H and #endif //EX2_REPO_SORTBUSLINES_H
#endif //EX2_REPO_SORTBUSLINES_H
