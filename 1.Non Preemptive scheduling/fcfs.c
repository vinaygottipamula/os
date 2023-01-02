//5 2 2 4 3 7 5 5 7 6 9
//6 0 4 1 2 2 3 3 5 4 6 5 2 
//6 5 3 8 6 3 3 6 1 2 2 4 5
#include <stdio.h>
int at[100], bt[100], ct[100], tat[100], wt[100], gc[100],process[100] = {-1},v[100] = {0};

int findmin(int n)
{
    int min = 1000;
    int k;

    for (int i = 0; i < n; i++)
    {
        if (v[i] != 1 && min > at[i])
        {

            min = at[i];
            k = i;
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
		k = findmin(n);
        printf("gc = %d ,at = %d\n,process = %d",gc[gci-1],at[k],k+1);
		if (gc[gci - 1] < at[k])
		{
			gc[gci] = at[k];
			process[gci - 1] = -1;
			gci++;
		}

		else
		{
			gc[gci] = gc[gci - 1] + bt[k];
			process[gci - 1] = k + 1;
			v[k] = 1;
			ct[k] = gc[gci];
            tat[k] = ct[k] - at[k];
            wt[k] = tat[k] - bt[k];
			gci++;
		}
	}
    printf("\n     AT       BT       CT      TAT      WT");
    for (int i = 0; i < n; i++)
    {
        printf("\n     %d       %d       %d      %d       %d     ", at[i], bt[i], ct[i], tat[i],wt[i]);
    }

for (int i = 0; i < n; i++)
{
    avgtat += tat[i];
    avgwt += wt[i];
}


avgtat = avgtat/n;
avgwt = avgwt/n;

printf("\n\n\nAverage Turn Around Time = %2f ",avgtat);
printf("\nAverage Wait Time = %2f \n",avgwt);
printf("\nTotal Idle Time = %d \n\n gantt chart: \n\n",idletime);

for (int i = 0; i < gci - 1; i++)
	{
		if (process[i] == -1)
			printf(" -1 ");
		else
			printf(" P%d ", process[i]);
	}
    printf("\n\n");


for (int i = 0; i < gci; i++)
{
    printf(" %d ",gc[i]);
}




    return 0;
}