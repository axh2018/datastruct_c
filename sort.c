#include <stdio.h>
#include <stdlib.h>

/**
 * 冒泡排序
 * @param arr
 * @param size
 */
void BubbleSort(int *arr, int size)
{
    int i, j, tmp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

/**
 * 选择排序
 * @param arr
 * @param size
 */
void SelectionSort(int *arr, int size)
{
    int i, j, k, tmp;
    for (i = 0; i < size - 1; i++) {
        k = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        tmp = arr[k];
        arr[k] = arr[i];
        arr[i] = tmp;
    }
}


/**
 * 插入排序
 * @param arr
 * @param size
 */
void InsertionSort(int *arr, int size)
{
    int i, j, tmp;
    for (i = 1; i < size; i++) {
        if (arr[i] < arr[i-1]) {
            tmp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
                arr[j+1] = arr[j];
            }
            arr[j+1] = tmp;
        }
    }
}

/**
 * 希尔排序
 * @param arr
 * @param size
 */
void ShellSort(int *arr, int size)
{
    int i, j, tmp, increment;
    for (increment = size/ 2; increment > 0; increment /= 2) {
        for (i = increment; i < size; i++) {
            tmp = arr[i];
            for (j = i - increment; j >= 0 && tmp < arr[j]; j -= increment) {
                arr[j + increment] = arr[j];
            }
            arr[j + increment] = tmp;
        }
    }
}

