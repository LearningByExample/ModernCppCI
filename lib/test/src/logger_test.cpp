/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include "logger.h"
#include <catch.hpp>

namespace ModernCppCI {

namespace Test {

class Person {
 public:
  Person(const std::string& name, const unsigned int& age) noexcept
      : name_{name}, age_{age} {}

  friend std::ostream& operator<<(std::ostream& stream, const Person& object) {
    stream << "name: " << object.name_ << " age: " << object.age_;
    return stream;
  }

 private:
  std::string name_{""};
  unsigned int age_{0};
};

TEST_CASE("logger work as expected", "[logger]") {
  Logger log("logger test");

  SECTION("the section is correct") { REQUIRE(log.section() == "logger test"); }

  SECTION("we could set log level") {
    Logger::level(LogLevel::trace);
    CHECK(true);
  }

  SECTION("we could info") {
    log.info("this is a {} message", "info");
    REQUIRE(true);
  }

  SECTION("we could trace") {
    log.trace("this is a {} message", "trace");
    REQUIRE(true);
  }

  SECTION("we could debug") {
    log.debug("this is a {} message", "debug");
    REQUIRE(true);
  }

  SECTION("we could error") {
    log.error("this is a {} message", "error");
    REQUIRE(true);
  }

  SECTION("we could simple logging info") {
    log.info("this is simple info logging");
    REQUIRE(true);
  }

  SECTION("we could simple logging trace") {
    log.trace("this is simple trace logging");
    REQUIRE(true);
  }

  SECTION("we could simple logging debug") {
    log.debug("this is simple debug logging");
    REQUIRE(true);
  }

  SECTION("we could simple logging error") {
    log.error("this is simple error logging");
    REQUIRE(true);
  }

  SECTION("we could logging with level as arg") {
    log.log(LogLevel::info, "this is simple logging with {} as arg", "level");
    REQUIRE(true);
  }

  Person person{"test", 20};

  SECTION("we could info objects") {
    log.info(person);
    REQUIRE(true);
  }

  SECTION("we could trace objects") {
    log.trace(person);
    REQUIRE(true);
  }

  SECTION("we could debug objects") {
    log.debug(person);
    REQUIRE(true);
  }
  SECTION("we could error objects") {
    log.error(person);
    REQUIRE(true);
  }
}

}  // namespace Test

}  // namespace ModernCppCI