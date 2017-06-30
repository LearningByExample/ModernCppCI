/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#ifndef CALC_STEP_HPP
#define CALC_STEP_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
#pragma once
#endif

#include <functional>
#include <string>

namespace ModernCppCI {

using Operation = std::function<int(const int &, const int &)>;

class CalcStep {
 private:
  CalcStep() noexcept {};

 public:
  explicit CalcStep(const int &value) noexcept
      : value_{value}, has_value_{true} {}

  CalcStep(const std::string &name, const Operation &operation) noexcept
      : operation_{operation}, operation_name_{name}, has_operation_{true} {}

  auto has_value() const noexcept { return has_value_; }

  auto has_operation() const noexcept { return has_operation_; }

  auto value() const noexcept { return value_; }

  auto operation() const noexcept { return operation_; }

  auto operation_name() const noexcept { return operation_name_; }

  friend std::ostream &operator<<(std::ostream &stream, const CalcStep &step);

 private:
  int value_{0};
  Operation operation_{nullptr};
  std::string operation_name_{""};
  bool has_value_{false};
  bool has_operation_{false};
};
}  // namespace ModernCppCI

#endif  // CALC_STEP_HPP
