// LEAST RECENTLY USED(LRU):


#include <stdio.h>

int findLRU(int time[], int n) {
  int i, minimum = time[0], position = 0;
  for (i = 1; i < n; ++i) {
    if (time[i] < minimum) {
      minimum = time[i];
      position = i;
    }
  }
  return position;
}
int main() {
  int
  f, p, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, position, faults = 0;
  printf("Enter number of pages: ");
  scanf("%d", & p);
  printf("Enter reference string: ");
  for (i = 0; i < p; ++i) {
    scanf("%d", & pages[i]);
  }
  printf("Enter number of frames: ");
  scanf("%d", & f);
  for (i = 0; i < f; ++i) {
    frames[i] = -1;
  }
  for (i = 0; i < p; ++i) {
    flag1 = flag2 = 0;
    for (j = 0; j < f; ++j) {
      if (frames[j] == pages[i]) {
        counter++;
        time[j] = counter;
        flag1 = flag2 = 1;
        break;
      }
    }
    if (flag1 == 0) {
      for (j = 0; j < f; ++j) {
        if (frames[j] == -1) {
          counter++;
          faults++;
          frames[j] = pages[i];
          time[j] = counter;
          flag2 = 1;
          break;
        }
      }
    }
    if (flag2 == 0) {
      position = findLRU(time, f);
      counter++;
      faults++;
      frames[position] = pages[i];
      time[position] = counter;
    }
    printf("\n");
    for (j = 0; j < f; ++j) {
      printf("%d\t", frames[j]);
    }
  }
  printf("\nTotal Page Faults = %d", faults);
  return 0;
}

// Enter number of pages: 10
// Enter reference string: 7 5 9 4 3 7 9 6 2 1
// Enter number of frames: 3
// 7 -1 -1
// 7 5 -1
// 7 5 9
// 4 5 9
// 4 3 9
// 4 3 7
// 9 3 7
// 9 6 7
// 9 6 2
// 1 6 2
// Total Page Faults = 10