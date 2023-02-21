#include <stdio.h>

int main(){
	int n;
	printf("enter no of processes: ");
	scanf("%d",&n);
	int all[n][3],max[n][3],need[n][3];
	int ava[3],vis[n];
	printf("enter ava: ");
	scanf("%d %d %d",&ava[0],&ava[1],&ava[2]);
	
	for(int i=0;i< n;i++){
		printf("\nenter allocation of %d: ",i);
		scanf("%d %d %d",&all[i][0],&all[i][1],&all[i][2]);
		printf("\nenter max of %d: ",i);
		scanf("%d %d %d",&max[i][0],&max[i][1],&max[i][2]);
		need[i][0] = max[i][0]-all[i][0];
		need[i][1] = max[i][1]-all[i][1];
		need[i][2] = max[i][2]-all[i][2];
		vis[i]=-1;
	}
	
	for(int i=0;i< n;i++){
		printf("\nallocation of %d: ",i);
		printf("%d %d %d",all[i][0],all[i][1],all[i][2]);
		printf("\nmax of %d: ",i);
		printf("%d %d %d",max[i][0],max[i][1],max[i][2]);
		printf("\nneed of %d: ",i);
		printf("%d %d %d",need[i][0],need[i][1],need[i][2]);
		printf("\n\n");
	}
	int k=1,j,i=0;
	while(k <= n){
		int flag=0;
		for(int j=0;j< 3;j++){
			if(vis[i]==1){
				flag=1;
				break;
			}
			if(need[i][j] <= ava[j]){
				continue;
			}
			else{
				flag=1;
				break;
			}
		}
		if(flag==0){
			ava[0] += all[i][0];
			ava[1] += all[i][1];
			ava[2] += all[i][2];
			vis[i]=1;
			k++;
			printf("p%d  ",i);
			i++;
		}
		else{
			i++;
		}
		if(i==n){
			i = 0;
		}
			
	}
		
}
