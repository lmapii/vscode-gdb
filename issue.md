I seem to have the very same problem, meaning that vscode can't handle .out files with relative paths (within) them while the actual .out file is perfectly fine. Created a little project to show what I mean:

/root
  |
  +-- /dev > where my source-code typically goes
  |
  +--/test        > where my unit-tests go
        Makefile  > for my unit-tests (TDD)

So what I'm doing is compiling my code as part of a unit-test suite, which creates a ".out" file. The files for compilation, however, are referred to with relative paths, see Makefile:

# change this - then step-into any module won't work anymore
PRJ_ROOT := ../test/dev
PRJ_BLD  := ../test/bld
# PRJ_ROOT := dev
# PRJ_BLD  := bld

## Reproduce FAIL - step-into

In order to showcase this I copied what's usually in /dev to /test/dev. This allows me to use relative paths in the makefile (and thus in the debug information of the .out file). If debug "as is" vscode will jump into main. So far so good. But you won't be able to step-into any function call (e.g. dummy_init). Now change the make file to the following:

# PRJ_ROOT := ../test/dev
# PRJ_BLD  := ../test/bld
PRJ_ROOT := dev
PRJ_BLD  := bld

Run 'make clean && make', now step-into will work.

## Reproduce FAIL - entry-point

You can play the same game with the line

# CC_FILES  := ../test/test-dummy/test_dummy.c
CC_FILES  := test-dummy/test_dummy.c

What will happen is that vscode won't even be able to find the entry point anymore, it's located within test_dummy.c. Hope this little showcase helps to reproduce the problem locally.

I really can't see how the sourceFileMap should fix this since my code should be able to be anywhere within the workspace. It cost me a full day to pin this down to vscode, I'm currently setting up unity + cmock + ceedling for testing, it would work so well together with vscode + gdb, I really think it's one of the best integrations of GDB so far.

Cheers.Martin
