/*
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Example 1:
Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.

Example 2:
Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.
*/

#include <stdio.h>
#include <stdbool.h>

bool checkIfExist(int* arr, int arrSize);

int main(void) {
    int arr[] = {7,1,14,11};
    int size = sizeof(arr) / sizeof(int);
    bool isNumHasDouble = checkIfExist(arr, size);

    isNumHasDouble ? printf("Array includes number which has it double: (True)"): printf("false");

    return 0;
}

bool checkIfExist(int* arr, int arrSize) {
    for(int i = 0; i < arrSize - 1; i++) {
        for (int j = i + 1; j < arrSize; j++){
            if (arr[i] == arr[j] * 2 || arr[j] == arr[i] * 2) {
                return true;
            }
        }
    }
    return false;
}
