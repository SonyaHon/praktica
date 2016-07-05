#pragma once
#include <vector>
#include "text.h"

class clusterAnaliz {
private:
	std::vector<text> texts;
	int findTextMass(int	);

public:
	clusterAnaliz(std::string);
};