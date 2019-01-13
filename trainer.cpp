
#include "RegressionModel.class.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

static std::vector<double>	parseNumbers(std::string str)
{
	std::replace(str.begin(), str.end(), ',', ' ');
	
	std::stringstream ss;
	std::vector<double> out;

	ss << str;

	std::string temp;
	double found;
	while (!ss.eof())
	{
		ss >> temp;

		if (std::stringstream(temp) >> found)
			out.push_back(found);
		temp = "";
	}
	return out;
}

static std::string	read_file(std::string filename)
{
	std::ifstream file(filename);
	std::stringstream ss;

	if (!file)
	{
		std::cout << "invalid file path\n";
		exit(1);
	}
	ss << file.rdbuf();
	return (ss.str());
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "give me a dataset file as a parameter" << std::endl;
		return 0;
	}
	std::string fileData = read_file(av[1]);
	std::vector<double> numbers = parseNumbers(fileData);
	std::vector<std::pair<double, double> > pairs;

	for (int i = 1; i < numbers.size(); i += 2)
		pairs.push_back(std::pair<double, double>(numbers[i - 1], numbers[i]));

	try
	{
		RegressionModel model(pairs);
		for (int i = 0; i < 1000; i++)
			model.Iteration();
		model.SaveIntoFile();
	}
	catch (std::exception)
	{
		std::cout << "bad dataset" << std::endl;
		return 1;
	}
}
