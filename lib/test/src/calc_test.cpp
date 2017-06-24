#include "calc.hpp"
#include <memory>
#include <iostream>
#include <catch\catch.hpp>

using namespace std;

namespace ModernCppCI {

  namespace Test {

    TEST_CASE("calc should be created", "[calc]") {
      auto calc = make_unique<Calc>();

      REQUIRE(calc != nullptr);
    }

    TEST_CASE("we could use +", "[calc]") {
      Calc calc = Calc();

      auto result = calc[1]["+"][2].result();

      REQUIRE(result == 3);
    }

    TEST_CASE("we could use -", "[calc]") {
      Calc calc = Calc();

      auto result = calc[1]["-"][2].result();

      REQUIRE(result == -1);
    }

    TEST_CASE("we could use *", "[calc]") {
      Calc calc = Calc();

      auto result = calc[1]["*"][2].result();

      REQUIRE(result == 2);
    }

    TEST_CASE("we could use /", "[calc]") {
      Calc calc = Calc();

      auto result = calc[10]["/"][2].result();

      REQUIRE(result == 5);
    }

    TEST_CASE("we could add operations", "[calc]") {
      Calc calc = Calc();

      auto originalNumOperations = calc.total_operations();

      calc.AddOperation("^", [] (const int& value1, const int& value2) { return (int) pow(value1, value2); });

      auto numOperations = calc.total_operations();

      REQUIRE((numOperations - originalNumOperations) == 1);

      auto result = calc[4]["^"][5].result();

      REQUIRE(result == 1024);
    }

    TEST_CASE("invalid operation return 0", "[calc]") {
      Calc calc = Calc();

      auto result = calc[1]["random"][2].result();

      REQUIRE(result == 0);
    }

    TEST_CASE("chain operations will work", "[calc]") {
      Calc calc = Calc();

      auto result = calc[1]["+"][2]["*"][5]["-"][1]["/"][4].result();

      REQUIRE(result == 3);
    }

    TEST_CASE("we could stream results", "[calc]") {

      ostringstream string_stream;

      Calc calc = Calc();

      string_stream << calc[1]["+"][2];

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

    TEST_CASE("adding steps will work", "[calc][calc step]") {
      Calc calc = Calc();

      REQUIRE(calc.total_steps() == 0);

      calc.AddStep(2);
      calc.AddStep(CalcStep("+", DefaultOperations::Plus));
      calc.AddStep(3);

      REQUIRE(calc.total_steps() == 3);
      REQUIRE(calc.result() == 5);
    }

    TEST_CASE("creating CalcStep with a value shouldn't have an operation", "[calc step]") {

      auto step = CalcStep(123);

      REQUIRE(step.has_value());
      REQUIRE(!step.has_operation());
      REQUIRE(step.value() == 123);
    }

    TEST_CASE("creating CalcStep with an operation shouldn't have a value", "[calc step]") {

      auto step = CalcStep("Z", [] (const int&, const int&) { return 0; });

      REQUIRE(!step.has_value());
      REQUIRE(step.has_operation());
      REQUIRE(step.operation()(1, 1) == 0);
    }

  }

}


