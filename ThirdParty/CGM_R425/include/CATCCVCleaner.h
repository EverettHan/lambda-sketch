// COPYRIGHT DASSAULT SYSTEMES 1999 
//==============================================================================
//
// CATCCVCleaner:
// Nettoyage d'une CCV : discontinuites en point, tangente et petits elements.
//
// Ce nettoyage est
// - en general sans changement de parametrisation
//   (ATTENTION: l'hypothese iso-parametrisation n'est plus systematiquement verifiee, et ce depuis longtemps,
//   certaines courbes complexes pouvant etre approchees). NLD280912
// - isotopologique
//==============================================================================
//
// Usage notes:
// Nettoyage de CCV 
// 
//======================================================================
//   /09/99 DHN Creation
// 28/02/02 NLD Ajout SetSoftwareConfiguration()
// 28/09/12 NLD Le Run() est type int et non plus void
//              On derive de CATTopOperator, et non plus de CATCGMVirtual, pour instrumentation CGMReplay
//======================================================================
#ifndef CATCCVCleaner_H
#define CATCCVCleaner_H
#include <FrFAdvancedOpeCrv.h>
#include "CATDataType.h"
#include <CATSkillValue.h>
#include "CATCGMVirtual.h"
#include "CATTopOperator.h"

class CATFrFCompositeCurve;
class CATGeoFactory;
class CATTopData;
class CATSoftwareConfiguration ;

//----------------------------------------------------------------------
class  ExportedByFrFAdvancedOpeCrv CATCCVCleaner

                                                 : public CATTopOperator // anciennement avant 28/09/12 CATCGMVirtual
{
  public:


    CATCCVCleaner(CATGeoFactory        * iFactory,
                  CATTopData           * iTopData,
                  CATFrFCompositeCurve * iCCV    
                 );


    virtual ~CATCCVCleaner()
    {
    };
    virtual int Run()=0;
    //
    // Pour recuperer le resultat du nettoyage 
    // Si la CCV a nettoyer etait continue en tangence et en point,
    // le pointeur retourne est celui de la CCV en entree
    // Si la CCV a ete nettoyee, le pointeur est celui d'une nouvelle
    // CCV pointant vers les memes courbes plus des nouvelles courbes
    // issues de la deformation
    //
    virtual CATFrFCompositeCurve* GetCleanedCCV()=0;
    //
    // Comment savoir quelles courbes sont nouvelles ?
    // Si le pointeur rendu est nul, il n'y a pas eu de deformation
    // Sinon, la taille du tableau rendu est le nombre d'element constitutifs
    // de la CCV. L'indicateur vaut 0 si l'element n'a pas ete deforme (cet
    // element est donc aussi pointe par la CCV a deformer), il vaut 1 sinon.
    // Attention, dans ce dernier cas, les nouvelles courbes ne sont pas streamables,
    // elles doivent donc IMPERATIVEMENT etre detruites. 
    //
    // On peut neanmoins obtenir une composite curve streamable via CreateCompositeCurve_Streamable()
    virtual const CATLONG32 * IsANewCurve() const =0;
    //
    // Definition de la configuration logicielle
    //
    virtual void SetSoftwareConfiguration(CATSoftwareConfiguration* iConfig) = 0 ;
};

//==================================================================
ExportedByFrFAdvancedOpeCrv 
CATCCVCleaner* CreateCCVCleaner(CATGeoFactory        * iFactory,
                                CATFrFCompositeCurve * iCCV    ,
                                CATSkillValue          iMode   = BASIC);

//==================================================================
ExportedByFrFAdvancedOpeCrv  
void Remove(CATCCVCleaner *&iCATCCVCleaner);
#endif

