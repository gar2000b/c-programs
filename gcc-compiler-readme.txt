gcc first.c 
gcc first.c -o first
gcc first.c -o first.exe
gcc main.c -o main
gcc main.c -o main
gcc main.c -o main
gcc main.c -o main
gcc -c foo.c
gcc -c foo.c
gcc -c addNum.c 
gcc -o foo foo.o addNum.o 
gcc -o foo foo.c addNum.c
gcc foo.c 
gcc foo.c addNum.c 
gcc -o foo2 *.c

^ from above, you can see several examples of where I have used gcc within the multiple-source-files and first projects.

If you do: gcc first.c : then it will compile, assemble and link to a default a.out binary executable file. Simple.

If you specify the -o switch, it places the output file to the filename specified (again, compiles, assembles and links).

If you specify the -c switch, it compiles and assembles to .o (object / intermediate files) but does not link to a binary executable.

With the -c or -o or no options, you can specify a space seperated list of files of interest.

On the whole, the easiest thing to do at this stage is to do something similar to the last command: gcc -o foo2 *.c :
this says, create my executable called foo2 and use every source file (that ends with .c) as part of this overall 
compile, assemble, link procedure that yields my end application file (foo2).
