#include<stdio.h>
#include<stdlib.h>
int handle_Queries();
int main() 
{ 
 while(1)
 {
  int choice;
  printf("\nEnter what you want to do : \n1.Faculty \t2.Student \t3.Exit\n");
  scanf("%d",&choice);
  switch(choice){
  	case 1:
  		printf("\n\t\tFaculty Queries : ");
  		handle_Queries();
  		break;
  	case 2:
  		printf("\n\t\tStudent Queries");
  		handle_Queries();
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
int handle_Queries(){
  	int i,j,n,time,remaining,flag=0,timeQuant,detail; 
  	int wait_Time=0,turnaround_Time=0; 
  	int at[100],bt[100],rt[100];
	printf("\nEnter Total Request:\t ");
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
  	printf("\nHow much time each request take ? :\t");
  	scanf("%d",&timeQuant); 
  	while(timeQuant<=0){
  		printf("Time Quant can not be less than 1 \nTry again\n Please Enter Again");
  		scanf("%d",&timeQuant);
	  }
  	printf("\n\nRequest\t|Turnaround Time|Waiting Time\n\n"); 
  	for(time=0,i=0;remaining!=0;) 
  	{ 
    	if(rt[i]<=timeQuant && rt[i]>0) 
    	{ 
      	time+=rt[i]; 
      	rt[i]=0; 
      	flag=1; 
    	} 
    	else if(rt[i]>0) 
    	{ 
      	rt[i]-=timeQuant; 
      	time+=timeQuant; 
    	} 
    	if(rt[i]==0 && flag==1) 
    	{ 
      	remaining--; 
      	printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      	wait_Time+=time-at[i]-bt[i]; 
      	turnaround_Time+=time-at[i]; 
      	flag=0; 
    	} 
    	if(i==n-1) 
      	i=0; 
    	else if(at[i+1]<=time) 
      	i++; 
    	else 
      	i=0; 
  	} 
  	printf("\nAverage Waiting Time= %f\n",wait_Time*1.0/n); 
  	printf("Avg Turnaround Time = %f",turnaround_Time*1.0/n); 
  	return 0;
}
