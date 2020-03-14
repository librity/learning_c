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

Bash Cheat Sheets:
- https://www.linuxtrainingacademy.com/linux-commands-cheat-sheet/

Cool List of OpenSource C Libs
==> https://en.cppreference.com/w/c/links/libs

# GCC

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

# But what is make? And why is it important?!?

Make is a build system that easily allows you to automatize the compilation of
your applications and libraries. It works with **targets** (named bash scripts),
with the default being **all:**. The target's dependencies are decleard after the
colon **':'**, and every tabbed line below it a line of bash code that gets is 
when the make runs said target. You can also assign varibles with the **'='** 
sign and call them with $(<variable_name>). These ate stored in files called 
'makefile' or 'Makefile', and stem at the projects's root. Targets can also call
other targets as needed.

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
- https://en.wikipedia.org/wiki/List_of_build_automation_software