#include <stdio.h>
#include <unistd.h>

#include "options.h"

int main(int argc, char *argv[])
{
	opt_parse(argc, argv);
	opt_validate();
	return 0;
}
