#include "Calc.hpp"
#include<iostream>

using namespace std;

namespace ModernCppCI {

    Calc::Calc() {
        this->addOperation("+", add);
        this->addOperation("-", sub);
        this->addOperation("*", mul);
        this->addOperation("/", div);
    }

    Calc::Calc(const Calc &other) : Calc() {
        this->operations = other.operations;
        this->steps = other.steps;
    }

	Calc & Calc::operator=(const Calc &other)
	{
		this->operations = other.operations;
		this->steps = other.steps;

		return *this;
	}

    void Calc::addOperation(string name, Operation operation) {
        this->operations[name] = operation;
    }

    unsigned int Calc::totalOperations() {
        return this->operations.size();
    }

    Calc Calc::operator[](string name) {
        auto operation = this->operations[name];

        if (operation == nullptr) {
            operation = NoP;
        }

        auto step = CalcStep(operation);
        this->steps.push_back(step);

        return Calc(*this);
    }

    Calc Calc::operator[](int value) {
        auto step = CalcStep(value);
        this->steps.push_back(step);

        return Calc(*this);
    }

    unsigned int Calc::totalSteps() {
        return steps.size();
    }

    int Calc::result() const {
        int total = 0;
        Operation lastOperation = NoP;
        bool nextExecute = false;
        bool firstValue = true;

        for (auto step : steps) {
            if (step.hasOperation()) {
                lastOperation = step.getOperation();
                nextExecute = true;
                continue;
            }

            if (step.hasValue()) {

                if (firstValue) {
                    total = step.getValue();
                    firstValue = false;
                    continue;
                }

                if (nextExecute) {
                    total = lastOperation(total, step.getValue());
                    nextExecute = false;
                }
            }
        }

        return total;
    }

    Operation Calc::add = [](int value1, int value2) { return value1 + value2; };
    Operation Calc::sub = [](int value1, int value2) { return value1 - value2; };
    Operation Calc::mul = [](int value1, int value2) { return value1 * value2; };
    Operation Calc::div = [](int value1, int value2) { return value1 / value2; };
    Operation Calc::NoP = [](int value1, int value2) { return 0; };

    CalcStep::CalcStep() {
        this->_hasValue = false;
        this->_hasOperation = false;
    }

    CalcStep::CalcStep(int value) : CalcStep() {
        this->_value = value;
        this->_hasValue = true;
    }

    CalcStep::CalcStep(Operation operation) : CalcStep() {
        this->_operation = operation;
        this->_hasOperation = true;
    }

    bool CalcStep::hasValue() {
        return _hasValue;
    }

    bool CalcStep::hasOperation() {
        return _hasOperation;
    }

    int CalcStep::getValue() {
        return _value;
    }

    Operation CalcStep::getOperation() {
        return _operation;
    }

    std::ostream &operator<<(std::ostream &stream, const Calc &calc) {
        stream << calc.result();

        return stream;
    }

}
