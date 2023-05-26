#ifndef CATHybBoolean_h
#define CATHybBoolean_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/ 

#include "CATHybOperatorImp.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"
#include "ListPOfCATBody.h"
#include "BOHYBOPELight.h"
#include "CATIAV5Level.h"

class CATSmartBodyDuplicator;
class CATTopOpInError;


class CATExtHybBoolean;

/**
* Class defining the operator that performs Boolean operations on two bodies.
*<br>
* This operator operates on the 2D (CATShell), 1D (CATWire) and 0D (CATVertexInVolume)
* domains of a CATBody.
* It follows the general frame of all operators and satisfies the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li><tt>CATHybBoolean</tt> is created with the <tt>CATCreateTopTrim</tt> or <tt>CATCreateTopSplit</tt> global functions.
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopSplit , CATCreateTopTrim
*/
class ExportedByBOHYBOPELight CATHybBoolean : public CATHybOperatorImp
{

  CATCGMVirtualDeclareClass(CATHybBoolean);
protected:
   
   /** @nodoc */
   CATHybBoolean(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybBoolean* iExtensible);

public :
   
   //  Destructor
   ~CATHybBoolean();     
   
  /** 
  * @nodoc
  * Removes an input body from the container (for example the cutting body in a split operation).
  * @param iRemoveBody
  * The body to be removed.
  */
   void SetRemoveBody(CATBody* iRemoveBody);
   
  /** 
  * @nodoc
  */
   void SetErrorBody(CATBody* iErrorBody);
   
  /**
  * @nodoc
  * Extrapolates the intersection on the first element.
  * @param yes_or_no
  * <ul>
  * <li>0: no extrapolation mode 
  * <li>1: extrapolation mode is activated.
  * </ul>
  */
   void SetExtrapolMode(int yes_or_no=1);
  /** 
  * @nodoc
  * Retrieves the extrapolation mode.
  * @return
  * <ul>
  * <li>0: no extrapolation mode 
  * <li>1: extrapolation mode is activated.
  * </ul>
  */
   int  GetExtrapolMode() const;
   
  /** 
  * Returns the number of ambiguous cells.
  * In some cases, the operator is unable to detect which cells
  * have to be removed. The operation completes, but the generated
  * body generally contains all the input cells. 
  * When there are ambiguous cells, the application must specify which
  * cells are to be kept or removed by using the <tt>SetSelectedCells</tt> methods.
  * @return
  * The number of ambiguous cells.
  */
   int  GetNbAmbiguousCells() const;
  /**
  * Returns the list of ambiguous cells.
  * In some cases, the operator is unable to detect which cells
  * have to be removed. The operation completes, but the generated
  * body generally contains all the input cells. 
  * When there are ambiguous cells, the application must specify which
  * cells are to be kept or removed by using the <tt>SetSelectedCells</tt> methods.
  * @param oListOfCells
  * The list of ambiguous cells.
  * @return
  * The number of ambiguous cells.
  */
   int  GetAmbiguousCells(ListPOfCATCell& oListOfCells) const;
  /** 
  * Returns the number of overlapping cells.
  * In some cases, the operator is unable to detect which cells
  * have to be removed. The operation completes, but the generated
  * body generally contains all the input cells. 
  * When there are overlapping cells, the application must specify which
  * cells are to be kept or removed by using the <tt>SetSelectedCells</tt> methods.
  * @return
  * The number of overlapping cells.
  */
   int  GetNbConfusionCells() const;
  /**
  * Returns the list of overlapping cells.
  * In some cases, the operator is unable to detect which cells
  * have to be removed. The operation completes, but the generated
  * body generally contains all the input cells. 
  * When there are overlapping cells, the application must specify which
  * cells are to be kept or removed by using the <tt>SetSelectedCells</tt> methods.
  * @param oListOfCells
  * The list of overlapping cells.
  * @return
  * The number of overlapping cells.
  */
   int  GetConfusionCells(ListPOfCATCell& oListOfCells) const;
     
