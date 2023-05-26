#ifndef __CATSPECIALEXIT
#define __CATSPECIALEXIT
//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2009                                         *
//*===========================================================================*
//*                                                                           *
//*  Reserved use                                                             *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Creation novembre 2009                                                   *
//*===========================================================================*


enum
{
// Called last
  SYSTEMTS_CORE = 0      // CATUnicodeString...
, HTTP_EXIT
, LIC_EXIT
, STAT_EXIT
, STATSIDL_EXIT
, SIDL_EXIT
, SET_EXIT
// Called first
};


#endif
