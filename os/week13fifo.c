#include <stdio.h>

int main() {
  int referenceString[10], pageFaults = 0, m, n, s, p, f;
  printf("\nEnter the number of Pages:\n");
  scanf("%d", & p);
  printf("\nEnter reference string values:\n");
  for (m = 0; m < p; m++) {
    printf("Value No. [%d]:\t", m + 1);
    scanf("%d", & referenceString[m]);
  }
  printf("\n Enter the number of frames:\t"); {
    scanf("%d", & f);
  }
  int temp[f];
  for (m = 0; m < f; m++) {
    temp[m] = -1;
  }
  for (m = 0; m < p; m++) {
    s = 0;
    for (n = 0; n < f; n++) {
      if (referenceString[m] == temp[n]) {
        s++;
        pageFaults--;
      }
    }
    pageFaults++;
    if ((pageFaults <= f) && (s == 0)) {
      temp[m] = referenceString[m];
    } else if (s == 0) {
      temp[(pageFaults - 1) % f] = referenceString[m];
    }
    printf("\n");
    for (n = 0; n < f; n++) {
      printf("%d\t", temp[n]);
    }
  }
  printf("\nTotal Page Faults:\t%d\n", pageFaults);
  return 0;
}

//Enter the number of Pages:
// 7
// Enter reference string values:
// Value No. [1]: 1
// Value No. [2]: 3
// Value No. [3]: 0
// Value No. [4]: 3
// Value No. [5]: 5
// Value No. [6]: 6
// Value No. [7]: 3
// Enter the number of frames: 3
// 1 -1 -1
// 1 3 -1
// 1 3 0
// 1 3 0
// 5 3 0
// 5 6 0
// 5 6 3
// Total Page Faults: 6