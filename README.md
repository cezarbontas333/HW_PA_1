# HW_PA_1
Homework for the Data Structures and Alogrithms course at ACS IS, to organize linked lists, queues, and more. Tasks are explained [here](https://ocw.cs.pub.ro/courses/sda-ab/tema1).

### How to run
There is `checker.sh` that calculates how many tasks have been completed. Currently only tasks from 1 through 3 are completed, the other ones are yet to be implemented.
There is also the `Makefile` that has 3 routines:
- `make build` creates the release build of the application;
- `make debug` creates a version of the executable with debug symbols (useful for Valgrind, which is also called, to point lines where memory leaks/other errors may occur);
- `make clean` clears the executable.
To use the routines, you need `gcc`, `make` and `valgrind` as all the other dependencies. This project runs only under Linux environments (including WSL).
To run the executable separately, you need 3 files from where it reads:
- `c.in` which selects tasks to be done;
- `d.in` which holds the actual team information;
- `r.out` to where the program writes the results.
Included with the source code, samples are included in their respective folders.
