
make:
	g++ -std=c++11 -o trainer RegressionModel.class.cpp trainer.cpp
	g++ -std=c++11 -o predict predict.cpp

fclean:
	rm -f trainer
	rm -f predict
