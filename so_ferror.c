// SPDX-License-Identifier: BSD-3-Clause
/* Radu Emanuel Ioan 336CC */
#include "so_stdio.h"
#include "so_file.h"

int so_ferror(SO_FILE *stream)
{
	return stream->error;
}

