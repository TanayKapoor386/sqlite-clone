#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
The buffer struct points to memory where user's string input is held.
Should be dynamically allocated.
InputBuffer is just a wrapper for the state necessary to be stored to interact with getline()
*/
typedef struct {
    char *buffer;
    size_t buffer_length; // unsigned length/size of current memory being pointed to by buffer
    ssize_t input_length; // signed integer representing the actual length of the user's input query
} InputBuffer;


/*
------------------METHODS-----------------
*/

int main(int, char **);

InputBuffer *new_input_buffer(void);

void print_prompt();

/*
NOT IMPLEMENTED

Reads a line of input (this is a wrapper for getline() provided in the Standard I/O library in C)
line_ptr is a pointer to the pointer of the buffer which contains the line to be read
If line_ptr is NULL, getline() will malloc for it, and the user must free() after execution whether or not command succeeds

buffer_size is a pointer to the size of the allocated buffer 

stream is the input stream being read from (reading from standard input)

returns a signed int representing the number of bytes read (CAN be < sizeof(buffer))

When using getline, the read line is stored in input_buffer->buffer member and sizeof
allocated buffer is in the input_buffer->buffer_length member. The return value is stored in input_buffer->input_length member

input_buffer is initially a NULL pointer, so getline always mallocs enough memory to hold the read input line and makes
input_buffer point to that (char *)
*/
ssize_t getline(char **line_ptr, size_t *buffer_length, FILE * stream);

void read_input(InputBuffer *);

void close_input_buffer(InputBuffer *);