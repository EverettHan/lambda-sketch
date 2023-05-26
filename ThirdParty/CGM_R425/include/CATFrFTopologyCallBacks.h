// DifferentBodies() a migrer dans CATTopologyCallBacks



// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
//
// CATFrFTopologyCallBacks:
// Utility for topology calls from FreeFormOperators
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
// classe virtuelle à instancier au niveau topologique
// puis transmettre un objet de la classe à l'operateur FreeForm concerné
//=============================================================================
// 24 12 04 NLD Creation
//              ConstructsBodyFromGeometry()
// 12 01 05 NLD Ajout ConstructsBodyFromCCV()
// 28 01 05 NLD On derive de CATTopologyCallBacks
// 13 12 05 NLD Ajout de _CreateOrRemoveDebugAutomaticCATFrFTopologyCallBacks
//              de CreateOrRemoveDebugAutomaticCATFrFTopologyCallBacks()
//              et de SetCreateOrRemoveDebugAutomaticCATFrFTopologyCallBacks()
//              pour creation/destruction facile de callback topologique en mode debug
// 14 12 05 NLD Ajout de DifferentBodies()
// 16 12 05 NLD Ajout de NameBody()
// 16 12 05 NLD Ajout de CreateFrFTopoCATExtCGMReplay()
// 16 12 05 NLD Ajout de DebugAutomaticLoadAdvancedTopologicalOpe()
// 28/03/13 NLD Ajout de AddRef(), Release()
//              Le destructeur n'est plus accessible (il faut utiliser Release())
// 07/06/17 NLD Smart indent
//              Ajout CreateATOCompositeCurve()
// 03/09/17 NLD Ajout CreateLocalizer2DFrom3D()
//=============================================================================

#ifndef CATFrFTopologyCallBacks_H
#define CATFrFTopologyCallBacks_H

// #include<>
#include <FrFAdvancedObjects.h>
#include <CATUnicodeString.h>

#include <CATListOfCATCurves.h>
#include <ListPOfCATCell.h>

class CATBody ;
class CATGeoFactory ;
class CATGeometry ;
class CATSoftwareConfiguration ;
class CATFrFCompositeCurve ;
class CATExtCGMReplay ;
class CATTopOperator;
class CATTopData;
class CATLocalizer2DFrom3D;
#include <CATTopologyCallBacks.h>

class /*ExportedByFrFAdvancedObjects*/ CATFrFTopologyCallBacks  : public CATTopologyCallBacks
{
 
 protected:
   virtual ~CATFrFTopologyCallBacks()
   {
   }
 
 public:
   
   // Construction d'un body à partir d'une composite curve
   virtual void              ConstructsBodyFromCCV       (CATGeoFactory            *  iFactory             ,
                                                          CATSoftwareConfiguration *  iConfig              ,
                                                          CATFrFCompositeCurve     *  iCCV                 ,
                                                          CATBody                  *& oBody                ) = 0 ;

   virtual CATFrFCompositeCurve *
                             CreateATOCompositeCurve     (CATGeoFactory            *  iFactory                   ,
                                                          CATTopData               *  iTopData                   ,
                                                    const CATBody                  *  iBodyWire                  ,
                                                    const CATBody                  *  iBodySupport               = 0,
                                                          CATBoolean                  iNonConnexWireSupport      = FALSE,
                                                          CATBoolean                  iIgnoreOutsideEdgeParts    = FALSE,
                                                          CATBoolean                  iHybrid3D2DMode            = FALSE,
                                                          CATTopOperator           *  iTopOperator               = NULL ,
                                                          CATBoolean                  iWarningNotOnShellBoundary = FALSE) = 0;


   // Comparaison de 2 bodies
   // rend 0 si egaux, 1 si differents (diagnostic enrichissable)
   virtual int               DifferentBodies             (CATSoftwareConfiguration *  iConfig              ,
                                                          CATBody                  *  iReferenceBody       ,
                                                          CATBody                  *  iResultBody          ,
                                                          double                      iTol                 = 0.0 )// tolerance to use if not null
                                                                                                                = 0 ;
   // Nommage d'un body
   // Avec - prefixe
   //      - numero eventuel (si non nul)
   //      - tag (si demandé)
   virtual void              NameBody                    (CATBody                  *  iBody                ,
                                                          CATUnicodeString          & iPrefix              ,
                                                          int                         iNum                 , 
                                                          CATBoolean                  iAddTagValue         )    = 0;

   // Creation d'un CGMReplay adherent à un framework topologique
   // Remarque: on nomme cette methode ainsi (avec la chaine FrF) pour la distinguer
   // d'une methode similaire eventuellement definie dans la classe mère CATTopologyCallBacks
   // et qui serait implementée dans un framework topologique de plus bas niveau (i.e TopologicalOperators)
   // que celui qui va implementer la présente méthode. (i.e AdvancedTopologicalOpe)
   virtual CATExtCGMReplay * CreateFrFTopoCATExtCGMReplay()                                                     = 0;

   // Add    a reference to this object (and give back reference counter)
   virtual int               AddRef                      (void                     *  iDebugPointingObject = 0) = 0;

   // Delete a reference to this object (and give back reference counter) (delete the object if reference counter decreased to 0)
   virtual int               Release                     (void                     *  iDebugPointingObject = 0) = 0;

   // Creation d'un localisateur topologique par Faces et PCurves
   virtual CATLocalizer2DFrom3D* CreateLocalizer2DFrom3D (CATGeoFactory            *  iFactory                   ,
                                                          CATSoftwareConfiguration *  iConfig                    ,
                                                          CATLISTP(CATCell)         & CellList                   ,
                                                          CATLISTP(CATCurve)        & PCurveList                 ) = 0;


} ;

//-----------------------------------------------------------------------------
// Definition de la methode statique de creation/destruction automatique de callback topologique
// (creation si pointeur nul en entree, destruction si pointeur non nul)
//-----------------------------------------------------------------------------
extern "C" ExportedByFrFAdvancedObjects
void SetCreateOrRemoveDebugAutomaticCATFrFTopologyCallBacks(void (*iDebugAutomaticCATFrFTopologyCallBacks)(CATFrFTopologyCallBacks*&)) ;

//-----------------------------------------------------------------------------
// Creation ou destruction de callback topologique (si on dispose de l'adresse d'une methode
// adequate fournie au prealable par la topologie)
//-----------------------------------------------------------------------------
extern "C" ExportedByFrFAdvancedObjects
void CreateOrRemoveDebugAutomaticCATFrFTopologyCallBacks(CATFrFTopologyCallBacks*& ioCallBacks) ;

//-----------------------------------------------------------------------------
// Chargement dynamique de AdvancedTopologicalOpe via CATAdvancedTopologicalOpeDummy()
// rend 1 si chargement OK, 0 sinon
//-----------------------------------------------------------------------------
// pas necessaire de l'exporter, mais bon, si quelqu'un en a besoin
extern "C" ExportedByFrFAdvancedObjects
int DebugAutomaticLoadAdvancedTopologicalOpe() ;
//
#endif
