#ifndef CATVidMdlAbstractProxy_h
#define CATVidMdlAbstractProxy_h

// COPYRIGHT DASSAULT SYSTEMES 2013

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidMdlAdapter.h>
#include <CATVidMdlIndex.h>
#include <CATSYPArray.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

class CATVidMdlStructureChangedEventArgs;
class CATVidMdlFilterChangedEventArgs;
class CATSYPEventHandler;

/**
 * CATVidMdlAbstractProxy is an adapter class for CATIVidMdl interface.
 * It eases the implementation of proxy models.
 * A proxy model transforms the structure of a source model by mapping the model indexes it supplies to new indexes, 
 * corresponding to different locations, for views to use. This approach allows a given source model to be restructured as far 
 * as views are concerned without requiring any transformations on the underlying data, and without duplicating the data in memory.
 * A proxy model acts as a wrapper for the original model. If you need to convert source CATVidMdlIndex to sorted/filtered model 
 * indexes or vice versa, use the MapToSource() and MapFromSource() methods.
 */
class ExportedByVisuDialog CATVidMdlAbstractProxy : public CATVidMdlAdapter
{
  CATDeclareClass;

public:

  /**
   * Default constructor.
   */
  CATVidMdlAbstractProxy();
  /**
   * Destructor.
   */
  virtual ~CATVidMdlAbstractProxy();

  /**
   * Sets the model used as the source for the proxy model.
   */
  void SetSourceModel(const CATIVidMdl_var & i_sourceModel);

  /**
   * Returns the model used as the source for the proxy model.
   */
  INLINE CATIVidMdl_var GetSourceModel() const {return _sourceModel;};

  /**
   * Reimplement this method to return the index in the source model that 
   * corresponds to the i_proxyIndex in the proxy model.
   */
  virtual CATVidMdlIndex MapToSource(const CATVidMdlIndex& i_proxyIndex) = 0;

  /**
   * Reimplement this method to return the index in the proxy model that 
   * corresponds to the i_sourceIndex in the source model.
   */
  virtual CATVidMdlIndex MapFromSource(const CATVidMdlIndex& i_sourceIndex) = 0;

  // Partial implementation of the CATIVidMdl interface
  virtual CATBaseUnknown_var GetElement(const CATVidMdlIndex & i_index);
  virtual CATVidMdlIndex GetRoot(int i_Column = 0);
  virtual CATBoolean _IsEqual(const CATVidMdlIndex & i_left, const CATVidMdlIndex & i_right); 

  /**
  * @copydoc CATIVidMdl#RemoveList
  */
  virtual CATBoolean RemoveList(const CATSYPDynArray<CATVidMdlIndex> & i_listOfIndexes);

	/**
	* @copydoc CATIVidMdl#ComputeHash
	*/
	virtual int ComputeHash(const CATVidMdlIndex &i_key);

  /**
  * @copydoc CATIVidMdl#GetModelType
  */
  virtual CATVid::ModelType GetModelType();

  // To be implemented in inheriting classes
  //virtual CATVidMdlIndex CreateIndex(int i_row, int i_column, const CATVidMdlIndex & i_parent);
  //virtual CATVidMdlIndex GetParent(const CATVidMdlIndex & i_index);
  //virtual int GetColumnCount(const CATVidMdlIndex & i_index);
  //virtual int GetRowCount(const CATVidMdlIndex & i_index);

  virtual CATISYPIntrospectable_var GetIntrospectable(const CATBaseUnknown_var & i_item);

protected:

  /**
   * Implement this method to be called on the structural change model events.
   */
  virtual void OnStructuralChangeModelEvents(CATBaseUnknown * i_pSender, CATVidMdlStructureChangedEventArgs * i_pArgs);

  /**
   * Method called on the filter change events.
   */
  void OnFilterChangedEvent(CATBaseUnknown * i_pSender, CATVidMdlFilterChangedEventArgs * i_pArgs);

  /**
   * Updates the proxy model according to the source model change.
   */
  virtual void Invalidate(CATBoolean i_updateView = TRUE);

  /**
   * @copydoc CATIVidMdl#ExportDataFromItems
   */
  virtual CATVidDnDData * ExportDataFromItems(const CATSYPDynArray<CATVidMdlIndex> & i_indexes);
  /**
   * @copydoc CATIVidMdl#CanDropData
   */
  virtual CATBoolean CanDropData(CATVidData * i_pData, CATVidDnD::Effect i_effect, const CATVidMdlIndex & i_index, const CATVidDnD::DropLocation & i_location);
  /**
   * @copydoc CATIVidMdl#DropData
   */
  virtual CATBoolean DropData(CATVidData * i_pData, CATVidDnD::Effect i_effect, const CATVidMdlIndex & i_index, const CATVidDnD::DropLocation & i_location);
  /**
   * @copydoc CATIVidMdl#GetViewportDropLocation
   */
  virtual void GetViewportDropLocation(CATVidMdlIndex & o_index, CATVidDnD::DropLocation & o_location);

private:

  // Copy constructor and equal operator
  CATVidMdlAbstractProxy(const CATVidMdlAbstractProxy &);
  CATVidMdlAbstractProxy & operator= (const CATVidMdlAbstractProxy &);

  /**
   * Creates all the event handlers necessary to handle the model events.
   */
  void AddModelEventHandlers();
  
  /**
   * Removes all the event handlers created for the model events.
   */
  void RemoveModelEventHandlers();

  CATIVidMdl_var _sourceModel;
  /** Event handler for @ref CATVidMdlEventEmitter#PreColumnsInserted,
                        @ref CATVidMdlEventEmitter#ColumnsInserted,
                        @ref CATVidMdlEventEmitter#PreColumnsRemoved,
                        @ref CATVidMdlEventEmitter#ColumnsRemoved,
                        @ref CATVidMdlEventEmitter#PreRowsInserted,
                        @ref CATVidMdlEventEmitter#RowsInserted,
                        @ref CATVidMdlEventEmitter#PreRowsRemoved,
                        @ref CATVidMdlEventEmitter#RowsRemoved,
                        @ref CATVidMdlEventEmitter#Reset,
                        @ref CATVidMdlEventEmitter#Update,
                        @ref CATVidMdlEventEmitter#ItemsDrop. */
  CATSYPEventHandler * _pOnStructuralChangeHandler;
  /** Event handler for @ref CATVidMdlEventEmitter#FilterChanged. */
  CATSYPEventHandler * _pOnFilterChangedHandler;
};

#endif // CATVidMdlAbstractProxy_h
