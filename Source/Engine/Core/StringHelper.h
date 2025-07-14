#pragma once
#include <string>

namespace parabellum {
	inline std::string toLower(const std::string& string) {
		std::string result = string;
		for (char& c : result) {
			c = std::tolower(c);
		}
		return result;
	}
}