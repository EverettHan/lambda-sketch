#ifndef _MOBILE_SOURCE
#include "TIE_CATIMessageReceiver.h"
#define OMY_TIECATIMessageReceiver( CLASS_NAME )  TIE_CATIMessageReceiver( CLASS_NAME );
#else
//Pas de TIE... merci System
#define OMY_TIECATIMessageReceiver( CLASS_NAME ) 
#endif
