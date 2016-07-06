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
#include <math.h>

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
}

void clusterAnaliz::caDo(int clustersAmount) {
	srand(time(NULL));
	std::vector<clusterAnaliz::centroid> centroids;

	for (size_t i = 0; i < clustersAmount; ++i) {
		int idx = rand() % texts.size();
		clusterAnaliz::centroid c;
		c.mass = 0;
		text temp = texts[idx];
		c.c_text = temp;
	}

	for (int i = 0; i < texts.size(); ++i) {
		double dist = 0;
		for (int j = 0; j < centroids.size(); ++j) {

		}
	}
}

void clusterAnaliz::findTextMass(int idx) {

	for (size_t i = 0; i < texts[idx].terms.size(); ++i) {
		for (size_t j = 0; j < texts[idx].terms.size(); ++j) {
			if (texts[idx].terms[i].str == texts[idx].terms[j].str) {
				texts[idx].terms[i].weight += 1;
			}
		}
	}

	for (size_t i = 0; i < texts[idx].terms.size(); ++i) {
		if (texts[idx].terms[i].weight <= 2) {
			texts[idx].terms.erase(texts[idx].terms.begin() + i);
			std::vector<text::myPair>(texts[idx].terms).swap(texts[idx].terms);
			--i;
		}
	}
}

double clusterAnaliz::textDist(int idx1, int idx2) {

	text t1 = texts[idx1];
	text t2 = texts[idx2];

	double summ = 0;

	for (size_t i = 0; i < t1.terms.size(); ++i) {
		for (size_t j = 0; j < t2.terms.size(); ++j) {
			if (t1.terms[i].str == t2.terms[j].str) {
				summ += t1.terms[i].weight + t2.terms[j].weight;
			}
		}
	}
	return summ / (t1.terms.size() + t2.terms.size());
}