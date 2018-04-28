#include<stdio.h>
#include<stdlib.h>
int handle();
int main() 
{ 
 while(1)
 {
  int key;
  printf("\nWelcome Sudhesh Sharma\nChoose an option to do : \n1.Faculty \n2.Student \n3.Exit\n");
  scanf("%d",&key);
  switch(key){
  	case 1:
  		printf("\n\tFaculty Queries : ");
  		handle();
  		break;
  	case 2:
  		printf("\n\tStudent Queries");
  		handle();
  		break;
  	case 3:
  		printf("\nProgram terminated ");
  		exit(0);
		break;
  	default:
  		printf("\nInvalid Choice");
  		break;
  }
}
}
int handle(){
  	int i,j,n,time,remaining,flag=0,tQ,detail; 
  	int WT=0,TAT=0; 
  	int at[100],bt[100],rt[100];
	printf("\nEnter Number of Request:\t ");
  	scanf("%d",&n);
  	while(n<=0){
  		printf("Request cannot be less than 1 \nEnter again");
  		scanf("%d",&n);
	  }
  	remaining=n; 
  	for(i=0;i<n;i++) 
  	{ 
  		printf("\nRequest Number %d :",i+1);
    	printf("\nEnter Arrival Time and Burst Time of Request"); 
    	scanf("%d",&at[i]);
    	scanf("%d",&bt[i]); 
    	rt[i]=bt[i]; 
  	} 
  	printf("\nTime taken by request? :\t");
  	scanf("%d",&tQ); 
  	while(tQ<=0){
  		printf("Time can not be less than 1 \nTry again\n Please Enter Again");
  		scanf("%d",&tQ);
	  }
  	printf("\n\nRequest\t|Turnaround Time|Waiting Time\n\n"); 
  	for(time=0,i=0;remaining!=0;) 
  	{ 
    	if(rt[i]<=tQ && rt[i]>0) 
    	{ 
      	time+=rt[i]; 
      	rt[i]=0; 
      	flag=1; 
    	} 
    	else if(rt[i]>0) 
    	{ 
      	rt[i]-=tQ; 
      	time+=tQ; 
    	} 
    	if(rt[i]==0 && flag==1) 
    	{ 
      	remaining--; 
      	printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      	WT+=time-at[i]-bt[i]; 
      	TAT+=time-at[i]; 
      	flag=0; 
    	} 
    	if(i==n-1) 
      	i=0; 
    	else if(at[i+1]<=time) 
      	i++; 
    	else 
      	i=0; 
  	} 
  	printf("\nAverage Waiting Time= %f\n",WT*1.0/n); 
  	printf("Avg Turnaround Time = %f",TAT*1.0/n); 
  	return 0;
}
