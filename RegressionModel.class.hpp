#ifndef REGRESSIONMODEL_CLASS_HPP
#define REGRESSIONMODEL_CLASS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

//pair.first = x
//pair.second = y

class RegressionModel
{
private:
	
	double _theta0;
	double _theta1;
	double _meanX;
	double _meanY;
	double _rangeX;
	double _rangeY;
	std::vector<std::pair<double, double> > &_dataPoints;
	static constexpr double _learningRate = 1;

	double	EstimateY(double x);		
	
public:
	
	RegressionModel(std::vector<std::pair<double, double> > &dataPoints);

	void	Iteration(void);
	void	SaveIntoFile(void);
};

#endif
