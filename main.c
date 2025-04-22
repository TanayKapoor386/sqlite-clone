/*
main will create a REPL (read-evaluate-execute-print loop) so SQLite can be used in the command line.

*/

#include "main.h"

/*
Infinite loop to print prompt, take input, and process input
*/

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;
    InputBuffer *input_buffer = new_input_buffer();

    while (1) {
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("%s: invalid command \n", input_buffer->buffer);
        }
    }
    
    
}

/*
Initialize Input Buffer.
*/

InputBuffer *new_input_buffer() {
    InputBuffer *input_buffer = (InputBuffer *) malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

/*
Prints prompt to user. Called while user input is being read.
Should look like Command Line.
*/

void print_prompt() {
    printf("db > ");
}

/*

*/
void read_input(InputBuffer *input_buffer) {
    ssize_t total_read_bytes = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (total_read_bytes <= 0) {
        printf("Input invalid. Error reading\n");
        exit(EXIT_FAILURE);
    }

    // IGNORE \n
    input_buffer->input_length = total_read_bytes - 1; // do NOT count \n character in input for proper string comparisons
    input_buffer->buffer[total_read_bytes - 1] = 0; // replace trailing newline character at end of input with null terminator so the buffer "array" sees the end of the input as a null terminator instead of
                                                    // a newline; crucial for string comparing
}

/*
Free the allocated memory for the instance of InputBuffer * and the respective buffer array member (char *)
getline will allocate memory for the read input (through input_buffer's buffer)
*/
void close_input_buffer(InputBuffer *input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}