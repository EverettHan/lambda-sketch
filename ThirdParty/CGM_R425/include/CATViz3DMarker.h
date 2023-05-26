#ifndef CATViz3DMarker_H
#define CATViz3DMarker_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "SGInfra.h"
#include "CATVizPrimitive.h"
#include "CAT3DMarkerGP.h"
#include "CATVizMacForMetaClass.h"
#include "CATVisMacroForInterfaces.h"

class IVisSG3DPoint;
class CATViz3DMarkerIVisSG3DPointBOAImpl;

class CATStreamer;
class CATRender;

class ExportedBySGInfra CATViz3DMarker : public CATVizPrimitive
{
   friend class SGCGRStreamerForCATViz3DMarker;
   friend class SGCGRNodesFactoryA;
   CATVizDeclareClass;

public :

   CATVisDeclarePublicInterfaceAdhesion(CATViz3DMarker, IVisSG3DPoint, CATViz3DMarkerIVisSG3DPointBOAImpl);
   
   /**
   * Default constructor.
   */
   CATViz3DMarker ();
   CATViz3DMarker (const CATViz3DMarker & toCopy);

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
   CATViz3DMarker (const float iPoints[], const int iNbPoints=1, CATSymbolType iSymbol = CROSS, CATVizAllocMode iAlloc=CATVizAllocModeAllocate);
   
   /** @nodoc */
   virtual CATVizPrimitive * Duplicate();

   /** @nodoc */
   void Empty();
  
   /** @nodoc */
   virtual void Draw(CATRender &iRender);

   /** @nodoc */
   void SetSymbolType(CATSymbolType iSymbol);

   /**
   * @nodoc
   * Streaming
   */
   virtual void Stream(CATStreamer& oStr,int iSavetype=0);
   INLINE virtual unsigned char GetStreamId() const;
   
   /**
   * @nodoc
   * Streaming
   */
   static void Stream(CATStreamer& oStr, CAT3DMarkerGP *iGP);

   /**
   * @nodoc
   * Streaming
   */  
   virtual void UnStream(CATStreamer& iStr);
   
     /**
   * Retrieves marked points coordinates and the symbol type used
   * to mark them.
   * This method must be called this way:
   * <pre>
   * float * points;
   * int nbPoints;
   * SymbolType symbol;
   *
   * Get(&points, &NbPoints, &symbol);
   * </pre>
   * @param oPoints
   *   Retrieves an array containing marked points coordinates: XYZXYZXYZ...
   *   Its size is equal to three times the number of marked points.
   * @param oNbPoints
   *   Retrieves the number of points marked by this 3D marker.
   * @param oSymbol
   *   Retrieves the symbol used to mark the points.
   */
   inline void GetReadOnly (float const**oPoints, int *oNbPoint, CATSymbolType * oSymbol) const;
   
   CATVizDeclareTinyRefCount(7); // 7 bits refCount

   //--------------------------------------------------------------------------------
   
protected :

   /** @nodoc */
   virtual ~CATViz3DMarker ();

   //--------------------------------------------------------------------------------

   //unsigned char  _type;
   unsigned int _type : 1;
   //----- 7 bits reserved for RefCount

   unsigned short _symbol;

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

//--------------------------------------------------------------------------------

inline void CATViz3DMarker::GetReadOnly(float const**oPoints, int *oNbPoint, CATSymbolType * oSymbol) const
{
  
  *oSymbol = (CATSymbolType) _symbol;
  if (_type == MARKER_MULTIPLE)
  {
    *oPoints    = _data._multiple._points;
    *oNbPoint = _data._multiple._nb_points;
  }
  else
  {
    *oPoints = (float*) &(_data._single._coord[0]);
    *oNbPoint = 1;
  }
}

INLINE unsigned char CATViz3DMarker::GetStreamId() const
{
	return VIZMARKER;
}

#endif
