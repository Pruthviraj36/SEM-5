#include <stdio.h>
#include <time.h>

void linear_search(int arr[], int n, int key)
{
    clock_t start, end;
    double time_taken;

    start = clock();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            end = clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Element found at index %d\n", i);
            printf("Time taken: %f seconds\n", time_taken);
            return;
        }
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Element not found\n");
    printf("Time taken: %f seconds\n", time_taken);
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

    linear_search(arr, n, key);
    return 0;
}
