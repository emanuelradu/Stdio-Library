// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"

int so_fgetc(SO_FILE *stream)
{

	unsigned char c = '0';

	stream->rwf_flag = 1;
	int bytes_read = 0;

	if (stream->buffer_pos == 0 ||
	 stream->buffer_pos == stream->buffer_size) {
		bytes_read = read(stream->fd, stream->buffer, BUF_LEN);
		if (bytes_read > 0) {
				stream->file_pos += bytes_read;

			stream->buffer_size = bytes_read;
			stream->buffer_pos = 0;
		} else {
			stream->error = 1;
			stream->EOF = 1;
			return SO_EOF;
		}
	}

	c = stream->buffer[stream->buffer_pos];
	stream->buffer_pos++;

	return c;
}
