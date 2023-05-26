#ifndef CATVidMdlCompletionProxy_h
#define CATVidMdlCompletionProxy_h

// COPYRIGHT DASSAULT SYSTEMES 2013

// VisuImmersiveDialog framework
#include <CATVidMdlAbstractProxy.h>
#include <CATVidMdlIndex.h>
#include <IndexHashMap.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>
#include <CATSYPHashMap.h>

// System framework
#include <CATUnicodeString.h>
#include <CATBoolean.h>

class CATVidMdlStructureChangedEventArgs;
class CATVidMdlIndexMapping;

/**
 * Implementation of a proxy model used for the filtering of a data model.
 * 
 * Let’s assume that we want to filter the items of a given source model. The code to set up 
 * the model and the view, without filtering, would look like this :
 *
 * @code
 *   CATVidCtlTreeView * pTreeView = new CATVidCtlTreeView();
 *   CATVidMdlStandardTree * pTreeModel = new CATVidMdlStandardTree();
 *
 *   pTreeView->SetSourceModel(pTreeModel);
 * @endcode
 * 
 * To add filtering support to the data model (here a CATVidMdlStandardTree), we need to create 
 * a CATVidMdlCompletionProxy, call SetSourceModel() with the CATVidMdlStandardTree instance as argument, 
 * and install the CATVidMdlCompletionProxy on the view as its source model :
 *
 * @code
 *   CATVidCtlTreeView * pTreeView = new CATVidCtlTreeView();
 *   CATVidMdlStandardTree * pTreeModel = new CATVidMdlStandardTree();
 *
 *   CATVidMdlCompletionProxy * pCompletionProxy = new CATVidMdlCompletionProxy();
 *
 *   pCompletionProxy->SetSourceModel(pTreeModel);  
 *   pTreeView->SetSourceModel(pCompletionProxy);
 * @endcode
 */
class ExportedByVisuDialog CATVidMdlCompletionProxy : public CATVidMdlAbstractProxy
{
  CATDeclareClass;

public:

  /**
   * Default constructor.
   */
  CATVidMdlCompletionProxy();
  /**
   * Destructor.
   */
  virtual ~CATVidMdlCompletionProxy();

  /**
   * Sets the string used to compute the completion model by filtering the source model.
   * When the completion string is modified, the virtual method OnCompletionStringChanged is called.
   */
  void SetCompletionString(const CATUnicodeString& i_completionString);

  /**
   * Returns the string used to compute the completion model by filtering the source model.
   */
  INLINE CATUnicodeString GetCompletionString() const {return _completionString;};

  /**
   * Specifies whether the string matching used to filter the source model from the completion string
   * is case sensitive or not.
   * By default, the CaseSensitiveFlag property is set to FALSE.
   */
  void SetCaseSensitiveFlag(CATBoolean i_caseSensitiveFlag);

   /**
    * Returns TRUE if the string matching used to filter the source model from the completion string
    * is case sensitive, FALSE otherwise.
    */
  INLINE CATBoolean GetCaseSensitiveFlag() const {return _caseSensitiveFlag;};

  /**
   * Specifies whether the comparison must be successfull only for exact matching with the completion string.
   * By default, the ExactMatchFlag property is set to FALSE.
   */
  void SetExactMatchFlag(CATBoolean i_exactMatchFlag);

   /**
    * Returns TRUE if the string matching used to filter the source model from the completion string
    * is case sensitive, FALSE otherwise.
    */
  INLINE CATBoolean GetExactMatchFlag() const {return _exactMatchFlag;};

  /**
   * Sets the name of the property used to compute the completion model by filtering the source model.
   * This property must be of type CATUnicodeString.
   */
  void SetFilteredPropertyName(const CATUnicodeString& i_filteredPropertyName);

  /**
   * Returns the name of the property used to compute the completion model by filtering the source model.
   * By default, the FilteredPropertyName property is set to 'Text'.
   */
  INLINE CATUnicodeString GetFilteredPropertyName() const {return _filteredPropertyName;};

