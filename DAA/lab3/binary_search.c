#include <stdio.h>
#include <time.h>

int binary_search(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binary_search(arr, low, mid - 1, key);
    else
        return binary_search(arr, mid + 1, high, key);

    // ITRATIVE APPROACH

    
    // while (low <= high) {
    //     int mid = low + (high - low) / 2;

    //     if (arr[mid] == key)
    //         return mid;
    //     else if (arr[mid] < key)
    //         low = mid + 1;
    //     else
    //         high = mid - 1;
    // }
}

int main()
{
    printf("Choose the type of case:\n");
    printf("1. Best case\n");
    printf("2. Worst case\n");
    printf("3. Average case\n");

    int choice;
    scanf("%d", &choice);

    FILE *fp;
    int arr[1000000];
    int n = 1000000;

    switch (choice)
    {
    case 1:
        fp = fopen("best.txt", "r");
        break;
    case 2:
        fp = fopen("worst.txt", "r");
        break;
    case 3:
        fp = fopen("average.txt", "r");
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    clock_t start = clock();
    int result = binary_search(arr, 0, n - 1, key);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
