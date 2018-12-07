#     Copyright 2018 AJ Jordan.
#
#     This file is part of CSC 173 project 5.
#
#     CSC 173 project 5 is free software: you can redistribute it and/or
#     modify it under the terms of the GNU General Public License as
#     published by the Free Software Foundation, either version 3 of the
#     License, or (at your option) any later version.
#
#     CSC 173 project 5 is distributed in the hope that it will be
#     useful, but WITHOUT ANY WARRANTY; without even the implied
#     warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#     See the GNU General Public License for more details.
#
#     You should have received a copy of the GNU General Public License
#     along with CSC 173 project 5.  If not, see
#     <https://www.gnu.org/licenses/>.

CFLAGS += -Werror -Wall -Wextra -Wpedantic -D_FORTIFY_SOURCE=2 -O9

.PHONY: clean

default: qubes.syscall.Access

clean:
	rm qubes.syscall.Access
