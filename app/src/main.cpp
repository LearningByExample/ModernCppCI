/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include "calc.hpp"
#include "logger.hpp"

int main(int argc, char *argv[]) {
  ModernCppCI::Logger::level(ModernCppCI::LogLevel::debug);

  ModernCppCI::Logger log(__func__);

  auto calc = ModernCppCI::Calc();

  log.info("doing some calculation");
  log.info(ModernCppCI::Calc()
           << 1 << "+" << 2 << "*" << 5 << "-" << 1 << "/" << 4);

  return 0;
}
