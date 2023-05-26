#ifndef CATPathElement_h
#define CATPathElement_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/*
 * HISTORY :
 *   17 Juillet 2001 - CDT : on surcharge le new/delete pour augmenter les perfos
 */

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "list.h"
#include "CATListOfCATString.h"
#include "CATSysAllocator.h"

class CATPathElementWithPositions;


/**
* Interactive context description.
* <br><b>Role</b>:This context is used in the @href CATPathElement#SetInteractiveContext
*  method.
* @param CATVisNoneContext
*        No context, graphic representation will be drawn simply.
*
* @param CATVisPreselContext
*        Context of pre-highlight, graphic representation will be
*        <br>drawn in furtive mode (faster).
*
* @param CATVisSelContext
*        Context of highlight, graphic representation will be
*        <br>drawn in highlight color (orange by default).
*
* @param CATVisMultiSelContext
*        Context of Trap Selection.
*
* @param CATVisMultiSelContextOptim
*         No documentation.
*/
enum CATVisInteractiveContext
{
  CATVisNoneContext,
  CATVisPreselContext,
  CATVisSelContext,
  CATVisMultiSelContext,
  CATVisMultiSelContextOptim
};

/**
  * Class representing a path of objects.
  * <b> Role </b>: provides a structure which is easy to use for manipulating pathes extracted
  * from a tree structure of objects, which is one of the foundations of the CATIAV5 model.
  * <p>
  * For example when one selects an object thru one of its visualized graphical representations,
  * it is interesting to retreive the whole path of graphical representations corresponding to
  * the selection. Thereafter one wants to translate this path into a path of objects and hold this
  * information for later usage.
  *
  */
class ExportedByCATVisItf CATPathElement : public CATBaseUnknown
{
/** @nodoc */
  CATDeclareClass;

  public:

  /** @nodoc */
   void *operator new(size_t iSize,void *iAllocType=NULL,
                      void *iAddr=NULL,int iReservedSize=0);

  /** @nodoc */
   void operator delete(void *iAddr);

#ifdef _WINDOWS_SOURCE
  /** @nodoc */
   void operator delete(void *iAddr,void *iAllocType,
                        void *iRefAddr,int iReservedSize);
#endif

  /**
    * Constructs the class from an object.
    * @param   iObject
    *     the object which will be the first object of the path.
    * Notice that one @href CATBaseUnknown#AddRef is done on this object.
    *
    */
  CATPathElement( const CATBaseUnknown *iObject = NULL );

  /**
    * Copy Constructor.
    * <br><b>Role</b>: This method creates a new CATPathElement which is a copy of the input
    * CATPathElement.
    * <br>But, if an interactive context had been put on the input CATPathElement, with the
    * @href #SetInteractiveContext method, it will not be copied onto the new CATPathElement.
    * @param iPath
    *    path to copy.
    */
  CATPathElement( const CATPathElement & iPath);


  /**
    * Assignment operator.
     * <br><b>Role</b>: The values of the input CATPathElement are assigned to this. However,
    * if an interactive context had been put on the input CATPathElement, with the
    * @href #SetInteractiveContext method, it will not be kept through the assignment.
    * @param iPath
    *   path to assign.
    */
  CATPathElement & operator = ( const CATPathElement &  iPath ) ;

  /**
    * Equality operator.
    * <br><b>Role:</b>This method compares one by one the elements of the two paths. As soon as
    * there is a difference, the comparison failed.
    * @param iPath
    *    Path to compare with the current path.
    * @return
    * An integer value whose <b>legal values</b> are:
    * <ul>
    * <li> 1: if the paths are equal</li>
    * <li> 0: else </li>
    * </ul>
    */
  virtual int operator == ( const CATPathElement & iPath ) const;

  /**
    * Returns a pointer to a new path of objects which is the clone of the current one.
    */
   virtual CATPathElement * Clone() const;


  virtual ~CATPathElement();

  /**
    * Adds one object at the top of the path or just above a given object.
    * The cursor position is set to the position of the added object if the operation succeeds, otherwise it does
    * not change.
    *
    * @param iObject
    *   the object to add.
    * @param iChildObject
    *    the given object which precises the position where to add <tt>iObject</tt>. If <tt>iChildObject</tt> is not found
    *    in the current path, nothing is added.
    */
    virtual void AddFatherElement ( const CATBaseUnknown *iObject,
			                                           const CATBaseUnknown *iChildoObject=NULL );

