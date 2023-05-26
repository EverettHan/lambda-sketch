#ifndef IVISSGCELL_H
#define IVISSGCELL_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSGObject.h"
#include "VisSceneGraph.h"
#include "VisDataType.h"
extern ExportedByVisSceneGraph IID IID_IVisSGCell;


/** 
* Interface for adjacency navigation over the cells of a body.
* <b>Role</b>: This interface provides methods to retrieve adjacent cells of a body cell.
*/
interface ExportedByVisSceneGraph IVisSGCell : public IVisSGObject
{
public:

  /**
  * Call this method to retrieve the cell dimension.
  * @return
  *   <dl>
  *   <dt><tt>0</tt>          <dd>If the cell is a vertex
  *   <dt><tt>1</tt>          <dd>If the cell is an edge
  *   <dt><tt>2</tt>          <dd>If the cell is a face
  *   </dl>
  */
  virtual unsigned int GetDimension() = 0;

  /**
  * Call this method to retrieve the cell identifier.
  * @param iType
  *   The type in which the identifier value has to be retrieved.
  *       <br><b>legal values</b>:<br>
  *       VIS_UNSIGNED_INT : the identifier will be returned as a 32 bits unsigned integer
  * @param oValue
  *   The retrieved identifier value.
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the identifier has been successfully retrieved
  *   <dt><tt>E_INVALIDARG</tt>  <dd>If the identifier can't be converted into the desired form
  *   <dt>Other                  <dd>If the identifier can't be retrieved for any other reason.
  *   </dl>
  */
  virtual HRESULT GetIdentifier(const VisDataType iType, void *oValue) = 0;
  /**
  * Call this method to start an iteration on all cells bounded by to this cell.
  * @param ioContext
  *   The iteration context.
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully started
  *   <dt>Other                  <dd>If the iteration can't be executed.
  *   </dl>
  */
  virtual HRESULT StartIterationOnBoundedCells(IVisSGIterationContext& ioContext) = 0;

  /**
  * Call this method to retrieve the next cell bounded by this cell.
  * @param ioContext
  *   The iteration context.
  * @param opCell
  *   The address where the returned pointer to the bounded cell is located.
  *   An AddRef is performed on the returned pointer
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully retrieved the next child node
  *   <dt>Other                  <dd>If the iteration failed for any reason.
  *   </dl>
  */
  virtual HRESULT GetNextBoundedCell(IVisSGIterationContext& ioContext, IVisSGCell* & opCell) = 0;

  /**
  * Call this method to end the previously started iteration on all cells bounded by this cell.
  * @param ioContext
  *   The iteration context.
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully ended
  *   <dt>Other                  <dd>If the iteration has not successfully ended.
  *   </dl>
  */
  virtual HRESULT EndIterationOnBoundedCells(IVisSGIterationContext& ioContext) = 0;

  /**
  * Call this method to start an iteration on all cells bounding this cell.
  * @param ioContext
  *   The iteration context.
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully started
  *   <dt>Other                  <dd>If the iteration can't be executed.
  *   </dl>
  */
  virtual HRESULT StartIterationOnBoundingCells(IVisSGIterationContext& ioContext) = 0;

  /**
  * Call this method to retrieve the next cell bounding this cell.
  * @param ioContext
  *   The iteration context.
  * @param opCell
  *   The address where the returned pointer to the bounding cell is located.
  *   An AddRef is performed on the returned pointer
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully retrieved the next child node
  *   <dt>Other                  <dd>If the iteration failed for any reason.
  *   </dl>
  */
  virtual HRESULT GetNextBoundingCell(IVisSGIterationContext& ioContext, IVisSGCell* & opCell) = 0;

  /**
  * Call this method to end the previously started iteration on all cells bounding this cell.
  * @param ioContext
  *   The iteration context.
  * @return
  *   <dl>
  *   <dt><tt>S_OK</tt>          <dd>If the iteration has successfully ended
  *   <dt>Other                  <dd>If the iteration has not successfully ended.
  *   </dl>
  */
  virtual HRESULT EndIterationOnBoundingCells(IVisSGIterationContext& ioContext) = 0;
};

#endif
