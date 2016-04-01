/**\file */
#ifndef SLIC_DECLARATIONS_LBProject_H
#define SLIC_DECLARATIONS_LBProject_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/




/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] offset_LBProjectKernel_dimoff Offset parameter "dimoff" for kernel "LBProjectKernel".
 * \param [in] ticks_LBProjectKernel The number of ticks for which kernel "LBProjectKernel" will run.
 * \param [in] inscalar_LBProjectKernel_dim Input scalar parameter "LBProjectKernel.dim".
 * \param [in] inscalar_LBProjectKernel_omega Input scalar parameter "LBProjectKernel.omega".
 * \param [in] instream_setup_cpu Stream "setup_cpu".
 * \param [in] instream_size_setup_cpu The size of the stream instream_setup_cpu in bytes.
 * \param [out] outstream_read_cpu Stream "read_cpu".
 * \param [in] outstream_size_read_cpu The size of the stream outstream_read_cpu in bytes.
 * \param [in] lmem_address_f_lmem Linear LMem control for "f_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_f_lmem Linear LMem control for "f_lmem" stream: array size, in bytes.
 * \param [in] lmem_address_g_lmem Linear LMem control for "g_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_g_lmem Linear LMem control for "g_lmem" stream: array size, in bytes.
 * \param [in] lmem_address_read_lmem Linear LMem control for "read_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_read_lmem Linear LMem control for "read_lmem" stream: array size, in bytes.
 * \param [in] lmem_address_setup_lmem Linear LMem control for "setup_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_setup_lmem Linear LMem control for "setup_lmem" stream: array size, in bytes.
 */
void LBProject(
	long offset_LBProjectKernel_dimoff,
	uint64_t ticks_LBProjectKernel,
	uint64_t inscalar_LBProjectKernel_dim,
	double inscalar_LBProjectKernel_omega,
	const void *instream_setup_cpu,
	size_t instream_size_setup_cpu,
	void *outstream_read_cpu,
	size_t outstream_size_read_cpu,
	size_t lmem_address_f_lmem,
	size_t lmem_arr_size_f_lmem,
	size_t lmem_address_g_lmem,
	size_t lmem_arr_size_g_lmem,
	size_t lmem_address_read_lmem,
	size_t lmem_arr_size_read_lmem,
	size_t lmem_address_setup_lmem,
	size_t lmem_arr_size_setup_lmem);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] offset_LBProjectKernel_dimoff Offset parameter "dimoff" for kernel "LBProjectKernel".
 * \param [in] ticks_LBProjectKernel The number of ticks for which kernel "LBProjectKernel" will run.
 * \param [in] inscalar_LBProjectKernel_dim Input scalar parameter "LBProjectKernel.dim".
 * \param [in] inscalar_LBProjectKernel_omega Input scalar parameter "LBProjectKernel.omega".
 * \param [in] instream_setup_cpu Stream "setup_cpu".
 * \param [in] instream_size_setup_cpu The size of the stream instream_setup_cpu in bytes.
 * \param [out] outstream_read_cpu Stream "read_cpu".
 * \param [in] outstream_size_read_cpu The size of the stream outstream_read_cpu in bytes.
 * \param [in] lmem_address_f_lmem Linear LMem control for "f_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_f_lmem Linear LMem control for "f_lmem" stream: array size, in bytes.
 * \param [in] lmem_address_g_lmem Linear LMem control for "g_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_g_lmem Linear LMem control for "g_lmem" stream: array size, in bytes.
 * \param [in] lmem_address_read_lmem Linear LMem control for "read_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_read_lmem Linear LMem control for "read_lmem" stream: array size, in bytes.
 * \param [in] lmem_address_setup_lmem Linear LMem control for "setup_lmem" stream: base address, in bytes.
 * \param [in] lmem_arr_size_setup_lmem Linear LMem control for "setup_lmem" stream: array size, in bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *LBProject_nonblock(
	long offset_LBProjectKernel_dimoff,
	uint64_t ticks_LBProjectKernel,
	uint64_t inscalar_LBProjectKernel_dim,
	double inscalar_LBProjectKernel_omega,
	const void *instream_setup_cpu,
	size_t instream_size_setup_cpu,
	void *outstream_read_cpu,
	size_t outstream_size_read_cpu,
	size_t lmem_address_f_lmem,
	size_t lmem_arr_size_f_lmem,
	size_t lmem_address_g_lmem,
	size_t lmem_arr_size_g_lmem,
	size_t lmem_address_read_lmem,
	size_t lmem_arr_size_read_lmem,
	size_t lmem_address_setup_lmem,
	size_t lmem_arr_size_setup_lmem);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	long offset_LBProjectKernel_dimoff; /**<  [in] Offset parameter "dimoff" for kernel "LBProjectKernel". */
	uint64_t ticks_LBProjectKernel; /**<  [in] The number of ticks for which kernel "LBProjectKernel" will run. */
	uint64_t inscalar_LBProjectKernel_dim; /**<  [in] Input scalar parameter "LBProjectKernel.dim". */
	double inscalar_LBProjectKernel_omega; /**<  [in] Input scalar parameter "LBProjectKernel.omega". */
	const void *instream_setup_cpu; /**<  [in] Stream "setup_cpu". */
	size_t instream_size_setup_cpu; /**<  [in] The size of the stream instream_setup_cpu in bytes. */
	void *outstream_read_cpu; /**<  [out] Stream "read_cpu". */
	size_t outstream_size_read_cpu; /**<  [in] The size of the stream outstream_read_cpu in bytes. */
	size_t lmem_address_f_lmem; /**<  [in] Linear LMem control for "f_lmem" stream: base address, in bytes. */
	size_t lmem_arr_size_f_lmem; /**<  [in] Linear LMem control for "f_lmem" stream: array size, in bytes. */
	size_t lmem_address_g_lmem; /**<  [in] Linear LMem control for "g_lmem" stream: base address, in bytes. */
	size_t lmem_arr_size_g_lmem; /**<  [in] Linear LMem control for "g_lmem" stream: array size, in bytes. */
	size_t lmem_address_read_lmem; /**<  [in] Linear LMem control for "read_lmem" stream: base address, in bytes. */
	size_t lmem_arr_size_read_lmem; /**<  [in] Linear LMem control for "read_lmem" stream: array size, in bytes. */
	size_t lmem_address_setup_lmem; /**<  [in] Linear LMem control for "setup_lmem" stream: base address, in bytes. */
	size_t lmem_arr_size_setup_lmem; /**<  [in] Linear LMem control for "setup_lmem" stream: array size, in bytes. */
} LBProject_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void LBProject_run(
	max_engine_t *engine,
	LBProject_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *LBProject_run_nonblock(
	max_engine_t *engine,
	LBProject_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void LBProject_run_group(max_group_t *group, LBProject_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *LBProject_run_group_nonblock(max_group_t *group, LBProject_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void LBProject_run_array(max_engarray_t *engarray, LBProject_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *LBProject_run_array_nonblock(max_engarray_t *engarray, LBProject_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* LBProject_convert(max_file_t *maxfile, LBProject_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* LBProject_init(void);

/* Error handling functions */
int LBProject_has_errors(void);
const char* LBProject_get_errors(void);
void LBProject_clear_errors(void);
/* Free statically allocated maxfile data */
void LBProject_free(void);
/* These are dummy functions for hardware builds. */
int LBProject_simulator_start(void);
int LBProject_simulator_stop(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_LBProject_H */

