#define CATCH_CONFIG_RUNNER
#include "log.hpp"
#include <catch\catch.hpp>

using namespace Log;

int main(int argc, char* argv[]) {

  Logger::level(log_level::debug);

  int result = Catch::Session().run(argc, argv);

  return (result < 0xff ? result : 0xff);
}