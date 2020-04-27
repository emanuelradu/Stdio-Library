// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"

size_t so_fwrite(const void *ptr, size_t size, size_t nmemb, SO_FILE *stream)
{

	stream->rwf_flag = 2;

	for (int i = 0; i < nmemb; i++) {
		unsigned char c = so_fputc(*(unsigned char *)ptr++, stream);

		if (c == SO_EOF) {
			stream->error = 1;
			return 0;
		}
	}
	return nmemb;
}
