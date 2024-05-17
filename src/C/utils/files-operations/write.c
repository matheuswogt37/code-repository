#include <stdio.h>
#define FILE_PATH "writeFile"
#define STR "Estar sozinho é incrível, mas se sentir sozinho é aterrorizante."

int main() {
    FILE *file_ptr;

    file_ptr = fopen(FILE_PATH, "wb");
    fprintf(file_ptr, STR);

    fclose(file_ptr);
}