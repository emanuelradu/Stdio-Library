// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"

int so_fseek(SO_FILE *stream, long offset, int whence)
{

	long position = 0;

	if (stream->rwf_flag == 1) {
		memset(stream->buffer, 0, BUF_LEN);
		stream->buffer_pos = 0;
		stream->buffer_size = 0;
	}
	if (stream->rwf_flag == 2)
		so_fflush(stream);
	position = lseek(stream->fd, offset, whence);
	if (position == -1)
		return SO_EOF;

	stream->file_pos = position;
	return 0;
}
