#ifndef TLPI_HDR_H
#define TLPI_HDR_H
#include "get_num.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "error_functions.h"
/* Declares our error-handling functions */
typedef enum { FALSE, TRUE } Boolean;
#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))
#endif
