#ifndef CATRepPath_H
#define CATRepPath_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/



#include "SGInfra.h"
#include <string.h>
#include "list.h"
#include "CATRep.h"
#include "CATRepWeakRef.h"
#include "RepWeakRefR10.h"

//System FW
#include "CATSysAllocator.h"
#include "CATBaseUnknown_WR.h"

class CATViewpoint;


/**
* Interactive context description.
*
* @param CATNoneContext
*        No context, graphic representation will be drawn simply.
*
* @param CATPreselContext
*        Context of pre-highlight, graphic representation will be
*        <br>drawn in furtive mode (faster).
*
* @param CATSelContext
*        Context of hihglight, graphic reprensation will be
*        <br>drawn in highlight color (orange by default).
*
* @see CATRepPath
*/
enum CATInteractiveContext
{ 
  CATNoneContext,
  CATPreselContext,
  CATSelContext,
  CATMultiSelContext,
  CATMultiSelContextOptim
};



/**
* Class representing a single graphical representation within a graphical tree.
* <br><b>Role</b> : use to identify or to draw a single graphical
* <br>representation of the graphic tree or part of one.
* <br>
* <br>This class uses an internal index to add, remove or give
* <br>graphic representation. Be carreful, when using methods
* <br>that modify this index especially if one instance of CATRepPath
* <br>could be use at the same time at differents places.
* <br>Preferes to use methods that doesn't use this index :
* <ol>
* <li>@href #Size </li>
* <li>@href #operator[] </li>
* </ol>
*
*/
class ExportedBySGInfra  CATRepPath
{
  
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
  * Default constructor.
  *
  * @param iViewpointWherePathIsDrawn
  *        The viewpoint in wich the graphic representation will be drawn.
  */
  CATRepPath (CATViewpoint *iViewpointWherePathIsDrawn = NULL);

  /**
  * Copy constructor.
  *
  * @param iPath
  *        The repPath to copy.
  */
  CATRepPath (const CATRepPath &iPath);


  /**
  * Operator of assignment.
  *
  * @param iPath
  *        The repPath use to create a new one identical.
  *
  * @return
  *        The new repPath created by assignment.
  */
  CATRepPath& operator =(const CATRepPath &iPath);


  virtual ~CATRepPath();
  
  
  /**
  * Defines the interactive context.
  * <br><b>Role</b> : precise if the graphic representation 
  * <br>must be drawn taking account the context defined in parameter.
  *
  * @param iContext
  *        The context defines by @href CATInteractiveContext enum.
  */
  void SetInteractiveContext ( CATInteractiveContext iContext );


  /**
  * Gets the interactive context.
  * <br><b>Role</b> : gives the interactive context that
  * <br>will be use to draw the graphic representation.
  *
  * @return
  *        The @href CATInteractiveContext of the context.
  */
  CATInteractiveContext GetInteractiveContext () const;
  

  /**
  * Sets the viewpoint in wich the repPath will be drawn.
  *
  * @param iViewpoint
  *        The viewpoint in which graphic representation will be drawn.
  */
  void SetViewpoint(CATViewpoint *iViewpoint);

  /**
  * Gets the viewpoint in wich the repPath will be drawn.
  *
  * @return
  *        The viewpoint in which graphic representation will be drawn.
  */
  CATViewpoint* GetViewpoint() const;


  /**
  * Adds a rep in the path.
  * <br><b>Role</b> : uses to build the path, this method
  * <br>must be called as many times as the depth of the path.
  *
  * @param iRep
  *        The rep to add.
  */
  void AddRep (CATRep &iRep, int fastAdd = 0);


  /**
  * Removes a rep from the path.
  * <br><b>Role</b> : removes a particular rep from the path.
  *
  * @param iRep
  *        The rep to remove.
  */
  void RemoveRep (CATRep &iRep);

  /**
  * Empties the path.
  * <br><b>Role</b> : removes all reps from the path.
  */
  void Empty();


  /**
  * Gives the size of the path.
  * <br><b>Role</b> : returns the number of graphic 
  * <br>representation in the path. You can use this
  * <br>method to go through the path from 0 to Size-1,
  * <br>using @href #operator[].
  *
  * @return
  *        The size of the path.
  */
  int Size() const;


  /**
  * Gives a particular rep from the path.
  * <br><b>Role</b> : return the rep at the
  * <br>position given by the index in parameter.
  * <br>
  *
  * @param iIndex
  *        The index of the position.
  *        <br><b>Legal values</b> : value of the index must
  *        <br>be betwween 0 and @href #Size -1.
  *
  * @return
  *        The rep at the iIndex position.
  */
  CATRep* operator[] (int iIndex) const;

  
  
  /**
  * Inits to the top rep.
  * <br><b>Role</b> : its the internal index before the first graphic
  * <br>representation in the path. 
  * <br>Call @href #NextChildRep to get the first rep.
  */
  virtual void InitToTopRep();

  /**
  * Gets the next rep.
  * <br><b>Role</b> : increment the internal cursor then gets
  * <br>the graphic representation at the cursor position.
  *
  * @return
  *        The next graphic representation of the path.
  */
  CATRep *NextChildRep();

