#ifndef CAT3DMarkerGP_H
#define CAT3DMarkerGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Graphic 3D marker. 
//------------------------------------------------------------------------------
// Inheritance: CAT3DMarker
//                 CATGraphicPrimitive
//                    CATBaseUnknown (SYSTEM framework)
//------------------------------------------------------------------------------

#include "SGInfra.h"

#include "CATGraphicPrimitive.h"
#include "CATVizMacForMetaClass.h"
#include "CATSymbolType.h"

class CATMathPointf;
class CATStreamer;
class CAT3DMarkerGPEditHelper;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DPoint;
class CAT3DMarkerGPIVisSG3DPointBOAImpl;
//-- SGCAAPlan


/**
 * Class to create the graphic primitive of 3D markers.
 * <b>Role</b>: This graphic primitive is a graphic 3D marker to point to one or
 * several specific points in the space. A 3D marker size is constant, it does not depend
 * on the zoom.
 */
class ExportedBySGInfra CAT3DMarkerGP : public CATGraphicPrimitive
{ 
  friend class CAT3DMarkerGPEditHelper;
  friend class CATMarshallable3DMarkerGP;
  friend class SGCGRStreamerFor3DMarkerGP;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  CATVizDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DMarkerGP, IVisSG3DPoint, CAT3DMarkerGPIVisSG3DPointBOAImpl);
 
public :

  /**
   * Default constructor.
   */
  CAT3DMarkerGP ();

  /**
   * Constructs 3D markers from a list of 3D points, and the type of symbol wanted to be used.
   * @param iPoints
   *   Array containing the coordinates of the points to mark : XYZXYZXYZ... Its size is equal
   *   to three times the number of points.
   * @param iNbPoints
   *   The number of points to mark, which coordinates are stored in the <tt>iPoints</tt> array.
   *   If no <tt>iNbPoints</tt> is specified, the number of points is assumed to be 1.
   * @param iSymbol
   *   The symbol wanted to be used to mark the points.
   *   The default value is <tt>CROSS</tt>.
   * @param iAlloc
   *    Flag used to specify whether points must be duplicated or not.
   *    <br><b>Legal values</b>:
   *    <dl>
   *      <dt>ALLOCATE</dt>
   *        <dd>All data are duplicated into the graphic primitive</dd>
   *      <dt>DONT_ALLOCATE</dt>
   *        <dd>The graphic primitive has a pointer to the data given as parameter
   *        Warning : If the number of points is equal to 1, the points are duplicated
   *		anyway (Memory issue). The input data must still be destroyed by the caller.</dd>
   *    </dl>
   *    The default value is <tt>ALLOCATE</tt>.
   */
  CAT3DMarkerGP (const float iPoints[], const int iNbPoints=1, CATSymbolType iSymbol = CROSS, const int iAlloc=ALLOCATE);

  /**
   * @nodoc
   */
  virtual void Stream(CATStreamer& oStr,int iSaveType=0);

  /**
   * @nodoc
   */
  virtual void UnStream(CATStreamer& iStr);


  /**
   * Retrieves marked points coordinates and the symbol type used
   * to mark them.
   * This method must be called this way:
   * <pre>
   * float const* points;
   * int nbPoints;
   * SymbolType symbol;
   *
   * GetReadOnly(&points, &NbPoints, &symbol);
   * </pre>
   * @param oPoints
   *   Retrieves an array containing marked points coordinates: XYZXYZXYZ...
   *   Its size is equal to three times the number of marked points.
   * @param oNbPoints
   *   Retrieves the number of points marked by this 3D marker.
   * @param oSymbol
   *   Retrieves the symbol used to mark the points.
   */
  inline void GetReadOnly (float const **oPoints, int *oNbPoint, CATSymbolType * oSymbol) const;

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
  /**
   * Draws the 3D marker.
   * @param iRender
   *   The render through which the 3D marker is drawn.
   * @param iViewpoint
   *   The viewpoint through which the 3D marker is seen.
   * @param iViewport
   *   The viewport in which the 3D marker is located.
   */
  virtual void Draw (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;
    
  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);
  
  /**
   * @nodoc
   */
  virtual CATVizPrimitive * GetVizPrimitive(int &oAllocateMode);

  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const final;

  /**
  * @nodoc
  */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

//------------------------------------------------------------------------------
protected :
  /**
   *sets the symbol used to mark the points to a new value.
   *@param iSymbol
   * The new symbol you wish to use.
   */

  void SetSymbolType(CATSymbolType iSymbol);

  /**
   * @nodoc
   */
  virtual void SetVizPrimitive(CATVizPrimitive* iPrimitive, int iAllocateMode);

  virtual ~CAT3DMarkerGP();

//------------------------------------------------------------------------------

//private :

  //CATSymbolType _symbol;
  //float      *_points;
  //int        _nb_points;
  //int        _alloc;
  
  unsigned short _symbol;
  unsigned char  _type;

  union 
  {
     struct
     {
        float  *_points;
        int     _nb_points;
        int     _alloc;
     } _multiple;
     struct
     {
        float _coord[3];
     } _single;
  } _data;
};

/**
 * @nodoc
 */
#define MARKER_SINGLE 0
/**
 * @nodoc
 */
#define MARKER_MULTIPLE 1


inline void CAT3DMarkerGP::GetReadOnly (float const**points, int *nb_points, CATSymbolType *symbol) const
{
  *symbol = (CATSymbolType) _symbol;
  if (_type == MARKER_MULTIPLE)
  {
    *points    = _data._multiple._points;
    *nb_points = _data._multiple._nb_points;
  }
  else
  {
    *points = (float*) &(_data._single._coord[0]);
    *nb_points = 1;
  }
}


#endif
