// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"


int so_fclose(SO_FILE *stream)
{
	stream->buffer_pos--;

	if (so_fflush(stream) < 0) {
		free(stream);
		return SO_EOF;
	}

	if (close(stream->fd) < 0) {
		free(stream);
		return SO_EOF;
	}

	free(stream);
	return 0;
}
