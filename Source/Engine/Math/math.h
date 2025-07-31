#pragma once
#include <cmath>
#include <algorithm>

namespace parabellum::math {
		constexpr float pi = 3.14f; //constant expression; they will be evaluated at runtime
		constexpr float twoPi = 2 * pi;
		constexpr float halfPi = pi / 2;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="radius"></param>
		/// <returns></returns>
		constexpr float radius_to_degrees(float radius) {
			return radius * (180 / pi);

		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="degrees"></param>
		/// <returns></returns>
		constexpr float degrees_to_radius(float degrees) {
			return degrees * (pi / 180);
		}

		constexpr int Wrap(int value, int min, int max) {
			int range = max - min;
			int result = (value - min) % range;
			if (result < 0) result += range;

			return min + result;
		}

		/*constexpr float Wrap(float value, float min, float max) {
			float range = max - min;
			float result = (value - min) % range;
			if (result < 0) result += range;

			return min + result;
		}*/

		using std::min;
		using std::max;
		using std::sqrt;
		using std::sqrtf;
		using std::sin;
		using std::sinf;
		using std::cos;
		using std::cosf;
		using std::atan2;
		using std::atan2f;

		//using std::clamp;
	
}