#ifndef CATVidMdlSortFilterProxy_h
#define CATVidMdlSortFilterProxy_h

// COPYRIGHT DASSAULT SYSTEMES 2014

// VisuImmersiveDialog framework
#include <CATVidMdlCompletionProxy.h>
#include <CATVidMdlIndex.h>
#include <CATVid.h>

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

// System framework
#include <CATUnicodeString.h>
#include <CATBoolean.h>

/**
 * Class providing support for sorting and filtering data passed between another model and a view.
 */
class ExportedByVisuDialog CATVidMdlSortFilterProxy : public CATVidMdlCompletionProxy
{
  CATDeclareClass;

public:

  /**
   * Default constructor.
   */
  CATVidMdlSortFilterProxy();
  /**
   * Destructor.
   */
  virtual ~CATVidMdlSortFilterProxy();

  /**
   * Specifies whether the string comparison used when sorting the source model is case sensitive or not.
   * By default, the SortCaseSensitiveFlag property is set to TRUE.
   */
  void SetSortCaseSensitiveFlag(CATBoolean i_sortCaseSensitiveFlag);

  /**
   * Returns TRUE if the string comparison used when sorting the source model is case sensitive, FALSE otherwise.
   */
  INLINE CATBoolean GetSortCaseSensitiveFlag() const {return _sortCaseSensitiveFlag;};

  /**
   * Sets the name of the property used to sort the source model.
   */
  void SetSortPropertyName(const CATUnicodeString& i_sortPropertyName);

  /**
   * Returns the name of the property used to sort the source model.
   * By default, the SortPropertyName property is empty.
   */
  INLINE CATUnicodeString GetSortPropertyName() const {return _sortPropertyName;};

  /**
   * Sets the sort order (ascending or descending).
   * By default, the SortOrder property is set to CATVid::AscendingOrder.
   */
  void SetSortOrder(CATVid::SortOrder i_sortOrder);

  /**
   * Returns the sort order.
   */
  CATVid::SortOrder GetSortOrder() const {return _sortOrder;};

  /**
   * Specifies whether the sorting of the source model is disabled or not.
   * By default, the SortDisabledFlag property is set to FALSE.
   */
  void SetSortDisabledFlag(CATBoolean i_sortDisabledFlag);

  /**
   * Returns TRUE if the sorting of the source model is disabled, FALSE otherwise.
   */
  INLINE CATBoolean GetSortDisabledFlag() const {return _sortDisabledFlag;};

  /**
   * Returns TRUE if the sorting of the source model is disabled, FALSE otherwise.
   * This method returns TRUE if the SortDisabledFlag property is set to TRUE or if the 
   * SortPropertyName property is empty.
   */
  virtual CATBoolean GetSortDisabledState() const;

  // Partial implementation of the CATIVidMdl interface
  virtual void Sort(const CATUnicodeString& i_propertyName, CATVid::SortOrder i_sortOrder = CATVid::AscendingOrder);

 /**
	* Returns >0 if the value of the item referred to by the given index i_index1 is more than 
	* the value of the item referred to by the given index i_index2, <0 if it is less or 0 if they are equal.

	* This method allowq taking in account integer (as string) contained in the compared CATUnicodeString.
	* For instance, with classic CATUnicodeString ascending SortCompare, 'myString45' will be positioned before 'myString5'.
	* SortCompareAlphaNum allows having the 'natural' order: 'myString5' will be positioned before 'myString45'.
	*/
	int SortCompareAlphaNum(const CATUnicodeString & istr1, const CATUnicodeString & istr2);

protected:

  /**
   * Sorts all the existing index mappings with the current sort properties (property name, sort order, ...).
   */
  void Sort();

  /**
   * Sorts the source rows of the given index mapping with the current sort properties (property name, sort order, ...).
   */
  virtual HRESULT Sort(CATVidMdlIndexMapping * i_pIndexMapping);

  /**
   * Returns >0 if the value of the item referred to by the given index i_index1 is more than 
   * the value of the item referred to by the given index i_index2, <0 if it is less or 0 if they are equal.
   * This function is used when sorting, and handles the following types :
   *     - Boolean
   *     - Integer
   *     - Float
   *     - Double
   *     - String
   * Any other type will be converted to a string before the comparison. 
   * Comparison of strings is case sensitive by default ; this can be changed using the 
   * SortCaseSensitiveFlag property.
   * The SortPropertyName property associated with the CATVidMdlIndex used for comparisons must have been set.
   * Note : The indices passed in correspond to the source model.
   */
  virtual int Compare(const CATVidMdlIndex& i_sourceIndex1, const CATVidMdlIndex& i_sourceIndex2);

private:

  // Copy constructor and equal operator
  CATVidMdlSortFilterProxy(const CATVidMdlSortFilterProxy &);
  CATVidMdlSortFilterProxy & operator= (const CATVidMdlSortFilterProxy &);

  static int s_CompareSourceRows(const int * i_pIndex1, const int * i_pIndex2);
  
  int count_digits(const char* s);

  static CATVidMdlSortFilterProxy * s_pSortingProxy;
  static CATVidMdlIndexMapping * s_pIndexMapping;

  static CATUnicodeString s_sortPropertyName;//Needed for s_CompareSourceRows method.
  CATSYPPropertyDescriptorBase::Type _sortPropertyType;
  CATUnicodeString _sortPropertyName;
  CATVid::SortOrder _sortOrder;
  CATBoolean _sortCaseSensitiveFlag;
  CATBoolean _sortDisabledFlag;
};

#endif // CATVidMdlSortFilterProxy_h
