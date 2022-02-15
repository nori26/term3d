#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

static size_t line_length = 80;
int main()
{
	char *s = "01234567890123456789";
	printf("%c\n", s[0][1]);
    return 0;
}
