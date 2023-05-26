#ifndef CATPathElement2DRep_h
#define CATPathElement2DRep_h
//
// CATIA Framework Visualization
// Copyright Dassault Systemes 1996
//----------------------------------------------------------------
// Abstract : 
//            class used to visualise elements of a Current Set of Object.  
//            She uses a CATRepPath to draw geometry.
//            She overrides attributs associated to representation pointed
//            by the CATRepPath.
//   
// ----------------------------------------------------------------
//  Usage :   is used to visualize a CATPathElement
// ----------------------------------------------------------------
//  Inheritance : CATPathElement2DRep
//                  CAT2DRep
// ----------------------------------------------------------------
//  Main Methods :
//               DrawShading
//----------------------------------------------------------------------------
//       
#include "SceneGraphManager.h"
#include "CATVizBasePathElement2DRep.h"
#include "CATPathElement.h"
#include "CATRepPath.h"

//System FW
#include "CATSysAllocator.h"

class CATRender;
class CATModelIdentificator;

class ExportedBySceneGraphManager CATPathElement2DRep : public CATVizBasePathElement2DRep
{
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
 * The CATPathElement2DRep constructor.
 * @param <tt>const CATPathElement & iPathElement</tt>
 * [in] A reference on the @href CATPathElement used to define the rep. It must be a heap allocated object.
 * @param <tt>CATRepPath & iRepPath</tt>
 * [in] A reference on the @href CATRepPath used to define the rep. It must be a heap allocated object.
 */
  CATPathElement2DRep( const CATPathElement & iPathElement, CATRepPath & iRepPath );

  CATPathElement2DRep(const CATPathElement2DRep &);
  virtual ~CATPathElement2DRep();

/** @nodoc */
  CATPathElement & GetPathElement( void );

/**
 * Returns the @href CATPathElement associated to the CATPathElement2DRep.
 * @param <tt>CATPathElement *& oPath</tt>
 * [out] A pointer on the @href CATPathElement associated to the rep. AddRef is done on the pointer.
 * @return
 * Un <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>S_OK</tt>     <dd> The pointer was succesfully valuated.
 * <dt> <tt>E_FAIL</tt>   <dd> There is no @href CATPathElement associated to this rep.
 * </dl>
 */
  HRESULT GetElementPath( CATPathElement *& oPath );

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
  virtual HRESULT UpdateRepPath( void );
  
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
    CATPathElement * _pElementPath;
};

#endif 
