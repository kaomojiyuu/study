#include <curses.h>
#include <unistd.h>

int main() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  timeout(0);

  mvaddstr(0, 0, "A\n");
  mvprintw(0, 1, "%s\n", "a");
  refresh();

  pause();

  endwin();
}