  /**
   * If the MatchPrefixOnlyFlag property is set to TRUE, a combo box item will match only if the beginning of 
   * its filtered property value is equal to the filtering string ; if set to FALSE it will match if the entire 
   * word contains the filtering string.
   * By default, the MatchPrefixOnlyFlag property is set to FALSE.
   */
  void SetMatchPrefixOnlyFlag(CATBoolean i_matchPrefixOnlyFlag);

  /**
   * Returns TRUE if the filtering of a combo box item is based only on the beginning of 
   * its filtered property value compared to the filtering string, or FALSE if the entire 
   * word is taken into account to search for the filtering string.
   */
  INLINE CATBoolean GetMatchPrefixOnlyFlag() const {return _matchPrefixOnlyFlag;};

  /**
   * Specifies whether the filtering is using the wild card character '*' when comparing strings or not.
   * Setting this property to TRUE can have an impact on the filtering performances.
   * By default, the UseWildCardCharFlag property is set to FALSE.
   */
  void SetUseWildCardCharFlag(CATBoolean i_useWildCardCharFlag);

  /**
   * Returns TRUE if the filtering is using the wild card character '*' when comparing strings, FALSE otherwise.
   */
  INLINE CATBoolean GetUseWildCardCharFlag() const {return _useWildCardCharFlag;};

  /**
   * Specifies whether the filtering of the source model is disabled or not.
   * By default, the FilterDisabledFlag property is set to FALSE.
   */
   void SetFilterDisabledFlag(CATBoolean i_filterDisabledFlag);

  /**
   * Returns TRUE if the filtering of the source model is disabled, FALSE otherwise.
   */
  INLINE CATBoolean GetFilterDisabledFlag() const {return _filterDisabledFlag;};

  /**
   * Returns TRUE if the filtering of the source model is disabled, FALSE otherwise.
   * This method returns TRUE if the FilterDisabledFlag property is set to TRUE or if the 
   * CompletionString property is empty.
   */
  virtual CATBoolean GetFilterDisabledState() const;

  /**
   * Returns the index of the first item that exactly matches the completion string.
   * This method returns an invalid index if no such item exists.
   */
  CATVidMdlIndex GetExactMatchIndex();

  /**
   * Returns the string used as the completion text for the given index of the source model.
   * This string is used to check whether the given index matches the current completion string or not.
   * The default implementation returns the 'Text' property value of the item for list models.
   * @see GetSourceModel
   * @see GetCompletionString
   */
  virtual CATUnicodeString GetStringFromIndex(const CATVidMdlIndex& i_sourceIndex);

  /**
   * Returns the index in the source model that 
   * corresponds to the i_proxyIndex in the proxy model.
   */
  virtual CATVidMdlIndex MapToSource(const CATVidMdlIndex& i_proxyIndex);

  /**
   * Returns the index in the proxy model that 
   * corresponds to the i_sourceIndex in the source model.
   */
  virtual CATVidMdlIndex MapFromSource(const CATVidMdlIndex& i_sourceIndex);

  /**
   * Method called when the source model must be filtered (e.g when the completion string
   * has been changed).
   * @param i_parseFilteredNodesOnly
   * Specifies whether the new filter string must be applyed on the already filtered nodes only or not
   * @see SetCompletionString
   * @see FilterAcceptsRow
   */
  void Filter(CATBoolean i_parseFilteredNodesOnly = FALSE, CATBoolean i_updateView = TRUE);

  /**
   * Returns TRUE if the item referenced in the source model by the given index is matching the
   * current completion string, FALSE otherwise.
   * The default implementation filters the current source model with the completion string.
   * Implement this method if you want to override the default behavior.
   * @see Filter
   */
  virtual CATBoolean FilterAcceptsRow(
        const CATVidMdlIndex & i_sourceIndex, 
        const CATUnicodeString& i_completionString, 
        CATBoolean& o_exactMatch);

