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
		std::string name = "./files/" + fileNames[i];
		std::cout << fileNames[i] << std::endl;
		text t = text(name);
		texts.push_back(t);
	}

	for(int i = 0; i < texts.size(); ++i) {
		texts[i].setMass(findTextMass(i));
		std::wcout << texts[i].getMass() << std::endl;
	}

}

int clusterAnaliz::findTextMass(int idx) {
	
	for(size_t i = 0; i < texts[idx].terms.size(); ++i) {
		for(size_t j = 0; j < texts.size(); ++j) {
			for(size_t k = 0; k < texts[j].terms.size(); ++k) {
				if(texts[idx].terms[i] == texts[j].terms[k]) {
					texts[idx].termsWeights[i] += 1;
				}
			}
		}
	}

	int mass = 0;

	for(size_t i = 0; i < texts[idx].terms.size(); ++i) {
		mass += texts[idx].termsWeights[i];
	}

	return mass;
 }