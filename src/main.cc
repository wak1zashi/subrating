#include "ui/layout_manager.h"
#include "ui/ui.h"
#include <ncurses.h>

void SetConfig();

int main() {

  SetConfig();

  ui::LayoutManager::Init();
  ui::UI user;

  endwin();
  return 0;
}

void SetConfig() {
  setlocale(LC_ALL, "");
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  refresh();
}
