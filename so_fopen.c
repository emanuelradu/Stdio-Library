// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"


SO_FILE *so_fopen(const char *pathname, const char *mode)
{
	int fd = -1;

	if (strcmp(mode, "r") == 0) {
		fd = open(pathname, O_RDONLY);
		if (fd < 0)
			return NULL;
	} else if (strcmp(mode, "r+") == 0) {
		fd = open(pathname, O_RDWR);
		if (fd < 0)
			return NULL;
	} else if (strcmp(mode, "w") == 0) {
		fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			return NULL;
	} else if (strcmp(mode, "w+") == 0) {
		fd = open(pathname, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			return NULL;
	} else if (strcmp(mode, "a") == 0) {
		fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			return NULL;
	} else if (strcmp(mode, "a+") == 0) {
		fd = open(pathname, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			return NULL;
	}

	SO_FILE *file = NULL;

	if (fd >= 0) {
		file = (SO_FILE *)malloc(sizeof(SO_FILE));
		file->fd = fd;
		file->EOF = 0;
		file->error = 0;
		file->buffer_pos = 0;
		file->rwf_flag = 0;
		file->file_pos = 0;
		file->buffer_size = 0;
		memset(file->buffer, 0, BUF_LEN);
		if (strcmp(mode, "r") == 0)
			file->op = 1;
		if (strcmp(mode, "r+") == 0)
			file->op = 2;
		if (strcmp(mode, "w") == 0)
			file->op = 3;
		if (strcmp(mode, "w+") == 0)
			file->op = 4;
		if (strcmp(mode, "a") == 0)
			file->op = 5;
		if (strcmp(mode, "a+") == 0)
			file->op = 6;
	}

	return file;
}
