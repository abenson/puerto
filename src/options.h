#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "common.h"

struct Options
{
	BOOL alive;
	BOOL tcp;
	BOOL udp;
	BOOL rdns;
	uint16_t *ports;
	unsigned int retries;
	unsigned int method;
	time_t interval;
	time_t timeout;
	FILE *output;
	unsigned int format;
};

int opt_parse(int argc, char *argv[]);
int opt_validate(void);

extern struct Options OPTIONS;

#endif
