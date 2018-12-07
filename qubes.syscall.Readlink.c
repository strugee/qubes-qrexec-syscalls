/*

  Copyright 2018 AJ Jordan.

  This file is part of qubes-qrexec-syscalls.

  qubes-qrexec-syscalls is free software: you can redistribute it
  and/or modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  qubes-qrexec-syscalls is distributed in the hope that it will be
  useful, but WITHOUT ANY WARRANTY; without even the implied warranty
  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with qubes-qrexec-syscalls.  If not, see
  <https://www.gnu.org/licenses/>.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WRITENUL \
	r = fwrite("\0", 1, 1, stdout); \
	if (r != 1) abort

int main()
{
	char *line = NULL;
	size_t linesize = 0;
	ssize_t linelen;

	char *buf = NULL;

	linelen = getline(&line, &linesize, stdin);

	if (linelen == -1) {
		fprintf(stderr, "failed to read from stdin\n");
		return 1;
	}

	// Zero out trailing delimiter
	line[linelen-1] = '\0';

	struct stat sb;
	int r = lstat(line, &sb);
	if (r == -1) goto bail;

	size_t bufsiz = sb.st_size + 1;

	/* Some magic symlinks under (for example) /proc and /sys
	   report 'st_size' as zero. In that case, take PATH_MAX as
	   a "good enough" estimate */

	if (sb.st_size == 0) bufsiz = PATH_MAX;

	buf = malloc(bufsiz);
	if (buf == NULL) goto bail;

	r = readlink(line, buf, bufsiz);
	if (r != -1) {
		printf("%i", r);
		WRITENUL();
		printf("0");
		WRITENUL();
		printf("%zu", bufsiz);
		WRITENUL();
		r = fwrite(buf, bufsiz, 1, stdout);
		if (r != 1) abort();
	} else {
	bail:
		printf("%i", r);
		WRITENUL();
		printf("%i", errno);
		WRITENUL();
		printf("0");
		WRITENUL();
		// Empty string for the result
	}

	free(buf);
	fflush(stdout);

	return 0;
}
