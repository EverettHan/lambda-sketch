#ifndef CATPathElementRep_h
#define CATPathElementRep_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

       
#include "SceneGraphManager.h"
#include "CATVizBasePathElementRep.h"
#include "CATPathElement.h"

//System FW
#include "CATSysAllocator.h"

class CATRender;
class CATModelIdentificator;

/**
  * Class representing a path of 3D graphical representations associated to a path of objects.
  *<b>Role</b>: this class is used to visualize objects that are (pre)highlighted and it is
  * based on a path of 3D graphical representations ( @href CATRepPath ), which is an input of the class,
  * to draw the geometry. This class overrides attributs associated to graphical representations hold in
  * the path.
  *
  */
class ExportedBySceneGraphManager CATPathElementRep : public CATVizBasePathElementRep
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
   * Constructs a rep from a path of objects and a path of graphical representations.
   *@param iPathOfObject
   *   path of objects
   *@param iPathOfRep
   *    path of graphical representations.
   */
  CATPathElementRep(const CATPathElement &iPathOfObject, CATRepPath &iPathOfRep);

  /** 
   * Constructs a rep from a path of objects and a path of graphical representations.
   *@param iPathOfObject
   *   path of objects
   *@param iPathOfRep
   *    path of graphical representations.
   */
  CATPathElementRep(CATPathElement *iPathOfObject, CATRepPath *iPathOfRep);

 /**
  * Copy constructor.
  */
  CATPathElementRep(const CATPathElementRep &iRep);

  virtual ~CATPathElementRep();
	 

  /**
   * Returns a reference to the path of objects.
   */
  CATPathElement & GetPathElement();

  /**
   * Returns a reference to the path of objects.
   */
  void GetElementPath(CATPathElement *&oPath);


/**
 * This function enables the user to know if the rep is set to be used in a highlight context.
 * @return
 * An <tt>int</tt>
 * <dl>
 * <dt> <tt>1</tt>   <dd> The rep is set to be used in a highlight context.
 * <dt> <tt>0</tt>   <dd> The rep is set to be used in a manipulation context.
 * </dl>
 */
  int IsCSOOperationRep( void );

/**
 * Enables the user to specify that the rep is used in a highlight context. The default context of the rep
 * is the manipulation one.
 * @param <tt>int iHighlightContext = 1</tt>
 * [in] The context: 1 means highlight context, 0 is for manipulation context. 
 */
  void SetCSOOperationRep( int iHighlightContext = 1 );

  
  protected:

/**
 * This method is set to be called in order to update the CATRepPath associated to the rep.
 * Currently, it is called when an invalid reppath is detected in a highlight context.
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The reppath was successfully updated.
 * <dt> <tt>E_FAIL</tt>   <dd> The regeneration of the reppath failed.
 * </dl>
 */
    HRESULT UpdateRepPath( void );


  private:

/**
 * This pointer to a CATPathElement has two functions for the CATPathElementRep:
 * + It represents the pointer to the model path of the element represented by the CATPathElementRep.
 * + The last bit is used to define the context of the CATPathElementRep. The last bit is set to
 * 1 if the rep is used in a highlight context. If it's a manipulation rep, it is set to 0 and this
 * is the default case.
 *
 * HOW TO USE THE POINTER ?
 *   A set of macros is provided to help using the kept pointer :
 *   o AS_PATHELEMENT(_pElementPath) returns the real pointer on the CATPathElement.
 *   o IS_CSOOPERATIONREP(_pElementPath) returns 0 if the rep is a manipulation rep. Either, it's a highlight rep.
 *   o SET_PATHELEMENT(_pElementPath,ptr2) valuates the real pointer to the CATPathElement to the given ptr2 pointer without affecting the context.
 *   o SET_CSOOPERATIONREP(_pElementPath) specifies the rep as a highlight rep.
 *   o UNSET_CSOOPERATIONREP(_pElementPath) specifies the rep as a manipulation rep.
 */
    CATPathElement *_pElementPath;
};

#endif 
