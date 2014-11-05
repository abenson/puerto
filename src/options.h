#ifndef OPTIONS_H
#define OPTIONS_H

#include "common.h"

struct Options
{
	BOOL alive;
	BOOL tcp;
	BOOL udp;
	BOOL rdns;
	uint16_t *ports;
	BOOL includeZero;
	unsigned int retries;
	char *method;
	time_t interval;
	time_t timeout;
	FILE *output;
	unsigned int format;
};

int opt_parse(int argc, char *argv[]);
int opt_validate(void);
void usage(const char *);

extern struct Options OPTIONS;

#endif
