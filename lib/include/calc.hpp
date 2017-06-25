/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#ifndef CALC_HPP
#define CALC_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

#include <ostream>
#include <map>
#include <list>
#include "calc_step.hpp"
#include "logger.hpp"

using namespace std;

namespace ModernCppCI {

  template<class Type> using Dictionary = map<string, Type>;


  class Calc {

  public:
    Calc();

    Calc(const Calc& other);

    Calc& operator=(const Calc& other);

    void add_operation(const string& name, const Operation& operation);

    inline auto total_operations() const {
      return operations_.size();
    }

    void add_step(const CalcStep& step);

    void add_step(const string& operation_name);

    inline auto total_steps() const {
      return steps_.size();
    }

    int result() const;

    Calc operator<<(const int& value);

    Calc operator<<(const string& operation_name);

    friend std::ostream &operator<<(std::ostream &stream, const Calc& calc);

  private:
    list <CalcStep> steps_;
    Dictionary<Operation> operations_ = Dictionary<Operation>();
    static Logger logger_;
  };

  namespace DefaultOperations {
    const Operation Plus = [] (const int& value1, const int& value2) { return value1 + value2; };
    const Operation Minus = [] (const int& value1, const int& value2) { return value1 - value2; };
    const Operation Times = [] (const int& value1, const int& value2) { return value1 * value2; };
    const Operation Div = [] (const int& value1, const int& value2) { return value1 / value2; };
    const Operation Zero = [] (const int& value1, const int& value2) { return 0; };
  }

}

#endif //CALC_HPP
