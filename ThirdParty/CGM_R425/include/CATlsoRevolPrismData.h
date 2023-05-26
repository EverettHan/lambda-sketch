// --------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.                                                             |
//===================================================================                                                 |
//                                                                                                                    |
// Header definition of CATlsoRevolPrismData                                                                          |
// Oct 2013                                                                                                           |
//                                                                                                                    |
// Resp : QF2                                                                                                         |
//===================================================================                                                 |
//                                                                                                                    |
// Decription : Objet de Transport pour les parametres du mode RevolPrim dans le TransformFace et Variational Ope.    |
// --------------------------------------------------------------------------------------------------------------------
//
// - Version 1 : oct 2013
//    RevolPrismMode + RevolAngle
// - Version 2 : Dec 2013
//    Add KeepDanglingFaces (CATBoolean)
//
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// CURRENT VERSION : 2
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#ifndef CATlsoRevolPrismData_H
#define CATlsoRevolPrismData_H

// #Include 
#include "CATCGMVirtual.h"
#include "CATGMLiveShapeRevolPrismMode.h"
#include "CATMathConstant.h"
#include "CATMathInline.h"
#include "AdvTrimOpe.h"
#include "CATMathDirection.h"
#include "CATMathPlane.h"

class CATCGMStream;
class CATCGMOutput;
class CATTolerance;
class CATMathAxis;
class CATGeoFactory;

class ExportedByAdvTrimOpe CATlsoRevolPrismData : public CATCGMVirtual
{
public:
  
  // default constructor
  CATlsoRevolPrismData();
  // constructor
  CATlsoRevolPrismData(CATGMLiveShapeRevolPrismMode iRevolPrismMode, CATBoolean iVolumicRequired=FALSE, CATBoolean iKeepDanglingFaces=FALSE);
  // copy constructor
  CATlsoRevolPrismData(const CATlsoRevolPrismData &iRevolPrismData);

  // destructor
  virtual ~CATlsoRevolPrismData();

  // Getter - Setter
  // ---------------
  INLINE CATGMLiveShapeRevolPrismMode GetRevolPrismMode() const;
  CATAngle                            GetRevolParam(const CATMathAxis *&oRevolAxis) const;
  CATBoolean                          GetBothSideParam(CATMathPlane & oBSidePlane)  const;
  INLINE CATAngle                     GetRevolAngle()         const;
  INLINE CATBoolean                   GetKeepDanglingFaces()  const;
  INLINE CATAngle                     GetExtrudeDraftAngle()  const;
  INLINE CATMathDirection           * GetExtrudeDraftDir()    const;
  INLINE CATBoolean                   GetVolumicResult  ()    const;
  INLINE CATBoolean                   GetTranslatedNeutralMode() const;  
  INLINE CATBoolean                   GetKeepInitialFaces()      const;

  INLINE void SetRevolPrismMode(CATGMLiveShapeRevolPrismMode iMode);
  INLINE void SetRequireVolumicResult(CATBoolean iVolumicResult=TRUE);

  void SetRevolParam        (CATAngle iValue, const CATMathAxis &iAxis);  
  void SetExtrudeDraftParam (const CATAngle &iDraftAngle, CATBoolean iVolumicResult=FALSE, CATBoolean iTranslatedNeutral=FALSE, const CATMathDirection * iPullDir=NULL);
  void SetExtrudeDraftDir   (const CATMathDirection &iDraftDir);
  void SetBothSideParam     (CATBoolean iRequireBothSide, const CATMathPlane &iMirrorPlane);

  INLINE void SetKeepDanglingFaces (CATBoolean iValue=TRUE);
  INLINE void SetExtrudeDraftAngle (const CATAngle &iDraftAngle);
  INLINE void SetKeepInitialFaces(CATBoolean iValue=TRUE);

  // deprecated
  INLINE void SetRevolAngle (CATAngle iValue);

  // ON but not SheetMetal
  CATBoolean IsRevolPrismModeON() const;
  void SetRevolPrismOFF();
  // CATBoolean IsEqualTo (const CATlsoRevolPrismData &iValue, double &iToleranceAngle) const;

