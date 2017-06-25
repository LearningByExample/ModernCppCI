/*
*  Distributed under the MIT License (See accompanying file /LICENSE )
*/
#include "calc_step.hpp"

using namespace std;

namespace ModernCppCI {
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

  std::ostream & operator<<(std::ostream& stream, const CalcStep& step) {

    if (step.has_value()) {
      stream << step.value();
    } else {
      stream << step.operation_name();
    }

    return stream;
  }

}