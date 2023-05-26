/* -*-C++-*-*/
#ifndef CATGMPolyMassProperties3DGeoOper_H
#define CATGMPolyMassProperties3DGeoOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyMassProperties3DGeoOper
//
// DESCRIPTION :
// Computation of 3D mass properties for a polyhedral body, face or edge.
//
//
// History
//
// April. 2016 WMN Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyGeoOperator.h" // derivation
#include "GMPolyBasicOper.h"      // ExportedBy

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATMathPoint.h"
#include "CATMath3x3Matrix.h"

class CATGMPolyMassProperties3DGeoExt;
class CATBody;
class CATFace;
class CATEdge;

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBasicOper CATGMPolyMassProperties3DGeoOper : public CATGMPolyGeoOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyMassProperties3DGeoOper);

public:
  
  /**
  * Destructor
  */
  virtual ~CATGMPolyMassProperties3DGeoOper();
  
  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyMassProperties3DGeoOper() method to create an instance
  static CATGMPolyMassProperties3DGeoOper * New(CATGeoFactory & iFactory, CATGMPolyMassProperties3DGeoExt & iExtension);

  // --------------------------------------------------
  // Get methods
  // --------------------------------------------------
  // Retrieves mass properties step by step
  double GetVolume();
  double GetWetArea();
  double GetLength();
  CATMathPoint      GetCenterOfGravity();
  CATMath3x3Matrix  GetInertiaMatrix();

  // Retrives mass relative error
  double GetVolumeRelativeError  ( CATBoolean &oIsRelativeErrorAvailableWithMethod );
  double GetWetAreaRelativeError ( CATBoolean &oIsRelativeErrorAvailableWithMethod );
  void GetCenterOfGravityRelativeError ( CATBoolean & oIsRelativeErrorAvailableWithMethod ,
    double       oRelativeError   [3]                ,
    double       oMaximalDimension[3]                );

  //=============================================================================
  // Settings
  //=============================================================================


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
  
  /** @nodoc
   * @nocgmitf
   * For CGMReplay only
   */
  void SetQuery(unsigned char iQuery);

protected:
  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyMassProperties3DGeoOper() method to create an instance
  CATGMPolyMassProperties3DGeoOper(CATGeoFactory & iFactory, CATGMPolyMassProperties3DGeoExt & iExtension);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyMassProperties3DGeoOper();
  CATGMPolyMassProperties3DGeoOper(const CATGMPolyMassProperties3DGeoOper& iOneOf); 
  CATGMPolyMassProperties3DGeoOper& operator =(const CATGMPolyMassProperties3DGeoOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create any interface)
 * Creates a CATGMPolyMassProperties3DGeoOper operator.
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
ExportedByGMPolyBasicOper CATGMPolyMassProperties3DGeoOper * CATCreatePolyMassProperties3DGeoOper(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATBody * iBody); 

/**
 * @nodoc @nocgmitf (do not create any interface)
 * Creates a CATGMPolyMassProperties3DGeoOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iConfig
 * The pointer to the software configuration.
 * If the software configuration is <tt>NULL</tt>, the best version of the code is used. 
 * @param iFace
 * The pointer to the face requiring computations.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBasicOper CATGMPolyMassProperties3DGeoOper * CATCreatePolyMassProperties3DGeoOper(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATFace * iFace); 

/**
 * @nodoc @nocgmitf (do not create any interface)
 * Creates a CATGMPolyMassProperties3DGeoOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iConfig
 * The pointer to the software configuration.
 * If the software configuration is <tt>NULL</tt>, the best version of the code is used. 
 * @param iEdge
 * The pointer to the edge requiring computations.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBasicOper CATGMPolyMassProperties3DGeoOper * CATCreatePolyMassProperties3DGeoOper(CATGeoFactory * iFactory, CATSoftwareConfiguration * iConfig, CATEdge * iEdge); 


#endif
