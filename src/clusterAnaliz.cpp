#include "../headers/clusterAnaliz.h"
#include <dirent.h>
#include <sys/types.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>

std::vector <std::string> readDir( const std::string& path = std::string() ) {
	std::vector <std::string> result;
	dirent* de;
	DIR* dp;
	errno = 0;
	dp = opendir( path.empty() ? "." : path.c_str() );
	if (dp)
	{
		while (true)
		{
			errno = 0;
			de = readdir( dp );
			if (de == NULL) break;
			result.push_back( std::string( de->d_name ) );
		}
		closedir( dp );
		std::sort( result.begin(), result.end() );
	}
	return result;
}

clusterAnaliz::clusterAnaliz(std::string directory) {

	std::vector<std::string> fileNames = readDir(directory);

	for (size_t i = 2; i < fileNames.size(); ++i) {
		std::string name = directory + fileNames[i];
		std::cout << name << std::endl;
		text t = text(name);
		texts.push_back(t);
	}

	for (int i = 0; i < texts.size(); ++i) {
		findTextMass(i);
	}

	std::cout << textDist(0, 1) << std::endl;

}

void clusterAnaliz::findTextMass(int idx) {

	for (size_t i = 0; i < texts[idx].terms.size(); ++i) {
		for (size_t j = 0; j < texts[idx].terms.size(); ++j) {
			if (texts[idx].terms[i] == texts[idx].terms[j]) {
				texts[idx].termsWeights[i] += 1;
			}
		}
	}

	for (size_t i = 0; i < texts[idx].terms.size(); ++i) {
		if(texts[idx].termsWeights[i] == 0) {
			texts[idx].termsWeights.erase(texts[idx].termsWeights.begin() + i);
			std::vector<double>(texts[idx].termsWeights).swap(texts[idx].termsWeights);
		}	
	}
}

double clusterAnaliz::textDist(int idx1, int idx2) {

	text t1 = texts[idx1];
	text t2 = texts[idx2];

	if (t1.terms.size() > t2.terms.size()) {
		for (size_t i = 0; i < t1.terms.size() - t2.terms.size(); ++i) {
			t2.termsWeights.push_back(1);
		}
	}

	double summ = 0;

	for (size_t i = 0; i < t1.terms.size(); ++i) {
		summ += (t1.termsWeights[i] - t2.termsWeights[i])*(t1.termsWeights[i] - t2.termsWeights[i]);
	}

	return 1/(summ + 1);
}