#include <stdio.h>
#include <stdlib.h>
# define INT_MAX 1000
int BT[100], AT[100], CT[10], TAT[10], WT[10], Ready_Queue[100], front = -1, rear = -1;
int is_all_finished(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (BT[i] > 0)
			return 0;
	}
	return 1;
}
int is_all_visited(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}


int min_AT(int n)
{
	int min = INT_MAX, i, in = 0;
	for (i = 0; i < n; i++)
	{
		if (AT[i] < min && BT[i] != 0)
		{
			min = AT[i];
			in = i;
		}
	}
	return in;
}
int min_AT1(int a[], int n)
{
	int min = INT_MAX, i, in = 0;
	for (i = 0; i < n; i++)
	{
		if (AT[i] < min && BT[i] != 0 && a[i] != 1)
		{
			min = AT[i];
			in = i;
		}
	}
	return in;
}
void EnQueue(int k)
{
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
		Ready_Queue[rear++] = k;
}
int DeQueue()
{
	if (front == rear)
	{
		int x = Ready_Queue[front];
		front = -1;
		rear = -1;
		return x;
	}
	else
	{
		return Ready_Queue[front++];
	}
}
int is_notin_Queue(int k)
{
	int i;
	for (i = front; i < rear; i++)
	{
		if (Ready_Queue[i] == k)
			return 0;
	}
	return 1;
}
int main()
{
	int n, TQ;
	printf("Enter the no.of processes & TQ");
	scanf("%d %d", &n, &TQ);
	int i;
	int temp_BT[n];
	for (i = 0; i < n; i++)
	{
		printf("Enter the AT,BT values of process %d",i);
		scanf("%d", &AT[i]);
		scanf("%d", &BT[i]);
		temp_BT[i] = BT[i];
	}
	int Gantt_Chart[100], process[100];
	Gantt_Chart[0] = 0;
	int gci = 1;
	printf("\n");
	while (!is_all_finished(n))
	{
		int m = min_AT(n);
		if (Gantt_Chart[gci - 1] < AT[m])
		{
			Gantt_Chart[gci] = AT[m];
			process[gci - 1] = -1;
			gci++;
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				if (AT[i] <= AT[m] && is_notin_Queue(i) == 1 && BT[i] != 0)
				{
					EnQueue(i);
				}
			}
			int x = DeQueue();
			process[gci - 1] = x + 1;
			if (BT[x] > TQ)
			{
				Gantt_Chart[gci] = Gantt_Chart[gci - 1] + TQ;
				//				process[gci-1]=x+1;
				BT[x] -= TQ;
			}
			else
			{
				Gantt_Chart[gci] = Gantt_Chart[gci - 1] + BT[x];
				BT[x] = 0;
			}
			int a[n];
			for (i = 0; i < n; i++)
			{
				if (BT[i] == 0)
					a[i] = 1;
				else
					a[i] = 0;
			}
			while (!is_all_visited(a, n))
			{
				m = min_AT1(a, n);
				if (AT[m] <= Gantt_Chart[gci] && BT[m] != 0 && m != x && is_notin_Queue(m) == 1)
				{
					EnQueue(m);
				}
				a[m] = 1;
			}
			if (BT[x] == 0)
				CT[x] = Gantt_Chart[gci];
			else
				EnQueue(x);
			gci++;
		}
	}

	for (i = 0; i < n; i++)
	{
		TAT[i] = CT[i] - AT[i];
		WT[i] = TAT[i] - BT[i];
	}
	int awt = 0, atat = 0;
	for (i = 0; i < n; i++)
	{
		awt += WT[i];
		atat += TAT[i];
	}
	printf("\n");
	printf("P.NO\tAT\tBT\tCT\tTAT\tWT\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], temp_BT[i], CT[i], TAT[i], WT[i]);
	}
	printf("\n");

	printf("THE AVERAGE WAITING TIME IS:");
	printf("     %d\n", awt / n);
	printf("THE AVERAGE TURN AROUND TIME IS:");
	printf("     %d", atat / n);

	printf("\n");

	for (i = 0; i < gci - 1; i++)
	{
		if (process[i] == -1)
			printf(" Id ");
		else
			printf(" P%d ", process[i]);
	}

		printf("\n");
	for (i = 0; i < gci; i++)
	{
		printf(" %d ", Gantt_Chart[i]);
	}
}
// 6 2 0 4 1 5 2 6 3 3 4 1 5 4

// 6 3 7 3 4 7 6 5 2 4 5 6 3 8

// 5 4 0 5 1 3 2 1 3 2 4 3

// 5 3 0 8 5 2 1 7 6 3 8 5

// 6 4 0 4 1 5 2 2 3 1 4 6 6 3

