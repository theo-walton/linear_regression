
#include "RegressionModel.class.hpp"

double	RegressionModel::EstimateY(double x)
{
	return _theta0 + _theta1 * x;
}

RegressionModel::RegressionModel(std::vector<std::pair<double, double> > &dataPoints)
	: _dataPoints(dataPoints),
	  _theta0(0),
	  _theta1(0),
	  _meanX(0),
	  _meanY(0)
{
	if (dataPoints.size() < 2)
		throw std::exception();
	
	double max[2] = {dataPoints[0].first, dataPoints[0].second};
	double min[2] = {dataPoints[0].first, dataPoints[0].second};
	
	for (auto &p : _dataPoints)
	{
		if (p.first > max[0])
			max[0] = p.first;
		if (p.second > max[1])
			max[1] = p.second;
		if (p.first < min[0])
			min[0] = p.first;
		if (p.second < min[1])
			min[1] = p.second;
		_meanX += p.first;
		_meanY += p.second;
	}
	_rangeX = max[0] - min[0];
	_rangeY = max[1] - min[1];
	_meanX /= _dataPoints.size();
	_meanY /= _dataPoints.size();

	if (_rangeX == 0 || _rangeY == 0)
		throw std::exception();
}

void	RegressionModel::Iteration(void)
{
	double tempTheta0 = 0;

	for (auto &p : _dataPoints)
	{
		double normX = (p.first - _meanX) / _rangeX;
		double normY = (p.second - _meanY) / _rangeY;
		tempTheta0 += EstimateY(normX) - normY;
	}

	double tempTheta1 = 0;

	for (auto &p : _dataPoints)
	{
		double normX = (p.first - _meanX) / _rangeX;
		double normY = (p.second - _meanY) / _rangeY;
		tempTheta1 += (EstimateY(normX) - normY) * normX;
	}
	_theta0 -= (tempTheta0 * _learningRate) / _dataPoints.size();
	_theta1 -= (tempTheta1 * _learningRate) / _dataPoints.size();

//	std::cout << _theta0 << " " << _theta1 << std::endl;
}

void	RegressionModel::SaveIntoFile(void)
{
	std::ofstream file("Thetas");

	double denorm0 = _meanY + _theta0 * _rangeY - (_rangeY * _theta1 * _meanX) / _rangeX;
	double denorm1 = (_rangeY * _theta1) / _rangeX;
	
	file << denorm0 << " " << denorm1;
}
