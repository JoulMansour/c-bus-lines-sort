#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "sort_bus_lines.h"
#include "test_bus_lines.h"

#define USAGE_ERR "Usage: the number of arguments should only be one\n"
#define BY_DUR "by_duration"
#define BY_DIST "by_distance"
#define BY_NAME "by_name"
#define BY_TEST "test"
#define USAGE_ERROR "Usage: argv can only be one of four" \
            "(by_duration, by_distance, by_name, or by_test)\n"
#define ENTER_NUMBER_OF_LINES "Enter number of lines. Then enter\n"
#define ERR_LESS_THAN_ZERO "Error: Number of lines should be " \
    "a positive integer\n"
#define ENTER_LINE_INFO "Enter line info. Then enter\n"
#define ERROR_ONLY_DIGIT_LOWER "Error: bus name should contains only " \
    "digits and small chars\n"
#define ERR_DIST "Error: distance should be an integer " \
    "between 0 and 1000 (includes)\n"
#define ERR_DUR "Error: duration should be an integer " \
    "between 10 and 100 (includes)\n"
#define TEST_1_PASSED "TEST 1 PASSED: The array is sorted by distance\n"
#define TEST_1_FAILED "TEST 1 FAILED: not sorted by distance.\n"
#define TEST_2_PASSED "TEST 2 PASSED: The array has the same " \
    "items after sorting\n"
#define TEST_2_FAILED "TEST 2 FAILED: original array was modified.\n"
#define TEST_3_PASSED "TEST 3 PASSED: The array is sorted by duration\n"
#define TEST_3_FAILED "TEST 3 FAILED: not sorted by duration.\n"
#define TEST_4_PASSED "TEST 4 PASSED: The array has the same " \
    "items after sorting\n"
#define TEST_4_FAILED "TEST 4 FAILED: original array was modified.\n"
#define TEST_5_PASSED "TEST 5 PASSED: The array is sorted by name\n"
#define TEST_5_FAILED "TEST 5 FAILED: not sorted by name.\n"
#define TEST_6_PASSED "TEST 6 PASSED: The array has the same " \
    "items after sorting\n"
#define TEST_6_FAILED "TEST 6 FAILED: original array was modified.\n"
#define NUM_1 1
#define NUM_2 2
#define NUM_3 3
#define NUM_10 10
#define NUM_63 63
#define NUM_100 100
#define NUM_1000 1000



/**
 * the main  function gets the number of lines as input from the
 * user and keeps getting information about each line until
 * info has been given about all the lines, if an input is invalid
 * an appropriate error message will appear and ask for inout again
 * then it will sort or test the given input according to the demand
 * and finally it will print the result
 */


int check_cli(int argc, char *argv[]) {
    if (argc != NUM_2) {
        printf(USAGE_ERR);
        return NUM_1;
    }
    if (strcmp(argv[NUM_1], BY_DUR) != 0 &&
        strcmp(argv[NUM_1], BY_DIST) != 0 &&
        strcmp(argv[NUM_1], BY_NAME) != 0 &&
        strcmp(argv[NUM_1], BY_TEST) != 0) {
        printf(USAGE_ERROR);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int check_num_of_lines_input() {
    char buffer[NUM_63];
    int number;
    while (NUM_1) {
        printf(ENTER_NUMBER_OF_LINES);
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &number);

        if (number > 0) {
            return number;
        } else {
            printf(ERR_LESS_THAN_ZERO);
            continue;
        }
    }
}



BusLine* check_info_input(int number) {
    BusLine *arr = malloc(sizeof(BusLine)*number);
    if (arr == NULL) {
        return NULL;
    }
    int i = 0;
    char buffer[NUM_63];
    char str[NAME_LEN];
    int distance, duration;
    while (i < number) {
        printf(ENTER_LINE_INFO);
        if (fgets(buffer, sizeof(buffer), stdin)) {
            if (sscanf(buffer, "%[^,],%d,%d", str,
                &distance, &duration) == NUM_3) {
                int valid_name = NUM_1;
                for (size_t j = 0; j < strlen(str); j++) {
                    if (!islower(str[j]) && !isdigit(str[j])) {
                        valid_name = 0;
                        break;
                    }
                }
                if (!valid_name) {
                    printf(ERROR_ONLY_DIGIT_LOWER);
                    continue;
                }
                if (distance < 0 || distance > NUM_1000) {
                    printf(ERR_DIST);
                    continue;
                }
                if (duration < NUM_10 || duration > NUM_100) {
                    printf(ERR_DUR);
                    continue;
                }
                strncpy(arr[i].name, str, NAME_LEN - NUM_1);
                arr[i].name[NAME_LEN - NUM_1] = '\0';
                arr[i].distance = distance;
                arr[i].duration = duration;
                i++;
                } else {
                    printf(ERR_DIST);
                    continue;
                }
        }
    }
    return arr;
}


int tests(BusLine *start, BusLine *end) {
    size_t size = end - start;
    BusLine *original_copy = malloc(size * sizeof(BusLine));
    if (original_copy == NULL) {
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < size; i++) {
        original_copy[i] = start[i];
    }
    quick_sort(start, end, DISTANCE);
    if (is_sorted_by_distance (start, end) == 0) {
        printf(TEST_1_FAILED);
    } else {
        printf(TEST_1_PASSED);
    }
    if (is_equal(start, end,
        original_copy, original_copy + size) == 0) {
        printf(TEST_2_FAILED);
    } else {
        printf(TEST_2_PASSED);
    }
    quick_sort(start, end, DURATION);
    if (is_sorted_by_duration (start, end) == 0) {
        printf(TEST_3_FAILED);
    } else {
        printf(TEST_3_PASSED);
    }
    if (is_equal(start, end,
        original_copy, original_copy + size) == 0) {
        printf(TEST_4_FAILED);
    } else {
        printf(TEST_4_PASSED);
    }
    bubble_sort(start, end);
    if (is_sorted_by_name (start, end) == 0) {
        printf(TEST_5_FAILED);
    } else {
        printf(TEST_5_PASSED);
    }
    if (is_equal(start, end,
        original_copy, original_copy + size) == 0) {
        printf(TEST_6_FAILED);
    } else {
        printf(TEST_6_PASSED);
    }
    free(original_copy);
    return EXIT_SUCCESS;
}



int main(int argc, char *argv[]) {
    if (check_cli(argc, argv) != 0) {
        return EXIT_FAILURE;
    }
    int number = check_num_of_lines_input();
    BusLine *arr = check_info_input(number);
    if (arr == NULL) {
        return EXIT_FAILURE;
    }
    if (strcmp(argv[NUM_1], BY_DUR) == 0) {
        quick_sort(arr, arr + number, DURATION);
        for (int i = 0; i < number; i++) {
            printf("%s,%d,%d\n", arr[i].name,
                arr[i].distance, arr[i].duration);
        }
    }
    if (strcmp(argv[NUM_1], BY_DIST) == 0) {
        quick_sort(arr, arr + number, DISTANCE);
        for (int i = 0; i < number; i++) {
            printf("%s,%d,%d\n", arr[i].name,
                arr[i].distance, arr[i].duration);
        }
    }
    if (strcmp(argv[NUM_1], BY_NAME) == 0) {
        bubble_sort(arr, arr + number);
        for (int i = 0; i < number; i++) {
            printf("%s,%d,%d\n", arr[i].name,
                arr[i].distance, arr[i].duration);
        }
    }
    if (strcmp(argv[NUM_1], BY_TEST) == 0) {
        return tests(arr, arr + number);
    }
    free(arr);
    return EXIT_SUCCESS;
}

