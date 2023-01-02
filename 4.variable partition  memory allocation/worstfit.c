// 3 300 25 70 3 150 300 35
// 4 300 25 125 50 2 150 350
// 4 357 210 468 491 6 200 400 600 500 300 250
#include <stdio.h>
int n, m, i, j;
int main()
{
	printf("Enter the no. of processes\n");
	scanf("%d", &n);

	int process_memory[n + 1];
	int process[n + 1];

	for (i = 1; i <= n; i++)
	{
		printf("memory requirementof process-%d : ", i);
		scanf("%d", &process_memory[i]);
		process[i] = -1;
	}

	printf("Enter the no. of empty partitons in the MM\n");
	scanf("%d", &m);
	int prt_size[m];

	int block_size[m + 1];
	printf("\nEnter the sizes of each blocks: \n");

	for (i = 1; i <= m; i++)
	{
		printf("process_memory of block_size-%d  ", i);
		scanf("%d", &block_size[i]);
	}
	printf("\n\n");

	int out_frag = 0;
	int empty_blocks_memory = 0;

	for (i = 1; i <= n; i++)
	{
		int max = 0, flag = 0;
		for (j = 1; j <= m; j++)
		{
			if (block_size[j] > max && block_size[j] >= process_memory[i])
			{
				max = block_size[j];
				flag = j;
			}
		}
		if (flag != 0)
		{
			process[i] = flag;
			block_size[flag] -= process_memory[i];
			// printf("if i = %d,j,flag,process[i]=%d,block_size[flag]=%d\n",i,process[i],block_size[flag]);
		}
	}

	printf("\n\n");

	for (int i = 1; i <= m; i++)
	{
		empty_blocks_memory += block_size[i];
	}

	for (i = 1; i <= n; i++)
	{
		if (process[i] != -1)
		{
			printf("process-%d is allocated to block-%d\n", i, process[i]);
		}
		else
		{
			printf("process %d is unallocated \n", i);
			if (empty_blocks_memory >= process_memory[i])
			{
				if (out_frag < process_memory[i])
					out_frag = process_memory[i];
			}
		}
	}

	printf("\n\n\nexternal fragment of memory:%d\n ", out_frag);
	printf("\nTotal memory of empty unallocated blocks = %d\n", empty_blocks_memory);
}
