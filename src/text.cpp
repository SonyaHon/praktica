#include "../headers/text.h"
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <locale>

std::wstring canonL = L"цкнгшщзхфвпрлджчмстбьъ1234567890";
std::wstring canonU = L"ЦКНГШЩЗХФВПРЛДЖЧМСТБЬЪ";
std::string euCanon = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm+-:;&$#@";

void text::setMass(int value) {
	mass = value;
}

void text::print() {
	for (size_t i = 0; i < terms.size(); ++i) {
		std::wcout << terms[i].str << " ";
	}
}

text::text() {
	mass = 0;
}

text text::operator=(text &t) {
	text a = text();
	a.terms = t.terms;
	a.mass = t.mass;

	return a;
}

text text::operator=(const text &t) {
	text a = text();
	a.terms = t.terms;
	a.mass = t.mass;

	return a;
}


text::text(std::string str) {

	std::ifstream file(str.c_str());
	std::string term;
	while (file >> term) {
		bool flag = false;
		for (size_t x = 0; x < euCanon.size(); ++x) {
			if (term[0] == euCanon[x]) flag = true;
		}
		if (flag) {
			wchar_t * ws = new wchar_t[(term.size())*sizeof(wchar_t)];
			mbstowcs(ws, term.c_str(), term.size());

			std::wstring wstr(ws);
			std::wstring finaleStr;

			for (size_t q = 0; q < wstr.size(); ++q) {
				for (size_t m = 0; m < euCanon.size(); ++m) {
					if (wstr[q] == euCanon[m]) {
						finaleStr += euCanon[m];
					}
				}
			}

			myPair p;
			p.str = finaleStr;
			p.weight = 0;

			terms.push_back(p);
		}
		else if (!flag) {
			if (term.size() < 8) {
				continue;
			}
			wchar_t * ws = new wchar_t[(term.size() / 2)*sizeof(wchar_t)];
			mbstowcs(ws, term.c_str(), term.size() / 2);

			std::wstring wstr(ws);
			std::wstring finaleStr;

			for (size_t i = 0; i < wstr.size(); ++i) {
				for (size_t j = 0; j < canonL.size(); ++j) {
					if (wstr[i] == canonL[j]) {
						finaleStr += wstr[i];
					}
					else if (wstr[i] == canonU[j]) {
						finaleStr += canonL[j];
					}
				}
			}

			myPair p;
			p.str = finaleStr;
			p.weight = 0;

			terms.push_back(p);
		}
	}

	mass = 0;
}

int text::getMass() {
	return mass;
}