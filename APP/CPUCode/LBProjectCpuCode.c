
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "MaxSLiCInterface.h"
#include "LBProjectInterface.hpp"

int main(void)
{
	size_t dim = 150;
	int T = 1000;
	int dT = 1000;
	double Re = 15000;

	LBProjectInterface lbInterface = LBProjectInterface(dim, Re);
	lbInterface.runSetup();

	for (int iT = 0; iT < T; iT++) {
		for (int idT = 0; idT < dT; idT++) {

			printf("Iteration: %d,%d\n", iT, idT);
			lbInterface.runMain();
		}
		lbInterface.runRead();
		lbInterface.printFile(iT);
	}

    printf("Done.\n");
    return 0;
}

