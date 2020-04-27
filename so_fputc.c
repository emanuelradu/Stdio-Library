// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"



int so_fputc(int c, SO_FILE *stream)
{
	if (stream->rwf_flag == 1)
		so_fflush(stream);

	if (stream->op == 5 || stream->op == 6)
		lseek(stream->fd, 0, SEEK_END);

	stream->rwf_flag = 2;
	if (stream->buffer_pos == BUF_LEN - 1) {
		stream->buffer[stream->buffer_pos] = c;

		if (so_fflush(stream) < 0)
			return SO_EOF;
	} else {
		stream->buffer[stream->buffer_pos] = c;
		stream->buffer_pos++;
	}
	stream->file_pos++;
	return c;
}

