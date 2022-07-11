#include<stdio.h>
#include<conio.h>

int main() {
  int p[20], at[20], bt[20], wt[20], tat[20], i, k, n, temp;
  float avgwt, avgtat;
  printf("\nEnter the number of processes :");
  scanf("%d", & n);
  for (i = 0; i < n; i++) {
    printf("Enter the ARRIVAL TIME for process[%d] :", i);
    scanf("%d", & at[i]);
  }
  printf("Enter the BURST TIME:", i);
  for (i = 0; i < n; i++) {
    p[i] = i;
    scanf("%d", & bt[i]);
  }
  for (i = 0; i < n; i++) {
    for (k = i + 1; k < n; k++)
      if (bt[i] > bt[k]) {
        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;
      }
    else {
      temp = p[i];
      p[i] = p[k];
      p[k] = temp;
    }
  }
  wt[0] = avgwt = 0;
  tat[0] = avgtat = bt[0];
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = tat[i - 1] + bt[i];
    avgwt = avgwt + wt[i];
    avgtat = avgtat + tat[i];
  }
  printf("\n PROCESS\t AT\t BT\t WT\t TAT\n");
  for (i = 0; i < n; i++)
    printf("p[%d]\t\t %d\t %d\t %d\t %d\n", p[i], at[i], bt[i], wt[i], tat[i]);
  printf("\nAVERAGE WAITING TIME: %f", avgwt / n);
  printf("\nAVERAGE TURN AROUND TIME %f", avgtat / n);
  getch();
}