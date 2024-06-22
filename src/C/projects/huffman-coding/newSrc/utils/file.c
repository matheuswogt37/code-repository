char *getReadName(char **argv);
char *getWriteName(char **argv);

// passing main parameters and return name of read file, the first parameter
char *getReadName(char **argv) {
    return argv[1];
}

// passing main parameters and return name of write file, the second parameter
char *getWriteName(char **argv) {
    return argv[2];
}