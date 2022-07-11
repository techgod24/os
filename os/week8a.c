#include<stdio.h>
#include<stdlib.h>

struct fcfs {
  int st, ft, at, bt, wt, tat, pr;
}
p[100], temp;
int main() {
  float avg_wt, avg_tat;
  int n, i, j;
  avg_wt = avg_tat = 0;
  printf("Enter number of processes:\n");
  scanf("%d", & n);
  printf("Enter the ARRIVAL TIME of process %d:\n", i + 1);
  for (i = 0; i < n; i++) {
    p[i].pr = i + 1;
    scanf("%d", & p[i].at);
  }
  printf("Enter the BURST TIME of process %d:\n", i + 1);
  for (i = 0; i < n; i++) {
    scanf("%d", & p[i].bt);
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 1; j < n - 1; j++) {
      if (p[j].at > p[j + 1].at) {
        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
  printf("PROCESS\t AT\t BT\t ST\t FT\t WT\t TAT\n");
  p[0].st = p[0].at;
  for (i = 1; i < n; i++) {
    if (p[i].at > p[i - 1].st + p[i - 1].bt) {
      p[i].st = p[i].at;
    } else {
      p[i].st = p[i - 1].st + p[i - 1].bt;
    }
  }
  for (i = 0; i < n; i++) {
    p[i].ft = p[i].st + p[i].bt;
    p[i].wt = p[i].st - p[i].at;
    p[i].tat = p[i].wt + p[i].bt;
  }
  for (i = 0; i < n; i++) {
    printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\n", p[i].pr, p[i].at, p[i].bt, p[i].st, p[i].ft, p[i].wt, p[i].tat);
    printf("\n");
  }
  for (i = 0; i < n; i++) {
    avg_wt = avg_wt + p[i].wt;
    avg_tat = avg_tat + p[i].tat;
  }
  printf("\n AVERAGE WAITING TIME: %f\n", (avg_wt) / n);
  printf("\n AVERAGE TURN AROUND TIME :%f\n", (avg_tat) / n);
  return 0;
}

// Enter number of processes:
// 3
// Enter the ARRIVAL TIME of process 1:
// 0
// 0
// 0
// Enter the BURST TIME of process 4:
// 24
// 3
// 3
// PROCESS AT BT ST FT WT TAT
// 1 0 24 0 24 0 24
// 2 0 3 24 27 24 27
// 3 0 3 27 30 27 30
// AVERAGE WAITING TIME: 17.000000
// AVERAGE TURN AROUND TIME :27.000000