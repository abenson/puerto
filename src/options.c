#include "common.h"

#include "options.h"

/* Define defaults.*/
struct Options OPTIONS = {
	NO,       /* alive */
	NO,       /* tcp */
	NO,       /* udp */
	NO,       /* rdns */
	NULL, /* ports */
	3,        /* retries */
	0,        /* method */
	10,       /* interval */
	60,       /* timeout */
	NULL,   /* output */
	0         /* format */
};

int opt_parse(int argc, char *argv[])
{
	int opt;
	while(opt = getopt(argc, argv, "atunp:r:m:i:w:o:f:h?")) {
		switch(opt) {
			case 'a':
				OPTIONS.alive = YES;
				break;
			case 't':
				OPTIONS.tcp = YES;
				break;
			case 'u':
				OPTIONS.udp = YES;
				break;
			case 'n':
				OPTIONS.rdns = NO;
				break;
			case 'p':
				OPTIONS.ports = ports_expand(optarg);
				break;
			case 'r':
				OPTIONS.retries = atoi(optarg);
				break;
			case 'm':
				OPTIONS.method = strdup(optarg);
				break;
			case 'i':
				OPTIONS.interval = atoi(optarg);
				break;
			case 'w':
				OPTIONS.timeout = atoi(optarg);
				break;
			case 'o':
				OPTIONS.
		}
	}
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
