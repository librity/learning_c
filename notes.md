# Cool Stuff

Clang Cheat Sheets:

- https://developerinsider.co/c-programming-language-cheat-sheet/
- https://cheatography.com/ashlyn-black/cheat-sheets/c-reference/
- https://www.dummies.com/programming/c/c-for-dummies-cheat-sheet-2/
- https://www.dummies.com/programming/c/c-all-in-one-desk-reference-for-dummies-cheat-sheet/
- https://www.techworm.net/2017/06/ultimate-c-programming-cheat-sheet.html
- https://sites.ualberta.ca/~ygu/courses/geoph624/codes/C.CheatSheet.pdf
- https://www.rankred.com/useful-c-cheat-sheets/
- https://courses.cs.washington.edu/courses/cse351/14sp/sections/1/Cheatsheet-c.pdf
- https://www.tutorialspoint.com/cprogramming
- https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference

Compiler&Makefile Cheat Sheets:

- https://www.lzone.de/cheat-sheet/GCC
- https://stackoverflow.com/questions/7820474/gnu-make-cheat-sheet
- https://gist.github.com/evertrol/4b6fd05f3b6be2b331c60638b1af7101
- https://github.com/janosgyerik/cheatsheets/wiki/Makefile-cheat-sheet
- https://cheatography.com/bavo-van-achte/cheat-sheets/gnumake/
- https://docs.w3cub.com/cheatsheets/makefile
- https://stackoverflow.com/questions/14412919/make-no-targets-specified-and-no-makefile-found-stop
- http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
- https://www.gnu.org/software/make/manual/make.html

OOP in C:

- https://stackoverflow.com/questions/3241932/is-the-c-programming-language-object-oriented
- https://www.eventhelix.com/realtimemantra/basics/object_oriented_programming_in_c.htm
- https://gist.github.com/InNoHurryToCode/d7a419a649b9d8081ba09f70d87ec449
- https://github.com/shichao-an/ooc
- https://duckduckgo.com/?q=object+oriented+c
- https://stackoverflow.com/questions/415452/object-orientation-in-c

Bash Cheat Sheets:

- https://www.linuxtrainingacademy.com/linux-commands-cheat-sheet/

Cool List of OpenSource C Libs

- https://en.cppreference.com/w/c/links/libs

## Resources

- https://www.youtube.com/watch?v=KJgsSFOSQv0
- https://www.youtube.com/watch?v=ix5jPkxsr7M
- https://www.youtube.com/playlist?list=PLGLfVvz_LVvSaXCpKS395wbCcmsmgRea7
- http://www.newthinktank.com/
- https://www.youtube.com/results?search_query=linux+kernel+source+code

## GCC

- To compile a .c file into a binary executable with the same name we use:

```bash
$ make <.c_file_name_without_the_.c>
```

- Get bash to show you where it loads Shared Object libraries

```bash
$ ld --verbose | grep SEARCH_DIR | tr -s ' ;' \\012
```

- Get the adress of a function in an executable binary

```bash
$ objdump -t <binaryname> | rg <function_name>
```

Information about different executable binary formats and where they're used.

=> https://en.wikipedia.org/wiki/Comparison_of_executable_file_formats

## But what is make? And why is it important?!?

Make is a build system that easily allows you to automatize the compilation of
your applications and libraries. It works with **targets** (named bash scripts),
with the default being **all:**. The target's dependencies are decleard after the
colon **':'**, and every tabbed line below it a line of bash code that gets is
when the make runs said target. You can also assign varibles with the **'='**
sign and call them with \$(<variable_name>). These ate stored in files called
'makefile' or 'Makefile', and stem at the projects's root. Targets can also call
other targets by calling them in the dependencies. Automatic variables serve to
shorten the code and eliminate repetition. Some automatic variables are:

- \$@ = target name
- \$^ = target dependencies

=> https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

Example Makefile:

```Makefile
CC = gcc
CFLAGS = -Wall -g
BINS = librarytest

all: $(BINS)

librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BINS)
```

The greatest advantage of make is that it's universal: I'd be hard pressed to
find a linux distro without make installed. Other notable build automation
softwares are: ant, rake, maven, **Chef (used a lot for ruby apps in AWS instances)**,
and many many more:

=> https://en.wikipedia.org/wiki/List_of_build_automation_software

## HEXDUMP

