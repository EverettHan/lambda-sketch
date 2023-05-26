/* -*-c++-*- */
#ifndef CATExtIVisUVData_H
#define CATExtIVisUVData_H

//
// COPYRIGHT DASSAULT SYSTEMES 2012
//

#include "SceneGraphManager.h"
#include "CATIVisUVData.h"
#include "CATBaseUnknown.h"
   
/**
 *
 * Code Adaptater for implementing the CATIVisUVData interface.
 *
 *
 */

class ExportedBySceneGraphManager CATExtIVisUVData : public CATIVisUVData
{
  // macros
  CATDeclareClass;

public:
	// Constructor
	CATExtIVisUVData (void) ;

	// destructor
	virtual ~CATExtIVisUVData (void) ;

   /** @nodoc */
   // Starting transaction of UV computation of a given Body.
   // Should be called for every body before looping over its faces.
   //
   // Returns E_FAIL if operation cannot be done. S_OK otherwise.
   //
   virtual HRESULT StartTransaction() = 0;

   /** @nodoc */
   // Ending transaction of UV computation of a given Body.
   // Should be called for every body after looping over its faces.
   //
   // Returns E_FAIL if operation cannot be done. S_OK otherwise.
   //
   virtual HRESULT EndTransaction() = 0;

   /** @nodoc */
   // Computes flattening data:
   // iNbVertices     : number of vertices of the mesh of the given face. Size = 1 * INT.
   // iXYZ            : 3d (un-flattened) coordinates of vertices. Size = 3 * oNbVertices. NULL of not filled.
   // oUV             : UV values for vertices, scaled to unit square. Size = 2 * oNbVertices. NULL of not filled.
   // iNormalUnfold[3]: 3D Normal of the plane of flattened skin. Not filled if equal to (0.f,0.f,0.f).
   // piBody          : Input Body. Should not be NULL. If NULL, it is up to the callee to manage this case.
   // piFace          : Input Face of the input Body. Should not be NULL. If NULL, it is up to the callee to manage this case.
   //
   // Returns E_FAIL if operation cannot be done. S_OK otherwise.
   //
   // Life cyle management.
   // It's up to the caller to manage the life cycle of input data and output data.
   // 
   virtual HRESULT ComputeUVData(    
                                 unsigned int   iNbVertices,
                                 float *iXYZ,
                                 float *oUV,
                                 float iNormalUnfold [3],
                                 CATBaseUnknown *piBody,
                                 CATBaseUnknown *piFace) = 0;
								 
								 
								 
								 

private :
  /** @nodoc */
  CATExtIVisUVData& operator=(CATExtIVisUVData& iRef);

  /** @nodoc */
  // Copy constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATExtIVisUVData(const CATExtIVisUVData &iObjectToCopy);

};



#endif

 
