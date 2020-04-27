/* SPDX-License-Identifier: BSD-3-Clause */
/* Radu Emanuel Ioan 336CC */
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "so_stdio.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_LEN 4096

typedef struct _so_file {
	int fd;
	int op;
	unsigned char buffer[BUF_LEN];
	char EOF;
	int error;
	int buffer_pos;
	int rwf_flag;
	int file_pos;
	int buffer_size;
} SO_FILE;
