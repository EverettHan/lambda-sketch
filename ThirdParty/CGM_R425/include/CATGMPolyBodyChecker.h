/* -*-C++-*-*/
#ifndef CATGMPolyBodyChecker_H
#define CATGMPolyBodyChecker_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2017
//
// CATGMPolyBodyChecker
//
// DESCRIPTION :
// 
//
//
// History
//
// July. 2017 WMN Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyGeoOperator.h"  // derivation
#include "GMPolyBodyServices.h"    // ExportedBy

#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATGMPolyBodyCheckerExt;
class CATBody;
class CATListPtrCATGMPolyAnomaly;
class CATPolyBody;
class CATGeoPolyBody;
class CATMapOfPtrToPtr;

#include "ListPOfCATPGMExplicitReport.h"

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBodyServices CATGMPolyBodyChecker : public CATGMPolyGeoOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyChecker);

public:
  
  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyChecker();
  
  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyBodyChecker() method to create an instance
  static CATGMPolyBodyChecker * New(CATGeoFactory & iFactory, CATGMPolyBodyCheckerExt & iExtension);

  // --------------------------------------------------
  // Get methods
  // --------------------------------------------------

  // None

  //=============================================================================
  // Settings
  //=============================================================================

  /** @nodoc
   * @nocgmitf
  */
  typedef enum
  {
    CheckTopo = 0,
    IsCATBodyReady = 1,
    Autocheck = 2
  } Level;

  /** @nodoc
   * @nocgmitf
  */
  void SetCheckLevel(CATGMPolyBodyChecker::Level iLevel);

  // Output methods

  /** @nodoc
   * @nocgmitf
  */
  void GetNbAnomalies(int& NbErrors,int& NbWarnings);

	/** @nodoc
   * @nocgmitf
  */
  CATBoolean IsBodyValid();

 /** @nodoc
  * @nocgmitf
  */
  void GetErrors(CATLISTP(CATGMPolyAnomaly) & oErrors);
  void GetWarnings(CATLISTP(CATGMPolyAnomaly) & oWarnings);
  // **** Caller must addref and release these anomalies using CATGMPolyAnomaly::AddRefList/ReleaseList.

  /** @nodoc
  * @nocgmitf
  * Caller must call addref and release on PolyBody
  */
  CATPolyBody * GetPolyBody();

	/** @nodoc
   * @nocgmitf
  */
  void SetFreezeMode(CATBoolean iMode); // Pourquoi ?

  /** @nodoc
   * @nocgmitf
   */
  void SetGeoPolyBody(CATGeoPolyBody *, CATMapOfPtrToPtr *);

  /** @nodoc
  * @nocgmitf
  */
  void SetPolyBody(CATPolyBody *, CATMapOfPtrToPtr *);

  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();
  //WMN20190529 Documentation une bonne fois pour toutes :
  //WMN20190529 NON, GetDefaultOperatorId n'est pas une methode de CATTopOperator
  //WMN20190529 C'est une methode statique implementee directement par les operateurs, topo ou geo,
  //WMN20190529 qui va retourner la string statique de ces operateurs, leur petit nom,
  //WMN20190529 pour deux choses :
  //WMN20190529 - listing des operateurs dispos dans l'atelier de capture CGMReplay
  //WMN20190529 - fournir l'operatorid via GetOperatorId qui elle est une methode de CATCGMOperator.
  //WMN20190529 
  //WMN20190529 Donc :
  //WMN20190529 - GetDefaultOperatorId seulement sur les operateurs, pas leurs classes meres,
  //WMN20190529 - va appeler l'equivalent sur l'extension pour recuperer l'operatorid          ====>>>> c'est le cas des operateurs GMPoly, appel à Ext::GetDefaultOperatorId a chaque fois.
  //WMN20190529 
  //WMN20190529 Et :
  //WMN20190529 - GetOperatorId seulement sur les classes meres d'operateurs ! => virtuelle pure sur la classe mere extension
  //WMN20190529   Celle de l'operateur appelle celle de l'extension qui elle doit etre dediee car appel a GetDefaultOperatorId
  //WMN20190529 => donc GetOperatorId classe mere appelle GetOperatorId extension, virtuelle pure surchargee par les extensions filles, qui appelle la static GetDefaultOperatorId de l'extension.
  
protected:
  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyBodyChecker() method to create an instance
  CATGMPolyBodyChecker(CATGeoFactory & iFactory, CATGMPolyBodyCheckerExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyChecker();
  CATGMPolyBodyChecker(const CATGMPolyBodyChecker& iOneOf); 
  CATGMPolyBodyChecker& operator =(const CATGMPolyBodyChecker& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create any interface)
 * Creates a CATGMPolyBodyChecker operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iConfig
 * The pointer to the software configuration.
 * If the software configuration is <tt>NULL</tt>, the best version of the code is used. 
 * @param iBody
 * The pointer to the body requiring computations.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBodyServices CATGMPolyBodyChecker * CATCreateGMPolyBodyChecker(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iBody); 

#endif
