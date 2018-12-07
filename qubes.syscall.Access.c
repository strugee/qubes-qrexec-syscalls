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
#include <unistd.h>
#include <errno.h>

int main()
{
	char *line = NULL;
	size_t linesize = 0;
	ssize_t linelen;

	linelen = getline(&line, &linesize, stdin);

	if (linelen == -1) {
		fprintf(stderr, "failed to read from stdin\n");
		return 1;
	}

	// Zero out trailing delimiter
	line[linelen-1] = '\0';

	// TODO don't hardcode F_OK
	int r = access(line, F_OK);
	if (r == 0) {
		printf("%i\n%i\n", r, 0);
	} else {
		printf("%i\n%i\n", r, errno);
	}

	return 0;
}
