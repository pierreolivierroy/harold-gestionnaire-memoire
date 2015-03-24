#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "memory.h"
#include "first-fit.h"

int main(int argc, char *argv[])
{
	/* code */
	Memory * ram = initmem();
	print_list(ram);
	// Block * block = alloumem(ram);

	return 0;
}