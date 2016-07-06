#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <locale>
#include "../headers/clusterAnaliz.h"

int main(int argc, char **argv) {
	setlocale(LC_CTYPE, "");

	clusterAnaliz ca = clusterAnaliz("./files1/");
	ca.caDo(3);

	return 0;
}