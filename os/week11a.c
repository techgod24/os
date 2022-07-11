//MFT
#include<stdio.h>
#include<conio.h>

int main() {
  int ma, bs, nob, ef, n, mp[10], tif = 0;
  int i, p = 0;
  printf("Enter the total memory available (in Bytes):");
  scanf("%d", & ma);
  printf("Enter the block size (in Bytes):");
  scanf("%d", & bs);
  nob = ma / bs;
  ef = ma - nob * bs;
  printf("\nEnter the number of processes:");
  scanf("%d", & n);
  for (i = 0; i < n; i++) {
    printf("Enter memory required for process %d (in Bytes):", i + 1);
    scanf("%d", & mp[i]);
  }
  printf("\nNo. of Blocks available in memory: %d", nob);
  printf("\n\nPROCESS\t MEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");
  for (i = 0; i < n && p < nob; i++) {
    printf("\n %d\t\t%d", i + 1, mp[i]);
    if (mp[i] > bs)
      printf("\t\tNO\t\t---");
    else {
      printf("\t\tYES\t\t%d", bs - mp[i]);
      tif = tif + bs - mp[i];
      p++;
    }
  }
  if (i < n)
    printf("\nMemory is Full, Remaining Processes cannot be accomodated");
  printf("\n\nTotal Internal Fragmentation is %d", tif);
  printf("\nTotal External Fragmentation is %d", ef);
  getch();
}
// Enter the total memory available (in Bytes):1000
// Enter the block size (in Bytes):300
// Enter the number of processes:5
// Enter memory required for process 1 (in Bytes):275
// Enter memory required for process 2 (in Bytes):400
// Enter memory required for process 3 (in Bytes):290
// Enter memory required for process 4 (in Bytes):293
// Enter memory required for process 5 (in Bytes):100
// No. of Blocks available in memory: 3
// PROCESS MEMORYREQUIRED ALLOCATED INTERNALFRAGMENTATION1 275 YES 25
// 2 400 NO --- 3 290 YES 10
// 4 293 YES 7
// Memory is Full, Remaining Processes cannot be accomodatedTotal Internal Fragmentation is 42
// Total External Fragmentation is 100