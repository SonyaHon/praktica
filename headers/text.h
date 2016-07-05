#pragma once
#include <vector>
#include <string>

class text {
private:
	int mass;

public:
	std::vector<std::wstring> terms;
	std::vector<double> termsWeights;
	text(std::string);
	text();
	~text(){};
	void setMass(int);
	int getMass();

	void print();

	text operator=(text &t);
};


//1/(summ(a-b)^2 +1)