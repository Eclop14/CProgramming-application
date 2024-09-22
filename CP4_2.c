#include <stdio.h>

int main()
{
	int ch;
	char message[100];
	int i = 0;
	while ((ch = getchar()) != '\n') {
		message[i++] = ch;
	}
	message[i] = '\0';
	printf("%s", message);

	/*
	ch = getchar();
	putchar(ch);
	int ch;
	ch = getchar();
	putchar(ch);
	int ch;
	ch = getchar();
	putchar(ch);
	int ch;
	ch = getchar();
	putchar(ch);
	int ch;
	ch = getchar();
	putchar(ch);
	int ch;
	ch = getchar();
	putchar(ch);
	int ch;
	ch = getchar();
	putchar(ch);
	*/
	return 0;
}