  /**
    * Adds one object at the end of the path or just beneath a given object.
    * The cursor position is set to the position of the added object if the operation succeeds, otherwise it does
    * not change.
    *
    * @param iObject
    *   the object to add.
    * @param iFatherObject
    *    the given object which precises the position where to add <tt>iObject</tt>. If <tt>iFatherObject</tt> is not found
    *    in the current path, nothing is added.
    */
    virtual void AddChildElement ( const CATBaseUnknown *iObject,
			                                     	const CATBaseUnknown *iFatherObject=NULL );

   /**
    * Adds one object as brother of the current position of the path or just at the right of a given object.
    * The cursor position is set to the position of the added object if the operation succeeds, otherwise it does
    * not change.
    *
    * @param iObject
    *   the object to add. It is added at the end of the brother's list of the current Bigbrother.
    * @param iLeftObject
    *    the given object which precises the position where to add <tt>iObject</tt>. If <tt>iLeftObject</tt> is not found
    *    in the current path, <tt>iObject</tt> is added at the end of the brother's list of the current Bigbrother.
    */
    virtual void AddBrotherElement ( const CATBaseUnknown *iObject,
				                                        const CATBaseUnknown *iLeftObject=NULL);


  /**
    * Removes one object from the path.
    * <br><b> Role</b>:
    *    the object to remove can be either a Bigbrother or a brother of a given Bigbrother. In the first case we remove
    *    the Bigbrother and all its brothers and in the second case we remove the object and all its right brothers.
    * The cursor's position is not changed if the object to remove is different from the current position and
    * if the current position is a left brother of the removed object. Otherwise, the position is set to the next existing
    * left object.
    * @param iObject
    *   the object to remove.
    */
     virtual void RemoveElement ( const CATBaseUnknown * iObject);


  /**
    * Initialize a top-down run of the path. To get the first object of the path, one should call
    * the @href #NextChildElement() method.
    */
     void InitToTopElement();

   /**
    * Initialize a bottom-up run of the path. To get the last object of the path, one should call
    * the @href #NextFatherElement() method.
    */
     void InitToLeafElement();


     /**
       * Retrieves the next object of the path from the current position in a top-down run of the path.
       * <br><b>Role</b>:
       * it goes from the curremt positon to the its 'child' object, that is the
       *  object which is the child of the current object's BigBrother. The cursor is updated to the next child object.
       * If the cursor is set to the last object, the call of this method will return NULL.
       * @return
       *   The next child object.
       *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the
       *   returned value.
       */
        CATBaseUnknown * NextChildElement();

   /**
       * Retrieves the next object of the path from the current position in a bottom-up run of the path.
       * <br><b>Role</b>:
       * it goes from the curremt positon to the its 'father' object, that is the
       *  object which is the father of the current object's BigBrother. The cursor is updated to the next father object.
       * If the cursor is set to the first object, the call of this method will return NULL.
       * @return
       *   The next parent object.
       *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the
       *   returned value.
       */
       CATBaseUnknown * NextFatherElement();


     /**
       * Retrieves the next right object of the path from the current position in a left-to-right run of the path.
       * <br><b>Role</b>:
       * it goes from the curremt positon to the next right object, that is the
       *  object which is the next right brother of the current object or the next child object.
       * The cursor is updated to the next right object.
       * If the cursor is set to the last object, the call of this method will return NULL.
       * @return
       *   The next right object.
       *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the
       *   returned value.
       */
       CATBaseUnknown * NextRightElement();


     /**
       * Retrieves the next right object of the path from the current position in a left-to-right run of the path.
       * <br><b>Role</b>:
       * it goes from the curremt positon to the next left object, that is the
       *  object which is the next left brother of the current object or the most right brother of the next father object.
       * The cursor is updated to the next left object.
       * If the cursor is set to the first object, the call of this method will return NULL.
       * @return
       *   The next left object.
       *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the
       *   returned value.
       */
       CATBaseUnknown * NextLeftElement();


    /**
      * Retrieves a pointer to the current object of the path.
      * @return
       *   The current object.
       *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the
       *   returned value.
      */
      CATBaseUnknown * CurrentElement() const;

     /**
       * Retrieves the current position.
       */
      void GetPosition( int *BBpos, int *Bpos);

    /**
      * Retrieves a pointer to the current big brother of the path.
       * @return
       *   The big brother object.
       *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the
       *   returned value.
      */
        CATBaseUnknown *CurrentBigBrother() const;


 /**
   * Retrieves a pointer to the brothers' list of the input object.
   * @param iObject
   *  the object from which we want to retrieve the brothers' list.
   * @return
   *   The brother list.
   *   <br>NULL is returned is the input object is not found.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is done on iObject.
   *       The returned list must not be deleted or released.
   */
  ::list<CATBaseUnknown> *BrotherList(const CATBaseUnknown *iObject) const;


