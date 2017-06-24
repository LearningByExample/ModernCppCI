#include <boost/current_function.hpp>
#include "calc.hpp"
#include "log.hpp"

using namespace ModernCppCI;
using namespace Log;

int main(int argc, char *argv[]) {

  Logger::level(log_level::info);

  Logger log(BOOST_CURRENT_FUNCTION);

  Calc calc = Calc();

  log.info("doing some calculation");
  log.info(calc[1]["+"][2]["*"][5]["-"][1]["/"][4]);

  return 0;
}
