/* -*-C++-*- */

#ifndef CATlsoTransformFaceAlgoElt_H
#define CATlsoTransformFaceAlgoElt_H

#include "AdvTrimOpe.h"
#include "CATlsoAlgoElt.h"

class CATlsoChainMaster;
class CATlsoTransformFaceContext;
class CATlsoPersistentContext;

class ExportedByAdvTrimOpe CATlsoTransformFaceAlgoElt : public CATlsoAlgoElt
{

public:

  enum AdmissionCode 
  {
    TransformFaceAlgoElt_Classical = 0,
    TransformFaceAlgoElt_SpecificFlexible = 1    
    // TransformFaceAlgoElt_Specific...   = 2,
    // TransformFaceAlgoElt_Specific...   = 3,
  };

  // Constructeur
  CATlsoTransformFaceAlgoElt(CATlsoTransformFaceContext * iContext,
                             CATlsoChainMaster          * iAdmin,
                             CATlsoTransformFaceAlgoElt::AdmissionCode iCode=TransformFaceAlgoElt_Classical);

    // Constructeur
  CATlsoTransformFaceAlgoElt(CATlsoPersistentContext * iContext,
                             CATlsoChainMaster  * iAdmin,
                             CATlsoTransformFaceAlgoElt::AdmissionCode iCode=TransformFaceAlgoElt_Classical);
 
  //-------------------------------------------------------------------------------------------------------
  // Surcharge du new/delete
  //-------------------------------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;
  
  // Destructeur
  virtual ~CATlsoTransformFaceAlgoElt();


  CATlsoTransformFaceContext & GetTFContext() const;

  // --------
  // Dump
  // --------
  virtual void DumpObj(CATCGMOutput& s, short iLongDump=0,
                       short iZtrNoDump=0) const = 0;


  // Balayage de tous les objets de la classe
  // @param iKey -> 
  //   value -1 : All
  //   value 0  : Classical 
  //   value 1  : Classical + TransformFaceAlgoElt_SpecificFlexible = 1
  //   value 2  : Classical + TransformFaceAlgoElt_... = 2
  static CATlsoTransformFaceAlgoElt * Next(CATlsoChainMaster * iAdmin, CATlsoTransformFaceAlgoElt * iCurElt, short iKey=0);

  INLINE void SetAdmissionCode(CATlsoTransformFaceAlgoElt::AdmissionCode iCode);
  INLINE CATlsoTransformFaceAlgoElt::AdmissionCode GetAdmissionCode() const;

protected: 
  

  // ---------------
  // Internal Data
  // ---------------
  CATlsoTransformFaceContext * _TFContext;
  CATlsoTransformFaceAlgoElt::AdmissionCode _AdmissionCode;
};


INLINE CATlsoTransformFaceAlgoElt::AdmissionCode CATlsoTransformFaceAlgoElt::GetAdmissionCode() const {
  return _AdmissionCode; }

INLINE void CATlsoTransformFaceAlgoElt::SetAdmissionCode(CATlsoTransformFaceAlgoElt::AdmissionCode iCode) {
  _AdmissionCode = iCode; }

#endif

