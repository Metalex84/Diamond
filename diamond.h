#ifndef DIAMOND_H
#define DIAMOND_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char **make_diamond(const char letter);
void free_diamond(char **diamond);

#endif
