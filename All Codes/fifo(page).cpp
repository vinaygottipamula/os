#include <bits/stdc++.h>
#include <queue>

using namespace std;

void display(queue<int> q){
	while(q.size()){
		printf("%d ",q.front());
		q.pop();
	}
}

bool test(char ch,queue<int> q){
	while(q.size()){
		if(ch == q.front())
			return true;
		else
			q.pop();
	}
	return false;
}

int main(){
	int frames,i=0,miss=0,hit=0,page_no;
	queue<int> q;
	printf("enter number of frames: ");
	scanf("%d",&frames);
	printf("enter no of pages: ");
	scanf("%d",&page_no);
	char pages[page_no];
	for(int i=0;i< page_no;i++){
		printf("enter page - %d:",i+1);
		scanf("%d",&pages[i]);
	}
	for(int i=0;i< page_no;i++){
		if(i < frames){
			q.push(pages[i]);
			miss++;
			display(q);
			printf("\t MISS\n");
		}
		else{
			if(test(pages[i],q)){
				hit++;
				display(q);
				printf("\t HIT\n");
			}
			else{
				q.pop();
				q.push(pages[i]);
				miss++;
				display(q);
				printf("\t MISS\n");
			}
		}
	}
	printf("Total number of misses: %d\n",miss);
	printf("Total number of hits: %d\n",hit);
}
