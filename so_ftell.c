// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"

long so_ftell(SO_FILE *stream)
{
	return stream->file_pos;
}
