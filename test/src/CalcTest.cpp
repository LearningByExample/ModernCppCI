#include "catch.hpp"
#include "Calc.hpp"
#include <cmath>
#include <memory>

using namespace std;

namespace ModernCppCI {

	namespace Test {
		TEST_CASE("calc should be created", "[calc]") {
			auto calc = make_unique<Calc>();

			REQUIRE(calc != nullptr);
		}

		TEST_CASE("we could use +", "[calc]") {
			Calc calc = Calc();

			auto result = calc["+"](1, 2);

			REQUIRE(result == 3);
		}

		TEST_CASE("we could use -", "[calc]") {
			Calc calc = Calc();

			auto result = calc["-"](1, 2);

			REQUIRE(result == -1);
		}

		TEST_CASE("we could use *", "[calc]") {
			Calc calc = Calc();

			auto result = calc["*"](1, 2);

			REQUIRE(result == 2);
		}

		TEST_CASE("we could use /", "[calc]") {
			Calc calc = Calc();

			auto result = calc["/"](10, 2);

			REQUIRE(result == 5);
		}

		TEST_CASE("we should add terms", "[calc]") {
			Calc calc = Calc();

			auto originalNumTerms = calc.totalOperations();

			calc.addOperation("^", [](int value1, int value2) { return (int) pow(value1, value2); });

			auto numTerms = calc.totalOperations();

			REQUIRE((numTerms - originalNumTerms) == 1);

			auto result = calc["^"](4, 5);

			REQUIRE(result == 1024);
		}

		TEST_CASE("invalid operation return 0", "[calc]") {
			Calc calc = Calc();

			auto result = calc["random"](1, 2);

			REQUIRE(result == 0);
		}

	}

}


