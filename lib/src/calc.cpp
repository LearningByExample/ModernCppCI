/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include "calc.h"
#include <typeinfo>

namespace ModernCppCI {

Calc &Calc::operator=(const Calc &other) noexcept {
  operations_ = {other.operations_};
  steps_ = {other.steps_};

  return *this;
}

void Calc::add_step(const CalcStep &step) { steps_.push_back(step); }

void Calc::add_step(const int value) { add_step(CalcStep{value}); }

void Calc::add_step(const std::string &operation_name) {
  auto &operation = operations_[operation_name];

  if (operation == nullptr) {
    operation = DefaultOperations::Zero;
  }

  add_step(CalcStep{operation_name, operation});
}

int Calc::result() const {
  logger_.debug("[{}]", __func__);

  int total{0};
  logger_.trace("total is {}", total);
  Operation operation_to_execute{DefaultOperations::Zero};
  bool execute_operation{false};
  bool first_value{true};

  for (const auto &step : steps_) {
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

std::ostream &operator<<(std::ostream &stream, const Calc &calc) {
  for (const auto &step : calc.steps_) {
    stream << step << " ";
  }

  stream << "= " << calc.result();
  return stream;
}

Logger Calc::logger_{typeid(Calc).name()};

}  // namespace ModernCppCI
