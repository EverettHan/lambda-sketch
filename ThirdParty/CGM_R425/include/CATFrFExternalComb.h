//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//==========================================================================
//
// Classe g�n�rique pour �ventuels peignes externes � FreeFormOperators
//
//--------------------------------------------------------------------------
// le but de cette classe est d'identifier et restreindre les services
// de la classe m�re red�finissables � l'ext�rieur
// et de garantir les possibilit�s d'�volution coh�rente
// - de cette classe m�re CATFrFComb
// - de toutes ses filles
// - des outils sur les peignes CATFrFCombCleaner, CATFrFCombImprovement
//
// REMARQUE : CATFrFExternalComb, comme CATFrFGeneralComb,
//            est defini sur [0,1] et est toujours norm� (*).
//            Ceci, quelque soit l'echelle de la Factory
//            A d�faut, l'appel � SetScaleOption(), depuis le constructeur
//            est INDISPENSABLE
//==========================================================================
// 28/01/20 NLD Cr�ation
//==========================================================================
#ifndef CATFrFExternalComb_H
#define CATFrFExternalComb_H


#include "FrFObjects.h"
#include "CATFrFObject.h"
#include "CATFrFGeneralComb.h"

//--------------------------------------------------------------------------
class ExportedByFrFObjects CATFrFExternalComb :public CATFrFGeneralComb
{
protected:
                                  CATFrFExternalComb          (      CATFrFObject  * iFrFObject);
         CATFrFGeneralComb      * Duplicate                   ()                                      const;
public:

  virtual                        ~CATFrFExternalComb          ();
  


  virtual CATMathClassId          IsA                         ()                                      const = 0;

  //==========================================================================
  // To change the orientation on the comb support ; iOrientation=1(default) or -1.
  // RESTRICTED OR TEMPORARY USE
  // NLD210519 pour MWE
  // voir responsabilit�s de cette orientation dans les �valuations, dans les nettoyages de peignes
  //==========================================================================
  virtual void                    SetSupportOrientation       (      CATLONG32        iOrientation);
  virtual CATLONG32               GetSupportOrientation       ()                                      const;

  //==========================================================================
  // To change the comb support
  //==========================================================================
  // RESTRICTED OR TEMPORARY USE
  // NLD220120 pour MWE
  // CAUTION:
  // - cycle life must be secured
  // - single call at beginning recommended
  // - to use in consistency with comb clean and deformation laws if any
  // - as for SetSupportOrientation(), EvalPointOnSupport(), ... 
  //   Support means a 1D geometry (curve, edge, ...) not a surface
  virtual void                    SetSupport                  (      CATGeometry*     iSupport);
  virtual CATGeometry           * GetSupport                  ()                                      const;

  //==========================================================================
  // Evaluators
  //==========================================================================
  // child classes evaluators should always take deformation laws into account
  // (through EvalLaw(), EvalFirstDerivativeLaw(), EvalSecondDerivativeLaw())
  virtual CATLONG32               Eval                        (double iT, CATMathVector & oDir      ) const = 0;
  virtual CATLONG32               EvalFirstDerivative         (double iT, CATMathVector & oDerivDir ) const;
  virtual CATLONG32               EvalSecondDerivative        (double iT, CATMathVector & oDersecDir) const;

  virtual void                    EvalTgtOnSupport            (double iT, CATMathVector & oDir      ) const = 0;
  virtual void                    EvalPointOnSupport          (double iT, CATMathPoint  & oPoint    ) const;

};
#endif

