// COPYRIGHT DASSAULT SYSTEMES 1997
//===================================================================
//
// CATFunctionG2IntoC2 :
// Class of piecewise functions of one variable for CleanCurve
//
//===================================================================
//
// 21/11/2017 : NLD : Ajout _LoadedFromReplay
// 17/11/2017 : NLD : Renommage de IsStreamable() en _IsStreamable() pour respect du protocole de stream plateforme
//                    Ajout GetDirectComponents()
//                    Ajout GetStreamDomainType()
// 16/11/2017 : NLD : Ajout CATFunctionXUnStream_CATFunctionG2IntoC2()
// 07/11/2017 : NLD : Ajout IsStreamable() 
//                    Smart indent
// 28/05/2003 : RNO : Mirroir OK
//   /07/2002 : RNO ; Mise en place de la classe evaluateur "CATG2IntoC2CommonEngine"
//===================================================================

#ifndef CATFunctionG2IntoC2_H
#define CATFunctionG2IntoC2_H

#include "CATIACGMLevel.h"

#include "FrFAdvancedOpeCrv.h"

#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#include "CATTolerance.h"

#include "CATMathFunctionX.h"
#include "CATMathPiecewiseX.h"
#include "CATMathBasisFunctionX.h"

#include "CATListOfCATCurves.h"
#include "CATListOfCATCrvLimits.h"

#include "CATCGMStreamVersion.h"


class CATCurve;
class CATFrFCompositeCurve;
class CATFrFCompositeCurveMapping;
class CATCrvLengths;

class CATG2IntoC2CommonEngine;

//===================================================================
class ExportedByFrFAdvancedOpeCrv CATFunctionG2IntoC2 : public CATMathBasisFunctionX
{

// public methods
 public:
  //----------------------------
  // Constructeur / Destructeur
  //----------------------------
  
                     CATFunctionG2IntoC2(      CATG2IntoC2CommonEngine *  iEvaluatorEngine,
                                               int                        iRangXYZ        ,
                                         const CATTolerance             & iTolObject      );


//Methodes a implementer pour etre une CATMathFunctionX
  virtual           ~CATFunctionG2IntoC2();

  CATMathClassId     IsA                () const;
  CATBoolean         IsAKindOf          (const CATMathClassId             iClassId        ) const;
  CATBoolean         IsATypeOf          (const CATMathFunctionXTypeId     iType           ) const;

  //-----------------------------------------------------------------
  // Duplicator
  //-----------------------------------------------------------------
  CATMathFunctionX * Duplicate          ()                                                  const;
  CATMathFunctionX * DeepDuplicate      ()                                                  const;


  //------------------------
  // Evaluators on doubles
  //------------------------  
  CATBoolean         IsOption           (const CATMathOption              iOption         ) const;

  double             Eval               (const double                   & t               ) const;

  double             EvalFirstDeriv     (const double                   & t               ) const;

  double             EvalSecondDeriv    (const double                   & t               ) const;

  virtual int        GetDirectComponents(const int                       iSizeOfComponents,
                                         const CATMathFunctionGeneral ** ioComponents     ) const;

  virtual short      GetStreamDomainType(      char                      ioDomain      [3]) const;


  virtual CATBoolean _IsStreamable      (const CATCGMStreamVersion        iTargetVersion  ,
                                               CATBoolean               & ioReversible    ) const;

  virtual void       Stream            (       CATMathStream            & Str             ,
                                         const char                       iLabelReserved[]) const;


  //-----------------
  // protected data
  //-----------------

 protected:

   int                       _RangXYZ;
   CATG2IntoC2CommonEngine * _EvaluatorEngine;

 public:
   int                       _LoadedFromReplay; // (N.B public pour facilite UnStream)
};

   // Ici extern "C" necessaire pour cette fonction à vocation de chargement dynamique; commentaire NLD021020
   extern "C" ExportedByFrFAdvancedOpeCrv
   CATMathFunctionX* CATFunctionXUnStream_CATFunctionG2IntoC2(            CATMathStream& Str              ,
                                                                    const CATTolerance & iTolObject       ,
                                                                    const char           iLabelReserved[] );
  
#endif
