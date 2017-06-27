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

typedef std::function<int(const int &, const int &)> Operation;

class CalcStep {
 private:
  CalcStep();

 public:
  CalcStep(const int &value);

  CalcStep(const std::string &name, const Operation &operation);

  inline auto has_value() const { return has_value_; }

  inline auto has_operation() const { return has_operation_; }

  inline auto value() const { return value_; }

  inline auto operation() const { return operation_; }

  inline auto operation_name() const { return operation_name_; }

  friend std::ostream &operator<<(std::ostream &stream, const CalcStep &step);

 private:
  int value_;
  Operation operation_;
  std::string operation_name_;
  bool has_value_ = false;
  bool has_operation_ = false;
};
}  // namespace ModernCppCI

#endif  // CALC_STEP_HPP
