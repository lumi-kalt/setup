#include <fmt/core.h>
#include "dry-comparisons.hpp"

using namespace rollbear;

int main() {
	fmt::print("{}", 
				any_of(std::plus{}, std::minus{})(2, 3) == 5);
}
