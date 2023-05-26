#ifndef CATNurbsCrvSpecs_H
#define CATNurbsCrvSpecs_H

// COPYRIGHT DASSAULT SYSTEMES  2000
//
// Classe des specifications de la convertion d'un courbe en une Nurbs
//
#include "CATBoolean.h"
#include "CATParameterizationOption.h"
#include "FrFObjects.h"
#include "CATBaseUnknown.h"
#include "CATCGMVirtual.h"

class ExportedByFrFObjects CATNurbsCrvSpecs  : public CATCGMVirtual
{
  public :
    CATNurbsCrvSpecs();
    CATNurbsCrvSpecs(CATNurbsCrvSpecs *iNurbsCrvSpecs);
    ~CATNurbsCrvSpecs();
//
// Set and Get Methodes
//
    void SetRationalAbility(CATBoolean iRationalAbility=TRUE);
    CATBoolean GetRationalAbility();

    void SetPeriodicityAbility(CATBoolean iPeriodicityAbility=TRUE);
    CATBoolean GetPeriodicityAbility();

    // si iMaxDegree=TRUE, iDegree sera le degre maximum
    // sinon iDegree sera le degre final
    void SetDegree(int iDegree, CATBoolean iMaxDegree=TRUE);
    void GetDegree(int &ioDegree, CATBoolean &ioMaxDegree);
    void SetMaxNbArcs(int iMaxNbArcs);
    void GetMaxNbArcs(int &ioMaxNbArcs);

    void SetSupportDimension(int iSupportDimension);
    void GetSupportDimension(int &ioSupportDimension);

    void SetParameterizationOption (CATParameterizationOption iParameterizationOption);
    void GetParameterizationOption (CATParameterizationOption &ioParameterizationOption);

//
// UpDate Methodes
//
    // no doc
    void SetUpToDate(CATBoolean iUpToDate);
    CATBoolean IsUpToDate();

  private :
    CATBoolean _RationalAbility;
    CATBoolean _PeriodicityAbility;
    int        _Degree;
    CATBoolean _MaxDegree;
    int        _MaxNbArcs;
    int        _SupportDimension;
    CATParameterizationOption _ParameterizationOption;
    CATBoolean _IsConvertible;
    int        _ComputedDegree;
    int        _NbArcs;
    CATBoolean _IsUpToDate; 
};

#endif
