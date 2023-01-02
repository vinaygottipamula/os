// 3 300 25 70 3 150 300 35
// 4 300 25 125 50 2 150 350
// 4 357 210 468 491 6 200 400 600 500 300 250
#include <stdio.h>
int n, m;
int main()
{
    printf("Enter the no. of processes\n");
    scanf("%d", &n);

    int process_memory[n];
    int process[n];

    for (int i = 0; i < n; i++)
    {
        printf("memory requirementof process-%d : ", i);
        scanf("%d", &process_memory[i]);
        process[i] = -1;
    }

    printf("Enter the no. of empty partitons in the MM\n");
    scanf("%d", &m);
    int partition[m];
    int prt_size[m];

    for (int i = 0; i < m; i++)
    {
        printf("Size of block%d  ", i);
        scanf("%d", &prt_size[i]);
        partition[i] = -1;
    }

    int in_frag = 0;
    int out_frag = 0;
    int empty_blocks_memory = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (partition[j] == -1 && process_memory[i] <= prt_size[j])
            {
                process[i] = j + 1;
                partition[j] = i + 1;
                in_frag += prt_size[j] - process_memory[i];
                // printf("%dparition is occupied with %d process\n",j+1,i);
                break;
            }
        }
    }

    printf("\n\n");

    for (int i = 0; i < m; i++)
    {
        if (partition[i] == -1)
            empty_blocks_memory += prt_size[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (process[i] == -1)
        {
            printf("process %d is unallocated\n", i + 1);
            if (empty_blocks_memory >= process_memory[i])
            {
                if (out_frag < process_memory[i])
                    out_frag = process_memory[i];
            }
        }
        else
        {
            printf("process %d is allocated to  partition %d \n", i + 1, process[i]);
        }
    }
    printf("\nInternal Fragmentation = %d and External Fragmentation = %d\n", in_frag, out_frag);
    printf("\nTotal memory of empty unallocated blocks = %d\n", empty_blocks_memory);
}