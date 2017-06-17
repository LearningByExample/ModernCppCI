#ifndef CALC_HPP
#define CALC_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

#include <map>
#include <functional>
#include <list>

using namespace std;

namespace ModernCppCI {

    template<class Type> using Dictionary = map<string, Type>;
    typedef function<int(int, int)> Operation;

    class CalcStep;

    class Calc {

    public:
        Calc();

        Calc(const Calc &other);

		Calc& operator=(const Calc& other);

        void addOperation(string name, Operation operation);

        unsigned int totalOperations();

        Calc operator[](string name);

        Calc operator[](int value);

        unsigned int totalSteps();

        int result() const;

        friend std::ostream &operator<<(std::ostream &stream, const Calc &calc);

    private:
        list <CalcStep> steps;
        Dictionary<Operation> operations = Dictionary<Operation>();

        static Operation add;
        static Operation sub;
        static Operation mul;
        static Operation div;
        static Operation NoP;
    };

    class CalcStep {

    private:
        CalcStep();

    public:
        CalcStep(int value);

        CalcStep(Operation operation);

        bool hasValue();

        bool hasOperation();

        int getValue();

        Operation getOperation();

    private:
        int _value;
        Operation _operation;

        bool _hasValue = false;
        bool _hasOperation = false;
    };
}

#endif //CALC_HPP
