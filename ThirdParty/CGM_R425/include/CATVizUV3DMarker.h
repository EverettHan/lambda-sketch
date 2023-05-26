#ifndef CATVizUV3DMarker_H
#define CATVizUV3DMarker_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "SGInfra.h"
#include "CATViz3DMarker.h"
#include "CAT3DMarkerGP.h"
#include "CATVizMacForMetaClass.h"

class CATStreamer;
class CATRender;


class ExportedBySGInfra CATVizUV3DMarker : public CATViz3DMarker
{
   CATVizDeclareClass;

public :
   CATVisDeclarePublicInterfaceAdhesion(CATVizUV3DMarker, IVisSG3DPoint, CATVizUV3DMarkerIVisSG3DPointBOAImpl);
   
   /**
   * Default constructor.
   */
   CATVizUV3DMarker ();
   CATVizUV3DMarker (const CATVizUV3DMarker & toCopy);

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
   CATVizUV3DMarker (const float iPoints[], const int iNbPoints=1, CATSymbolType iSymbol = CROSS, const int iAlloc=ALLOCATE);
   
   /** @nodoc */
   virtual CATVizPrimitive * Duplicate();
	inline void SetId(unsigned int id);
	inline void SetSymbolType(CATSymbolType symbolType);
	inline void SetCoordinates(float x, float y, float z);     
  virtual unsigned int GetId();
   //--------------------------------------------------------------------------------
   
protected :

   /** @nodoc */
   virtual ~CATVizUV3DMarker ();

   //--------------------------------------------------------------------------------
   
private :
	unsigned int _id;
};

inline void CATVizUV3DMarker::SetId(unsigned int id)
{
	_id = id;
}

inline void CATVizUV3DMarker::SetSymbolType(CATSymbolType symbolType)
{
	_symbol = symbolType;
}


inline void CATVizUV3DMarker::SetCoordinates(float x, float y, float z)
{
	_type = MARKER_SINGLE;

   _data._single._coord[0] = x;
   _data._single._coord[1] = y;
   _data._single._coord[2] = z;
}


//--------------------------------------------------------------------------------
#endif
