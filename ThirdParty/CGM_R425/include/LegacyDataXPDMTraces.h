/* -*-c++-*- */
/**
* @quickReview LBV CCY1 22:03:17  creation
* @fullreview LBV CCY1 22:03:17
*/
//
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// Traces for XPDMXML
//
//=============================================================================
// Creation : LBV: 2022:03:17
//
//=============================================================================

#ifndef LegacyDataXPDMTraces_H
#define LegacyDataXPDMTraces_H

#include "ExportedByXPDMServices.h"
#include "CATTrace.h"
#include "CATUnicodeString.h"
#include "CATStackTrace.h"
//#include "iostream.h"
#include "CATStdIO.h"
/*

#include "CATUuid.h"
#include "CATBinary.h"
#include "CATPLMID.h"
*/
extern ExportedByXPDMServices CATTrace TraceXPDM;
class ExportedByXPDMServices IndentTraces
{
public:
  static int __Level;
  static int __Depth;
  static int __Increment;

  static CATUnicodeString GetRCString (HRESULT result);
};

// ============================================
//
//               TRACE XPDM ENGINE
//
// ============================================
ExportedByXPDMServices void LegacyDataXPDM_IN(int Level,const char* Msg);
ExportedByXPDMServices void LegacyDataXPDM_OUT(int Level,const char* Msg);
ExportedByXPDMServices void LegacyDataXPDM_OUT_HRESULT(int Level,const char* Msg,HRESULT result);
ExportedByXPDMServices void LegacyDataXPDM_ERROR(const char* Msg);
ExportedByXPDMServices void LegacyDataXPDM_CURRENT(int Level,const char* Msg);
ExportedByXPDMServices void LegacyDataXPDM_CALLSTACK(int Level,const char* Msg);
ExportedByXPDMServices void LegacyDataXPDM_NUM_VALUE(int Level,const char* Msg,int Valeur );
ExportedByXPDMServices void LegacyDataXPDM_TXT_VALUE(int Level,const char* Msg,const CATUnicodeString& Valeur);

/*
ExportedByXPDMServices void LegacyDataXPDM_DumpPLMID(CATPLMID &iPLMID);
ExportedByXPDMServices void LegacyDataXPDM_VALEUR_UUID(const char* Msg, const CATUuid&  Valeur );
ExportedByXPDMServices void LegacyDataXPDM_VALEUR_Binary(const char* Msg, const CATBinary&  Valeur );
*/

#endif // LegacyDataXPDMTraces_H

