#ifndef CALC_HPP
#define CALC_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

#include <map>
#include <functional>

using namespace std;


namespace ModernCppCI {

	template<class Type> using Dictionary = map<string, Type>;
	typedef function<int(int, int)> Operation;

	class Calc {
	public:
		Calc();

		void addOperation(string name, Operation operation);
		unsigned int totalOperations();
		Operation operator[] (string name);

	private:
		Dictionary<Operation> operations = Dictionary<Operation>();
		static Operation add;
		static Operation sub;
		static Operation mul;
		static Operation div;
		static Operation NoP;
	};

}

#endif //CALC_HPP
