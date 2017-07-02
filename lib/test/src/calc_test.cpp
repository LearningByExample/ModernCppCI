/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include "calc.h"
#include <catch.hpp>
#include <iostream>
#include <memory>

namespace ModernCppCI {

namespace Test {

TEST_CASE("calc should be created", "[calc]") {
  auto calc = std::make_unique<Calc>();

  REQUIRE(calc != nullptr);
}

TEST_CASE("we could use +", "[calc]") {
  auto calc = Calc{} << 2 << "+" << 1;

  REQUIRE(calc.result() == 3);
}

TEST_CASE("we could use -", "[calc]") {
  auto calc = Calc{} << 2 << "-" << 1;

  REQUIRE(calc.result() == 1);
}

TEST_CASE("we could use *", "[calc]") {
  auto calc = Calc{} << 2 << "*" << 1;

  REQUIRE(calc.result() == 2);
}

TEST_CASE("we could use /", "[calc]") {
  auto calc = Calc{} << 2 << "/" << 1;

  REQUIRE(calc.result() == 2);
}

TEST_CASE("invalid operation return 0", "[calc]") {
  auto calc = Calc{} << 2 << "random" << 1;

  REQUIRE(calc.result() == 0);
}

TEST_CASE("chain operations will work", "[calc]") {
  auto calc = Calc{} << 1 << "+" << 2 << "*" << 5 << "-" << 3 << "/" << 4;

  REQUIRE(calc.result() == 3);
}

TEST_CASE("we could stream results", "[calc]") {
  std::ostringstream string_stream{};

  string_stream << (Calc{} << 1 << "+" << 2);

  REQUIRE(string_stream.str() == "1 + 2 = 3");
}

TEST_CASE("default operation Plus will work", "[operations]") {
  auto result = DefaultOperations::Plus(10, 2);

  REQUIRE(result == 12);
}

TEST_CASE("default operation Minus will work", "[operations]") {
  auto result = DefaultOperations::Minus(10, 2);

  REQUIRE(result == 8);
}

TEST_CASE("default operation Times will work", "[operations]") {
  auto result = DefaultOperations::Times(10, 2);

  REQUIRE(result == 20);
}

TEST_CASE("default operation Div will work", "[operations]") {
  auto result = DefaultOperations::Div(10, 2);

  REQUIRE(result == 5);
}

TEST_CASE("default operation Zero will work", "[operations]") {
  auto result = DefaultOperations::Zero(10, 2);

  REQUIRE(result == 0);
}

TEST_CASE("adding steps will work", "[calc]") {
  Calc calc{};

  REQUIRE(calc.total_steps() == 0);

  calc.add_step(2);
  calc.add_step("+");
  calc.add_step(3);

  REQUIRE(calc.total_steps() == 3);
  REQUIRE(calc.result() == 5);
}

}  // namespace Test

}  // namespace ModernCppCI
