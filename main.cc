#include <curses.h>
#include <thread>

void handler(int &, int &, int &);

int main() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  timeout(0);

  int x = getmaxx(stdscr) / 2;
  int y = getmaxy(stdscr) / 2;
  int q = 0;
  std::chrono::milliseconds msec(50);

  while (!q) {
    mvprintw(y, x, "       ");
    handler(y, x, q);

    mvprintw(y, x, "%s", "(*'v'*)");
    refresh();
    std::this_thread::sleep_for(msec);
  }

  endwin();
}

void handler(int &y, int &x, int &q) {
  int input = getch();
  flushinp();
  switch (input) {
  case 'h':
    x -= 2;
    return;

  case 'j':
    y++;
    return;

  case 'k':
    y--;
    return;

  case 'l':
    x += 2;
    return;

  case 'q':
    q = 1;
    return;
  }
}
