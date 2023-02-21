#include <stdio.h>
#include <stdlib.h>

int find_min(int n,int arr[][6],int vis[]){
	int max = 1000,ind;
	for(int i=1;i<= n;i++){
		if(max > arr[i][1] && vis[i]==-1){
			max = arr[i][1];
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
	for(int i=1;i<=n;i++){
		vis[i]=-1;
		arr[i][0]=i;
		printf("enter at and bt: ");
		scanf("%d %d",&arr[i][1],&arr[i][2]);
	}
	
	int l=0,k=0,ct=0,p=-1;
	int gant_chat[100];
	for(int i=1;i<=n;i++){
		if(arr[i][1]==0){
			p=i;
			break;
		}
	}
	if(p==-1){
		gant_chat[l++]=-1;
		p = find_min(n,arr,vis);
		gant_chat[l++]=p;
		ct = arr[p][1]+arr[p][2];
		arr[p][3] = ct;
		vis[p]=1;
		k++;
	}
	else{
		gant_chat[l++]=p;
		ct = arr[p][2];
		arr[p][3] = ct;
		vis[p]=1;
		k++;
	}
	while(k != n){
		p = find_min(n,arr,vis);
		if(arr[p][1] > ct){
			gant_chat[l++]=-1;
			ct = arr[p][1];
			p = find_min(n,arr,vis);
		}
		gant_chat[l++]=p;
		ct = ct+arr[p][2];
		arr[p][3] = ct;
		vis[p]=1;
		k++;
	}
	for(int i=1;i<=n;i++){
		arr[i][4] = arr[i][3]-arr[i][1];
		arr[i][5] = arr[i][4]-arr[i][2];
	}
	printf("\npno\tat\tbt\tct\ttat\twt\n");
	for(int i=1;i<=n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5]);
	}
	

}
