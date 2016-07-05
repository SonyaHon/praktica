#pragma once
#include <vector>
#include "text.h"

class clusterAnaliz {
private:
	std::vector<text> texts;
	void findTextMass(int);

	double textDist(int, int);

public:
	clusterAnaliz(std::string);
};