/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include <catch/catch.hpp>
#include <iostream>
#include <memory>
#include "calc.hpp"

namespace ModernCppCI {

namespace Test {

TEST_CASE("creating CalcStep with a value shouldn't have an operation",
          "[calc step]") {
  auto step = CalcStep(123);

  REQUIRE(step.has_value());
  REQUIRE(!step.has_operation());
  REQUIRE(step.value() == 123);
}

TEST_CASE("creating CalcStep with an operation shouldn't have a value",
          "[calc step]") {
  auto step = CalcStep("r-", [](const int& value1, const int& value2) {
    return value2 - value1;
  });

  REQUIRE(!step.has_value());
  REQUIRE(step.has_operation());
  REQUIRE(step.operation()(1, 2) == 1);
}

}  // namespace Test

}  // namespace ModernCppCI