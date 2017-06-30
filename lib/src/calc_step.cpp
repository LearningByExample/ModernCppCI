/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include "calc_step.h"
#include <sstream>

namespace ModernCppCI {

std::ostream &operator<<(std::ostream &stream, const CalcStep &step) {
  if (step.has_value()) {
    stream << step.value();
  } else {
    stream << step.operation_name();
  }

  return stream;
}

}  // namespace ModernCppCI
