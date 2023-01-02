// 3 5 3 3 2 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 0
// 3 5 2 3 0 0 1 0 3 0 2 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 0
#include <stdio.h>
int t, n, p = 0;
int finish[10];
int process[10];
int alloc[10][10];
int max[10][10];
int need[10][10];
int available[10];
int work[10];

int neediwork()
{
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == -1)
        {

            int flag = 0;
            for (int j = 0; j < t; j++)
            {
                if (need[i][j] > work[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    printf("\nEnter the no. of types of resources  :");
    scanf("%d", &t);
    printf("\nEnter the no. of processes :");
    scanf("%d", &n);

    printf("\nEnter the no. of available resources :");
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    printf("\n\n");

    printf("\nEnter the no. of allocated resources matrix :");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
        finish[i] = -1;
        process[i] = -1;
    }

    printf("\nEnter the no. of max resources matrix :");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            scanf(" %d ", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            printf(" %d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        int k = neediwork();
        if (k == -1)
        {
            printf("\nNO SAFE STATE EXISTS\n");
        }

        for (int j = 0; j < t; j++)
        {
            work[j] += alloc[k][j];
        }

        finish[k] = 1;
        process[i] = k;
    }

    printf("\n\n");

    for (int i = 0; i < t; i++)
    {
        printf(" %d ", work[i]);
    }
    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", process[i]);
    }
    printf("\n\n");

    return 0;
}
