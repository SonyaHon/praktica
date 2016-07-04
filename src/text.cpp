#include "../headers/text.h"
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <locale>

std::wstring canonL = L"цкнгшщзхфвпрлджчмстбьъ";
std::wstring canonU = L"ЦКНГШЩЗХФВПРЛДЖЧМСТБЬЪ";

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
		std::wcout << finaleStr << std::endl;
	}

}
