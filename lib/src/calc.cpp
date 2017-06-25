/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include "calc.hpp"

using namespace std;

namespace ModernCppCI {

  Logger Calc::logger_ = Logger("ModernCppCI::Calc");

  Calc::Calc() {
    add_operation("+", DefaultOperations::Plus);
    add_operation("-", DefaultOperations::Minus);
    add_operation("*", DefaultOperations::Times);
    add_operation("/", DefaultOperations::Div);
  }

  Calc::Calc(const Calc &other) : Calc() {
    operations_ = other.operations_;
    steps_ = other.steps_;
  }

  Calc& Calc::operator=(const Calc& other) {
    operations_ = other.operations_;
    steps_ = other.steps_;

    return *this;
  }

  void Calc::add_operation(const string& name, const Operation& operation) {
    operations_[name] = operation;
  }

  void Calc::add_step(const CalcStep& step) {
    steps_.push_back(step);
  }

  Calc Calc::operator[](const string& name) {
    auto operation = operations_[name];

    if (operation == nullptr) {
      operation = DefaultOperations::Zero;
    }

    auto new_calc = Calc(*this);

    new_calc.add_step(CalcStep(name, operation));

    return new_calc;
  }

  Calc Calc::operator[](const int& value) {
    auto new_calc = Calc(*this);

    new_calc.add_step(value);

    return new_calc;
  }

  int Calc::result() const {

    logger_.debug("[{}]", __func__);

    int total = 0;
    logger_.trace("total is {}", total);
    Operation operation_to_execute = DefaultOperations::Zero;
    bool execute_operation = false;
    bool first_value = true;

    for (auto step : steps_) {
      logger_.trace("step = {}", step);
      if (step.has_operation()) {
        logger_.trace("step is an operation");
        operation_to_execute = step.operation();
        execute_operation = true;
        continue;
      }

      if (step.has_value()) {
        logger_.trace("step has value");
        if (first_value) {
          logger_.trace("step is first step");
          total = step.value();
          first_value = false;
          continue;
        }
        if (execute_operation) {
          logger_.trace("executing operation");
          total = operation_to_execute(total, step.value());
          execute_operation = false;
          logger_.trace("total so far is = {}", total);
        }
      }
    }

    logger_.debug("[{}] = {}", __func__, total);

    return total;
  }

  CalcStep::CalcStep() {
    has_value_ = false;
    has_operation_ = false;
  }

  CalcStep::CalcStep(const int& value) : CalcStep() {
    value_ = value;
    has_value_ = true;
  }

  CalcStep::CalcStep(const string& name, const Operation& operation) : CalcStep() {
    operation_ = operation;
    operation_name_ = name;
    has_operation_ = true;
  }

  std::ostream &operator<<(std::ostream &stream, const Calc& calc) {

    for (auto step : calc.steps_) {
      stream << step << " ";
    }

    stream << "= " << calc.result();
    return stream;
  }

  std::ostream & operator<<(std::ostream & stream, const CalcStep & step) {

    if (step.has_value()) {
      stream << step.value();
    } else {
      stream << step.operation_name();
    }

    return stream;
  }

}
