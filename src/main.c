#include <stdio.h>
#include <unistd.h>

#include "options.h"

int main(int argc, char *argv[])
{
	
	if(opt_parse(argc, argv) > 0 || opt_validate() > 0) {
		usage(argv[0]);
		return 1;
	}
	return 0;
}
