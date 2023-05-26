/* -*-C++-*- */

#ifndef CATCVMAtomPath_H
#define CATCVMAtomPath_H

// COPYRIGHT DASSAULT SYSTEMES 2008

//===================================================================
//===================================================================
//
// CATCVMAtomPath
//
// class for Collaborative Variational Modelling (CVM) atom paths
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Jun. 2008    Creation                         Alex State
//===================================================================
#include "CATCVMGeoObjects.h"
#include "CATBaseUnknown.h"
#include "CATCGMNewArray.h"

class CATCVMAtom;
class CATCVMInstancePath;
class CATCVMGeometry;

class ExportedByCATCVMGeoObjects CATCVMAtomPath : public CATBaseUnknown
{
  //------------------------------------------------------------------------------
  // Component declaration
  //------------------------------------------------------------------------------
  CATDeclareClass;

  //------------------------------------------------------------------------------
  // Create
  //------------------------------------------------------------------------------
  public:
  static CATCVMAtomPath *Create(CATCVMInstancePath *iInstancePath,
                                CATCVMAtom         *iAtom);

  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  protected:
  CATCVMAtomPath(CATCVMInstancePath *iInstancePath,
                 CATCVMAtom         *iAtom);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMAtomPath();

  //------------------------------------------------------------------------------
  // Get Atom
  //------------------------------------------------------------------------------
  public:
  CATCVMGeometry *GetGeometry();

  //------------------------------------------------------------------------------
  // Get InstancePath
  //------------------------------------------------------------------------------
  public:
  CATCVMInstancePath *GetInstancePath();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATCVMAtom         *_Atom;
  CATCVMInstancePath *_InstancePath;
};
#endif
