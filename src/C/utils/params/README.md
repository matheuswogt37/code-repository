# params

## params.c
using the file params.c
```C
#include <stdio.h>

int main(int argc, char **argv) {

    printf("your param size - %i \n", argc);
    for (int i = 1; i < argc; i++) {
        printf("%s \n", argv[i]);
    }

    return 0;
}
```

the main is a function with two parameters:
- argc
    - count how many arguments are
- agrv
    - pointer to the arguments, they are strings so need to be pointer-pointer

in the example below the first line will print argc, the others will print all the argv when each line is a diferent parameter: \
input
```bash
params.c.out jonas percy i-am-a-parameter i,am,too "hi hello world"
``` 

output
```bash
your param size - 6 
./params.c.out 
jonas 
percy 
i-am-a-parameter 
i,am,too 
hi hello world 
```

observe the call of binary-program is the first parameter (**argv[0]**) so usually is used **argv[1]** foward \
the only character that can separate parameters is the space " " but if you want to pass the space as a parameter then use inside double quotes like **"hi hello world"**

## params-tags.c
compile using:
```bash
gcc params-tags.c -o params-tags.c.out
```
and try: params-tags.c.out -h