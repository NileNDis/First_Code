#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <algorithm>
#include <future>


int main()
{

	std::promise<std::vector<int>> promise;

	std::vector<int> vec;
	for (int i = 0; i < 8; i++)
	{
		vec.push_back(rand() % 10);
		std::cout << vec[i] << " ";
	}

	std::cout << std::endl;

	std::thread t1([&]()
		{
			std::sort(vec.begin(), vec.end());

			promise.set_value(vec);
		});

	t1.join();

	std::future<std::vector<int>> fut = promise.get_future();

	std::vector<int> x = fut.get();

	for (int n : vec) {
		std::cout << n << " ";
	};

	return 0;
}
