# os_p2_getlastcat

This program creates a new system call `getlastcat` that outputs the last file that was accessed using the `cat` command. The output format is: `XV6_TEST_OUTPUT Last catted filename: lastfilename`.

## Implementation - System Calls

First, I defined a syscall called `SYS_getlastcat` in `syscall.h` and assigned it the number 22. Then, in `syscall.c`, I added the `sys_getlastcat(void)` function, which calls the kernel-level `getlastcat` function. 

I defined a `usedcat` variable in `defs.h` and a `stored_arg` char array to keep track of the last file accessed with `cat`. In the kernel file `sysfile.c`, specifically in the `sys_exec` system call (where commands are checked), I check if the argument to the shell is `cat`. If so, I save the string value of the file into the `stored_arg` buffer for later recall.

## User Program

I then implemented `sys_getlastcat()`. This function takes the value from the `stored_arg` buffer and copies it to the userspace variable `userbuf`. Then, I created the user-level program `getlastcat.c`. This program calls the system-level function, retrieves the value from the user buffer, and prints it to the screen.

## Usage

```sh
$getlastcat

This command prints `XV6_TEST_OUTPUT Last catted filename: lastfilename` or
Cat has not yet been called