   // Analyze result according Tangent Design
 /** 
  * (De)activates the detection of cells which are tangent to each other.
  * The tangent cells are retrieved by using the <tt>GetTangentDesignCells</tt> method.
  * <pre>
  * pIntersectOpe->SetWarningOnTangentDesign(1);
  * ...
  * pIntersectOpe->Run(); 
  * CATBody *pBody =  pIntersectOpe->GetResult();
  * if  (pIntersectOpe->IsResultTangentDesign())  
  *	{  
  *	  ListPOfCATCell  ListOfCells;  
  *	  pIntersectOpe->GetTangentDesignCells(ListOfCells); 
  *   ...
  * }
  * </pre>
  * @param yes_or_no
  * <ul>
  * <li>0: deactivates the "tangent design" mode
  * <li>1: activates the "tangent design" mode.
  * </ul>
  */
   void  SetWarningOnTangentDesign(int yes_or_no=1);
  /** 
  * Retrieves the tangent design mode.
  * @return
  * <ul>
  * <li>0: the "tangent design" mode is not activated
  * <li>1: the "tangent design" mode is activated.
  * </ul>
  */
   int  GetTangentDesignMode() const;
  /** 
  * Retrieves the result of the tangent design analysis.
  * @return 
  * <ul>
  * <li>0: no tangent cells have been detected
  * <li>1: tangent cells have been detected.
  * </ul>
  */
   int  IsResultTangentDesign() const;
  /** 
  * Retrieves the list of tangent cells.
  * <pre>
  * pIntersectOpe->SetWarningOnTangentDesign(1);
  * ...
  * pIntersectOpe->Run(); 
  * CATBody *pBody =  pIntersectOpe->GetResult();
  * if  (pIntersectOpe->IsResultTangentDesign())  
  *	{  
  *	  ListPOfCATCell  ListOfCells;  
  *	  pIntersectOpe->GetTangentDesignCells(ListOfCells); 
  *   ...
  * }
  * </pre>
  * @param oListOfCells
  * The list of tangent cells.
  * @return
  * <ul>
  * <li>0: no tangent cells have been detected
  * <li>1: tangent cells have been detected.
  * </ul>
  */
   int  GetTangentDesignCells(ListPOfCATCell& oListOfCells) const;
   

/**
* Specifies the cells to be kept and the cells to be removed in the operation.
* At least one of the lists must be filled in. 
* The operator throws an exception when: 
* <ul>
*    <li>both lists are empty
*    <li>the specified cells do not belong to the input bodies
*    <li>some cells to be cut are specified in either list. 
*    A cell to be cut should not be added to any list
*    <li>the list contents is not consistent with respect to the sides definition. 
*    For example,  if a cell to be removed and a cell to be 
*    kept should not be located on the same side.
* </ul>
* More generally, the operator throws when the lists which are specified do not allow the operator to
* compute in an unambiguous way the pieces to be kept or removed.
* @param iCellsToRemove
* The list of cells to be removed.
* @param iCellsToKeep
* The list of cells to be kept.
*/
   void SetSelectedCells (CATLISTP(CATCell) & iCellsToRemove, 
                          CATLISTP(CATCell) & iCellsToKeep);
   
  /**
  * When the cells specified in the SetSelectedCells method do not
  * belong to the input bodies, the boolean operation cannot complete.
  * When the cells specified in the SetSelectedCells methods are vertices,
  * you can use <tt>SetSelectedCellsByLayDownMode</tt> to define the side to be kept or removed.
  * If the vertices are not ON the cells to be kept or removed, the operator
  * projects them onto the cells to be kept or removed. 
  * This method applies to vertices only.
  * By default (0), the cells are assumed to belong to the input bodies
  * and are not "laid down" (projected).
  * @param yes_or_no
  * <ul>
  * <li>0: the "lay down" mode is not activated
  * <li>1: the "lay down" mode is activated.
  * </ul>
  */
   void SetSelectedCellsByLayDownMode(int yes_or_no=1);
  /** 
  * Returns the number of cells kept or removed by using the SetSelectedCellsByLayDownMode method.
  * <pre>
  * CATHybSplit*  pSplitOpe =  CATCreateTopSplitShellWithKeepRemove(piGeomFactory,&topdata,ToBeSplit,SplittingBody);   
  * pSplitOpe->SetSelectedCellsByLayDownMode(1);  
  * CATLISTP(CATCell) cellsToRemove ;
  * CATLISTP(CATCell) cellsToKeep ;
  * cellsToKeep.Append(listOfVertex[1]);
  * pSplitOpe->SetSelectedCells(cellsToRemove,cellsToKeep); 
  * pSplitOpe  ->  Run();  
  *	int nbCells = pSplitOpe->GetSelectedCellsByLayDownMode();
  * </pre>
  * @return
  * Number of cells kept or removed.
  */
   int  GetSelectedCellsByLayDownMode() const;

   // treatment with Wire Positionning (to use before run)
  /** 
  * @nodoc 
  */
   void SetWirePositionningMode(int yes_or_no=1);
  /** 
  * @nodoc 
  */
   int  GetWirePositionningMode() const;

  /** 
  * @nodoc 
  * INTERNAL USE ONLY.
  * USED TO EXTEND THE BEHAVIOUR OF CATHybBoolean.h
  */
   inline CATExtHybBoolean* GetHybBooleanExtensible() const;
   
};

/** @nodoc  */
inline CATExtHybBoolean* CATHybBoolean::GetHybBooleanExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybBoolean*) _Extensible;
}

#endif
