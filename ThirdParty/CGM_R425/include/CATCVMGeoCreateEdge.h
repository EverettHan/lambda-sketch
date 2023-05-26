/* -*-C++-*- */

#ifndef CATCVMGeoCreateEdge_H
#define CATCVMGeoCreateEdge_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoCreateEdge
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June 2006    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"

class CATCVMGeoContainer;
class CATCVMInstancePath;
class CATCVMGeometry;
class CATMathPoint;

class ExportedByCATCVMGeoOperators CATCVMGeoCreateEdge : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a CreateEdge operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoCreateEdge* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                     CATTopData         *iTopData);
  static CATCVMGeoCreateEdge* Create(CATCVMInstancePath *iCVMInstancePath,
                                     CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
  CATCVMGeoCreateEdge(CATCVMGeoContainer   *iCVMGeoContainer,
                      CATTopData           *iTopData,
                      CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoCreateEdge(CATTopData           *iTopData,
                      CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoCreateEdge();

  //------------------------------------------------------------------------------
  // Set the start vertex
  //------------------------------------------------------------------------------
  public:
  virtual void SetStartVertex(CATCVMGeometry *iStartVertex);

  //------------------------------------------------------------------------------
  // Set the end vertex
  //------------------------------------------------------------------------------
  public:
  virtual void SetEndVertex(CATCVMGeometry *iEndVertex);

  //------------------------------------------------------------------------------
  // Set the support face (in order to draw on the face's surface)
  //------------------------------------------------------------------------------
  public:
  virtual void SetSupportFace(CATCVMGeometry *iSupportFace);

  //------------------------------------------------------------------------------
  // Set the preview mode
  //
  // Please note: this option works only when a support face is defined
  //------------------------------------------------------------------------------
  public:
  virtual void SetPreviewMode(CATBoolean iPreviewMode);

  //------------------------------------------------------------------------------
  // Set automatic face creation mode
  //
  // Please note: the list of edges makes it possible to restrict the search
  //              for closed loops
  //------------------------------------------------------------------------------
  public:
  virtual void SetAutomaticFaceCreationMode(CATBoolean             iAutomaticFaceCreationMode,
                                            ListPOfCATCVMGeometry *iEdgeList = NULL);

	//------------------------------------------------------------------------------
  // Set the merge option
	//------------------------------------------------------------------------------
  public:
  virtual void SetMergeOption(CATBoolean iMergeOption);

	//------------------------------------------------------------------------------
  // Get the merge option
	//------------------------------------------------------------------------------
  public:
  virtual CATBoolean GetMergeOption();

  //------------------------------------------------------------------------------
  // Get the created edge - DO NOT USE ANYMORE
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMGeometry *GetCreatedEdge();

  //------------------------------------------------------------------------------
  // Get number of created edges
  //------------------------------------------------------------------------------
  public:
  virtual int GetNbCreatedEdges();

  //------------------------------------------------------------------------------
  // Get a created edge
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMGeometry *GetCreatedEdge(int iIndex);

  //------------------------------------------------------------------------------
  // Get number of created faces
  //------------------------------------------------------------------------------
  public:
  virtual int GetNbCreatedFaces();

  //------------------------------------------------------------------------------
  // Get a created face
  //------------------------------------------------------------------------------
  public:
  virtual CATCVMGeometry *GetCreatedFace(int iIndex);

  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
  //virtual int RunOperator();
   
  public:
  static const CATString *GetDefaultOperatorId();
};
#endif
