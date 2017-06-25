/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#define CATCH_CONFIG_RUNNER
#include <catch/catch.hpp>
#include "logger.hpp"

using namespace ModernCppCI;

int main(int argc, char* argv[]) {

  Logger::level(debug);

  int result = Catch::Session().run(argc, argv);

  return (result < 0xff ? result : 0xff);
}