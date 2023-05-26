// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidLayLayer.h
// Header definition of CATVidLayLayer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidLayLayer_H
#define CATVidLayLayer_H

#include <VisuDialog.h>
#include <CATVidLayCollection.h>
#include <CATMathPoint2Df.h>
#include <CATVidLayConstraints.h>
#include <CATVidBorder.h>
//-----------------------------------------------------------------------
/**
* A Layer is a simple way to position widgets. 
* Its allows to overlap widgets.
* 
* 
* @par In CAPSYPStyle files
* @code
* <CATVidLayLayer ...........>
*   <MyWidgetA .........../>
*   <MyWidgetB .........../>
*   ....
* </CATVidLayLayer>
*
* @see CATVidLayLayerConstraints
* @see CATVidLayCollection
* @see CATISYPCollection
* @ingroup VIDLayout
*/
class ExportedByVisuDialog CATVidLayLayerConstraints: public CATVidLayConstraints
{
  CATDeclareClass;
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidLayLayerConstraints() {};
  virtual ~CATVidLayLayerConstraints() {};

  virtual CATVidLayConstraints* Clone() const {return new CATVidLayLayerConstraints();}; 

  /**
   * Copy the given constraints values.
   */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints);
};

//-----------------------------------------------------------------------

class ExportedByVisuDialog CATVidLayLayer: public CATVidLayCollection
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATVidLayLayer ();
  CATVidLayLayer (CATCommand *i_pParent, const CATString & i_pIdentifier);

  /** 
   * Sets the margins used around the layout.
   * By default, these margins are null.
   */
  void SetContentsMargins(const CATVidBorder& i_contentsMargins);

  /**
   * @return the margins used around the layout.
   */
  INLINE const CATVidBorder& GetContentsMargins() const 
  {
    return _contentsMargins;
  }


protected:

  virtual ~CATVidLayLayer ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidLayLayer (CATVidLayLayer &);
  CATVidLayLayer& operator=(CATVidLayLayer&);

  virtual CATVidLayConstraints* CreateConstraints();

  virtual void Layout();
  virtual void UpdateComputedMinimumDimension();
private:
  CATVidBorder _contentsMargins;
};

//-----------------------------------------------------------------------

#endif
