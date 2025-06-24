#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    FILE *fp;
    int num;
    char *files[] = {"best_case.txt", "worst_case.txt", "average_case.txt"};

    int arr[1000];

    printf("Reading elements from file(best_case.txt)...\n");
    fp = fopen(files[0], "r");
    for (int i = 0; i < 1000; i++)
    {
       fscanf(fp, "%d", &arr[i]);
    }
    printf("Sorting the elements...\n");
    selectionSort(arr, 12);

    printf("Sorted array \n");
    for (int i = 0; i < 1000; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");

    return 0;
}
