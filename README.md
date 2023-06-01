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

Authors:
Abel Sekibaala
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
