#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "../headers/text.h"
#include <locale>

int main(int argc, char **argv) {
	setlocale(LC_CTYPE, "");

	text t = text("text.txt");

	return 0;
}