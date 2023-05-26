// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATFrFSetOfGuides:
// Interface class of Guide Object for the Generalized Sweep Operator.
//
//==========================================================================
//
// Usage notes:
//   
//==========================================================================
// Nov   97 CPL Creation                                            Pradalou
// 04/11/05 NLD On herite de CATFrFObjectVirtual au lieu de CATCGMVirtual
// 27/02/07 NLD : Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 12/03/07 NLD Ajout du constructeur avec CATFrFObject
//              et mise en prive des autres constructeurs
// 14/04/22 JSX Ajout (Get/Set)SetOfBaseCurve pour BoundarySurface
//========================================================================== 
//
#ifndef CATFrFSetOfGuides_H
#define CATFrFSetOfGuides_H
//
#include "FrFAdvancedObjects.h"

#include "CATListOfCATFrFCompositeCurve.h"
#include "CATListOfCATGeometries.h"

#include "CreateFrFSetOfGuides.h"
//#include "CATCGMVirtual.h"
#include "CATFrFObject.h"

class CATCurve;
class CATFrFSetOfBaseCurves;
//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFSetOfGuides : public CATFrFObject
{
 private:
   CATFrFSetOfGuides() ;
   CATFrFSetOfGuides(const CATFrFSetOfGuides& iFrFSetOfGuides) ;
 public :

   CATFrFSetOfGuides(CATFrFObject& iFrFObject) ;


 virtual                                          ~CATFrFSetOfGuides()       ;

 // Get the number of Guides 
 virtual CATLONG32                                 GetNumberOfLimitGuides     ()                 const = 0;
 virtual CATLONG32                                 GetNumberOfMiddleGuides    ()                 const = 0;
 virtual CATLONG32                                 GetNumberOfFunctionalGuides()                 const = 0;

 // Get the list of Guiding Curve
 // N.B definition de macros pour aider le parser de Sniff
 #define ListPOfCompositeCurves_CATFrFSetOfGuides  CATLISTP(CATFrFCompositeCurve)
 #define ListPOfCATGeometry_CATFrFSetOfGuides      CATLISTP(CATGeometry)
 virtual ListPOfCompositeCurves_CATFrFSetOfGuides* GetLimitGuides             ()                 const = 0;
 virtual ListPOfCompositeCurves_CATFrFSetOfGuides* GetMiddleGuides            ()                 const = 0;
 virtual ListPOfCATGeometry_CATFrFSetOfGuides    * GetFunctionalGuides        ()                 const = 0;

 // Get one Guide 
 virtual CATCurve                                * GetOneLimitGuide           (CATLONG32 iIndex) const = 0;
 virtual CATFrFCompositeCurve                    * GetOneCcvLimitGuide        (CATLONG32 iIndex) const = 0;
 virtual CATCurve                                * GetOneMiddleGuide          (CATLONG32 iIndex) const = 0;
 virtual CATFrFCompositeCurve                    * GetOneCcvMiddleGuide       (CATLONG32 iIndex) const = 0;
 virtual CATGeometry                             * GetOneFunctionalGuide      (CATLONG32 iIndex) const = 0;

 // Insert one Guide 
 virtual void                                      InsertOneLimitGuide        (CATLONG32 iIndex, CATFrFCompositeCurve* iGuide) = 0;
 virtual void                                      InsertOneMiddleGuide       (CATLONG32 iIndex, CATFrFCompositeCurve* iGuide) = 0;
 virtual void                                      InsertOneFunctionalGuide   (CATLONG32 iIndex, CATGeometry         * iGuide) = 0;

 // Set one Guide 
 virtual void                                      SetOneLimitGuide           (CATLONG32 iIndex, CATFrFCompositeCurve* iGuide) = 0;
 virtual void                                      SetOneMiddleGuide          (CATLONG32 iIndex, CATFrFCompositeCurve* iGuide) = 0;
 virtual void                                      SetOneFunctionalGuide      (CATLONG32 iIndex, CATGeometry         * iGuide) = 0;

 // Append one Guide 
 virtual void                                      AppendOneLimitGuide        (CATFrFCompositeCurve  *  iGuide) = 0;
 virtual void                                      AppendOneMiddleGuide       (CATFrFCompositeCurve  *  iGuide) = 0;
 virtual void                                      AppendOneFunctionalGuide   (CATGeometry           *  iGuide) = 0;

 virtual void                                      SetSetOfBaseCurve          (CATFrFSetOfBaseCurves *  iGuideBaseCurves) = 0;
 virtual void                                      GetSetOfBaseCurve          (CATFrFSetOfBaseCurves *& iGuideBaseCurves) = 0;


};
#endif

