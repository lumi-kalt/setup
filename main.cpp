#include <string>
#include <string_view>

#include <fmt/core.h>
#include <scn/scn.h>

#include "dry-comparisons.hpp"
#include "tl/optional.hpp"

using namespace rollbear;

class Kitten {
	std::string name;
public:
	Kitten(std::string_view name) : name{name} {}

	static auto pat(Kitten k) noexcept
	-> tl::optional<Kitten>  {
		fmt::print("*patpat {}*\n", k.name);
		return k;
	}

	static auto feed(Kitten k) noexcept
	-> tl::optional<Kitten> {
		fmt::print("{} is fed a nice bowl of food.\n", k.name);
		return k;
	}
};

auto main()
-> int {
	std::string name;
	auto _ = scn::prompt("Kitty name? ", "{}", name);

	tl::optional<Kitten> kitty;
	kitty = Kitten{name};
	kitty.and_then(Kitten::feed)
		 .map(Kitten::pat)
		 .or_else([] { fmt::print("\nThis is not a kitten!?"); });

	kitty = tl::nullopt;
	kitty.and_then(Kitten::feed)
		 .map(Kitten::pat)
		 .or_else([] { fmt::print("\nThis is not a kitten!?"); });

}
