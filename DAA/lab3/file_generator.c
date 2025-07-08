// generate filesm for best, worst and average
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    FILE *fp;
    fp = fopen("best.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);
    fp = fopen("worst.txt", "w");
    for (int i = n; i > 0; i--)
    {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);
    fp = fopen("average.txt", "w");
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", rand() % n);
    }
}