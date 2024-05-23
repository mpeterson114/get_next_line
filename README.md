# 📄 Get_next_line
> A function that reads and returns one line at a time from a file descriptor

## ⚙️ Usage
You can test the function using the provided files within ```test_files``` and the included ```main.c``` function.

Once inside the cloned repository, compile with default ```BUFFER_SIZE```:
```
gcc main.c get_next_line.c get_next_line_utils.c
```
or override the default buffer size with the buffer size of your choice:
```
gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1024
```
and execute with a test file of your choice
```
./a.out test_files/3.txt
```
Output should be the entire contents of the specified file.

⚠️ Note: This is not a stand-alone program, it's files will have to be included and compiled within another project using its header ```#include "get_next_line.h"```

