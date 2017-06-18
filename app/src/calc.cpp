#include "Calc.hpp"
#include<iostream>

using namespace std;

namespace ModernCppCI {

  Calc::Calc() {
    AddOperation("+", DefaultOperations::Plus);
    AddOperation("-", DefaultOperations::Minus);
    AddOperation("*", DefaultOperations::Times);
    AddOperation("/", DefaultOperations::Div);
  }

  Calc::Calc(const Calc &other) : Calc() {
    operations_ = other.operations_;
    steps_ = other.steps_;
  }

  Calc& Calc::operator=(const Calc &other) {
    operations_ = other.operations_;
    steps_ = other.steps_;

    return *this;
  }

  void Calc::AddOperation(const string& name, const Operation& operation) {
    operations_[name] = operation;
  }

  unsigned int Calc::total_operations() const {
    return operations_.size();
  }

  void Calc::AddStep(const CalcStep & step) {
    steps_.push_back(step);
  }

  Calc Calc::operator[](const string& name) {
    auto operation = operations_[name];

    if (operation == nullptr) {
      operation = DefaultOperations::Zero;
    }

    auto new_calc = Calc(*this);

    new_calc.AddStep(operation);

    return new_calc;
  }

  Calc Calc::operator[](const int& value) {
    auto new_calc = Calc(*this);

    new_calc.AddStep(value);

    return new_calc;
  }

  unsigned int Calc::total_steps() const {
    return steps_.size();
  }

  int Calc::result() const {
    int total = 0;
    Operation operation_to_execute = DefaultOperations::Zero;
    bool execute_operation = false;
    bool first_value = true;

    for (auto step : steps_) {
      if (step.has_operation()) {
        operation_to_execute = step.operation();
        execute_operation = true;
        continue;
      }

      if (step.has_value()) {
        if (first_value) {
          total = step.value();
          first_value = false;
          continue;
        }
        if (execute_operation) {
          total = operation_to_execute(total, step.value());
          execute_operation = false;
        }
      }
    }

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

  CalcStep::CalcStep(const Operation& operation) : CalcStep() {
    operation_ = operation;
    has_operation_ = true;
  }

  bool CalcStep::has_value() const {
    return has_value_;
  }

  bool CalcStep::has_operation() const {
    return has_operation_;
  }

  int CalcStep::value() const {
    return value_;
  }

  Operation CalcStep::operation() const {
    return operation_;
  }

  std::ostream &operator<<(std::ostream &stream, const Calc &calc) {
    stream << calc.result();

    return stream;
  }

}
