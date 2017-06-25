#include "calc.hpp"
#include "logger.hpp"

using namespace ModernCppCI;

int main(int argc, char *argv[]) {

  Logger::level(info);

  Logger log(__func__);

  Calc calc = Calc();

  log.info("doing some calculation");
  log.info(calc[1]["+"][2]["*"][5]["-"][1]["/"][4]);

  return 0;
}
