//
//===================================================================
// Copyright Dassault Systemes Provence 2009, all rights reserved
//===================================================================
//
// CATFrFFSFilletDevInfo.h
// Header definition of CATFrFFSFilletDevInfo
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 02/07/09 : MWE ; Creation d'apres CATClassATopoOperators\ProtectedInterfaces\CATCltFilletDevInfo.h
//===================================================================
#ifndef CATFrFFSFilletDevInfo_H
#define CATFrFFSFilletDevInfo_H

//#include "CATFrFFilletStyle.h"

#include "CATFrFFilletStyle.h"
#include "CATMathPoint.h"

#include "CATMathDirection.h" // Non utile ici mais sert en effet de bord !

class  ExportedByCATFrFFilletStyle CATFrFFSFilletDevInfo
{

public :
            CATFrFFSFilletDevInfo( );
            CATFrFFSFilletDevInfo(const CATFrFFSFilletDevInfo &);
   virtual ~CATFrFFSFilletDevInfo();

   CATBoolean operator==(const CATFrFFSFilletDevInfo& original) const;
   CATBoolean operator!=(const CATFrFFSFilletDevInfo& original) const;

   void       SetPosition(CATMathPoint &iLocation1, CATMathPoint &iLocation2, double iValue);
   CATBoolean GetPosition(CATMathPoint &oLocation1, CATMathPoint &oLocation2, double &oValue );
   // not yet implemented
 /*  double GetPositionValue();
   CATMathPoint GetPositionPoint(int index = 0);

   void SetTangent(CATMathPoint &iLoc1, CATMathPoint &iLoc2, double iValue);
   double GetTangentValue();
   CATBoolean GetTangent( CATMathPoint &oLocation1, CATMathPoint &oLocation2, double &oValue );
   CATMathPoint GetTangentPoint(int index = 0);

   void SetCurvature(CATMathPoint &iLoc1, CATMathPoint &iLoc2, double iValue);
   CATBoolean GetCurvature( CATMathPoint &oLocation1, CATMathPoint &oLocation2, double &oValue );

   void SetG3(CATMathPoint &iLoc1, CATMathPoint &iLoc2, double iValue);
   CATBoolean GetG3( CATMathPoint &oLocation1, CATMathPoint &oLocation2, double &oValue );

   CATBoolean GetUnSet(); */

protected :
   CATMathPoint _PositionLocation1;
   CATMathPoint _PositionLocation2;

   CATMathPoint _TangentLocation1;
   CATMathPoint _TangentLocation2;

   CATMathPoint _CurvatureLocation1;
   CATMathPoint _CurvatureLocation2;

   CATMathPoint _G3Location1;
   CATMathPoint _G3Location2;

   double       _PositionDeviation;
   double       _TangentDeviation;
   double       _CurvatureDeviation;
   double       _G3Deviation;

   CATBoolean   _UnSet;
};

/*
//----------------------------------------------------------------------
//   CATLISTV(CATFrFFSFilletDevInfo) declaration :
#include "CATLISTV_Clean.h"
// #define CATLISTV_ReSize
// #define CATLISTV_Append
// #define CATLISTV_RemoveValue
// #define CATLISTV_RemoveAll
#include "CATLISTV_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATFrFFSFillet

CATLISTV_DECLARE(CATFrFFSFilletDevInfo)
typedef CATLISTV(CATFrFFSFilletDevInfo) CATListOfFrFFSFilletDevInfo;
 */
#endif
