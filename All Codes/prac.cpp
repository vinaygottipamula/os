#include <stdio.h>
#include <stdlib.h>

struct node{
	int pno;
	int at;
	int bt;
	struct node* next;
};
struct node* front = NULL;

void ready_queue(int pno,int at,int bt){
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
		ready_queue(i,at[i],bt[i]);
	}
	
	int time = 0;
	struct node* temp = front;
	while(temp != NULL){
		if(temp->at > time){
			printf("%d idle %d || ",time,temp->at);
			time = temp->at;
		}
		if(temp->bt > timequantum){
			printf("%d pno:%d %d || ",time,temp->pno+1,time+timequantum);
			time = time+timequantum;
			ready_queue(temp->pno,time,temp->bt-timequantum);
		}
		else{
			printf("%d pno:%d %d || ",time,temp->pno+1,time+temp->bt);
			time = time+temp->bt;
			ct[temp->pno] = time;
		}
		temp = temp->next;
	}
}

int main(){
	int n,timequantum;
	printf("enter n and timequantum: ");
	scanf("%d %d",&n,&timequantum);
	int at[n],bt[n],ct[n];
	
	for(int i=0;i< n;i++){
		printf("enter at and bt of %d: ",i+1);
		scanf("%d %d",&at[i],&bt[i]);
	}
	
	roundrobin(at,bt,ct,n,timequantum);
	
	int tat[n],wt[n];
	for(int i=0;i< n;i++){
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
	}
	
	printf("\npno at bt ct tat wt \n");
	for(int i=0;i< n;i++){
		printf("%d %d %d %d %d %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
}
