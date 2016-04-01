/*
 * LBProjectInterface.cpp
 *
 *  Created on: 21 Mar 2016
 *      Author: dpackwood
 */
#include "LBProjectInterface.hpp"
#include "Maxfiles.h"

LBProjectInterface::LBProjectInterface(size_t dim_, double Re) {
	dim = dim_;
	maxfile = LBProject_init();
	engine = max_load(maxfile, "*");

	int burstWidthInBytes = 192;
	size_t candidatefSize = dim*dim*9*sizeof(double);
	size_t fBursts = (candidatefSize + burstWidthInBytes - 1)/burstWidthInBytes;
	fSize = fBursts*burstWidthInBytes;
	printf("Determined an lmem size of %d bytes\n", (int) fSize);
	f = (double *) malloc(fSize);
	flipper = false;
	double nu = dim*0.1/Re;
	omega = 2.0/(2.0*nu/3.0 + 1.0);
}

void LBProjectInterface::runSetup() {

	int idx = 0;
	for (size_t i = 0; i < dim; i++) {
		for (size_t j = 0; j < dim; j++) {
			f[idx]   = 4.0/9.0;
			f[idx+1] = 1.0/9.0;
			f[idx+2] = 1.0/9.0;
			f[idx+3] = 1.0/9.0;
			f[idx+4] = 1.0/9.0;
			f[idx+5] = 1.0/36.0;
			f[idx+6] = 1.0/36.0;
			f[idx+7] = 1.0/36.0;
			f[idx+8] = 1.0/36.0;
			idx+=9;
		}
	}

	max_actions_t * act = max_actions_init(maxfile, NULL);
	max_queue_input(act, "setup_cpu", f, fSize);
	max_lmem_linear(act, "setup_lmem", 0, fSize);
	max_ignore_kernel(act, "LBProjectKernel");
	max_ignore_lmem(act, "read_lmem");
	max_ignore_lmem(act, "f_lmem");
	max_ignore_lmem(act, "g_lmem");
	max_run(engine, act);
	max_actions_free(act);
}

void LBProjectInterface::runRead() {

	max_actions_t * act = max_actions_init(maxfile, NULL);
	max_queue_output(act, "read_cpu", f, fSize);
	if (flipper == false) {
		max_lmem_linear(act, "read_lmem", 0, fSize);
	} else {
		max_lmem_linear(act, "read_lmem", fSize, fSize);
	}
	max_ignore_kernel(act, "LBProjectKernel");
	max_ignore_lmem(act, "setup_lmem");
	max_ignore_lmem(act, "f_lmem");
	max_ignore_lmem(act, "g_lmem");
	max_run(engine, act);
	max_actions_free(act);
}

void LBProjectInterface::printFile(int findex) {

	const size_t filenameMax = 100;
	char fname[filenameMax];
	snprintf(fname, filenameMax, "output/LB%d.dat", findex);
	printf("Writing to file: %s\n",fname);
	fname[filenameMax - 1] = 0;
	FILE * fout = fopen (fname, "w");
	fprintf(fout, "%d\n", (int) dim);
	int idx = 0;
	for (size_t i = 0; i < dim; i++) {
		for (size_t j = 0; j < dim; j++) {
			fprintf(fout, "%g %g %g %g %g %g %g %g %g\n", f[idx],
														  f[idx+1],
														  f[idx+2],
														  f[idx+3],
														  f[idx+4],
														  f[idx+5],
														  f[idx+6],
														  f[idx+7],
														  f[idx+8]);
			idx += 9;
		}
	}
	fclose(fout);
}

void LBProjectInterface::runMain() {

	max_actions_t * act = max_actions_init(maxfile, NULL);
	if (flipper == false) {
		max_lmem_linear(act, "f_lmem", 0, fSize);
		max_lmem_linear(act, "g_lmem", fSize, fSize);
	} else {
		max_lmem_linear(act, "f_lmem", fSize, fSize);
		max_lmem_linear(act, "g_lmem", 0, fSize);
	}
	max_set_ticks(act, "LBProjectKernel", dim*dim);
	max_set_uint64t(act, "LBProjectKernel", "dim", dim);
	max_set_double(act, "LBProjectKernel", "omega", omega);
	max_set_offset(act, "LBProjectKernel", "dimoff", dim);
//	max_ignore_kernel(act, "LBProjectKernel");
//	max_ignore_lmem(act, "g_lmem");
//	max_ignore_lmem(act, "f_lmem");
	max_ignore_lmem(act, "setup_lmem");
	max_ignore_lmem(act, "read_lmem");
	max_run(engine, act);
	max_actions_free(act);
	flipper = !flipper;
}