  // Partial implementation of the CATIVidMdl interface
  virtual CATVidMdlIndex CreateIndex(int i_row, int i_column, const CATVidMdlIndex & i_parent);
  virtual CATVidMdlIndex GetParent(const CATVidMdlIndex & i_index);
  virtual int GetColumnCount(const CATVidMdlIndex & i_index);
  virtual int GetRowCount(const CATVidMdlIndex & i_index);

protected:

  /**
   * Returns TRUE if the item referenced in the source model by the given row and parent is matching the
   * current completion string, FALSE otherwise.
   * @see Filter
   */
  CATBoolean FilterAcceptsRow(
        int i_row, 
        const CATVidMdlIndex & i_sourceParent, 
        const CATUnicodeString& i_completionString, 
        CATBoolean i_parseFilteredNodesOnly,
        CATBoolean& o_exactMatch,
        CATSYPHashMap<CATVidMdlIndex, int, IndexHashMap> * io_pMatchingSourceIndexes);

  /**
   * Sorts the source rows of the given index mapping.
   * The default implementation does nothing.
   */
  virtual HRESULT Sort(CATVidMdlIndexMapping * i_pIndexMapping) {return E_FAIL;};

  /**
   * Method called on the structural change model events.
   */
  virtual void OnStructuralChangeModelEvents(CATBaseUnknown * i_pSender, CATVidMdlStructureChangedEventArgs * i_pArgs);

  /**
   * Updates the proxy model according to the source model change.
   */
  virtual void Invalidate(CATBoolean i_updateView = TRUE);

private:

  // Copy constructor and equal operator
  CATVidMdlCompletionProxy(const CATVidMdlCompletionProxy &);
  CATVidMdlCompletionProxy & operator= (const CATVidMdlCompletionProxy &);

  /**
   * Retrieves the mapping corresponding to the given source parent if it exists, or NULL if not yet created.
   */
  CATVidMdlIndexMapping * _GetMapping(const CATVidMdlIndex& i_sourceParent);

  /**
   * Retrieves the mapping corresponding to the given source parent, or creates it
   * if it does not exist.
   */
  CATVidMdlIndexMapping * _GetOrCreateMapping(const CATVidMdlIndex& i_sourceParent);

  /**
   * Returns the mapping stored for the given proxy index.
   */
  CATVidMdlIndexMapping * _GetStoredMapping(const CATVidMdlIndex& i_proxyIndex) const;

  /**
   * Updates the given mapping according to the current filter and sort properties.
   */
  void _UpdateMapping(
        CATVidMdlIndexMapping * i_pIndexMapping, 
        CATBoolean i_parseFilteredNodesOnly = FALSE,
        CATSYPHashMap<CATVidMdlIndex, int, IndexHashMap> * io_pMatchingSourceIndexes = NULL);

  void _ClearIndicesMap();

	void _CleanMapsForIndexAndItsChildren(CATVidMdlIndex& index);

  CATSYPHashMap<CATVidMdlIndex, CATVidMdlIndexMapping *, IndexHashMap> _indicesFromSourceParentMap;
  CATSYPHashMap<CATBaseUnknown *, CATVidMdlIndexMapping *, CATSYPHashMapPointerHasher> _indicesFromSourceIndexMap;
  CATSYPHashMap<CATBaseUnknown *, CATBaseUnknown *, CATSYPHashMapPointerHasher> _firstSiblingMap;
  CATUnicodeString _completionString;
  CATUnicodeString _filteredPropertyName;
  CATVidMdlIndex _exactMatchIndex;
  CATBoolean _caseSensitiveFlag;
  CATBoolean _matchPrefixOnlyFlag;
  CATBoolean _useWildCardCharFlag;
  CATBoolean _filterDisabledFlag;
  CATBoolean _exactMatchFlag;

  friend class CATVidMdlSortFilterProxy;
};

#endif // CATVidMdlCompletionProxy_h
