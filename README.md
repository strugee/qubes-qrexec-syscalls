# qubes-qrexec-syscalls

Common Unix calls implemented as [Qubes OS](https://qubes-os.org/) qrexec3 services, such that you can e.g. `read()` files in another VM.

Note that for obvious reasons, **these services can be extremely dangerous. You had better know what you're doing when enabling them.**

## Status

This repository is very much a work in progress. Read-only functions will be implemented first. I may follow up with write functions for completeness, although frankly those come too close to being able to completely compromise the target VM...

## (Security) Notes

### All services

These services are all-or-nothing. In the future there may be a way to limit access to a directory, similar to `chroot(2)`, but this is currently unimplemented.

This is because qrexec arguments have path components sanitized out of them, it is not possible to use this as a mechanism for passing arguments.

### `qubes.syscall.Access`

**This interface is not stable.**

The pathname to `access()` should be passed on the first line of stdin. Either `0` (success) or `-1` will be written to the first line of stdout, and the second line will be the value of `errno` (`0` in case of no error).

`F_OK` is assumed as the `mode`. This will change in the future.

All access control semantics of `access(2)` are ignored.

### `qubes.syscall.Chmod`

Unimplemented.

### `qubes.syscall.Chown`

Unimplemented.

### `qubes.syscall.Create`

Unimplemented.

### `qubes.syscall.Fsync`

Unimplemented.

### `qubes.syscall.Link`

Unimplemented.

### `qubes.syscall.Mkdir`

Unimplemented.

### `qubes.syscall.Mknod`

Unimplemented.

### `qubes.syscall.Open`

Unimplemented.

### `qubes.syscall.Read`

Unimplemented.

### `qubes.syscall.Readdir`

Unimplemented.

### `qubes.syscall.Readlink`

Unimplemented.

### `qubes.syscall.Rename`

Unimplemented.

### `qubes.syscall.Rmdir`

Unimplemented.

### `qubes.syscall.Stat`

Unimplemented.

### `qubes.syscall.Symlink`

Unimplemented.

### `qubes.syscall.Truncate`

Unimplemented.

### `qubes.syscall.Unlink`

Unimplemented.

### `qubes.syscall.Write`

Unimplemented.

## Intentionally unimplemented syscalls