 /**
   * Retrieves a new list enclosing the children list of the input object.
   * <br><b>Role</b> :
   * the returned list holds the child  along with all of its brothers of the input parameter.
   * It's up to the user to destroy the returned list.
   * @param iObject
   *   The object from which we want to retrieve its children.
   * <br><b>Lifecycle rules deviation</b>: No AddRef is done on the objects
   * <br> contained in the list. They must not be destroyed or released.
   * <br> The returned list has to be destroyed by the caller.
   */
  ::list<CATBaseUnknown> *ChildrenList(const CATBaseUnknown *iObject) const;

  /**
   * Retrieves a sub-path resulting from the search of one object in the path which adheres
   * to a given interface.
   * <br><b>Role</b>:
   * Search into the current path, an object adhering to a given interface. And it is a bottom-up search,
   * that is we look for objects from leaf to top and from right to left. If we succeed, we extract
   * and return a 1D sub-path holding the found object.If the search fails, NULL is returned.
   *
   * @param iIid
   *   the interface IID.
   * @return
   *  a 1D sub-path of the current path if the search succeeds,  NULL otherwise.
   */
  CATPathElement *GetSubPath ( const CATClassId iIid) const;

  /**
   * Retrieves a sub-path resulting from the search of one object in the path which adheres
   * at least to one interface of a given list of interfaces.
   * <br><b>Role</b>:
   * Search into the current path, an object adhering to one of the given interfaces. And it is a bottom-up search,
   * that is we look for objects from leaf to top and from right to left. Then we extract and return a 1D sub-path
   * holding the found object.If the search fails, NULL is returned.
   * <p>
   * Because one object can adhere to
   * more than one of the given interfaces, you should notice that this is the first successful encountered interface
   * which is choosen. Notice that at each position in the path, the search is also performed by looking at the first interface,
   * then the second and so on till the last interface of the input list. And search is stopped whenever one interface suits.
   * So you have to put interfaces into the list carefully : the order may lead to different results as far as the elected
   * interface is concerned!
   *
   * @param iList_Interfaces
   *   the list of interface names.
   * @param oPos
   *   the index of the found interface from the input list.
   *<br><b>Legal Values</b>: a non zero positive integer if the search succeeds, -1 otherwise.
   * @return
   *  a 1D sub-path of the current path if the search succeeds,  NULL otherwise.
   *
   */
  virtual CATPathElement *GetSubPath ( const CATListOfCATString iList_Interfaces, int &oPos ) const;



  /**
   * Finds a given object anywhere into the path.
   *<br><b>Role</b>:
   * Searches the input object and sets the internal cursor positions if the search succeeds.
   *
   * @param iObject
   *  a pointer to the object to find.
   * @return
   *  an integer embodying the result of the search.
   *<br><b>Legal Values</b>:
   *<ol>
   *<li> 1 if the input object is found <li>
   *<li> 0 otherwise</li>
   *</ol>
   *
   */
  int FindElement (const CATBaseUnknown *iObject);


  /**
   * Finds one object in the path adhering to a given interface.
   *<br><b>Role</b>:
   * Searches from leaf to top an object which adheres to a given interface and sets the internal cursor
   * positions if the search succeeds.
   *
   * @iIid
   *  the interface IID.
   * @return
   * A pointer to the TIE interface of the found object if the search succeeds, NULL otherwise.
  */
  virtual CATBaseUnknown * FindElement(const IID &iIid) ;

  /**
   * Retrieves a TIE pointer of an object in the path adhering to a given interface.
   *<br><b>Role</b>:
   * Searches from leaf to top an object which adheres to a given interface and sets the internal cursor
   * positions if the search succeeds. If search is successful, given the found object and the input interface, the TIE
   * pointer of the found object is returned.
   *
   * @iIid
   *  the interface IID.
   * @param oPtr
   *  the TIE pointer.
   * @return an HRESULT value
   *<br><b>Legal Values</b>:
   *<ol>
   *<li> S_OK if the search succeeds</li>
   *<li> E_FAIL otherwise </li>
   *</ol>
   *
   */
  virtual HRESULT Search(const IID &iIid, void **oPtr);

  /**
   * Reverse the current path.
   */
  void Reverse();


  /**
   * Retrieves the size of the path.
   * @return
   *    The count of element in the path.
   */
  inline int GetSize() const;

 /**
  * Returns the (i+1)th object of the path.
  * @param i
  * index in the path.
  * @return
  * a pointer to an object, or NULL if the input parameter is out of the scope of the path.
  */
  inline CATBaseUnknown * operator [] (int i) const ;

