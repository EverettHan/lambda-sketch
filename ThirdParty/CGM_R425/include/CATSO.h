#ifndef CATSO_h
#define CATSO_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SceneGraphManager.h"
#include "list.h"
#include "CATBaseUnknown.h"
#include "CATSysSimpleHashTable.h"
#include "CATDataType.h"

/**
* A set of objects.
* <br><b>Role</b> : Enclosed objects are instances of the @href CATBaseUnknown class.
* This class makes use of the AddRef/Release mechanism when adding or removing object.
*/
class ExportedBySceneGraphManager CATSO : public CATBaseUnknown
{
   /** @nodoc */
  CATDeclareClass;

  public:

  /**
  * Default constructor.
  *
  * @param iThereIsNoDuplicata
  *        Parameter use to avoid the check of each object added.
  *        <br><b>Legal values</b> :
  *        <BR>The default comportment expressed by the default value 0 is
  *        <BR>to check if the object still exist before added it.
  *        <BR>If the value is set to 1 you must be sure that each new object
  *        <BR>not still exist in the set.
  */
  CATSO (int iThereIsNoDuplicata = 0);


  virtual ~CATSO();

  /**
   * Subscripting operator.
   * <br><b>Role</b> : returns an object using the object index.
   * <br><b>Lifecycle rules deviation</b> : This method doesn't AddRef returned value.
   *
   * @param iIndex
   *        The index
   *        <br><b>Legal values</b> : <tt>iIndex</tt> values are between 0 and GetSize()-1.
   * @return
   *        The object.
   */
  CATBaseUnknown * operator [] (int iIndex) const ;
  
  /**
   * Adds an element to the set.
   *
  * @param iElement
  *   The element to add to the set.
  *   <br><b>Cyclic reference</b>: A copy of <tt>iElementToAdd</tt> is kept and
  *   an AddRef is performed. It is Released either when the element is removed from the set,
  *   or by the CATSO destructor.
  * @param iCheckIfThere
  *   Unused argument
  */
  virtual HRESULT AddElement    (CATBaseUnknown *iElement, int iCheckIfThere = 1);

  /**
   * Removes an element from the set.
   *
   * @param iElem
   *        The objectto remove.
   *        <br><b>Cyclic reference</b> : the removed object is released.
   */
  virtual void RemoveElement (CATBaseUnknown *iElem);

  
  /**
   * Remove all elements from the set.
   * A Release is done for each element.
   * <br><b>Cyclic reference</b>: each object is released.
   */
   virtual void Empty ();


  /**
   * Checks if an element ready exists in the set.
   *
   * @param iElem
   *        The object to look for.
   * @return
   *        <br><b>Legal values</b> : return 0 if the element isn't in the set, otherwise return 1.
   */
   int IsMember (CATBaseUnknown *iElem);


  /**
   * Returns the count of elements in the set.
   *
   * @return
   *        Return the size of the set.
   */
   int GetSize ();

  /**
   * Gathers an other set with this one.
   *
   * @param iSo
   *            The set of elements to add.
   */
   void Gather(CATSO *iSo);

  /**
   * @nodoc
   * Deprecated.
   */
   void InitElementList();

  /**
   * @nodoc
   * Deprecated.
   */
   CATBaseUnknown * NextElement();

  /**
   * @nodoc
   * Deprecated.
   */
   CATBaseUnknown * GetCurrentElement();


  /**
   * @nodoc
   * Do not use.
   */
   int IsThereNoDuplicata();

   
 protected:
  
  ::list<CATBaseUnknown> _Liste;
  int _thereisnoduplicata;

 private :
  CATSysSimpleHashTable* _HTable;
  CATBaseUnknown* _currentelemt;
  
  /** @nodoc */
  CATSO (const CATSO &);
  /** @nodoc */
  CATSO & operator = (const CATSO &);


 public :
 /** @nodoc */
  static unsigned int GetKey(void*);
  
 /** @nodoc */
  static int Compare(void*, void*);
  
};

inline CATBaseUnknown * CATSO::operator [] (int i) const { return ( (i>=0)  ? _Liste[i] : 0); }

#endif
