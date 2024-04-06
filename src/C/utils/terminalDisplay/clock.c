#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Your custom function to be executed
void myFunction() {
    // Implement your logic here
    printf("Function executed!\n");
}

int main() {
    // Set the desired frame rate (60 FPS)
    const double targetFrameTime = 1000.0 / 60.0; // in milliseconds

    // Initialize timing variables
    clock_t startTime, endTime;
    double elapsedTime;

    while (1) {
        // Record start time
        startTime = clock();

        // Call your custom function
        myFunction();

        // Calculate elapsed time
        endTime = clock();
        elapsedTime = (double)(endTime - startTime) * 1000.0 / CLOCKS_PER_SEC;

        // Sleep to maintain frame rate
        if (elapsedTime < targetFrameTime) {
            const int sleepTime = (int)(targetFrameTime - elapsedTime);
            usleep(sleepTime * 1000); // Sleep in microseconds
        }
    }

    return 0;
}