#include "validator.h"

void run() {
	auto check_line = []() {
		string term = Word();
		Endl();
		assert(term.size() >= 1 && term.size() <= 10);
		assert(term == "0" || term[0] != '0'); // No leading zeros
		for (char c : term) {
			assert((c >= '0' && c <= '9') || (c>='A' && c <= 'F'));
		}
	};
	check_line();
	check_line();
	check_line();
	// Checking at least one base in answer is checked by an assert in js.cpp
}
