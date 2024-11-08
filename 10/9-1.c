/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define SIZE 100

int main()
{
    char input[SIZE];
    FILE* fp = NULL;

    if((fp = fopen("output.bin", "wb")) == NULL) {
        printf("error...");
        return 0;
    }

    gets(input);
    // fputs(input, fp);
    fwrite(input, strlen(input), 1, fp);

    fclose(fp);

    return 0;
}