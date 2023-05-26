//===================================================================
// COPYRIGHT Dassault Systemes 2017/03/23
//===================================================================
// CATComputeCivilTransitions.h
// Header definition of class CATCivilTransitionInfo
//===================================================================
//
// Usage notes: Civil transition curve information
//
//===================================================================
// Historic:
// 23/03/17 F1Z : Creation
// 30/07/18 KJD : In the frame of the extension of the CivilTransition 
//                operators to new input, the class becomes protected 
//                to store the specificated data.
//                => New architecture of the class : 
//                new APIs for the exchanges with users (new ctor, new get...) 
//                + split between a protected part (CATCivilTransitionInfo)
//                 and a local part (CATCivilTransitionData).
//                Previously, CATCivilTransitionInfo was a pure virtual local class
//                without any attributes whose specializations were  
//                CATCivilLineCircleLineTransitionInfo and CATCivilLineLineTransitionInfo.
//                Now CATCivilTransitionInfo is a protected class with as attributes
//                the type of the transition and a new structure enabling to store
//                different types of data CATCivilTransitionData 
//                (local class very similar to the previous CATCivilTransitionInfo).
//                The classes CATCivilLineCircleLineTransitionInfo and CATCivilLineLineTransitionInfo
//                were also migrated in the new local class  CATCivilTransitionData.
// 23/12/21 Q48 : File tidy and add Clone to ease creation
// 07/21/22 Q48 : Tidy architecture + streaming
//===================================================================

#ifndef CATCivilTransitionInfo_H
#define CATCivilTransitionInfo_H

// Base class
#include "CATPGMCivilTransitionInfo.h"

// ExportedBy
#include "GeoAdvCurves.h"

// C++11
#include "CATGeoOpVirtual.h"

// System
#include "CATBoolean.h"

// Mathematics
#include "CATMathConstant.h"

// Advanced Mathematics
#include "CATMathIdentifierMacros.h"

// GMModelInterfaces
#include "CATCivilCurveDef.h"
class CATCivilCurveParam;

// Geometric Operators
class CATCivilTransitionData;
class CATCivilHorizParam;

// CGMReplay
class CATCGMOutput;
class CATCGMStream;
class CATGeoODTScaleManager;

// ============================================================================================================================= //
//                                                    CATCivilTransitionInfo                                                     //
// ============================================================================================================================= //
class ExportedByGeoAdvCurves CATCivilTransitionInfo  : public CATPGMCivilTransitionInfo
{
   //-----------------------------------------------------------------------------
   // Object Management
   //-----------------------------------------------------------------------------

private:

   CATCivilTransitionInfo();

public:

   // For Line-Circle-Line
   CATCivilTransitionInfo(const CATCivilTransitionType   iTransitionType, 
                          const CATCivilHorizParam     & iL1, 
                          const CATCivilHorizParam     & iL2,
                          const CATCivilHorizParam     & iR);

   // For Line-Line
   CATCivilTransitionInfo(const CATCivilTransitionType     iTransitionType, 
                          const CATCivilTransitionInfoType iTransitionTypeInfo,
                          const double                     iVal);

   CATCivilTransitionInfo(const CATCivilTransitionInfo & iCivilTransitionInfo);
  
protected:

   // For CGM replay
   CATCivilTransitionInfo(const CATCivilTransitionType   iTransitionType,
                                CATCivilTransitionData * iTransitionData);

public:

   virtual ~CATCivilTransitionInfo();

   //-----------------------------------------------------------------------------
   // Clone
   //-----------------------------------------------------------------------------

   static CATCivilTransitionInfo* Clone(const CATPGMCivilTransitionInfo & iCivilTransitionInfo);

   //-----------------------------------------------------------------------------
   // Get
   //-----------------------------------------------------------------------------

public:

   virtual CATCivilTransitionType GetTransitionType() const CATGEOOverride CATGEOFinal;

   virtual const CATCivilTransitionData* GetTransitionData() const CATGEOFinal;

protected:

   //-----------------------------------------------------------------------
   //- Stream
   //-----------------------------------------------------------------------   

public:

   //@nocgmitf
   virtual void Stream(CATCGMStream & ioStream) const CATGEOFinal;

   //@nocgmitf
   static CATCivilTransitionInfo* UnStream(      CATCGMStream          & ioStream,
                                                 CATGeoODTScaleManager * iScaleManager,
                                           const int                     iVersionOfStream);

   //@nocgmitf
   virtual void Dump(CATCGMOutput & os) const CATGEOFinal;

private:

   //-----------------------------------------------------------------------------
   // Attributs (private)
   //-----------------------------------------------------------------------------

   const CATCivilTransitionType    _Type;
  
   CATCivilTransitionData       *  _pData;
};

// --------------------------------------------------------------------------------------
// Line - Line
// --------------------------------------------------------------------------------------
ExportedByGeoAdvCurves CATCivilTransitionInfo * CATCreateCATCivilTransitionInfo(const CATCivilTransitionType     iTransitionType, 
                                                                                const CATCivilTransitionInfoType iTransitionTypeInfo,
                                                                                const double                     iVal);

// --------------------------------------------------------------------------------------
// TSCST (deprecated - please use CATCivilCurveParam signature)
// --------------------------------------------------------------------------------------
ExportedByGeoAdvCurves CATCivilTransitionInfo * CATCreateCATCivilTransitionInfo(const CATCivilTransitionType iTransitionType, 
                                                                            const double iL1,
                                                                            const double iL2,
                                                                            const double iR );

// --------------------------------------------------------------------------------------
// TSCST
// --------------------------------------------------------------------------------------
ExportedByGeoAdvCurves CATCivilTransitionInfo * CATCreateCATCivilTransitionInfo(const CATCivilTransitionType   iTransitionType, 
                                                                                const CATCivilCurveParam     & iL1,
                                                                                const CATCivilCurveParam     & iL2,
                                                                                const CATCivilCurveParam     & iR);


/**
* @nodoc
* @nocgmitf
*/
ExportedByGeoAdvCurves void Remove (CATCivilTransitionInfo * & ioCivilTransitionInfo);

#endif
