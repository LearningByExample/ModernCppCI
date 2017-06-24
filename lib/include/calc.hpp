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
#include "log.hpp"

using namespace std;
using namespace Log;

namespace ModernCppCI {

  template<class Type> using Dictionary = map<string, Type>;
  typedef function<int(const int&, const int&)> Operation;

  class CalcStep {

  private:
    CalcStep();

  public:
    CalcStep(const int& value);

    CalcStep(const string& name, const Operation& operation);

    bool has_value() const;

    bool has_operation() const;

    int value() const;

    Operation operation() const;

    friend std::ostream &operator<<(std::ostream &stream, const CalcStep& step);
    
    string operation_name() const;

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

    void AddOperation(const string& name, const Operation& operation);

    unsigned int total_operations() const;

    void AddStep(const CalcStep& step);

    Calc operator[](const string& name);

    Calc operator[](const int& value);

    unsigned int total_steps() const;

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
