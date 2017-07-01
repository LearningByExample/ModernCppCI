/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include <catch.hpp>
#include <iostream>
#include <memory>
#include "calc.h"

namespace ModernCppCI {

namespace Test {

TEST_CASE("creating CalcStep with a value shouldn't have an operation",
          "[calc step]") {
  CalcStep step{123};

  CHECK(step.has_value());
  CHECK_FALSE(step.has_operation());
  REQUIRE(step.value() == 123);
}

TEST_CASE("creating CalcStep with an operation shouldn't have a value",
          "[calc step]") {
  CalcStep step{"r-", [](const int& value1, const int& value2) {
                  return value2 - value1;
                }};

  CHECK_FALSE(step.has_value());
  CHECK(step.has_operation());
  REQUIRE(step.operation()(1, 2) == 1);
}

}  // namespace Test

}  // namespace ModernCppCI