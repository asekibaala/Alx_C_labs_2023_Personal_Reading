Personal Reading - C Programming Labs
This repository contains the source code and documentation for my personal C programming labs for the year 2023. The purpose of this project is to practice and improve my skills in C programming, including data structures, algorithms, and problem-solving.

Contents
The repository is organized into several subdirectories:


Dependencies
The labs are designed to be compiled and run on a Unix-based system with a C compiler such as gcc. The following software packages are required:
gcc (version 9 or higher)
make (version 4.3 or higher)


Getting Started
To get started, clone the repository to your local machine:
git clone 

Authors:Abel Sekibaala

**C Intermediate Concepts you must know 
**
Module 5
array indexing,
using pointers: perils and disadvantages,
the void type,
arrays of arrays and multidimensional arrays,
memory allocation and deallocation: the malloc() and free() functions,
arrays of pointers vs. multidimensional arrays,
functions,
how to declare, define and invoke functions,
the scope of variables, local variables and function parameters.

**Module 6**
structures,
declaring, using and initializing structures,
pointers to structures and arrays of structures,
the basics of recursive data collections,
pointers, arrays and structures as function parameters,
function result and the return statement,
void as a parameter, pointer and result,
parameterizing the main function,
external functions and the extern declarator,
header files and their role.

**Module 7**
files vs. streams,
header files needed for stream operations,
the FILE structure,
opening and closing streams, open modes, the errno variable,
reading and writing to/from a stream,
predefined streams: stdinstdout, and stderr,
stream manipulation: the fgetc(), fputc(), fgets(), and fputs() functions,
raw input/output: the fread(), and fwrite() functions.

**Module 8**
preprocessor,
#include - how to make use of a header file,
#define - simple and parameterized macros,
the #undef directive,
predefined preprocessor symbols,
macrooperators: # and ##,
conditional compilation: the #if and #ifdef directives,
avoiding multiple compilations of the same header files,
scopes of declarations, storage classes,
user-defined types,
pointers to functions,
analyzing and creating complex declarations.

**C Advanaced Concepts you Must know **

**C Advanced: Module 2**
calling conventions, parameters passing, stack usage, stack frame, returning a value, recursion;
va_start();
va_arg();
va_end();
va_copy();
vsprintf(), vprintf(), vfprintf();
vscanf(), vsscanf(), vfscanf()

**C Advanced: Module 3**
POSIX, API, ABI, WINAPI, etc.;
access();
open();
errno;
close();
read();
write();
lseek();
dprintf();
stat();
symlink(), link();
readlink();

**C Advanced: Module 4**
manipulating memory blocks
string manipulation: strchr(), strrchr(), strstr(), strtok();
qsort(), bsearch();
aligned_alloc(), calloc(), malloc(), and realloc();
bcopy();
memcpy();
memccpy();
memmove();
bzero();
memset();
memcmp();
Internationalization I18N
UNICODE. UCS, UTF-8 - how to deal with multilingual environment?;
universal character names;
wide characters support in different C dialects (, , …);
strcoll() and wcscoll();

**C Advanced: Module 5**
definitions, implementations and history;
thread safety;
system(), getenv(), setenv();
processes in Unix way:
fork();
exit();
execxx();
wait() and waitpid();
processes in MS Windows way:
CreateProcess();
WaitForSingleObject();
POSIX threads;
MS Windows threads;
C11 threads ().

**C Advanced: Module 6**
IEEE-754: a different universe;
NaN, infinity, zero;
floats and doubles – should we trust them?;
numerical anomalies vs precision;
ULP;
what is pragma?;
FENV_ACCESS pragma;
floating-point exceptions;
rounding;
multi-precision libraries (GMP, MPFR, MPIR).

**C Advanced: Module 7**
what is socket? what is network socket?;
TCP/IP protocol stack, UDP;
connection and connection-less transmissions;
servers and clients;
big and little endians and why you should be aware of them;
socket addressing: IP4, IP6, service numbers;
getaddrinfo();
socket();
connect();
bind();
listen();
accept();
send() and recv();
simple example of client-server communication;
simple example of peer-to-peer communication.

**C Advanced: Module 8**
const variables vs. volatile variables;
goto – why and why not, advantages, disadvantages and limitations;
long (non-local) jumps: setjmp() and longjmp();
static array indices, designated initializers, compound literals, variable-length arrays, flexible array members, restrict keyword;
sequence points: why ++/-- may sometimes make you crazy?;
the asm keyword
portability issues and undefined behaviours