  /**
   * @nodoc
   * Sets a flag.
   *
   * @param iFlag
   * integer value between [-128,127]
   * <br><b> legal values </b>
   * <ol>
   * <li> 1 means that the method @href #IsEqual is required for comparing
   *       objects hold in the current path </li>.
   * <li> 0 is the default value and means nothing </li>
   * </ol>
   */
  inline void SetFlag(char iFlag);

 /**
  * @nodoc
  * Gets the flag.
  *
  * @return an integer value between [-128,127]
  * <br><b> legal values </b>
  * <ol>
  * <li> 1 means that the method @href #IsEqual is required for comparing
  *       objects hold in the current path </li>.
  * <li> 0 is the default value and means nothing </li>
  * </ol>
  */
  inline char GetFlag();

  /**
   * Sets the offset for next searches.
   * @param iOffset
   * the offset.
   */
  virtual void SetOffsetForSearch(int iOffset);

  /**
  * Sets the interactive context.
  * <br><b>Role</b> : This method precises if the graphic representation
  * <br>must be drawn taking account the context defined in parameter.
  * @param iContext
  *        The context
  */
  virtual void SetInteractiveContext ( CATVisInteractiveContext iContext );


  /**
  * Retrieves the interactive context.
  * <br><b>Role</b> : This method gives the interactive context that
  * <br>will be use to draw the graphic representation.
  *
  * @return
  *        The context.
  */
  virtual CATVisInteractiveContext GetInteractiveContext () const;

  /** @nodoc */
  virtual CATPathElementWithPositions* SafeCastToPathElementWithPositions();
  /** @nodoc */
  virtual const CATPathElementWithPositions* SafeCastToPathElementWithPositions() const;

  /** @nodoc */
  static CATPathElement & GetCurrent();

  /** @nodoc */
  static void SetCurrent ( CATPathElement & );


  //==============================================================
  // DO NOT USE
  /** @nodoc */
  void Last();
  /** @nodoc */
  void Next();
  /** @nodoc */
  virtual CATBaseUnknown * FindObject(const IID &) ;
  /** @nodoc */
  CATBaseUnknown * SearchObject(const CATClassId) ;
  /** @nodoc */
  CATBaseUnknown * GetCurrentObject() const;
  /** @nodoc */
  CATBaseUnknown * CurrentObject() const;
  /** @nodoc */
  CATBaseUnknown * GetNextFatherObject();
  /** @nodoc */
  CATBaseUnknown * NextFatherObject();
  /** @nodoc */
  void InitToLeafObject();
  /** @nodoc */
  void InitToTopObject();
  /** @nodoc */
  virtual void RemoveChildElement ( const CATBaseUnknown * );
  /** @nodoc */
  CATBaseUnknown * GetNextChildObject();
  /** @nodoc */
  CATBaseUnknown * NextChildObject();
  //===============================================================

  protected :

  /** @nodoc */
  CATVisInteractiveContext _interactiveVisContext;

  private:
  /** @nodoc */
  int _softLimit; /* size of the BigBrothers'list */
  /** @nodoc */
  int _cur; /* cursor for the BigBrothers' list */
  /** @nodoc */
  int _curbrother; /* cursor for the brothers' list */
  /** @nodoc */
  ::list<CATBaseUnknown> _ref; /* BigBrothers' list */
  /** @nodoc */
  ::list< ::list<CATBaseUnknown> > _brotherref;  /* list of brothers' list */

  // offset from the bottom right element of the path from which we start searching
  // the element which suits the 'GetSubPath<ii>' request
  /** @nodoc */
  int _OffsetForSearch;

  // flag used to known that some objects hold in the path need
  // IsEqual method for comparison.
  /** @nodoc */
  char _Flag;

  /** @nodoc */
  static CATPathElement *_current;

    public :

 /**
  * Increments the reference count for the given interface.
  * @return The reference count value.
  * <br>This information is meant to be used for diagnostic/testing purposes only, because, in some situations, the value may be unstable.
  */
  virtual ULONG   __stdcall AddRef();

 /**
  * Decrements the reference count for the given interface.
  * @return The reference count value.
  * <br>This information is meant to be used for diagnostic/testing purposes only, because, in some situations, the value may be unstable.
  */
  virtual ULONG   __stdcall Release();

};

inline CATBaseUnknown * CATPathElement::operator [] (int i) const { return ( (i>=0)  ? _ref[i] : 0); }

inline int CATPathElement::GetSize(void) const { return _ref.length();}

inline char CATPathElement::GetFlag(void) {return _Flag;}

inline void CATPathElement::SetFlag(char iFlag) { _Flag = iFlag;}


#endif
