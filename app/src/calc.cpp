#include "Calc.hpp"

using namespace std;

namespace ModernCppCI {

	Calc::Calc() {
		this->addOperation("+", add);
		this->addOperation("-", sub);
		this->addOperation("*", mul);
		this->addOperation("/", div);
	}

	void Calc::addOperation(string name, Operation operation) {
		this->operations[name] = operation;
	}

	unsigned int Calc::totalOperations() {
		return this->operations.size();
	}

	Operation Calc::operator[](string name)
	{
		auto operation = this->operations[name];

		if (operation == nullptr) {
			return NoP;
		}

		return operation;
	}

	Operation Calc::add = [](int value1, int value2) { return value1 + value2; };
	Operation Calc::sub = [](int value1, int value2) { return value1 - value2; };
	Operation Calc::mul = [](int value1, int value2) { return value1 * value2; };
	Operation Calc::div = [](int value1, int value2) { return value1 / value2; };
	Operation Calc::NoP = [](int value1, int value2) { return 0; };

}
