// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"

int so_fflush(SO_FILE *stream)
{
	int writterBytes = 0;

	if (stream->rwf_flag == 2) {
		writterBytes = write(stream->fd, stream->buffer,
		 stream->buffer_pos + 1);
		if (writterBytes < 0) {
			stream->error = 1;
			return SO_EOF;
		}

		stream->buffer_size -= writterBytes;
		stream->buffer_pos = 0;
		return 0;
	}
}
