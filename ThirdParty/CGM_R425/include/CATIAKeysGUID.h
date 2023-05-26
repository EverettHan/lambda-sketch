
#ifndef CATIAKeysGUID_H
#define CATIAKeysGUID_H

#include "CATIAV5Level.h"

#if !defined(CATIAR418)
// R417 & prior releases
#define DS_RELEASE_VERSION      "1"
#define CATIA_APP_GUID          "{87fd6f40-e252-11d5-8040-0010b5fa1031}"
#elif !defined(CATIAR419)
// R418
#define DS_RELEASE_VERSION      "1"
#define CATIA_APP_GUID          "{87fd6f40-e252-11d5-8040-0010b5fa1031}"
#else
//#error New GUIDs must be generated for this release!
#define DS_RELEASE_VERSION      "1"
#define CATIA_APP_GUID          "{87fd6f40-e252-11d5-8040-0010b5fa1031}"
#endif

#endif  // CATIAKeysGUID_H
