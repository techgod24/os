// first fit
#include<stdio.h>
#include<conio.h>

#define max 25
void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
    static int bf[max], ff[max];
    printf("Memory Management Scheme - First Fit\n");
    printf("\nEnter the number of blocks:");
    scanf("%d", & nb);
    printf("Enter the number of files:");
    scanf("%d", & nf);
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
      printf("Block %d:", i);
      scanf("%d", & b[i]);
    }
    printf("Enter the size of the files :\n");
    for (i = 1; i <= nf; i++) {
      printf("File %d:", i);
      scanf("%d", & f[i]);
    }
    for (i = 1; i <= nf; i++) {
      for (j = 1; j <= nb; j++) {
        if (bf[j] != 1) {
          temp = b[j] - f[i];
          if (temp >= 0)
            if (highest < temp) {
              ff[i] = j;
              highest = temp;
            }
        }
      }
      frag[i] = highest;
      bf[ff[i]] = 1;
      highest = 0;
    }
    printf("\nFILE NO\t FILE SIZE\t BLOCK NO\t BLOCK SIZE\t FRAGMENT ");
      for (i = 1; i <= nf; i++)
        printf("\n%d\t\t %d\t\t %d\t\t %d\t\t %d", i, f[i], ff[i], b[ff[i]], frag[i]); 
    getch();
    }


// Memory Management Scheme - First Fit
// Enter the number of blocks:3
// Enter the number of files:2
// Enter the size of the blocks:
// Block 1:5
// Block 2:2
// Block 3:7
// Enter the size of the files :
// File 1:1
// File 2:4
// FILE NO FILE SIZE BLOCK NO BLOCK SIZE FRAGMENT1 1 3 7 62 4 1 5 1