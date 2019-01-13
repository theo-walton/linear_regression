
#include <iomanip>
#include <iostream>
#include <fstream>

int	main(void)
{
	std::ifstream file("Thetas");

	if (!file)
	{
		std::cout << "no data available" << std::endl;
		return 1;
	}

	double theta0, theta1;
	file >> theta0 >> theta1;

	while (!std::cin.eof())
	{
		float mileage;
		std::cout << "give me a mileage" << std::endl;
		std::cin >> mileage;
		float price = theta0 + theta1 * mileage;
		std::cout << "estimated price is: " << price << std::endl << std::endl;
	}
}
