// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFShapeResult:
// Abstract class of the result of the Generating Shape Object
//
//==========================================================================
//
// Usage notes:
// This class can be used as it or derived in order to implement 
// specific management of results. 
//
//==========================================================================
// June 98     Creation                       Christophe Pradal (cpl)
//==========================================================================
// Dec  18  JSX Add virtual functions to uses marching from another FW
//
#ifndef CATFrFShapeResult_H
#define CATFrFShapeResult_H

#include "FrFObjects.h"
#include "CATCGMVirtual.h"

//--------------------------------------------------------------------------
class ExportedByFrFObjects CATFrFShapeResult   : public CATCGMVirtual
{
    public :

    virtual ~CATFrFShapeResult()
      {}
    
    // GetType() == 1 : CATFrFNurbsMultiForm
    virtual CATLONG32 GetType() const = 0;
    // 
    virtual void Add(CATFrFShapeResult* iShape) = 0;

    virtual CATFrFNurbsMultiForm*  GetNurbsMultiForm(CATLONG32) const = 0;
    virtual CATFrFNurbsMultiForm** GetNurbsMultiForm()           const = 0;
    virtual void DeletePointedObject(CATGeoFactory *_factory) = 0;

    // Obtention d'un résultat unitaire (par le numéro de multi-forme)
    virtual CATMathSetOfPointsND*  GetParam(CATLONG32)             const = 0;
    virtual CATMathSetOfPointsND*  GetShapeParam(CATLONG32)        const = 0;
    virtual CATMathSetOfPointsND*  GetTang(CATLONG32)              const = 0;
    virtual CATMathSetOfPointsND*  GetSecondDeriv(CATLONG32)       const = 0;
    virtual CATListOfInt           GetDiscontinuity(CATLONG32)     const = 0;
    virtual CATListOfInt           GetDiscontinuityType(CATLONG32) const = 0;

};

#endif
