// COPYRIGHT DASSAULT SYSTEMES 2003
//==========================================================================
//
// CATFrFObject:
// "Mother" Class for FreeFormOperators 
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// 10/10/03 JSX Creation de CATFrFObjectVirtual
//   /07/06 CPT migration sur CATCGMVirtualDeclareClass
// 25/07/06 NLD Tentative de debug des objets non effaces par generation de code77
//              en utilisant CATCGMNewArray. Pas actif
//              Ajout Init()
// 04/08/06 NLD Ajout de _DebugKeepDummyObject
//              Ajout de _Count
// 06/12/06 jsx Ajout _Factory et SetFactory() et acces aux tolerances
//              de _Factory via CATFrFTolerance
// 27/02/07 NLD Ajout de GetFactory() 
//              pour securisation des acces aux factorys non initialisees
//              et passage de _Factory en private
// 27/02/07 NLD Separation en CATFrFObjectVirtual et CATFrFObject
//              pour permettre de deriver seulement de CATFrFObjectVirtual
//              avec mecanismes de debug des references, sans
//              gestion des donnees de CATFrFObject (configuration, factory)
//              et pour bien distinguer un vrai objet d'un objet virtuel
//              ### Ensuite il faudra forcer le passage par un constructeur
//              ### explicite avec configuration
// 28/02/06 NLD Argument iFirstLevelToSet au constructeur recevant un CATFrFObject
// 01/03/06 NLD Oui mais du coup il faut definir le constructeur par defaut
//              pour bien gerer la configuration
// 02/03/07 NLD Suppression du constructeur avec CATFrFConfiguration qui reposait
//              sur une affectation bancale de celle-ci, rendue desormais impossible
//              Du coup c'est le constructeur avec SoftwareConfiguration
//              qui prend un pointeur nul par defaut et fait office
//              de constructeur par defaut
// 12/03/07 NLD Ajout constructeur avec SoftwareConfiguration et Factory
// 26/05/09 JSX Ajout de SetFrFTopologyCallBacks
// 19/01/10 NLD Ajout _TolObject
//              Init() recoit la factory
// 27/03/13 NLD Ajout GetFrFTopologyCallBacks()
// 16/06/22 JSX Ajout du versionning a la mode Jeremy CATFreeFormOpeVersioning
//==========================================================================
//
#ifndef CATFrFObject_H
#define CATFrFObject_H
//
#include "CATFrFObjectVirtual.h"
#include "FrFObjects.h"
#include "CATDataType.h"

#include "CATFrFConfiguration.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATTolerance;
class CATFrFTopologyCallBacks;

#include "CATTolerance.h"
#include "CATGetTolerance.h"
// NLD270313 dans un .h? #define FACTORY_NAME _Factory
#include "CATFrFTolerance.h"
#include "CATFreeFormOpeVersioning.h"

class ExportedByFrFObjects CATFrFObject : public CATFrFObjectVirtual

  {
  CATCGMVirtualDeclareClass(CATFrFObject);
  public :
    //                                CATFrFObject            (      CATFrFConfiguration     * iFrFConfig            = 0);

                                      CATFrFObject            (      CATGeoFactory           * iFactory              ,
                                                                     CATSoftwareConfiguration* iConfig               ) ;

                                      CATFrFObject            (      CATSoftwareConfiguration* iConfig               = 0);

                                      // Ici la configuration reçue via iCATFrFObject ne doit etre appliquee que si elle contient
                                      // un niveau CGM superieur ou egal a iFirstLevelToSet
                                      CATFrFObject            (      CATFrFObject            * iCATFrFObject         ,
                                                                     int                       iFirstLevelToSet      );

                                      CATFrFObject            (const CATFrFObject            & iCATFrFObject         );

    virtual                          ~CATFrFObject            ();

    virtual CATSoftwareConfiguration* GetSoftwareConfiguration() const;

    virtual void                      SetSoftwareConfiguration(      CATSoftwareConfiguration* iConfig               );

    // Ici la configuration ne doit etre appliquee que si elle contient un niveau CGM superieur ou egal a iFirstLevelToSet
    virtual void                      SetSoftwareConfiguration(      CATSoftwareConfiguration* iConfig               ,
                                                                     int                       iFirstLevelToSet      );

    //

    virtual void                      SetFactory              (      CATGeoFactory           * iFactory              );

    virtual CATLONG32                 GetCGMLevel             () const;

    virtual CATGeoFactory           * GetFactory              (      int                       iNoErrorIfNullFactory = 0) const;

    // @nocgmitf
            void                      SetFrFTopologyCallBacks (      CATFrFTopologyCallBacks * iFrFTopologyCallBacks );

    // @nocgmitf
    // N.B le callback eventuellement rendu, et dont la propriete n'est pas connue,
    //     ne doit etre utilise qu'immediatement et non conserve
            CATFrFTopologyCallBacks * GetFrFTopologyCallBacks ();

  protected :
            void                      Init                    (      CATGeoFactory           * iFactory              ) ;
            
    // @nocgmitf
    // Versioning 
    static const CATFreeFormOpeVersioning& GetVersioning(); // static utility method
            //////////////////////////////////////////////
    // DATA /////////////////////////////////////
    //////////////////////////////////////////////
  public :
  protected:
          CATFrFConfiguration       _FrFConfig;
          CATFrFTopologyCallBacks * _FrFTopologyCallBacks;
    // Centralisation du lien _FrFConfig->_SoftwareConfiguration et du niveau CGM 
          int                       _CGMLevel;
    const CATTolerance            * _TolObject;

    // Versioning
    const CATFreeFormOpeVersioning  & _VersioningFRFOPE;
  private:
          CATGeoFactory           * _Factory;
  } ;

















#endif
