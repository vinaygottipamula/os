#include <stdio.h>
#include <stdlib.h>

struct node{
	int pno;
	int at;
	int bt;
	struct node* next;
};

struct node* front = NULL;

void readyqueue(int pno,int at,int bt){
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->pno = pno;
	nn->at = at;
	nn->bt = bt;
	nn->next = NULL;
	if(front == NULL || at < front->at){
		nn->next = front;
		front = nn;
	}
	else{
		struct node* temp = front;
		while(temp->next != NULL && temp->next->at <= at){
			temp = temp->next;
		}
		nn->next = temp->next;
		temp->next = nn;
	}
}

void roundrobin(int at[],int bt[],int ct[],int n,int timequantum){
	for(int i=0;i< n;i++){
		readyqueue(i,at[i],bt[i]);
	}
	struct node* temp = front;
	int time = 0;
	while(temp != NULL){
		if(temp->at > time){
			printf("%d idle %d  ",time,temp->at);
			time = temp->at;
		}
		if(temp->bt > timequantum){
			printf("%d pn:%d %d  | ",time,temp->pno+1,time+timequantum);
			time = time+timequantum;
			readyqueue(temp->pno,time,temp->bt-timequantum);
		}
		else{
			printf("%d pn:%d %d | ",time,temp->pno+1,time+temp->bt);
			time = time+temp->bt;
			ct[temp->pno] = time;
		}
		temp = temp->next;
	}
}

int main(){
	int n,timequantum;
	printf("enter no of processes: ");
	scanf("%d",&n);
	printf("enter timequantum: ");
	scanf("%d",&timequantum);
	int at[n],bt[n],ct[n];
	for(int i=0;i< n;i++){
		printf("\nenter arrival and burst time of processor %d: ",i);
		scanf("%d %d",&at[i],&bt[i]);
	}
	roundrobin(at,bt,ct,n,timequantum);
	
	int tat[n],wt[n];
	for(int i=0;i< n;i++){
		tat[i] = ct[i]-at[i];
	}
	for(int i=0;i< n;i++){
		wt[i] = tat[i]-bt[i];
	}
	
	printf("pno at bt ct tat wt \n");
	for(int i=0;i< n;i++){
		printf("%d %d %d %d %d %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}
