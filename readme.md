# CIO

A very small library of functions to read the contents of text files. 


### Usage


Read a file into a string:

```
const char* str = ReadFile("file.txt");
\\ Now you have the contents of a file as a string.

\\ Don't forget to free it after you're done!.
free(str);
```

Get the size of a file in bytes;

```
FILE* file_pointer = fopen()....
int size = GetFileSize(file_pointer);
```
