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
#include <functional>
#include <list>
#include "logger.hpp"

using namespace std;

namespace ModernCppCI {

  template<class Type> using Dictionary = map<string, Type>;
  typedef function<int(const int&, const int&)> Operation;

  class CalcStep {

  private:
    CalcStep();

  public:
    CalcStep(const int& value);

    CalcStep(const string& name, const Operation& operation);

    inline auto has_value() const {
      return has_value_;
    }

    inline auto has_operation() const {
      return has_operation_;
    }

    inline auto value() const {
      return value_;
    }

    inline auto operation() const {
      return operation_;
    }

    inline auto operation_name() const {
      return operation_name_;
    }

    friend std::ostream &operator<<(std::ostream &stream, const CalcStep& step);

  private:
    int value_;
    Operation operation_;
    string operation_name_;
    bool has_value_ = false;
    bool has_operation_ = false;
  };

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

    Calc operator[](const string& name);

    Calc operator[](const int& value);

    inline auto total_steps() const {
      return steps_.size();
    }

    int result() const;

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
