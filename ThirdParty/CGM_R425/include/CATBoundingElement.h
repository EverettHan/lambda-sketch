#ifndef CATBoundingElement_H
#define CATBoundingElement_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//HISTORY
//   CDT - 26 Mars 2002 - on passe sur pool d'allocation

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATVizBaseIUnknown.h"
#include "CATSysAllocator.h"


/**
 * @nodoc 
 * Possible bounding element states.
 * @param EMPTY
 *  The bounding element has not been valuated.
 * @param NORMAL
 *  The bounding element contains some finite element.
 * @param INFINIT
 *  the bounding element is infinite.
 * @param CONTAIN
 *  The bounding element is infinite but contain some finite element.
 */

enum STATE
{
 EMPTY,
 NORMAL,
 INFINIT,
 CONTAIN
};

class CATStreamer;




/**
 * Base Class to manage bounds of elements.
 * <b>Role</b>:This class is used to manage the space used by elements.
 * It is not used as such but through inheritance. The main class
 * inheriting from this class are CAT3DBoundingElement for 3D element
 * and CAT2DBoundingElement for 2D Elements.
 */

class ExportedBySGInfra CATBoundingElement : public CATVizBaseIUnknown
{
 friend class CATMarshalBoundingElement;
 friend class SGCGRStreamerForBoundingElement;
 friend class SGCGRNodesFactoryA;
 CATDeclareClass_Deprec;

 /** @nodoc */
   void *operator new(size_t iSize,void *iAllocType=NULL,
                      void *iAddr=NULL,int iReservedSize=0);
   
  /** @nodoc 
   *  Surcharge de l'operateur delete pour gerer un compteur de reference interne aux reps
   *  et pouvoir detecter les cas ou une rep est mal detruite.
   */
  void operator delete (void *iPtr);
  
#ifdef _WINDOWS_SOURCE
  /** @nodoc */
   void operator delete(void *iAddr,void *iAllocType,
                        void *iRefAddr,int iReservedSize);
#endif


 public :

  /**
    * @nodoc
	* Streaming
	*/
  virtual void Stream(CATStreamer& str,int savetype=0);

  /**
    * @nodoc
	* UnStreaming
	*/
  virtual void UnStream(CATStreamer& str);

  /**
   * Returns the empty state of the bounding element.
   * @return 
   * 1 if empty or 0 otherwise.
   */
  inline int IsEmpty    () const {return (_state == EMPTY);};

  /**
   * Returns the infinite state of the bounding element.
   * @return
   * 1 if infinite or 0 otherwise.
   */
  inline int IsInfinite () const {return (_state == INFINIT);};

  /**
   * @nodoc.
   */
  inline int IsInvalid  () const {return (_invalid);};

  /**
   * Returns the contain state of the bounding element.
   * @return
   * 1 if state is CONTAIN or 0 otherwise.
   */
  inline int IsContain  () const {return (_state == CONTAIN);};
 
  /**
   * Sets the bounding element state to Infinite.
   */
  inline void SetInfinite () {_state = INFINIT;_invalid = 0;};

  /**
   * Sets the bounding element state to Empty.
   */
  inline void SetEmpty () {_state = EMPTY;_invalid = 0;};
  
  /**
   * @nodoc
   */
  inline void SetInvalid() {_invalid = 1;};

  /**
   * @nodoc
   */
  inline void SetValid() {_invalid = 0;};


//------------------------------------------------------------------------------

 protected :

   /**
   * Construct an empty boundingElement.
   * This is only called through inheritance.
   */
   CATBoundingElement ();

   /**
    * Copy constructor.
	*/
   CATBoundingElement (const CATBoundingElement &);

   virtual ~CATBoundingElement ();

   /**
    * @nodoc.
	*/
   CATBoundingElement & operator += (const CATBoundingElement &);

   /**
    * @nodoc.
	*/
   CATBoundingElement & operator  = (const CATBoundingElement &);

   STATE _state:3;
   int   _invalid:2;
   int   _padding:27;
};

#endif
