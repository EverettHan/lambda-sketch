/* -*-C++-*-*/
#ifndef CATGMPolyBodyAdapter_H
#define CATGMPolyBodyAdapter_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyBodyAdapter 
//
// DESCRIPTION :
// Export a CATGMPolyBody into a standalone PolyBody with its own geometry (not an adapter)
//
//
// History
//
// March. 2015 DPS Creation
// March  2019 DPS Rearchitecture, hide the implementation in the derived class CATGMPolyBodyPrivateAdapter
// April  2019 DPS Rearchitecture, make this class derive from the new interface CATPGMPolyBodyAdapter
//
//=============================================================================

// For Windows NT export
#include "CATPGMPolyBodyAdapter.h" // derivation
#include "GMPolyImportExport.h"    // ExportedBy
#include "CATErrorDef.h"           // HRESULT
#include "CATTopDefine.h"          // CATOrientation
#include "CATMathInline.h"         // inline Methods

#include "CATBoolean.h" 
#include "CATSysBoolean.h" 

class CATSoftwareConfiguration;
class CATMathTransformation;
class CATMapOfPtrToPtr;
class CATPolyBody;
class CATPolyCell;
class CATPolyVolume;
class CATPolyFace;
class CATPolyEdge;
class CATPolyVertex;
class CATBody;
class CATDomain;
class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;
class CATCell;

class CATGMPolyBodyPrivateAdapter;
class CATGMPolyBodyPrivateAdapterIterator;

class ExportedByGMPolyImportExport CATGMPolyBodyAdapter : public CATPGMPolyBodyAdapter
{
public:

  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyAdapter();


  //=============================================================================
  // Settings
  //=============================================================================
   
  // Please, note here that the convention of matter side for a CATShell bounding a CATVolume is INWARD,
  // opposite to the PolyBody convention  which is always OUTWARD.
  // So, importing a volumic set of PolyFaces obviously leads to reverse the global side of the imported CATDomain.
  // The default behavior in case of surfacic set of faces consists in reversing the original sides as if the domain was volumic.
  // The following option allows the user to keep (Positive) or not (Negative) the global orientation of surfacic shells only.
  virtual void SetMeshOrientationVsSurfacicShell(CATOrientation iOriMeshVsShell) = 0;

  virtual void SetMatrixPosition(CATMathTransformation * iMatrix) = 0;

  virtual void ForceDuplicationMode() = 0;

  virtual void EnableCanonicityTransfer() = 0;

  virtual void EnablePolyVolumeMode() = 0;


  //=============================================================================
  // Computation
  //=============================================================================
  /**
  * Compute the PolyBody from the input polyhedral CATBody 
  * if the Check is required, the PolyBody result will be returned only if it's valid
  * PLEASE NOTE THAT THE CALLER HAS TO RELEASE THE RETURNED oResultBody AFTER USE !!!
  */
  virtual HRESULT Run(CATPolyBody * &oResultPolyBody, CATBoolean iCheckResult=FALSE) = 0;


  //=============================================================================
  // Journaling
  //=============================================================================

  virtual CATPolyVertex * GetImage(CATVertex & iGMVtx) = 0;
  virtual CATPolyEdge   * GetImage(CATEdge   & iGMEdge, CATOrientation * oOriVsSource=NULL) = 0;
  virtual CATPolyFace   * GetImage(CATFace   & iGMFace, CATOrientation * oOriVsSource=NULL) = 0;
  virtual CATPolyVolume * GetImage(CATVolume & iGMVolume) = 0;

  /**
  * Get the map of equivalent image cell for each source cell
  * iDim allows the caller to filter according to a specific dimension :
  * -1 to get all cells (default), 0 to get only vertices, 1 to get only edges, 2 to get only faces, 3 to get only volumes
  */
  virtual HRESULT GetMapOfGMCellToPolyCell(CATMapOfPtrToPtr & oMap, int iDim=-1) = 0;

  /**
  * Get the map of equivalent source cell for each image cell
  * iDim allows the caller to filter according to a specific dimension :
  * -1 to get all cells (default), 0 to get only vertices, 1 to get only edges, 2 to get only faces, , 3 to get only volumes
  */
  virtual HRESULT GetMapOfPolyCellToGMCell(CATMapOfPtrToPtr & oMap, int iDim=-1) = 0;


protected :

  // Private only, use CATCreate functions instead
  CATGMPolyBodyAdapter();


private:


  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyAdapter(const CATGMPolyBodyAdapter & iOneOf); 
  CATGMPolyBodyAdapter & operator =(const CATGMPolyBodyAdapter & iOneOf);

};

/**
* Creates a CATGMPolyBodyAdapter.
* @param iGMPolyBody
* The input polyhedral CATBody to adapt into a CATPolyBody
* @param iSoftwareConfig
* The pointer to the SoftwareConfiguration in order to drive the versionning of future modifications
* If iSoftwareConfig is NULL, default config 10313 will be used (versioning value of V5R32 SP2 / V6R424 FD03)
* @return [out]
* The pointer to the created operator. To be deleted after use.
*/
ExportedByGMPolyImportExport CATGMPolyBodyAdapter * CATCreateGMPolyBodyAdapter(CATBody * iGMPolyBody, CATSoftwareConfiguration * iSoftwareConfig=NULL); 

/**
* @nodoc @nocgmitf (do not create any specific interface)
* Creates a CATGMPolyBodyAdapter.
* @param iGMPolyDomain
* The input polyhedral CATDomain to adapt into a CATPolyBody
* @param iSoftwareConfig
* The pointer to the SoftwareConfiguration in order to drive the versionning of future modifications
* If iSoftwareConfig is NULL, default config 10313 will be used (versioning value of V5R32 SP2 / V6R424 FD03)
* @return [out]
* The pointer to the created operator. To be deleted after use.
*/
ExportedByGMPolyImportExport CATGMPolyBodyAdapter * CATCreateGMPolyBodyAdapter(CATDomain * iGMPolyDomain, CATSoftwareConfiguration * iSoftwareConfig=NULL);

#endif
