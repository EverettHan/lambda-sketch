#ifndef __CATOmcEnv_H
#define __CATOmcEnv_H

#include "CATOmxPortability.h"

#if !defined(_MOBILE_SOURCE) 
#define OMC_SUPPORT_V4 1
#else
#define OMC_SUPPORT_V4 0
#endif

#if defined(_WINDOWS_SOURCE) && !defined(CATIAR213)
#define OMC_SUPPORT_ISTO_MODE 1
#else
#define OMC_SUPPORT_ISTO_MODE 0
#endif

#ifdef CATIAR213
#include "CATOmcBase.h"
#else
#ifndef ExportedByCATOmcBase
#include "AC0CATPL.h"
#define ExportedByCATOmcBase ExportedByAC0CATPL
#endif
#endif


struct CATOmcEnv
{
  CATOmcEnv();

  unsigned int NO_DOC_6:1;
  unsigned int ALLOW_NULL_CONTAINER_TYPE:1;
  unsigned int USE_LOAD_FILE_PATH_FOR_SAVE_AS:1;
  unsigned int OMC_INTERNAL_TEST:1;
};

ExportedByCATOmcBase const CATOmcEnv& omc_env();
ExportedByCATOmcBase CATOmcEnv& omc_env_modify();

#endif

