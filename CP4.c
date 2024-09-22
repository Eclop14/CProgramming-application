#include <stdio.h>

int main()
{
    //char message[100] = "hello world\n"
    char message2[5] = { 'a','b','c','d','\0' };
    char message[5] = { 'a','b','c','\0' };

    //printf("s",message);

    printf("message = %s, message2 = %s", message, message2);
    //&message = "hello hoseo university";
    return 0;
}
