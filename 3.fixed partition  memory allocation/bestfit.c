// 3 300 25 70 3 150 300 35
// 4 300 25 125 50 2 150 350
// 4 357 210 468 491 6 200 400 600 500 300 250
#include <stdio.h>
int n, m, i, j;
int main()
{
	printf("Enter the no. of processes: ");
	scanf("%d", &n);

	int process_memory[n + 1];
	int process[n + 1];

	for (i = 1; i <= n; i++)
	{
		printf("memory requirementof process-%d : ", i);
		scanf("%d", &process_memory[i]);
		process[i] = -1;
	}

	printf("enter the number of blocks in memory: ");
	scanf("%d", &m);
	int partition[m + 1];
	int prt_size[m + 1];

	for (i = 1; i <= m; i++)
	{
		printf("Size of block%d  ", i);
		scanf("%d", &prt_size[i]);
		partition[i] = -1;
	}

	int in_frag = 0;
	int out_frag = 0;
	int empty_blocks_memory = 0;

	for (i = 1; i <= n; i++)
	{
		int min = 999, flag = 0;
		for (j = 1; j <= m; j++)
		{
			if (partition[j] == -1 && process_memory[i] <= prt_size[j] && prt_size[j] < min)
			{
				min = prt_size[j];
				flag = j;
			}
		}
		if (flag != 0)
		{
			process[i] = flag;
			partition[flag] = i;
			in_frag += prt_size[flag] - process_memory[i];
		}
	}

	printf("\n\n");

	for (int i = 1; i <= m; i++)
	{
		if (partition[i] == -1)
			empty_blocks_memory += prt_size[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (process[i] == -1)
		{
			printf("process %d is unallocated\n", i);
			if (empty_blocks_memory >= process_memory[i])
			{
				if (out_frag < process_memory[i])
					out_frag = process_memory[i];
			}
		}
		else
		{
			printf("process %d is allocated to  partition %d \n", i, process[i]);
		}
	}

	printf("\n\n\ninternal fragment of memory:%d\n ", in_frag);
	printf("external fragment of memory:%d\n ", out_frag);
	printf("\nTotal memory of empty unallocated blocks = %d\n", empty_blocks_memory);
}
