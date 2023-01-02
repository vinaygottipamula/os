// 6 0 8  1 6 2 5 3 2 4 4 5 1
//7 5 1 2 1 4 3 1 10 3 4 1 8 2 6
//6 0 8 1 4 2 2 3 1 4 3 5 2
#include <stdio.h>
#include <string.h>
#define tq 1
int at[100], bt[100], Bt[100], ct[100], tat[100], wt[100], gc[100], process[100];

int is_all_visited(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (bt[i] > 0)
            return 0;
    }
    return 1;
}
int findminofbt(int n)
{
    int min = 1000;
    int p1;

    for (int i = 0; i < n; i++)
    {
        if (bt[i] != 0 && min > bt[i])
        {
            min = bt[i];
            p1 = i;
        }

        if (bt[i] == min && bt[i] != 0 && at[i] < at[p1])
            p1 = i;
    }
    return p1;
}
int find2minofbt(int a[],int n)
{
    int min = 1000;
    int p1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && min > bt[i] && bt[i] != 0)
        {
            min = bt[i];
            p1 = i;
        }

        if (bt[i] == min && a[i] == 0 && at[i] < at[p1])
            p1 = i;
    }
    return p1;
}

int findminofat(int n)
{
    int min = 1000;
    int s;

    for (int i = 0; i < n; i++)
    {
        if (bt[i] != 0 && min > at[i])
        {
            min = at[i];
            s = i;
        }

        if (bt[i] != 0 && bt[i] < bt[s] && min == at[i])
        {
            s = i;
        }
    }
    return s;
}

int main()
{
    int n;
    printf("\nEnter the no of processes");
    scanf("%d", &n);
    memset(bt, 0, 100 * sizeof(bt[0]));
    memset(process, -1, 100 * sizeof(process[0]));

    float avgwt = 0, avgtat = 0;
    int idletime = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the at & bt of process %d ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        Bt[i] = bt[i];
    }

    gc[0] = 0;
    int gci = 1;

    printf("\n\n");

    while (!is_all_visited(n))
    {
        int m = findminofbt(n);
        if (gc[gci - 1] < at[m])
        {

            int a[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = 0;
            }
            int c = 0;
            while (gc[gci - 1] < at[m] && c < n)
            {
                m = find2minofbt(a, n);
                c++;
                a[m] = 1;
            }
            if (c == n)
            {
                int s = findminofat(n);
                if (gc[gci - 1] < at[s])
                {
                    gc[gci] = at[s];
                    process[gci - 1] = -1;
                    gci++;
                }
                else
                {
                    if (process[gci - 2] == (s + 1) && gci > 1)
                    {
                        gc[gci - 1]++;
                        bt[s]--;
                        if (bt[s] == 0)
                        {
                            ct[s] = gc[gci-1];
                            tat[s] = ct[s] - at[s];
                            wt[s] = tat[s] - Bt[s];
                        }
                        
                    }
                    else
                    {
                        gc[gci] = gc[gci - 1] + 1;
                        bt[s]--;
                        if (bt[s] == 0)
                        {
                            ct[s] = gc[gci];
                            tat[s] = ct[s] - at[s];
                            wt[s] = tat[s] - Bt[s];
                        }
                        process[gci - 1] = s + 1;
                        gci++;
                    }
                }
            }
            else if (process[gci - 2] == m + 1)
            {
                gc[gci - 1] += 1;
                bt[m]--;
                if (bt[m] == 0)
                        {
                            ct[m] = gc[gci-1];
                            tat[m] = ct[m] - at[m];
                            wt[m] = tat[m] - Bt[m];
                        }
            }
            else
            {
                process[gci - 1] = m + 1;
                gc[gci] = gc[gci - 1] + 1;
                bt[m] -= 1;
                if (bt[m] == 0)
                        {
                            ct[m] = gc[gci];
                            tat[m] = ct[m] - at[m];
                            wt[m] = tat[m] - Bt[m];
                        }
                gci++;
            }
        }
        else
        {
            if (process[gci - 2] == m + 1)
            {
                gc[gci - 1] += 1;
                bt[m]--;
                if (bt[m] == 0)
                        {
                            ct[m] = gc[gci-1];
                            tat[m] = ct[m] - at[m];
                            wt[m] = tat[m] - Bt[m];
                        }
            }
            else
            {
                process[gci - 1] = m + 1;
                gc[gci] = gc[gci - 1] + 1;
                bt[m]--;
                if (bt[m] == 0)
                        {
                            ct[m] = gc[gci];
                            tat[m] = ct[m] - at[m];
                            wt[m] = tat[m] - Bt[m];
                        }
                gci++;
            }
        }
    }

    printf("\n     AT       BT       CT      TAT      WT");
    for (int i = 0; i < n; i++)
    {
        printf("\n     %d       %d       %d      %d       %d     ", at[i], Bt[i], ct[i], tat[i], wt[i]);
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

    for (int i = 0; i < gci; i++)
    {
        printf(" %d ", gc[i]);
    }

    return 0;
}