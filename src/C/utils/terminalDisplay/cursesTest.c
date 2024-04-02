// for kbhit
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// for setCursorPosition
#include <ncurses.h>

// utils
#include <string.h>
#include <stdlib.h>
#include <time.h>

int msleep(unsigned int tms) {
  return usleep(tms * 1000);
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int main()
{
  initscr();
  int y, x;
  

  getmaxyx(stdscr, y, x);
  // while(!kbhit()) {
    
  //   for (int i = 0; i > -1; i++) {
  //     move((y/2), (x/2));
  //     printw("%i", i);
  //     system("clear");
  //     refresh();
  //     nanosleep(100);
  //   }
  // }


  mvprintw(5, 5, "%s", "hello world");
  refresh();
  sleep(5);
  printw("hello world");

  printf("\nacabou\n");

  sleep(5);
  endwin();

  // refresh();
  // WINDOW *window;
  // window = stdscr;

  // while (!kbhit())
  // {
  //   printf("teste\n");
  //   wmove(window, 100, 100);
  //   refresh();
  //   sleep(1);
  // }

  // printf("passou");

  return 0;
}