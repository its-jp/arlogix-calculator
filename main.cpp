#include <QApplication>

#include "lib/ui/ui.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  arlogix::UICalc window;
  window.show();
  return app.exec();
}