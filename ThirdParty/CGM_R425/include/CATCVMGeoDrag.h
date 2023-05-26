/* -*-C++-*- */

#ifndef CATCVMGeoDrag_H
#define CATCVMGeoDrag_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoDrag
//
//===================================================================


//===================================================================
// Example of use:
// CATCVMGeoDrag * Drag = Create(Container, TopData);
// Drag->SetCells(Cells, Bodies);//To be done only once 
// while (InCommand)
// {
//   Drag->Run();//At the first call to Run() there is no transformation set: it must be done just to retrieve the DoF
//               //At the next calls to Run(), transformation is applied
//   CATCVMDoF * DoF = Drag->GetDoF();
//   CATMathTransformation Transformation = ... // Get transformation as UI input, by taking into account the DoF
//   Drag->SetTransformation(CATMathTransformation &iTransformation);
// }
//===================================================================


// On debranche toutes les methodes utilisees pour le snapping


//===================================================================
// June 2006    Creation                         ASE
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"
#include "ListPOfCATCVMBody.h"
#include "ListPOfCATCVMInstancePath.h"
#include "CATListOfDouble.h"

class CATCVMGeoContainer;
class CATCVMGeometry;
class CATMathTransformation;
class CATCVMBody;
class CATCVMDoF;
class CATCVMDoFImp;
class CATMathPoint;
class CATCVMInstancePath;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoDrag : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a drag operator
  //------------------------------------------------------------------------------
public:
  static CATCVMGeoDrag* Create(CATCVMGeoContainer *iCVMGeoContainer, CATTopData *iTopData);
  static CATCVMGeoDrag* Create(CATCVMInstancePath *iCVMInstancePath, CATTopData *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
protected:
  CATCVMGeoDrag(CATCVMGeoContainer *iCVMGeoContainer, CATTopData  *iTopData, CATCVMGeoOperatorExt *iExtensible);
  CATCVMGeoDrag(CATTopData  *iTopData, CATCVMGeoOperatorExt *iExtensible);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
public:
  virtual ~CATCVMGeoDrag();

  //------------------------------------------------------------------------------
  // Specifies the cells in iCells and the cells in each body of iBodies 
  // as the cells to drag. All these cells are considered as a rigid group in all 
  // calls to GetDoF() and to Run().
  // This method must be called only once, before the first call to GetDoF() or Run(). 
  // If iBoundaryOption is set to TRUE, the Boundary Cells of input cells will be added
  // in the list of the dragged cells
  //------------------------------------------------------------------------------
public:
  virtual void SetCells(ListPOfCATCVMGeometry & iCells, 
                        ListPOfCATCVMBody & iBodies, 
                        CATBoolean iBoundaryOption=FALSE);

  virtual void SetObjects(ListPOfCATCVMObject & iObjectList, CATBoolean iBoundaryOption=FALSE);


  //------------------------------------------------------------------------------
  // Specifies the instance path to drag.
  //------------------------------------------------------------------------------
public:
  virtual void SetInstancePath(CATCVMInstancePath * iInstancePath);
  virtual void SetInstancePaths(ListPOfCATCVMInstancePath & iInstancePathList);

  //------------------------------------------------------------------------------
  // Set the transformation to be applied to the cells specified in SetCells() and
  // to bodies defined in SetBodies() 
  // This method must be called once before each Run()
  // iDeltaParameter is the Translation 1D that should be applied to the paramter of moved object
  // example : for a circle this represents the change of Radius value
  // note : 
  //   1. iDeltaParameter is taken into account only in case of a single moved object
  //   2. Not null iDeltaParameter and not identical transformation set together are not 
  //      supported yet    
  //------------------------------------------------------------------------------
public:
  virtual void SetTransformation(CATMathTransformation &iTransformation, double iDeltaParameter=0);
  //-------------------------------------------------------------------------------
  // On transforme l'API pour gérer les tores. 
  // Dans les cas habituels, la liste ne contiendra qu'un élément.
  // Pour le cas du tore, le premier paramètre correspond au rayon majeur et le second au rayon mineur 
  //-------------------------------------------------------------------------------
  virtual void SetTransformation(CATMathTransformation &iTransformation, CATListOfDouble & iListOfDeltaParameter);
  virtual CATMathTransformation GetOutputTransformation();


public:
  virtual void SetDoF(CATCVMDoFImp* iCVMDoF); // kub : for coverage

  // ----------------------------------------------------------------------------
  // Set and get the manipulator point
  //-----------------------------------------------------------------------------
public:
  // CATMathPoint to be set in input of CATCVMGeoDrag
  virtual void SetManipulatorPoint(CATMathPoint& iMathPoint, CATCVMGeometry * iCVMSupportGeometry);
  // updated CATMathPoint to get after the run of CATCVMGeoDrag
  virtual CATMathPoint GetManipulatorPoint();
  CATBoolean AreAllChecksOK();



  //------------------------------------------------------------------------------
  // Get the entire list of CVM cells that are dragged 
  // ( = full list of cells on which User Transformation will be applied ) 
  // This list includes all cells provided by caller to the drag operator 
  // and their boundary cells if iBoundaryOption was set to TRUE during SetCells call.  
  //------------------------------------------------------------------------------
public:
  virtual const ListPOfCATCVMGeometry* GetCellsToDrag();

  //------------------------------------------------------------------------------
  // Set "drag-for-extrude" mode
  //------------------------------------------------------------------------------
public:
  virtual void SetDragForExtrudeMode(CATBoolean iDragForExtrudeMode);

  //------------------------------------------------------------------------------
  // Set snap tolerances (but does not activate it)
  //------------------------------------------------------------------------------
//public:
//  void SetMagnetPrecisions(double iMagnetDistancePrecision, double iMagnetAnglePrecision);

  //------------------------------------------------------------------------------
  // Override list of reference bodies for snapping (default : bodies of dragged cells)
  //------------------------------------------------------------------------------
//public:
//  void SetMagnetBodies(ListPOfCATCVMBody & iListBody);

  //------------------------------------------------------------------------------
  // Activate the snap (deactivated by default)
  //------------------------------------------------------------------------------
//public:
//  void SetMagnet(int iActivate);
//
  //------------------------------------------------------------------------------
  // Return the Degrees Of Freedom of the cells defined in SetCells()
  // The returned object must be deleted by the caller
  //------------------------------------------------------------------------------
public:
  virtual CATCVMDoF * GetDoF();

  //------------------------------------------------------------------------------
  // Return the "Natural" Degrees Of Freedom of the cells defined in SetCells()
  // It is the DOF we want to privileged by guessing users intent thanks to heuristical rules
  // The returned object must be deleted by the caller
  //------------------------------------------------------------------------------
public:
  virtual CATCVMDoF * GetPrivilegedDoF();

  //------------------------------------------------------------------------------
  // CGM Internal Use
  //------------------------------------------------------------------------------
private:
  //virtual int RunOperator();

  //------------------------------------------------------------------------------
  // Returns TRUE if a snapping occurred
  //------------------------------------------------------------------------------
//public:
//  virtual int HasSnapped();

  //------------------------------------------------------------------------------
  // Check collisions
  //------------------------------------------------------------------------------
public:
//  HRESULT CheckCollisions();

  //------------------------------------------------------------------------------
  // Solve collisions
  //------------------------------------------------------------------------------
public:
//  HRESULT SolveCollisions();

public:
  static const CATString *GetDefaultOperatorId();

};
#endif
