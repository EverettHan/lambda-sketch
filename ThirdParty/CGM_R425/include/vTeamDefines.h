#if !defined(__vTeamDefines_h) 
#define __vTeamDefines_h

/**
@file		  vTeamDefines.h
@brief		Custom definitions
@details	This file contains several custom definitions for Visualization Team only.
			    It SHOULD never be promoted in the BSF (except if all the lines are disabled).
*/

/** 
@todo juju -> établir un protocol
*/
#if !defined(V_DOXYGEN)

// UIVCoreTools -> 

//--- Defines your own defines HERE ---//



/*
#if !defined(V_TEST_KERNEL)
#define V_TEST_KERNEL
#endif*/

//#define V_KERNEL_NOT_PROMOTION

/** Enable the assert even if CNEXT_CLIENT is defined */

/*
#if defined(V_TEST_KERNEL)
#define V_FORCE_ASSERT

#define V_CULLING_MT_DISABLE
#endif*/

//nsi_test
//#define V_NO_CONTROL_DRAW_ON_MGPU
//#define V_CULLING_MULTIPLEXING_ON_MGPU

//j6h_test
#define V_NO_VIDIMMEDIATEDRAW

//j6h_test
#define V_NO_LAYERING_SYSTEM


/** Disable the culling */
//#define V_CULLING_DISABLE
/** Disable the use of SSE in the culling */
//#define V_CULLING_SSE_DISABLE

/** Enable Visu markers even if CNEXT_CLIENT is defined --> see vDebugMarkers*/
//#define V_FORCE_VISU_MARKERS

#define V_VSCENE_MT_DISABLE

/** Disable the multithreading inside the PassSystem
 *  By default, the multi-threading is enabled.
 */


/** Disable the use of the MT culling
 *  
 */
//#define V_CULLING_MT_DISABLE


/** Disable the use of the MT culling in volatile */
//#define DISABLE_VOL_CULLING_ON_THREAD

/** Disable the MT sort */
//#define V_DISABLE_MT_SORT

/** Disable the MT logger(same thread that post message and display message) */
//#define V_DISABLE_MT_LOGGING

/** Enable this define to have a better debugging for the task infra */
//#define V_ENABLE_DEBUG_MT

/** Disable the profiling */
//#define V_DISABLE_PROFILING

/** Enable this define to use Nsight Marker with the profiler */
#define V_USE_PROFILER_WITH_NSIGHT


/** Enable the TBB graph tool*/
//#define TBB_USE_THREADING_TOOLS 1
//#define DO_ITT_NOTIFY  1

/** Uncomment this to restrict drawing to the main 3D vp */
//#define V_DRAW_ONLY_MAIN_VIEWPOINT

/** Uncomment to enable advance debug : new tags in the profiler*/
//#define V_ADVANCED_DEBUG


#endif  // !defined(V_DOXYGEN)

#endif //__vTeamDefines_h
