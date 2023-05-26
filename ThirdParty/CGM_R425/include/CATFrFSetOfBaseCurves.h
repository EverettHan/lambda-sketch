// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATFrFSetOfBaseCurves:
// Interface class of Base Curves Object for the Generalized Sweep Operator.
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// May   97 CPL Creation                                                 CPL
// 09/06/99 CPL Ajout de la methode GetClosure
// 28/01/00 CPL Ajout des Orientations
// 03/02/00 CPL Ajout de ComputeFixedPoints
// 03/07/00 CPL Ajout de SetCombs pour PERFO
// 23/10/00 CPL Ajout de SetBreakInfo
// 05/06/01 CPL Reorder: reordonnancement des profils en fonction des 
//              parametres associes
// 04/11/05 NLD On herite de CATFrFObjectVirtual au lieu de CATCGMVirtual
// 27/02/07 NLD Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 12/03/07 NLD Ajout du constructeur avec CATFrFObject
//              et mise en prive des autres constructeurs
//              SetCombs() ne recoit plus la factory
// 20/12/10 JSX remontée de IncreaseDegreeForDeformation()
// 13/02/23 NLD Mise au propre; Smart indent
//              Renommages de iGuide en iProfile (ancestrales erreurs de Copy/Paste)
// 14/02/23 NLD Changement de protocole de la méthode statique ComputeFixedPoints()
//              qui peut calculer un point interne en sus
//              ainsi que de la méthode de classe
//==========================================================================
//
#ifndef CATFrFSetOfBaseCurves_H
#define CATFrFSetOfBaseCurves_H
//
#include "FrFAdvancedObjects.h"
#include "CATListOfCATFrFProfile.h"
//
#include "CreateFrFSetOfBaseCurves.h"
//#include "CATCGMVirtual.h"
#include "CATFrFObject.h"

//
class CATFrFProfile;
class CATMathAxis;
class CATMathPoint;
class CATFrFCompositeCurve;
class CATMathPoint;
class CATFrFNurbsMultiForm;
class CATMathVector;
class CATGeoFactory;
class CATBreakInfo;
//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFSetOfBaseCurves : public CATFrFObject
{
 private:
   CATFrFSetOfBaseCurves() ;
   CATFrFSetOfBaseCurves(const CATFrFSetOfBaseCurves& iFrFSetOfBaseCurves) ;
 public :

  CATFrFSetOfBaseCurves(CATFrFObject& iFrFObject) ;

 virtual               ~CATFrFSetOfBaseCurves()       ;

 // Get the number of profiles
 virtual CATLONG32      GetNumberOfBaseCurves()                                                const = 0;

 // return 1 if all profiles are closed
 virtual CATLONG32      GetClosure       ()                                                    const = 0;

 // Get the list of Guiding Curve
//virtual CATLISTP(CATFrFProfile)* GetBaseCurves() const = 0;

 // Get one Profile
 virtual CATFrFProfile* GetOneBaseCurve  (       CATLONG32               iIndex              ) const = 0;

 // Set Bases Orientation
 virtual void           SetOrientations  (       CATLONG32            *  iOrientations       )       = 0;

 // Get one Base Orientation
 virtual CATLONG32      GetOneBaseOrientation(   CATLONG32               iIndex              ) const = 0;

 // Set One Axis
 virtual void           SetAxis           (      CATLONG32               iIndex              ,
                                                 CATMathAxis          *  iAxis               )       = 0;

 // Insert one Profile
 virtual void           Insert            (      CATLONG32               iIndex              ,
                                                 CATFrFProfile        *  iProfile            )       = 0;

 // Append one Profile
 virtual void           Append            (      CATFrFProfile        *  iProfile            )       = 0;

 // If all profiles intersect themselves at first and/or end
 // point, point's allocation. Else return NULL;
 virtual void           ComputeFixedPoints(      CATMathPoint         *& ioFirstPoint        ,
                                                 CATMathPoint         *& ioInternPoint       ,
                                                 CATMathPoint         *& ioLastPoint         )       = 0;

  static void           ComputeFixedPoints(      CATLONG32               iNumberOfBases      ,
                                           const CATFrFCompositeCurve**  iBases              ,
                                           const CATLONG32            *  iOrientations       ,
                                                 CATMathPoint         *& ioFirstPoint        ,
                                                 CATMathPoint         *& ioInternPoint       ,
                                                 CATMathPoint         *& ioLastPoint         );

  virtual void          SetCombs          (    /*CATGeoFactory        *  iFactory            ,*/
                                                 CATLONG32               iComputeFirstTgt    ,
                                                 CATLONG32               iComputeLastTgt     ,
                                                 CATMathVector        *  iFirstTgt           ,
                                                 CATMathVector        *  iLastTgt            ,
                                                 CATFrFNurbsMultiForm**  iNurbsComb1         ,
                                                 CATFrFNurbsMultiForm**  iNurbsComb2         ,
                                                 CATLONG32               iMasterProfile      )       = 0;

  virtual void          SetBreakInfo      (      CATBreakInfo        **  iBreakInfo          ,
                                                 CATLONG32               iNbElt              )       = 0;

  virtual void          Reorder           (      CATFrFCompositeCurve**  ioOrderProfileCcv   ,
                                                 CATLONG32            *  ioOrientation       ,
                                                 CATLONG32             & ioIndexMasterProfile)       = 0;

   //-----------------------------------------------------------------------------
 // Augmentation de degre si necessaire pour la deformation
 // sur le segment d'index iSegmentIndex
 // en assurant un nombre minimum de points de controles de iNbCPMin
 //-----------------------------------------------------------------------------
 virtual void       IncreaseDegreeForDeformation(int                    iNbCPMin            ,
                                                 int                    iSegmentIndex       )       = 0;

};
#endif

