#include <stdio.h>
#include <string.h>

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void main() {
	// Declarations
	// n = no. of processes
	int et[20],at[10],n,p[10],st[10],ft[10],wt[10],ta[10];
	int totwt = 0, totat = 0;
	float awt, ata;
	char pn[10][10], t[10];
	int i,j;

	// Input no. of Processes
	printf("No. of Process : ");
	scanf("%d", &n);
	printf("\n");
	// Take 
	// Process Name pn[i]
	// Arrival Time at[i]
	// Execution Time / Burst Time et[i]
	// Priority p[i]

	for (i = 0; i < n; i++) {
		printf("Enter Process Name, Arrival Time, Execution/Burst Time & Priority : ");
		scanf("%s%d%d%d", &pn[i][10], &at[i], &et[i], &p[i]);
		printf("\n");
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (p[i] < p[j]) {
				// Swap Both
				swap(&p[i], &p[j]);
				swap(&at[i], &at[j]);
				swap(&et[i], &et[j]);
				swap(&p[i], &p[j]);
				// Swap Process Name
				strcpy(t, pn[i]);
				strcpy(pn[i], pn[j]);
				strcpy(pn[j], t);
			}
		}
	}

	for (i = 0; i < n; i++) {
		if (i == 0) {
			st[i] = at[i];
			wt[i] = st[i] - at[i];
			ft[i] = st[i] + et[i];
			ta[i] = ft[i] - at[i];
		} else {
			st[i] = ft[i-1];
			wt[i] = st[i] - at[i];
			ft[i] = st[i] + et[i];
			ta[i] = ft[i] - at[i];
		}
		// Total Waiting Time & Arrival Time
		totwt += wt[i];
		totat += at[i];
	}

	// Average Waiting Time a& Arrival Time
	awt = (float)totwt/n;
	ata = (float)totat/n;

	// Table
	printf("Process\tArrival Time\tExecution Time\tPriority\tWaiting Time\tArrival Time\n");

	for (i = 0; i < n; i++) {
		printf("%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d\n", pn[i], at[i], et[i], p[i], wt[i], at[i]);
	}

	printf("Average Waiting Time : %f \n", awt);
	printf("Average Turn Around Time : %f\n", ata);
 }