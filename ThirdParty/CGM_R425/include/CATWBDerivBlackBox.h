// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATWBDerivBlackBox.h
// Header definition of the derivative of a CATWBDerivBlackBox
//
//===================================================================
//   /01/14 KJD  Creation
// 29/07/19 Q48  Add IsADerivative method (remove _IsADerivative flag)
// 25/01/23 Q48  Removed
//===================================================================

#ifndef CATWBDerivBlackBox_h
#define CATWBDerivBlackBox_h

// Base class
#include "CATWBBlackBox.h"

// ExportedBy
#include "WhiteBoxData.h"

// C++ 11
#include "CATCDSVirtual.h"

class CATWBVariable;
class CATWBValue;
class CATWBBlackBoxOperator;

////-----------------------------------------------------------------------
//class ExportedByWhiteBoxData CATWBDerivBlackBox : public CATWBBlackBox
//{
//public:
//
//  CATWBDerivBlackBox(const CATWBBlackBox * iBBx,
//                     const CATWBVariable * iDerivVar);
//
//  //CATWBDerivBlackBox(const CATWBBlackBoxOperator * ipBBxOp,
//  //                         CATWBVariable         * ipVar);
//
//  virtual ~CATWBDerivBlackBox();
//
//  virtual CATCDSBoolean IsADerivative() const CATCDSFinal;
//
//protected:
//
//  virtual double Eval(const CATWBBlackBoxOperator * iBBxOp) const CATCDSOverride;
//
//  virtual void Eval(const CATWBBlackBoxOperator * iBBxOp,
//                          CATWBValue            & oValue) const CATCDSOverride;
//
//public:
//
//  CATCDSBoolean IsAPrimitive(const CATWBBlackBoxOperator * ipBBxOp) const;
//  //CATWBBlackBox* GetAPrimitive();
//  
//  CATCDSBoolean IsTheDiffVariable(CATWBVariable * ipVar) const;
//
//protected:
//
//  //const CATWBBlackBoxOperator* _pBBxToDiff;
//  //const CATWBBlackBox * _pBBxToDiff;
//  //CATWBVariable * _pVar;
//  const double          _BBxStep;
//};

#endif
