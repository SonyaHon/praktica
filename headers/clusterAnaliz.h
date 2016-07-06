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

		int t_idx;

		text c_text;

		std::vector<text> c_texts;

		void countMass() {
			text temp = c_texts[0];
			for(size_t i = 1; i < c_texts.size(); ++i) {
				temp+=c_texts[i];
			}
			c_text = temp;
		}
	};

public:
	clusterAnaliz(std::string);
	void caDo(int);
};