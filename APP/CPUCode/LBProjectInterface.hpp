/*
 * LBProjectInterface.h
 *
 *  Created on: 21 Mar 2016
 *      Author: dpackwood
 */

#ifndef LBPROJECTINTERFACE_H_
#define LBPROJECTINTERFACE_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Maxfiles.h"

class LBProjectInterface {
private:
	size_t dim, fSize;
	double * f;
	max_file_t * maxfile;
	max_engine_t * engine;
	bool flipper;
	double omega;
public:
	LBProjectInterface(size_t, double);
	void runSetup();
	void runMain();
	void runRead();
	void printFile(int);
};

#endif /* LBPROJECTINTERFACE_H_ */
