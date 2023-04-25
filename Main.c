#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Algorithms.c"
//#define PRINT

int main() {
    clock_t start_time, end_time;
    char choice;
    int n;
    printf("Please select sorting algorithm:\n[i] - insert sort\n[s] - selection sort\n[b] - bubble sort\n[q] - quick sort\n[l] - shell sort\n[h] - heap sort\n");
    scanf(" %c", &choice);
    printf("Enter values count that yoqu want to sort\n");
    scanf("%d", &n);
    /*
    for(int i = 200000; i <= 2600000; i += 200000) {
        FILE *input_file = fopen("dane_posortowane_odwrotnie.txt", "r");
        if (input_file == NULL) {
            printf("Error opening input file!\n");
            return 1;
        }
        int value;
        int* arr = (int*)malloc(i * sizeof(int));
        for(int z = 0; z < i; z++) {
            fscanf(input_file, "%d", &arr[z]);
        }
        fclose(input_file);
        start_time = clock();
        heap_sort(arr, i);
        end_time = clock();
        printf("%f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    }
    */
    
    FILE *input_file = fopen("dane_losowe.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    
    int value;
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }
    fclose(input_file);

    switch (choice) {
        case 'i':
            start_time = clock();
            insert_sort(arr, n);
            end_time = clock();
            break;
        case 's':
            start_time = clock();
            selection_sort(arr, n);
            end_time = clock();
            break;
        case 'b':
            start_time = clock();
            bubble_sort(arr, n);
            end_time = clock();
            break;
        case 'q':
            start_time = clock();
            quick_sort(arr, 0, n);
            end_time = clock();
            break;
        case 'l':
            start_time = clock();
            shell_sort(arr, n);
            end_time = clock();
            break;
        case 'h':
            start_time = clock();
            heap_sort(arr, n);
            end_time = clock();
            break;
        default:
            printf("Error\n");
    }
    printf("Sorting time: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
#if defined(PRINT)
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
#endif
    printf("\n");
    
    return 0;
}