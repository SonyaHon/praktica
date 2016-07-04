#include "../headers/text.h"
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <locale>

std::wstring canonL = L"цкнгшщзхфвпрлджчмстбьъ";
std::wstring canonU = L"ЦКНГШЩЗХФВПРЛДЖЧМСТБЬЪ";

void text::setMass(int value) {
	mass = value;
}

void text::print() {
	for(size_t i = 0; i < terms.size(); ++i) {
		std::wcout << terms[i] << " ";
	}
	std::wcout << "-----------------" <<std::endl;
}

text::text(std::string str) {

	std::ifstream file(str.c_str());
	std::string term;
	while(file >> term) {
		if(term.size() < 4) {
			continue;
		}
		wchar_t * ws = new wchar_t[(term.size()/2)*sizeof(wchar_t)];
		mbstowcs(ws, term.c_str(), term.size()/2);

		std::wstring wstr(ws);
		std::wstring finaleStr;

		for(size_t i = 0; i < wstr.size(); ++i) {
			for(size_t j = 0; j < canonL.size(); ++j) {
				if(wstr[i] == canonL[j]) {
					finaleStr += wstr[i];
				}
				else if(wstr[i] == canonU[j]) {
					finaleStr += canonL[j];
				}
			}
		}
		terms.push_back(finaleStr);
	}

	mass = 0;
}
