#include "common.h"

#include "options.h"

/* Define defaults.*/
struct Options OPTIONS = {
	NO,       /* alive */
	NO,       /* tcp */
	NO,       /* udp */
	NO,       /* rdns */
	NULL,     /* ports */
	3,        /* retries */
	0,        /* method */
	10,       /* interval */
	60,       /* timeout */
	NULL,     /* output */
	0         /* format */
};

int opt_parse(int argc, char *argv[])
{
	return 0;
}

int opt_validate(void)
{
	if((OPTIONS.tcp && OPTIONS.udp) || (!OPTIONS.tcp && !OPTIONS.udp)) {
		fprintf(stderr, "can only specify either tcp or udp for scan type.\n");
		return 1;
	}
	return 0;
}
