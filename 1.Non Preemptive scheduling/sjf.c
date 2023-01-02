//4 0 10 1 3 2 6 3 2
//6 0 4 1 2 2 3 3 1 4 5 5 1
//7 8 2 3 2 6 5 2 8 5 3 4 1 2 6
#include <stdio.h>
#include <string.h>
int at[100], bt[100], ct[100], tat[100], wt[100], gc[100], process[100], v[100];

int findminofbt(int n)
{
    int min = 1000;
    int k;

    for (int i = 0; i < n; i++)
    {
        if (bt[i] < min && v[i] != 1)
        {
            min = bt[i];
            k = i;
        }

        if (bt[i] == min && v[i] != 1 && at[i] < at[k])
            k = i;
    }
    return k;
}

int findminofat(int n)
{
    int min = 1000;
    int s;

    for (int i = 0; i < n; i++)
    {
        if (at[i] < min && v[i] != 1)
        {
            min = at[i];
            s = i;
        }

        if (at[i] == min && v[i] != 1)
        {
            if (bt[s] > bt[i])
            {
                s = i;
            }
        }
    }
    return s;
}

int is_all_visited(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    printf("\nEnter the no of processes");
    scanf("%d", &n);
    memset(v, 0, 100 * sizeof(v[0]));
    memset(process, -1, 100 * sizeof(process[0]));

    float avgwt = 0, avgtat = 0;
    int idletime = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the at & bt of process %d ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }

    gc[0] = 0;
    int gci = 1;

    printf("\n\n");

    while (!is_all_visited(n))
    {
        int k;
        k = findminofbt(n);
        if (gc[gci - 1] < at[k])
        {
            int a;
            a = findminofat(n);

            if (gc[gci - 1] < at[a])
            {

                gc[gci] = at[a];
                process[gci - 1] = -1;
                gci++;
            }
            else
            {
                gc[gci] = gc[gci - 1] + bt[a];
                v[a] = 1;
                ct[a] = gc[gci];
                tat[a] = ct[a] - at[a];
                wt[a] = tat[a] - bt[a];
                process[gci - 1] = a + 1;
                gci++;
            }
        }

        else
        {
            gc[gci] = gc[gci - 1] + bt[k];
            v[k] = 1;
            ct[k] = gc[gci];
            tat[k] = ct[k] - at[k];
            wt[k] = tat[k] - bt[k];
            process[gci - 1] = k + 1;
            gci++;
        }
    }
    printf("\n     AT       BT       CT      TAT      WT");
    for (int i = 0; i < n; i++)
    {
        printf("\n     %d       %d       %d      %d       %d     ", at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    for (int i = 0; i < n; i++)
    {
        avgtat += tat[i];
        avgwt += wt[i];
    }

    avgtat = avgtat / n;
    avgwt = avgwt / n;

    printf("\n\n\nAverage Turn Around Time = %2f ", avgtat);
    printf("\nAverage Wait Time = %2f \n", avgwt);
    printf("\nTotal Idle Time = %d \n\n gantt chart: \n\n", idletime);

    for (int i = 0; i < gci - 1; i++)
    {
        if (process[i] == -1)
            printf(" -1 ");
        else
            printf(" P%d ", process[i]);
    }
    printf("\n\n");

    gc[0] = 0;

    for (int i = 0; i <= gci; i++)
    {
        printf(" %d ", gc[i]);
    }

    return 0;
}