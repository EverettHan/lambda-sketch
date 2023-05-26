// Not a real header. Just some macros.

// [Public] General options
DeclareCATSGStaticOption(LDH_BV_QUERY, 1.f) /* <- '1' to use CATISGAsyncRequestServices (default or custom) to acquire the BoundingBox information. */
DeclareCATSGStaticOption(LDHBlueBoxOpacity, 0.f) /* <- Anything strictly over 0.0 will display BoundingBoxes for unloaded CGRs. Values between '0.' and '1.'. */
DeclareCATSGStaticOption(LDHBlueBoxAsRep, 0.f) /* <- '1' to have each BoundingBox as CATRep | '0' to have a single global CATRep with shader. */
DeclareCATSGStaticOption(LDHBlueBoxColorRed, 0.f) /* <- Values between '0.' and '1.'. */
DeclareCATSGStaticOption(LDHBlueBoxColorGreen, 0.1f) /* <- Values between '0.' and '1.'. */
DeclareCATSGStaticOption(LDHBlueBoxColorBlue, 0.6f) /* <- Values between '0.' and '1.'. */
DeclareCATSGStaticOption(LDH_CGRMT, 0.f) /* <- '1' to activate multithread for CATReadCgr with LDH. */
DeclareCATSGStaticOption(LDH_ASYNC_OPEN, 1.f) /* <- '1' to activate multithreaded open of CATILockBytes2. */
DeclareCATSGStaticOption(LDH_ONE_VIEWER, 0.f) /* <- '1' to force LDH to work only in the current active viewer. */
DeclareCATSGStaticOption(LDH_UNLOAD_CGR, 1.f) /* <- '1' to Unload/Reload at CGR BagRep level instead of at LeafRep level. */

// [Public] Tuning options
DeclareCATSGStaticOption(LDH_TARGET_FPS, 15.f) /* <- 5 fps is 200ms per frame -- 15 fps is 67ms -- 30 fps is 33ms -- 60 fps is 17ms. */
DeclareCATSGStaticOption(LDH_MIN_MEM_UNLOAD, 0.f) /* <- Do not Unload unless system memory is ABOVE this threshold. Values between '0' and '100'. */
DeclareCATSGStaticOption(LDH_MAX_MEM_LOAD, 95.f) /* <- Do not Load unless system memory is BELOW this threshold. Values between '0' and '100'. */
// [Private] Tuning options
DeclareCATSGStaticOption(LDH_BV_QUERY_MAXSIZE, 100000.f) /* <- Wait for this number of unknown BBox before sending the BBox query. */
DeclareCATSGStaticOption(LDH_DL_QUERY_MINSIZE, 20.f) /* <- Wait for this number of CGR urls before sending the Download query. */
DeclareCATSGStaticOption(LDH_DL_QUERY_MAXSIZE, 20.f) /* <- Wait for this number of CGR urls before sending the Download query. */
DeclareCATSGStaticOption(LDH_LOADJOB_MAXSIZE, 20.f) /* <- Init size of the Load (ReadCgr) job queue. */
DeclareCATSGStaticOption(LDH_UNLOADJOB_MAXSIZE, 1000.f) /* <- Init size of the Unload (destroy rep) job queue. */
DeclareCATSGStaticOption(LDH_IOJOB_MAXSIZE, 1000.f) /* <- Init size of the IO (open ILB2) job queue. */
DeclareCATSGStaticOption(LDH_NB_IOTHREADS, 8.f) /* <- Number of threads to be used for Open/Read/Write operations. */
DeclareCATSGStaticOption(LDH_FACTOR_NBJOBS, 0.20f) /* <- (see CATSGMsgLoopJobs.cpp): +|- 20% on nbJobs. */
DeclareCATSGStaticOption(LDH_FRAMETIME_DEV, 0.05f) /* <- (see CATSGMsgLoopJobs.cpp): +|- 5% deviation on frameTime. */
DeclareCATSGStaticOption(LDH_ANIM_DRAW, 1.f) /* <- '1' trigger new frames through callback | '0' trigger new frames through CATVisuAnimation. */
DeclareCATSGStaticOption(LDH_ANIM_WORK, 8.f) /* <- non-zero means do LDH Load/Unload on callback | '0' means do LDH Load/Unload in DoDrawJob. */
DeclareCATSGStaticOption(LDH_IDLE_MODE, 1.f) /* <- '1': deferred draw infrastructure is used | '0': callback is managed by LDH through OnIdle. */
DeclareCATSGStaticOption(LDH_TBB_ParallelLoad, 0.f) /* <- '1' to use tbb::parallel_for to process visibility array. */

// [Public] Debug options
DeclareCATSGStaticOption(LDH_LOADINDICATOR, 0.f) /* <- '1' to display scene stats as a little text rep. */
DeclareCATSGStaticOption(LDH_MIPMIP, 0.f) /* <- '1' to use MipMip tool to measure performance during LDH scenario. */
// [Private] Debug options
DeclareCATSGStaticOption(LDH_MEASURES, 0.f) /* <- '1' to dump perf measures at the end of LDH context. */
DeclareCATSGStaticOption(LDH_ALL_VISIBLE, 0.f) /* <- '1' to force all reps to be considered visible at all times (usefull to generate full Dump.CGRDict). */
DeclareCATSGStaticOption(LDH_ENDAFTER, -1.f) /* <- Forcibly exit when a number of CGRs have been loaded through LDH (only usefull for ODTs). */
DeclareCATSGStaticOption(LDH_NO_HEADERBOX, 0.f) /* <- '1' to avoid reading CGR headers when BBox info is unknown. */
DeclareCATSGStaticOption(LDH_DUMP_TEXT_DICT, 0.f) /* <- '1' to write Dump.CGRDict as a plaintext file instead of binary. */
DeclareCATSGStaticOption(LDH_DUMP_JOB_SIZES, 0.f) /* <- '1' to track and dump the size of JobQueues at each frame. */
//DeclareCATSGStaticOption(LDH_ENABLE_PROFILING, 0.f) /* <- '1' to activate V_PROFILE macros during LDH scenario. */

// [Private] Deprecated/unused/untested options
DeclareCATSGStaticOption(LDH_PROGRESSIVE_DOWNLOAD, 1.f)
DeclareCATSGStaticOption(LDH_LATE_DL, 0.f)