We can read binaries as ASCII with this bash command (cats output to a file).

```bash
$ hexdump  -C <bin_name> > <bin_name>.hxdmp
```

## assembler.out

Also known as a.o, the old-school format of executable code in an UNIX-like sys.
Although most modern compilers don't use this format, they still output
intermediary files with the .o extension due to tradition (the true format of
the executable depending on the OS it is being compiled in).

=> https://en.wikipedia.org/wiki/A.out

## ELF: Executable and Linkable Format

Subsequent replacement of the .o/.out format in UNIX-like systems. If we compile
C code in a moder Linux machine it will probably output with this format.
Extremely versatile and extensible, with different endiannesses and address
sizes so to include as many
[Instruction Set Architectures](https://en.wikipedia.org/wiki/Instruction_set_architecture)
as possible.

=> https://en.wikipedia.org/wiki/Executable_and_Linkable_Format

## Mach-Object

ELF equivalent for MacOS, utilizing the Mach kernel. GCC outputs this on MacOS by
default. We can check what a file seems to be with the `file` bash command.

```bash
$ file <file_name>.c
file_name.c: c program text, ASCII text

$ file <file_name>.o
file_name.o: Mach-O 64-bit object x86_64

$ file <file_name>.so
file_name.so: Mach-O 64-bit dynamically linked shared library x86_64

$ file <file_name>.a
file_name.a: current ar archive random library

$ file <file_name>
file_name: Mach-O 64-bit executable x86_64
```

=> https://en.wikipedia.org/wiki/Mach-O

## POSIX Reference/unistd.h

Functions: _close_, _exec_, _fork_, _open_, _read_, _select_, _sleep_, _swab_ &
**write**.

Info
=> https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/unistd.h

Used by libft => https://github.com/R4meau/libft.git

## Unix file types

- **Dircetory**: Store other files and organize permissions. We can create them
  with `$ mkdir <directory_name>`.

  `drwxr-xr-x 26 root root 4096 Sep 22 09:29 /`

- **Regular file**: Contain binary data. We can create them with
  `$ touch <file_name>`.

  `-rw-r--r-- ... /etc/passwd`

- **Symbolic link**: Reference to another file, usually in another location. We
  can create them with `$ ln -s /path/to/file /path/to/symlink`.

  `lrwxrwxrwx ... name -> /path/to/file`

- **FIFO/Named pipe**: Pipes send the output of a process to input of another.
  Processes from the same user and within the same process-space use unnamed pipes
  **`|`** to comunicate with one another. Named pipes are used when processes from
  different users and process-spaces need to communicate with eachother. Named
  pipes are created as files with the **`$ mkfifo <pipe_name>`**, and can exist
  anywhere in the file system.

  `prw-rw---- ... mypipe`

- **Socket**: While named and unnamed pipes only allow for one-way i/o flow,
  sockets allow by-directional interaction between processes and are fully
  duplex-capable. They also allow for the exchange of
  [File descriptors](https://en.wikipedia.org/wiki/File_descriptor) (like stdin,
  stdout and stderr). We can create them with **netcat**
  `$ nc -k -l <listening_port> > <file_name>`

  `srwxrwxrwx /tmp/.X11-unix/X0`

- **Device file**: In UNIX-like systems everything except network devices
  are handled by files. Whenever we mount and access storage hardware we are
  interacting with either a _block_ or a _character_ device file. Block devices
  are randomly accessible (through a buffer), while character devices provide
  either serial stream of input or accept a serial stream of output (un-buffered).
  Creating one of these is pretty involved, as we must first have some sort of
  storage space we wish to encapsulate, and format it accordingly.

  ```bash
  brw-rw---- ... /dev/sda
  crw------- ... /dev/null
  ```

- **Door**: Communication between a client and a server, though only Solaris has
  this, and it's not available on Linux.

  `Dr--r--r-- ... name_service_door`

=> https://en.wikipedia.org/wiki/Unix_file_types

## GDB: The GNU Project Debugger

An extremely useful tool that gives you full control and analysis over an
executable's runtime.

=> https://www.gnu.org/software/gdb/
=> https://en.wikipedia.org/wiki/GNU_Debugger

## NSA Ghidra

A reverse-engineering toolbox with a forensics/security focus. Great for
analyzing executables as assembly code. This one has a GUI.

=> https://ghidra-sre.org/
