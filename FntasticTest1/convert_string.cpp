#include <iostream>
#include <string>
#include <map>
#include <cctype>

std::string convert(const std::string& s) {
	std::map<char, int> char_count;
	for (char c : s) {
		++char_count[tolower(c)];
	}
	std::string ret_val(s.size(), '(');
	for (int i = 0; i < s.size(); ++i) {
		char c = tolower(s[i]);
		if (char_count[c] > 1) {
			ret_val[i] = ')';
		}
	}
	return ret_val;
}

int main() {
	std::string input;
	while (true) {
		std::cout << "enter a string or press 'Enter' to quit" << std::endl;
		getline(std::cin, input);
		if (input.empty()) {
			break;
		}
		std::cout << '"' << input << "\" => \"" << convert(input) << '"' << std::endl;
	}
	return 0;
}