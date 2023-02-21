#include <stdio.h>

int findmin1(int n,int arr[][6],int vis[]){
	int min = 10000,ind=-1;
	for(int i=1;i<=n;i++){
		if(min > arr[i][1] && vis[i]==-1){
			min = arr[i][1];
			ind = i;
		}
	}
	return ind;
}

int findmin(int n,int arr[][6],int vis[],int ct){
	int min = 10000,ind = -1;
	for(int i=1;i<=n;i++){
		if(vis[i]==-1 && ct >= arr[i][1] && (min > arr[i][2] || (min == arr[i][2] && arr[ind][1] > arr[i][1]))){
			min = arr[i][2];
			ind = i;
		}
	}
	return ind;
}

int main(){
	int n;
	printf("enter no of processes: ");
	scanf("%d",&n);
	int arr[n+1][6],vis[n+1],bt[n+1];
	printf("enter at and bt and pt:\n");
	for(int i=1;i<=n;i++){
		vis[i]=-1;
		arr[i][0] = i;
		arr[i][3]=0;
		printf("\nenter %d process: ",i);
		scanf("%d %d",&arr[i][1],&arr[i][2]);
		bt[i]=arr[i][2];
	}
	
	int l=0,k=0,p=-1,ct=0,min=1000;
	int gant_chat[100];
	for(int i=1;i<=n;i++){
		if(min > arr[i][1] || (min == arr[i][1] && arr[i][2] < arr[p][2])){
			min = arr[i][1];
			p = i;
		}
	}
	arr[p][2]--;
	if(min != 0){
		gant_chat[l++]=-1;
		gant_chat[l++]=p;
		arr[p][3]++;
		ct = arr[p][3];
	}
	else{
		gant_chat[l++]=p;
		arr[p][3]++;
		ct=arr[p][3];
	}
	if(arr[p][2] == 0){
		vis[p]=1;
		k++;
	}
	
	while(k != n){
		p = findmin(n,arr,vis,ct);
		if(p == -1){
			gant_chat[l++]=-1;
			p = findmin1(n,arr,vis);
			ct = arr[p][1];
			p = findmin(n,arr,vis,ct);
		}
		arr[p][2]--;
		if(gant_chat[l-1]==p){
			ct++;
			arr[p][3] = ct;
		}
		else{
			gant_chat[l++]=p;
			ct++;
			arr[p][3] = ct;
		}
		if(arr[p][2]==0){
			vis[p]=1;
			k++;
		}
	}
	
	for(int i=1;i<=n;i++){
		arr[i][4] = arr[i][3]-arr[i][1];
		arr[i][5] = arr[i][4]-bt[i];
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
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],bt[i],arr[i][3],arr[i][4],arr[i][5],arr[i][6]);
	}
}
