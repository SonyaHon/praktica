#pragma once
#include <vector>
#include <string>

class text {
private:
	std::vector<std::wstring> terms;

public:
	text(std::string);
	~text(){};
	void print();

};