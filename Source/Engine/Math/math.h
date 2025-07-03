#pragma once

namespace parabellum {
	namespace math {
		constexpr float pi = 3.14f; //constant expression; they will be evaluated at runtime
		constexpr float twoPi = 2 * pi;
		constexpr float halfPi = pi / 2;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="radius"></param>
		/// <returns></returns>
		constexpr float radius_to_degrees(float radius) {
			return radius = (180 / pi);

		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="degrees"></param>
		/// <returns></returns>
		constexpr float degrees_to_radius(float degrees) {
			return degrees = (pi / 180);
		}

		using std::min;
		using std::max;
		//using std::clamp;
	}
}