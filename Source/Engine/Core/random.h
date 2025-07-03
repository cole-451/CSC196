#pragma once
#include <cstdlib>
namespace parabellum {
	namespace random {
		inline int getrandom() {
			return rand();
		}

		inline int getrandom(int max) {
			return rand() % max;
		}

		inline int getrandom(int min, int max) {
			return min + getrandom(max - min + 1);
		}

		inline float getrandomfloat() {
			return rand()/ (float)RAND_MAX;
		}
	}
}