  /**
  * Returns the internal cursor position.
  *
  * @return
  *        The internal cursor value.
  *        <br>This cursor could be modified by methods
  *        <br>@href #InitToTopRep and @href #NextChildRep
  */
  int GetCursorPosition();

 /**
  * Returns the internal cursor position.
  *
  * @return
  *        The internal cursor value as a const.
  *        <br>@href #InitToTopRep and @href #NextChildRep
  *        
  */
  int GetCursorPosition() const;

  /**
  * Gets the graphic representation at the internal cursor position.
  *
  * @return
  *     The rep at the internal cursor position.   
  */
  CATRep* GetCurrentRep() ;

  /**
  * @nodoc
  */
  virtual void InitToLeafRep();

  /**
  * @nodoc
  */
  CATRep *NextFatherRep();

  /**
  * Checks if an other repPath is inclued in this.
  *
  * @param iOtherRepPath
  *        The repPath we look for into this.
  *
  * @return
  *        The result of the check.
  */
  int Contains ( const CATRepPath& iOtherRepPath );
  

  /**
  * @nodoc
  */
  int GetFurtive () const;

  /**
  * @nodoc
  */
  inline int GetRefNbr() const;

  /**
  * @nodoc
  */
  void SetFurtive (const int);
  
  /**
  * Sets a list of sub-element for this repPath.
  *
  * <br><b>Role</b> : A sub element is a value that represent
  * <br>a single part of a graphic representation.
  * <br>Seting a sub-element allow precise which sub-part
  * <br>of the leaf graphic representation you want to describe
  * <br>in the repPath.
  *
  * @param iSubElementList
  *        The sub-element list : a list of index.
  */
  void SetSubElementList (const ::list<int> &iSubElementList);

  /**
  * Sets a list of sub-element for this repPath without any duplicate check.
  *
  * <br><b>Role</b> : A sub element is a value that represent
  * <br>a single part of a graphic representation.
  * <br>Seting a sub-element allow precise which sub-part
  * <br>of the leaf graphic representation you want to describe
  * <br>in the repPath.
  *
  * @param iSubElementList
  *        The sub-element list : a list of index.
  */
  void SetFastSubElementList (const ::list<int> &iSubElementList);

  /**
  * Gets the actual list of sub-element for this repPath.
  *
  * @return
  *        The list of sub-elements : a list of index that
  *        <br>indicates singles parts of the leaf graphic 
  *        <br>representation in the repPath.
  */
  const ::list<int>& GetSubElementList() const;

  /**
  * Indicates if the repPath has sub-elements.
  *
  * @return
  *        The number of sub-elements, returns 0 if no sub-element.
  */
  int HasSubElement() const;
  

  /**
  * @nodoc
  */
  CATRep *GetManipulatedRep();
  
  /**
  * @nodoc
  */
  void SetManipulatedRep();

  
  /**
  * @nodoc
  */
  void SetMesh ( int mesh );

  /**
  * @nodoc
  */
  int IsMesh();

  /**
 * Increments the reference count for the given object. 
 * @return The reference count value.
 * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
  */
  int  AddRef();
  /**
  * Decrements the reference count for the given object. 
  * @return The reference count value.
  * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
  */
  int Release();


/**
 * Enables to know if a CATRepPath is still valid or not.
 * @return
 * An <tt>int</tt>
 * <dl>
 * <dt> <tt>1</tt>     <dd> All the @href CATRep referenced by the @href CATRepPath are still alive. The path can be used as is.
 * <dt> <tt>0</tt>     <dd> At least one of the referenced @href CATRep was destroyed. Therefore, the @href CATRepPath is not valid anymore.
 */
  int IsValid( void );
  
  /** @nodoc*/
  void SetPSOFaceZ( const int);
  
  /** @nodoc*/
  int GetPSOFaceZ () const;

  /**
  * @nodoc
  */
  CATBoolean IsFrontSide () const;

  /**
  * @nodoc
  */
  void SetFrontSide (const CATBoolean);

protected :
  ///////////
  
  // internal method to get the next element (child or father)
  CATRep *NextElement();
  
  // curseur sur representation rendue par GetRep
  int cursor_;
  
  //  manipulation management
  int _manipulatedRep;
  
  // sense for getting the next element.
  int sense_;
  
  // number of elements, initialized before parcouring the list.
  int size_;

  // list of CATRepWeakRef.
  // The reppath only knows weak references on reps. It enables to known if the referenced rep was deleted.
#ifndef RepWeakRef_R10
  list <CATRep> liste_;
#else
  ::list <CATRepWeakRef> liste_;
#endif
  
  // a path of rep has an existence through a viewpoint
  CATBaseUnknown_WR _viewpointWR;
  
  int	furtive_;
  
  ::list<int>  _subElementList;
  
  CATInteractiveContext _interactiveContext;
  
  // inform if repPath has mesh to draw
  // ----------------------------------
  int _mesh;

  /** @nodoc */
  int _psoFaceZ;

  CATBoolean _bFrontSide;

private : 
  int _RefNbr;
  
};

inline int CATRepPath::GetRefNbr(void) const
{
 return _RefNbr;
}

#endif 
