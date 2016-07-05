#pragma once
#include <vector>
#include <string>

class text {
private:
	int mass;

public:
	std::vector<std::wstring> terms;
	std::vector<int> termsWeights;
	text(std::string);
	~text(){};
	void setMass(int);
	int getMass();

	void print();
};