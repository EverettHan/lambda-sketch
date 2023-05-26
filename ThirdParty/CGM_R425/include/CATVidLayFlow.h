// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidLayFlow.h
// Header definition of CATVidLayFlow
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidLayFlow_H
#define CATVidLayFlow_H

#include <VisuDialog.h>
#include <CATVidLayCollection.h>
#include <CATMathPoint2Df.h>
#include <CATVidLayConstraints.h>
#include <CATVidEnum.h>

//-----------------------------------------------------------------------
/**
* A flow is a simple way to position widgets. 
* If possible, the widgets are disposed in a horizontal line. 
* When resized, the flow layout re-position the widgets in a grid 
* 
* @par In CAPSYPStyle files
* @code
* <CATVidLayFlow ...........>
*   <MyWidgetA .........../>
*   <MyWidgetB .........../>
*   ....
* </CATVidLayFlow>
*
* @see CATVidLayCollection
* @see CATISYPCollection
* @ingroup VIDLayout
*/
class ExportedByVisuDialog CATVidLayFlowConstraints: public CATVidLayConstraints
{
  CATDeclareClass;
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidLayFlowConstraints() {};
  virtual ~CATVidLayFlowConstraints() {};

  virtual CATVidLayConstraints* Clone() const {return new CATVidLayFlowConstraints();}; 

  /**
   * Copy the given constraints values.
   */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints);
};


class ExportedByVisuDialog CATVidLayFlow: public CATVidLayCollection
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATVidLayFlow ();
  CATVidLayFlow (CATCommand *i_pParent, const CATString & i_pIdentifier);

  // Set/Get cell dimension
  //-----------------------
  void SetCellDimension(const CATMathPoint2Df& i_cellDimension);
  const CATMathPoint2Df& GetCellDimension() const;

  // Set/Get cell spacing (space inter-cells)
  //-----------------------------------------
  void SetCellSpacing(int i_cellSpacing);
  unsigned int  GetCellSpacing() const;

  void SetComputedCellDimensionFlag(CATBoolean i_computedCellDimensionFlag);
  CATBoolean  GetComputedCellDimensionFlag() const;

  void SetUniformCellSizesFlag(CATBoolean i_uniformCellSizesFlag);
  CATBoolean GetUniformCellSizesFlag();

  // Set/Get align parameter
  //------------------------
  void SetAlign(unsigned int i_align); // align parameter 0:left, 1:right, 2:center
  unsigned int  GetAlign() const;  
  
  void SetStretchContentFlag(CATBoolean i_stretchContentFlag);
  CATBoolean GetStretchContentFlag() const { return _stretchContentFlag;}

  // Set/Get orientation parameter
  //------------------------
  void SetOrientation(CATVidFlowOrientation i_orientation);
  CATVidFlowOrientation GetOrientation() const;

	/**
	* Set Inverse orientation flag that changes children display order
	*/
  void SetInvertFlowDirectionFlag(CATBoolean i_invertFlowDirectionFlag);
  CATBoolean GetInvertFlowDirectionFlag() const;

protected:
  virtual ~CATVidLayFlow ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidLayFlow (CATVidLayFlow &);
  CATVidLayFlow& operator=(CATVidLayFlow&);

  int ComputeNbColumns(const CATMathPoint2Df& i_cellDimension, const CATMathPoint2Df& i_dimension);
  int ComputeNbRows(const CATMathPoint2Df& i_cellDimension, const CATMathPoint2Df& i_dimension);
  CATMathPoint2Df ComputePosition(const CATMathPoint2Df& i_cellDimension, unsigned int i_column, unsigned int i_row, unsigned int i_nbMaxElements, unsigned int i_nbElements);

  virtual void Layout();
  virtual void UpdateComputedMinimumDimension();
  virtual CATVidLayConstraints* CreateConstraints();
  virtual CATMathPoint2Df GetMaximumCellDimension() const;

  unsigned int GetNbColumns() {return _nbColumns;};
  void SetNbColumns(unsigned int i_nb) {_nbColumns = i_nb;};
  unsigned int GetNbRows() {return _nbRows;};
  void SetNbRows(unsigned int i_nb) {_nbRows = i_nb;};

private:
  CATMathPoint2Df GetComputedMaximumCellDimension() const;

	/**
	* get flow maximum dimension; i.e return dimension while all children are placed vertically and 
	* dimension if all children are placed horizontally. 
	* @see TryFitDimension
  * @see SetInvertFlowDirectionFlag
	*/
	CATMathPoint2Df GetOrientationMinimumDimension() const;

  //void UpdateComputedMinimumDimension_DifferentItemSizes();
  //void UpdateComputedMinimumDimension_UniformItemSizes();
  void Layout_DifferentItemSizes();

	int TryFitDimension(unsigned int i_w, unsigned int i_h, unsigned int& o_x, unsigned int& o_y);
	int ComputeInvertFlowDirectionMinimumDimension(unsigned int &o_x, unsigned int &o_y);

private:
  CATMathPoint2Df _forcedCellDimension;
  unsigned int _cellSpacing;
  unsigned int _align;
  unsigned int _nbColumns;
  unsigned int _nbRows;
  CATVidFlowOrientation _orientation;
  CATBoolean _computedCellDimensionFlag;
  CATBoolean _uniformCellSizesFlag;
	CATBoolean _invertFlowDirectionFlag;
  CATBoolean _stretchContentFlag;

  friend class CATVidTstLayFlowTestLayoutNotUniformCellSizes;
};

//-----------------------------------------------------------------------

#endif