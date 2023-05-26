/* -*-C++-*- */

#ifndef CATCVMGeoCellNavigator_H
#define CATCVMGeoCellNavigator_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoCellNavigator
//
// class for Collaborative Variational Modelling (CVM) RelationManager operator
//
// Operator made to find neighbours cells of a given list of cells
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Aug. 2006    Creation                         AAD
// Jan. 2007    Comments to make this code industrial  PKC 
// Jan. 2007    NaturalNeighbourMode                   PKC
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMSysOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"
#include "CATListOfInt.h"
#include "ListPOfCATCell.h"
#include "CATCGMHashTableWithAssoc.h"
#include "CATCGMNewArray.h"

class CATCVMContainer;
class CATBody;
class CATCell;
class CATGeometry;
class CATCVMBody;

class ExportedByCATCVMGeoOperators CATCVMGeoCellNavigator : public CATCVMSysOperator
{
public:
  static CATCVMGeoCellNavigator *Create(CATCVMContainer *iContainer);
  virtual ~CATCVMGeoCellNavigator();
  
  //------------------------------------------------------------------------------
  // Pool allocation
  //------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare;

  // Method that provide input list of Cells to the operator
  // Operator will look for neighbour cells of iCells
  void SetCells(ListPOfCATCVMGeometry & iCells);

  //
  // Set Options methods :
  //
  void SetReverseLinkActivation();
  // Method that provide input list of allowed Cells to the operator
  // Operator will look for neighbour cells of iCells if included in iAllowedCellsForPropagation
  // iCells may be included even partially into iAllowedCellsForPropagation 
  void SetAllowedCellsForPropagation(const ListPOfCATCVMGeometry & iAllowedCells);
 
  // Provide list input index list of Cells to the operator
  // index is provided regarding iAllowedCells given to the method SetAllowedCellsForPropagation
  void SetCellIndexList (const CATListOfInt & iCellIndex);

  // NOT IMPLEMENTED: currently, depth == 1

  void SetDepth(int iDepth, CATBoolean iUpToDepth = TRUE);

  // Progatation will be done from input Cells until no new neighbour cell is found regarding other operans
  void SetNoDepthLimit();
  
  // Method that sets _Dimension
  // The operator will look only for neighbour cells of asked dimension
  // if iDimension is set to -1 The operator will look for cells of any dimension
  // by default (if this method is not called) _Dimension is set to -1
  void SetDimension(int iDimension);

  // Method that sets _AcceptLowerDimensions
  // The operator will look for neighbour cells of asked dimension, i.e. _Dimension, or less
  // if _Dimension is set to -1 this method has no effect
  // by default (if this method is not called) _AcceptLowerDimensions is set to FALSE
  void SetAcceptLowerDimensions(CATBoolean iAcceptLowerDimensions);

  // Method that sets _BooleanMode
  // if iBooleanMode is set to FALSE : list of neighbours provided by GetResult is Union of neighbour Cells lists
  //                                   found for every input Cells
  // if iBooleanMode is set to TRUE : list of neighbours provided by GetResult is Intersection of neighbour Cells lists
  //                                  found for every input Cells
  // by Default (if this method is not called) _BooleanMode is set to FALSE
  void SetBooleanMode(CATBoolean iBooleanMode);

  // Neighbourhood depth will be computed according to a view closer to user,
  // ie 2 cells are considered as neigbour if they are adjacent or if the are adjacent to a common vertex
  // Operator is asked to look for neighbour up to _Depth (set by SetDepth) and to fill a list of depth corresponding to the list of neighbours found
  void SetNaturalNeighbourMode();

  //
  // Run method of the operator
  //
  void Run();

  //
  // Get results methods
  //

  // Provide list of neighbour cells built according to _BooleanMode option
  // GetResult must be called after Run
  void GetResult(ListPOfCATCVMGeometry & oNeighbours);
  
  // Provide list of neighbour cells built according to _BooleanMode option
  // GetResultIndexList must be called after Run
  void GetResultIndexList (CATListOfInt & oAllowedCellIndex);


  // Provide list of depth corresponding to the result list of Neighbours
  // !!! at present only filled if NaturalNeighbourMode option is set!
  void GetDepthResult(CATListOfInt & oNaturalNeighboursDepth);

protected:
  CATCVMGeoCellNavigator(CATCVMContainer *iContainer);

private:
  CATCVMGeoCellNavigator();
  CATCVMGeoCellNavigator(const CATCVMGeoCellNavigator &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMGeoCellNavigator &);

  //------------------------------------------------------------------------------
  void RunCell    (CATCell * iCGMCell, ListPOfCATCell & oCGMCellNeighbours, int iDepth );
  
  void RunNaturalNeighbour();
  void FindNaturalNeighbours(int iDepth, const ListPOfCATCell &iCGMCells);

  //------------------------------------------------------------------------------
  // liens remontants
  //------------------------------------------------------------------------------
  CATCVMGeometry * ReadCVMGeometryLink  (CATGeometry* iCGMGeometry ,  int &oAllowedPos );
  void             SetCVMGeometryLink   (CATGeometry* iCGMGeometry, CATCVMGeometry *iCVMGeometry ,int &iAllowedPos);
  void             DeleteCVMGeometryLink(ListPOfCATCell &iCGMCellList);
  void             InitCVMGeometryLink  ();
  
  //------------------------------------------------------------------------------
  // private Data :
  //------------------------------------------------------------------------------
  ListPOfCATCVMGeometry  _CVMCells;                    // Input list of CVM Cells
  ListPOfCATCell         _CGMCells;                    // CGMCells for Input CVM Cells
  ListPOfCATCell         _CGMNeighbours;               // list of neighbour CGM cells found 
  ListPOfCATCVMGeometry  _CVMCellsForPropagationInput; // list of allowed neighbour CVM cells  
  ListPOfCATCVMGeometry  _CVMCellsForPropagation;      // working list of allowed neighbour CVM cells  
  ListPOfCATCell         _CGMCellsForPropagation;      // list of neighbour CGM cells found 
  
  CATListOfInt           _AllowedCellIndexList;
  CATListOfInt           _NaturalNeighboursDepth;

  CATBody    * _CGMBody;
  CATCVMBody * _CVMBody;
  CATCVMBody * _CVMBodyActivated;
  
  CATCGMHashTableWithAssoc * _CGMNeighboursHashTab;
  
  int          _Depth;
  int          _Dimension;
  int          _ReverseLinkActivation;
  
  CATBoolean   _UpToDepth;
  CATBoolean   _NoDepthLimit;
  CATBoolean   _AcceptLowerDimensions;
  CATBoolean   _BooleanMode;            //0: Union; 1: Intersect
  CATBoolean   _NaturalNeighbourMode;   // PKC
};
#endif
