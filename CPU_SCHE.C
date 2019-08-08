#include<stdio.h>

int main()
{
	int n;
	clrscr();
	printf("1.FCFS \n2.SJF \n3.Roundrobin \n4.Priority");
	printf("\n\nEnter your selection number : ");
	scanf("%d",&n);
	if(n == 1)
	{
		Fcfs();
	}
	return 0;
}


int Fcfs()
{
	int n, at[20]={0}, bt[20]={0}, ct[20]={0}, tat[20]={0};
	int wt[20]={0}, sum=0;
	int totalTAT=0, totalWT=0;
	int i,j,k;

	printf("Enter the number of Processes : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter arrival time of process %d : ",i+1);
		scanf("%d",&at[i]);

		printf("\n Enter burst time of process %d : ",i+1);
		scanf("%d",&bt[i]);
		printf("\n");
	}

	//Completion Time
	for(i=0; i<n; i++)
	{
		sum += bt[i];
		ct[i] += sum;
	}
	//Turn around time
	for(j=0; j<n;j++)
	{
		tat[j] = ct[j] - at[j];
		totalTAT += tat[j];
	}
	//Waiting time
	for(k=0; k<n; k++)
	{
		wt[k] = tat[k] - bt[k];
		totalWT += wt[k];
	}

	printf("Solutions:\n\n");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\n\n");

	for(i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\t \n\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
	}
	printf("Average turnaround time : %d\n", totalTAT/n);
	printf("Average waiting time : %d\n", totalWT/n);
	getch();
	return 0;
}

