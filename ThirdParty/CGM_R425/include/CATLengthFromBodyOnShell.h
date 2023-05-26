/* -*-c++-*- */
#ifndef CATLengthFromBodyOnShell_h
#define CATLengthFromBodyOnShell_h

// COPYRIGHT DASSAULT SYSTEMES 1999

//-------------------------------------------------------------------------
// Usage :  Determine the Point and the direction of a geodesic 
//          that begins at point reference  and tha ends to a target point
//-------------------------------------------------------------------------
// Comment :  this class is used for pre visu. So the result is approximative.
//-------------------------------------------------------------------------
//
//
// Example :
//----------
//  
//-------------------------------------------------------------------------
// 19/01/22 NLD Declaration retard du CreateLengthFromBodyOnShell() avec CATTopData
//-------------------------------------------------------------------------
#include "YJ000GSM.h"
#include "CATSkillValue.h"
#include "CATMathDef.h"
#include "CATMathPoint.h"
#include "CATTopDef.h"
#include "CATCrvParam.h"
#include "CATTopOperator.h"

class CATVertex;
class CATEdge;
class CATShell;
class CATBody;
class CATGeoFactory;
class CATSurface;

class ExportedByYJ000GSM CATLengthFromBodyOnShell : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATLengthFromBodyOnShell);
public:


  CATLengthFromBodyOnShell();
  CATLengthFromBodyOnShell(CATGeoFactory* iFactory, CATTopData * iData);
  CATLengthFromBodyOnShell(CATGeoFactory* iFactory, CATCGMJournalList * iData);


  // If Run() was already used, all previous results will be lost
  virtual int       Run()=0;

  virtual CATLONG32 GetProjIni(CATMathPoint       & PointIni)=0;

  virtual CATLONG32 GetCoords( CATMathVector      & vect,/* direction of the geodesic*/
                               CATPositiveLength  & Lgth /* length geodesic */)=0;
  
  virtual CATBody * GetResult()=0;/* resulting Point */

  // To use these, CATSkillValue must be declared as ADVANCED when the operator is created.

  virtual ~CATLengthFromBodyOnShell();

  
};

//
// creates the operator
//
ExportedByYJ000GSM
CATLengthFromBodyOnShell * CreateLengthFromBodyOnShell( CATGeoFactory    *   iFactory    ,
                                                        CATTopData       *   iTopData    ,
                                                        CATBody          *   VertexIni   ,
                                                        CATBody          *   VertexTarget,
                                                        CATBody          *   SupportShell);

ExportedByYJ000GSM
CATLengthFromBodyOnShell * CreateLengthFromBodyOnShell( CATGeoFactory    *   iFactory    ,
                                                        CATBody          *   VertexIni   ,
                                                        CATBody          *   VertexTarget,
                                                        CATBody          *   SupportShell,
                                                        CATSkillValue        modev       = BASIC);



#endif

