/* -*-C++-*-*/
#ifndef CATHLRContainer_H
#define CATHLRContainer_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRContainer 
//
// DESCRIPTION :
/**
 * Object made to handle a list of objects for the HLR. This object is made to
 * be inherited.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
// Mar. 2000 HKL Release des entites V4 sur lesquelles il y a eu BindInterface
// Oct. 2000 TPD Mise en place d'une protection contre une face ou une edge NULL
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

#include "CATListPV.h"

#include "CATCGMRefCounted.h"

class CATHLRGeoTempFactory;
class CATHLRObject;

class CATFace;
class CATEdge;

class ExportedByHLRModele CATHLRContainer : public CATCGMRefCounted
{
public:
  // HLK 02 03 2000
  CATHLRContainer(CATHLRContainer * iContainerObject=NULL);
  
  // HLK 02 03 2000
  ~CATHLRContainer();
  
//=============================================================================
// METHODS
//=============================================================================
  /** Adding an object in the container
  */
  virtual void AddObject(CATHLRObject * iObject) = 0;

  // Ajout d'objets a reeaser au destructeur
  void AddFaceToReleaseOnDelete(CATFace * iData);
  void AddEdgeToReleaseOnDelete(CATEdge * iData);

  //  Release a appeler au destructeur
  void ReleaseV4Objects();

  inline int GiveNewTagForNewHLRObject();


protected:  

  // Faces et aretes V4 sur lesquelles il faut faire un release au destructeur
  CATListPV _V4EdgesToRelease;
  CATListPV _V4FacesToRelease;

  // Gestion d'un Tag unique quel que soit le type d'objet CATHLRxxxEntity, CATHLRxxxFace, CATHLRxxxCurve ...
  unsigned int             _HLRObjectTag;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
// methodes inline
// ---------------
inline int CATHLRContainer::GiveNewTagForNewHLRObject() {
  _HLRObjectTag++; 
  return _HLRObjectTag; }


#endif
