#ifndef TIME_TRACK_H
#define TIME_TRACK_H

#include <chrono>
#include <functional>
#include <tuple>

namespace common {

	template <typename T>
	std::tuple<T, std::chrono::milliseconds> time_solve_duration(std::function<T()> func) {
		auto start{ std::chrono::high_resolution_clock::now() };
		T result{ func() };
		auto end{ std::chrono::high_resolution_clock::now() };
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		return std::make_tuple(result, duration);
	}
}
#endif // !TIME_TRACK_H
