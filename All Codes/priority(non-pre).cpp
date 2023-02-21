#include <stdio.h>

int findmin1(int n,int arr[][7],int vis[]){
	int min = 100000,ind;
	for(int i =1;i<=n;i++){
		if(min > arr[i][1] && vis[i]==-1){
			min = arr[i][1];
			ind = i;
		}
	}
	return ind;
}


int findmin(int n,int arr[][7],int vis[],int ct){
	int min = 10000,ind=-1;
	for(int i=1;i<=n;i++){
		if(vis[i]==-1 && ct >= arr[i][1] && (min > arr[i][3] || (min == arr[i][3] && arr[ind][1] > arr[i][1]))){
			min = arr[i][3];
			ind = i;
		}
	}
	return ind;
}


int main(){
	int n;
	printf("enter no of processes: ");
	scanf("%d",&n);
	int arr[n+1][7],vis[n+1];
	printf("enter at and bt and pt:\n");
	for(int i=1;i<=n;i++){
		vis[i]=-1;
		arr[i][0] = i;
		printf("\nenter %d process: ",i);
		scanf("%d %d %d",&arr[i][1],&arr[i][2],&arr[i][3]);
	}
	
	int l=0,k=0,p=-1,ct=0;
	int gant_chat[100];
	int min = 100000;
	for(int i=1;i<=n;i++){
		if(min > arr[i][1] || (min == arr[i][1] && arr[i][3] < arr[p][3])){
			min = arr[i][1];
			p = i;
		}
	}
	if(min != 0){
		gant_chat[l++]=-1;
		gant_chat[l++]=p;
		k++;
		vis[p] = 1;
		arr[p][4] = arr[p][1] + arr[p][2];
		ct = arr[p][4];
	}
	else{
		gant_chat[l++]=p;
		k++;
		vis[p]=1;
		arr[p][4] = arr[p][2];
		ct = arr[p][4];
	}
	
	while(k != n){
		p = findmin(n,arr,vis,ct);
		if(p == -1){
			gant_chat[l++]=-1;
			p = findmin1(n,arr,vis);
			ct = arr[p][1];
			p = findmin(n,arr,vis,ct);
		}
		gant_chat[l++]=p;
		k++;
		vis[p]=1;
		arr[p][4] = ct + arr[p][2];
		ct = arr[p][4];
	}
	
	for(int i=1;i<=n;i++){
		arr[i][5] = arr[i][4]-arr[i][1];
		arr[i][6] = arr[i][5]-arr[i][2];
	}
	
	printf("\n Gant chat:\n");
	for(int i=0;i<l;i++){
		if(gant_chat[i]==-1){
			printf("idle  ");
		}
		else{
			printf("%d  ",gant_chat[i]);
		}
	}
	
	printf("\n");
	printf("p\tat\tbt\tct\ttat\twt\n");
	for(int i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5],arr[i][6]);
	}
}