  // Mirror 
  // ----------------------------------------------
  HRESULT Replicate(CATGeoFactory *iFactory, const CATMathPlane &iMirrorPlane, CATlsoRevolPrismData & oReplicatedValue) const;

  // Dump  
  void Dump(CATCGMOutput& os) const;

  // -------------------
  // Steam - Unsteam 
  // -------------------
  void Write(CATCGMStream& ioStr) const;
  void Read (CATCGMStream& ioStr);

  //  ***  Operators  ***
  // --------------------
  CATlsoRevolPrismData& operator=(const CATlsoRevolPrismData &iValue);

private : 
  void InitMembers();

  // Dump
  static const char * GetRevolPrismModeName(const CATGMLiveShapeRevolPrismMode &iRevolPrismMode);
  
//---------------------------------------
// Internal Data
// --------------------------------------
  // Version 1
  CATGMLiveShapeRevolPrismMode _RevolPrismMode;
  CATAngle                     _RevolAngle;
  CATMathAxis                * _RevolAxis;  
  
  // Extrude Draft options
  CATAngle                     _ExtrudeDraftAngle; // Version 3 : ExtrudeDraftAngle = Angle du mode ExtrudeDraft
  CATMathDirection           * _ExtrudeDraftDir;
  CATBoolean                   _TranslatedIsNeutral; // version 6 (w21-18).
  
  // Mode surfacique
  CATBoolean                   _KeepDanglingFaces; // Version.2 : DanglingFaces = Faces pendantes avec Prism Surfacique  

  // Mode volumique (v4)
  CATBoolean                   _VolumicResult;

  // BothSide Param (v5)
  CATBoolean                   _BothSide;
  CATMathPlane                 _BothSidePlane;

  // Surfacic only - KeepMovingFace (v6)
  CATBoolean                   _KeepInitialFaces; // =0 (default)
};


/*------------------------------------------------------------------------------------------*/
/* INLINE Methods Impl
/*------------------------------------------------------------------------------------------*/
INLINE CATGMLiveShapeRevolPrismMode CATlsoRevolPrismData::GetRevolPrismMode() const {
  return _RevolPrismMode; }

INLINE CATAngle CATlsoRevolPrismData::GetRevolAngle() const {
  return _RevolAngle; }

INLINE CATBoolean CATlsoRevolPrismData::GetKeepDanglingFaces() const {
  return _KeepDanglingFaces; }

INLINE CATAngle CATlsoRevolPrismData::GetExtrudeDraftAngle() const {
  return _ExtrudeDraftAngle; }

INLINE CATMathDirection * CATlsoRevolPrismData::GetExtrudeDraftDir() const {
  return _ExtrudeDraftDir; }

INLINE CATBoolean CATlsoRevolPrismData::GetVolumicResult() const {
  return _VolumicResult ; }

INLINE void CATlsoRevolPrismData::SetRevolPrismMode(CATGMLiveShapeRevolPrismMode iMode) {
  _RevolPrismMode = iMode; 
  if(_RevolPrismMode==CATGMLiveShapeRevolPrism_OFF) _RevolAngle=0.; }

INLINE void CATlsoRevolPrismData::SetRevolAngle (CATAngle iValue) {
  _RevolAngle = iValue; }
  
INLINE void CATlsoRevolPrismData::SetKeepDanglingFaces (CATBoolean iValue) {
  _KeepDanglingFaces = iValue; }

INLINE void CATlsoRevolPrismData::SetRequireVolumicResult(CATBoolean iVolumicResult) {
  _VolumicResult = iVolumicResult; }

INLINE void CATlsoRevolPrismData::SetExtrudeDraftAngle (const CATAngle &iDraftAngle) {
  _ExtrudeDraftAngle = iDraftAngle; }

INLINE CATBoolean CATlsoRevolPrismData::GetTranslatedNeutralMode() const {
  return _TranslatedIsNeutral; }

INLINE CATBoolean CATlsoRevolPrismData::GetKeepInitialFaces()      const {
  return _KeepInitialFaces; }

INLINE void CATlsoRevolPrismData::SetKeepInitialFaces(CATBoolean iValue) {
  _KeepInitialFaces = iValue; }

#endif

