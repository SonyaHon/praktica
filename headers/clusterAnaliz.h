#pragma once
#include <vector>
#include "text.h"

class clusterAnaliz {
private:
	std::vector<text> texts;
	void findTextMass(int);

	double textDist(int, int);

	struct centroid {
		
		double mass;

		text c_text;

		std::vector<text> c_texts;

		void countMass() {};
	};

public:
	clusterAnaliz(std::string);
	void caDo(int);
};