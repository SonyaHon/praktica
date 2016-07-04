#pragma once
#include <vector>
#include <string>

class text {
private:
	std::vector<std::wstring> terms;
	int mass;

public:
	text(std::string);
	~text(){};
	void setMass(int);

	void print();
};