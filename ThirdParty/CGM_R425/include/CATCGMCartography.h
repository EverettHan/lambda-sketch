#ifndef CATCGMCartography_h
#define CATCGMCartography_h
/* -*-C++-*-*/
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//=================================================================
//   NOT DELIVER
//==========================================================================
/*

    CATCGMCartographyBegin(marqueur,factory) 
    {
       // Lecture de container geometrique par Append  
    }
    CATCGMCartographyEnd(marqueur);
    
*/
//
//==========================================================================
#include "CATBaseUnknown.h"
#include "CATErrorMacros.h"
#include "CATCGMNewArray.h"
#include "CATCGMTransaction.h"
#include "CATMathInline.h"
#include "CGMObject.h"
#include "CATMathInline.h" 
#include "CATBoolean.h" 
#include "CGMV5Interop.h"

class CATGeoFactory;
class CATCGMMapCATULONGPTR;
class CATCGMStream;
class CATCGMReportByType;

//------------------------------------------------------------------
// Identification of a transaction
//------------------------------------------------------------------
class ExportedByCGMV5Interop CATCGMCartography : public CATCGMTransaction
{
public :
  //------------------------------------------------------------------
  // LifeCycle
  //------------------------------------------------------------------
  static CATCGMCartography * Create(CATCGMReportByType *iReport);
  CATCGMNewClassArrayDeclare;   

  //------------------------------------------------------------------
  // INTERNAL : Used to make sure that end of Transaction is done
  // in case of exception throw with longjmp ..
  //------------------------------------------------------------------
  virtual void Clean();
 

  INLINE CATCGMReportByType * GetReport();

  INLINE void       SetSilentTrace();

  INLINE CATBoolean IsSilentTrace();


protected:
  //------------------------------------------------------------------
  // CLIENT : life of one CATCGMCartography Object identify a transaction
  //------------------------------------------------------------------
  CATCGMCartography(CATCGMReportByType *iReport);

  CATCGMReportByType *_Report;
  CATBoolean         _SilentTrace;
 };



/**
* GetReport 
*/
INLINE  CATCGMReportByType * CATCGMCartography::GetReport()
{
  return  _Report;
}

/**
* SetSilentTrace 
*/
INLINE void CATCGMCartography::SetSilentTrace()
{
  _SilentTrace = TRUE;
}

/**
* SetSilentTrace 
*/
INLINE CATBoolean CATCGMCartography::IsSilentTrace()
{
  return _SilentTrace;
}





#define CATCGMCartographyBegin(marqueur,iReport)  \
  CATCGMCartography *volatile marqueur = CATCGMCartography::Create(iReport); \
CATTry  \
{  

#define CATCGMCartographyEnd(marqueur)  \
  if ( marqueur ) { marqueur->Clean(); delete marqueur; marqueur=NULL; } \
} \
CATCatch(CATError, error) \
{  \
  if ( marqueur ) { marqueur->Clean(); delete marqueur; marqueur=NULL; } \
  CATRethrow; \
}  \
CATEndTry 
 

#endif

