#include "../../heterogeneous.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
	heterogeneous<std::vector, int, float, std::string> hetero;
	hetero.get<int>().emplace_back(1);
	hetero.get<int>().push_back(2);
	hetero.get<float>().emplace_back(1.5f);
	hetero.get<std::string>().emplace_back("hello");
	hetero.get<std::string>().emplace_back("world");

	std::apply([](auto ...x)
	{
		auto print = [](auto const& container) {
			for (auto const& e : container)
				std::cout << e << std::endl;
		};

		(print(x),...);
	}, hetero.containers);
}