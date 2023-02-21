#include <stdio.h>
#include <stdlib.h>

int main(){
	int p;
	printf("enter no of processors: ");
	scanf("%d",&p);
	int pr[p];
	printf("enter processors: ");
	for(int i=0;i< p;i++){
		scanf("%d",&pr[i]);
	}
	int m;
	printf("enter no of memory blocks: ");
	scanf("%d",&m);
	int mem[m];
	int vis[m];
	int internal = 0;
	int external = 0;
	printf("enter memory blocks: ");
	for(int i=0;i< m;i++){
		scanf("%d",&mem[i]);
		vis[i]=0;
	}

	for(int i=0;i< p;i++){
		int j,ind=-1;
		int min = 0;
		for(j=0;j< m;j++){
			if(min < mem[j] && pr[i] <= mem[j] && vis[j] == 0){
				min = mem[j];
				ind = j;
			}
		}
		if(ind == -1){
			printf("%d is not allocated\n",pr[i]);
		}
		else{
			vis[ind]=1;
			printf("processor(%d) in memory_block(%d)\n",pr[i],mem[ind]);
			internal += mem[ind]-pr[i];
		}
	}
	
	for(int i=0;i< m;i++){
		if(vis[i]==0){
			external += mem[i];
		}
	}
	
	printf("Internal fragmentation: %d\n",internal);
	printf("External fragmentation: %d\n",external);
}
