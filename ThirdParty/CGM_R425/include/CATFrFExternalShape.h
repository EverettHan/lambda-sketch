// COPYRIGHT DASSAULT SYSTEMES 2019
//==========================================================================
//
// CATFrFExternalShape:
// Interface class of FrF reduced Shape Object for external derivations
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Shape or derived
// in order to implement specific algorithm or capabilities.
//
// See CATFrFGeneratingShape for more information
//==========================================================================
// 11/02/19 NLD Creation pour simplifier les derivations externes
//              et redonner �volutivit� interne FreeForm aux m�thodes
//              non destin�es � etre red�finies � l'ext�rieur
//==========================================================================
#ifndef CATFrFExternalShape_H
#define CATFrFExternalShape_H

#include "FrFAdvancedObjects.h"

#include "CATMathDef.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#include "CATFrFObject.h"
#include "CATFrFGeneratingShape.h"

class CATMathSetOfPoints;
class CATMathSetOfPointsND;
class CATMathSetOfVectors;
class CATMathInterval;
class CATFrFCoupling;
class CATFrFMovingFrame;
class CATFrFSetOfGuides;
class CATFrFSetOfBaseCurves;
class CATFrFShapeConstraint;
class CATFrFProfile;
class CATFrFNurbsMultiForm;
class CATCurve;
class CATGeoFactory;
class CATMathTransformation;
class CATFrFShapeResult;

class ExportedByFrFAdvancedObjects CATFrFExternalShape : public CATFrFGeneratingShape
{

private:
                                   CATFrFExternalShape        ();
public:

                                   CATFrFExternalShape        (      CATFrFObject           *   iCATFrFObject           );

                                  ~CATFrFExternalShape        ();

  // 0        : disable
  // 1, 2, ...: enable with special eval code depending on shape type
  // - Loft
  //            1 : Eval without sketcher in variational sweep
  //            1 : Eval without area law in loft
  // - Blend
  //            1, 2, ...: Special Blend Eval options, see CATFrFImplicitProfile. NLD201115
          void                     SetFastEval                (      CATLONG32                 iEvalMode                )
        {
           return; 
        };
          void                     GetFastEvalInfo            (      CATLONG32               & NbOfEvalMode             ,
                                                                     CATLONG32               & CurrentEvalMode          ,
                                                                     CATLONG32               & CompletEvalCost          ) const
        {
           NbOfEvalMode    = 0;
           CurrentEvalMode = 0;
           CompletEvalCost = 0;

        };

  // Donne le discernement de la shape
  // Generalement parfait  oPerfect=1 ce qui correspond a oShapeDiscernment=0.
  // Quand la shape fait appel a un solver, 2 evaluations proches peuvent etre confondues (faussent les deriv�es par differences finies)
          void                     GetDiscernment             (      CATLONG32               & oPerfect                 ,
                                                                     double                  & oShapeDiscernment        ) const
       {
       }

          void                     DataForNextEval            (      int                       iDataIndex               ,
                                                                     CATLONG32              *  iTLong                   ,
                                                                     double                 *  iTDouble                 )
      {
      };
  // Ca c'est pour recuperer des donnees de la derni�re �valuation,
  // et chaque shape d�riv�e l'impl�mente � sa mani�re
  // avec la signification qu'elle veut pour les iDataIndex, et pour les
  // valeurs de sortie. NLD020704. Cr�ation de la m�thode: JSX pour mesure d'aire du loft
  // utilisations specifiques existant pour Loft et pour Blend, a la date du 20/11/15
          void                     DataFromLastEval           (       int                      iDataIndex               ,
                                                                      CATLONG32             *  oTLong                   ,
                                                                      double                *  oTDouble                 )
     {
     };

};
#endif
