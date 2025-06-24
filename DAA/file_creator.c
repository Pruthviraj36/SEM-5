#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fileCreator()
{
    FILE *fp;
    char *files[] = {"best_case.txt", "worst_case.txt", "average_case.txt"};

    for (int i = 0; i < 3; i++)
    {
        fp = fopen(files[i], "w");
        if (fp == NULL) {
            printf("Error opening file %s\n", files[i]);
            return;
        }

        if (i == 0) {
            for (int j = 0; j < 100000; j++)
                fprintf(fp, "%d\n", j);
        } else if (i == 1) {
            for (int j = 100000; j >= 0; j--)
                fprintf(fp, "%d\n", j);
        } else {
            srand(time(0));
            for (int j = 0; j < 100000; j++)
                fprintf(fp, "%d\n", rand());
        }

        fclose(fp);
    }
}

int main()
{
    fileCreator();
    return 0;
}
