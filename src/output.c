
#include "common.h"
#include "output.h"

struct { 
	char *name;
} format_list[] = {
	{"normal"},
	{NULL}
};

static int fmt_selection = 0;

int format_lookup(const char *fmt)
{
	int i = 0;
	if(strcmp(fmt, "list") == 0) {
		return -1;
	}
	while(format_list[i].name != NULL) {
		if(strcmp(format_list[i].name, fmt) == 0) {
			break;
		}
		i++;
	}
	return i;
}

void format_list_print(FILE *fp)
{
	int i = 0;
	while(format_list[i].name != NULL) {
		fprintf(fp, "  %s\n", format_list[i].name);
		i++;
	}
}
