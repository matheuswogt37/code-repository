#include <stdio.h>
#define FILE_PATH "files/file"

int main() {
    FILE *file_ptr;
    char ch;

    file_ptr = fopen(FILE_PATH, "r");

    if (NULL == file_ptr) {
        printf("error - file cannot be opened\n");
    } else {
        printf("Content of %s\n", FILE_PATH);

        do {
            ch = fgetc(file_ptr);
            printf("%c", ch);           
        } while (ch != EOF);
    }

    fclose(file_ptr);
    return 0;
}