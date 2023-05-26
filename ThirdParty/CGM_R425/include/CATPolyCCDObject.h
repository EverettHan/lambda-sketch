//============================================================================================
// Copyright Dassault Systemes Provence 2018, All Rights Reserved
//============================================================================================
//
// CATPolyCCDObject.h
//
//============================================================================================
//
// Usage notes : Object to be used in the continuous clash detection operator.
//
//============================================================================================
// 15.11.2018 : RAQ : Déplacement dans PolyhedralOperatorsAdv
// 03.10.2018 : RAQ : Creation
//============================================================================================
#ifndef CATPolyCCDObject_H
#define CATPolyCCDObject_H

//Base class
#include "CATPolyRefCounted.h"

//Pour l'export
#include "ExportedByCATPolyContinuousClashDetection.h"

//Misc
#include "CATBoolean.h"

class CATIPolyMesh;
class CATBVHTree;

class ExportedByCATPolyContinuousClashDetection CATPolyCCDObject : public CATPolyRefCounted
{
public:

  //Get ID
  virtual unsigned int GetID() const = 0;

  //Get mesh
  virtual const CATIPolyMesh* GetMesh() const = 0;

  //Check whether this object is a stock part
  virtual CATBoolean IsStockPart() const = 0;
    
  //Check whether this object is disabled
  virtual CATBoolean IsDisabled() const = 0;

  virtual CATBVHTree* GetBVHTree() = 0;

protected:

  CATPolyCCDObject():CATPolyRefCounted() {}
  virtual ~CATPolyCCDObject() {}

private:

  CATPolyCCDObject(const CATPolyCCDObject&);
  CATPolyCCDObject& operator=(const CATPolyCCDObject&);
};


/**
 * Create an object to be used by the dynamic clash detection operator.
 *
 * @param ipPolyMesh
 * The mesh representing the object
 * @param iID
 * The object's identifier
 * @param iIsStockPart
 * TRUE if this part refers to a stock, FALSE otherwise.
 * Will be used later to retreive an updated mesh of this part
 *
 * @return
 * A pointer on the object.
 * It must be deleted with the Release method.
 **/
ExportedByCATPolyContinuousClashDetection
  CATPolyCCDObject* CATCreateCCDObject(CATIPolyMesh* ipPolyMesh, const unsigned int iID,
                                       const CATBoolean iIsStockPart = FALSE);

#endif  //CATPolyCCDObject_H

