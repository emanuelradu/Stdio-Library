// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"

size_t so_fread(void *ptr, size_t size, size_t nmemb, SO_FILE *stream)
{
	stream->rwf_flag = 1;
	int c = 0;
	int i;

	for (i = 0; i < nmemb; i++) {
		c = so_fgetc(stream);
		if (c == SO_EOF) {
			stream->error = 1;
			return 0;
		}
		*(unsigned char *)ptr++ = (unsigned char)c;
	}
	return nmemb;
}
