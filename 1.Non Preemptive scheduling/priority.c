// 7 2 0 4 4 1 2 6 2 3 1 3 5 8 4 1 3 5 4 2 11 6
// 7 2 0 3 6 2 5 3 1 4 5 4 2 7 6 9 4 5 4 10 7 10
// 5 0 7 2 1 4 3 3 7 5 2 5 1 4 6 9
// 5 1 2 2 1 3 1 0 1 4 2 0 5 3 4 2
#include <stdio.h>
#include <string.h>
int at[100], bt[100], ct[100], tat[100], wt[100], gc[100], process[100], v[100], priority[100];

int maxpriority(int n)
{
    int min = 1000;
    int k;

    for (int i = 0; i < n; i++)
    {
        if (v[i] != 1 && min > priority[i])
        {
            min = priority[i];
            k = i;
        }

        if (priority[i] == min && v[i] != 1 && at[i] < at[k])
            k = i;
    }
    return k;
}
int max2priority(int n, int a[])
{
    int min = 1000;
    int k;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1 && min > priority[i])
        {
            min = priority[i];
            k = i;
        }

        if (priority[i] == min && a[i] != 1 && at[i] < at[k])
            k = i;
    }
    return k;
}
int minofat(int n)
{
    int min = 1000;
    int k;

    for (int i = 0; i < n; i++)
    {
        if (v[i] != 1 && min > at[i])
        {

            {

                min = at[i];
                k = i;
            }
        }
    }
    return k;
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
        printf("\nEnter the priority,at & bt of process %d ", i + 1);
        scanf("%d", &priority[i]);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }

    gc[0] = 0;
    int gci = 1;

    printf("\n\n");

    while (!is_all_visited(n))
    {
        int k;
        k = maxpriority(n);
        //printf("k = %d\n", k + 1);
        if (gc[gci - 1] < at[k])
        {
            int a[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = v[i];
            }
            int c = 0;
            while (gc[gci - 1] < at[k] && c < n)
            {
                k = max2priority(n, a);
                a[k] = 1;
                c++;
            }
            if (c == n)
            {
                int s = minofat(n);
                if (gc[gci - 1] < at[s])
                {
                    gc[gci] = at[s];
                    process[gci - 1] = -1;
                    gci++;
                }

                else
                {
                    gc[gci] = gc[gci - 1] + bt[s];
                    v[s] = 1;
                    ct[s] = gc[gci];
                    tat[s] = ct[s] - at[s];
                    wt[s] = tat[s] - bt[s];
                    process[gci - 1] = s + 1;
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
    printf("\n      PT     AT       BT       CT      TAT      WT");
    for (int i = 0; i < n; i++)
    {
        printf("\n      %d     %d       %d       %d      %d       %d     ", priority[i], at[i], bt[i], ct[i], tat[i], wt[i]);
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
// 7 2 0 4 4 1 2 6 2 3 1 3 5 8 4 1 3 5 4 2 11 6