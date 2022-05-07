#include <fmt/core.h>
#include "dry-comparisons.hpp"
#include "tl/optional.hpp"

using namespace rollbear;

int main() {
	fmt::print("{}\n", 
				any_of(std::plus{}, std::minus{})(2, 3) == 5);
}
