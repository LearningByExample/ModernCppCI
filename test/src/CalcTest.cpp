#include "catch.hpp"
#include "Calc.hpp"
#include <cmath>
#include <memory>
#include<iostream>

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

			auto originalNumOperations = calc.totalOperations();

			calc.addOperation("^", [](int value1, int value2) { return (int)pow(value1, value2); });

			auto numOperations = calc.totalOperations();

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

		TEST_CASE("adding steps will work", "[calc][calcstep]") {
			Calc calc = Calc();

			REQUIRE(calc.totalSteps() == 0);

			calc = calc[1];
			REQUIRE(calc.totalSteps() == 1);

			calc = calc["+"];
			REQUIRE(calc.totalSteps() == 2);

			calc = calc[2];
			REQUIRE(calc.totalSteps() == 3);
		}

		TEST_CASE("we could stream results", "[calc]") {

			ostringstream oss;

			Calc calc = Calc();

			oss << calc[1]["+"][2];

			REQUIRE(oss.str() == "3");
		}

		TEST_CASE("creating CalcStep with a value shouldn't have an operation", "[calcstep]") {

			auto step = CalcStep(123);

			REQUIRE(step.hasValue() == true);
			REQUIRE(step.hasOperation() == false);
			REQUIRE(step.getValue() == 123);
		}

		TEST_CASE("creating CalcStep with an operation shouldn't have a value", "[calcstep]") {

			auto step = CalcStep([](int, int) { return 0; });

			REQUIRE(step.hasValue() == false);
			REQUIRE(step.hasOperation() == true);
			REQUIRE(step.getOperation()(1, 1) == 0);
		}

	}

}


