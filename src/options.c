#include "common.h"
#include "output.h"
#include "options.h"

/* Define defaults.*/
struct Options OPTIONS = {
	NO,       /* alive */
	NO,       /* tcp */
	NO,       /* udp */
	NO,       /* rdns */
	NULL,     /* ports */
	NO,       /* incl. port zero */
	3,        /* retries */
	0,        /* method */
	10,       /* interval */
	60,       /* timeout */
	NULL,     /* output */
	0         /* format */
};

static int ports_expand(const char *ports, uint16_t **pList, BOOL *incPortZero);

void usage(const char *prog)
{
	fprintf(stderr, "usage: %s -atunh? -p <ports> -r <retries> -m <method> -i <interval> -w <timeout> -o <file> -f <format> host...\n", prog);
}

int opt_parse(int argc, char *argv[])
{
	int opt;
	while((opt = getopt(argc, argv, "atunp:r:m:i:w:o:f:h?")) != -1) {
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
				ports_expand(optarg, &OPTIONS.ports, &OPTIONS.includeZero);
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
				OPTIONS.output = fopen(optarg, "w");
				break;
			case 'f':
				OPTIONS.format = format_lookup(optarg);
				break;
			case 'h':
			case '?':
				return 1;
				break;
		}
	}
	return 0;
}

int opt_validate(void)
{
	if(!OPTIONS.tcp && !OPTIONS.udp) {
		return 1;
	}
	if(OPTIONS.tcp && OPTIONS.udp) {
		fprintf(stderr, "can only specify either tcp or udp for scan type.\n");
		return 1;
	}
	if(OPTIONS.output == NULL) {
		fprintf(stderr, "couldn't open file for writing.\n");
		return 1;
	}
	return 0;
}

int opt_cleanup(void)
{
	if(OPTIONS.ports != NULL) {
		free(OPTIONS.ports);
		OPTIONS.ports = NULL;
	}
	return 0;
}

static int ports_expand(const char *ports, uint16_t **pList, BOOL *incPortZero)
{
	*incPortZero = NO;
	*pList = malloc(sizeof(**pList) * 2);
	if(*pList == NULL) {
		return -1;
	}
	memset(*pList, 0, 2);
	*pList[0] = 22;
	return 0;
}
