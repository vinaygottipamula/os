#include <stdio.h>

int findmin(int n,int arr[][6],int vis[]){
	int min = 1000,ind;
	for(int i=1;i<=n;i++){
		if(min>arr[i][1] && vis[i] == -1){
			min = arr[i][1];
			ind = i;
		}
	}
	return ind;
}

int main(){
	int n;
	printf("enter no of processes: ");
	scanf("%d",&n);
	int arr[n+1][6],vis[n+1];
	printf("enter at and bt: ");
	for(int i=1;i<=n;i++){
		vis[i]=-1;
		arr[i][0]=i;
		printf("\nenter %d process: ",i);
		scanf("%d %d",&arr[i][1],&arr[i][2]);
	}
	int p=-1,l=0,k=0,ct=0;
	int gant_chat[100];
	for(int i=1;i<=n;i++){
		if(arr[i][1] == 0){
			p=i;
			break;
		}
	}
	if(p == -1){
		gant_chat[l++]=-1;
		p = findmin(n,arr,vis);
		gant_chat[l++]=p;
		vis[p]=1;
		arr[p][3] = arr[p][1]+arr[p][2];
		ct = arr[p][3];
		k++;
	}
	else{
		gant_chat[l++]=p;
		vis[p]=1;
		arr[p][3] = arr[p][2];
		ct = arr[p][3];
		k++;
	}
	
	while(k != n){
		p = findmin(n,arr,vis);
		if(arr[p][1] > ct){
			gant_chat[l++] = -1;
			ct = arr[p][1];
		}
		vis[p] = 1;
		gant_chat[l++] = p;
		k++;
		arr[p][3] = ct + arr[p][2];
		ct = arr[p][3];
	}
	
	for(int i=1;i<=n ;i++){
		arr[i][4] = arr[i][3] - arr[i][1];
		arr[i][5] = arr[i][4] - arr[i][2];
	}
	printf("\n Gant_chatt is: \n");
	for(int i=0;i< l;i++){
		if(gant_chat[i]==-1){
			printf("idle  ");
		}
		else{
			printf("p%d  ",gant_chat[i]);
		}
	}
	printf("\n");
	printf("p\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5]);
	}
}
