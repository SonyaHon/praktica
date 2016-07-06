#pragma once
#include <vector>
#include <string>

class text {
private:
	int mass;

public:

	struct myPair {
		std::wstring str;
		double weight;
	};

	std::vector<myPair> terms;
	text(std::string);
	text();
	~text() {};
	void setMass(int);
	int getMass();

	void print();

	text operator=(const text &t);
	text operator=(text &t);
	text operator+=(text &t) {
		for(size_t i = 0; i < t.terms.size(); ++i) {
			terms.push_back(t.terms[i]);
		}

		return *this;
	}
};


//1/(summ(a-b)^2 +1)