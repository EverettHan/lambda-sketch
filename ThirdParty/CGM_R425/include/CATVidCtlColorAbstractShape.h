//===================================================================
// COPYRIGHT COPYRIGHT DASSAULT SYSTEMES 2011/09/22
//===================================================================
// CATVidCtlColorAbstractShape.cpp
// Header definition of class CATVidCtlColorAbstractShape
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/09/22 Creation: RZH
//===================================================================

#ifndef CATVidCtlColorAbstractShape_H
#define CATVidCtlColorAbstractShape_H

#include <VisuDialog.h>
#include <CATVidCtlColorPicker.h>


/**
 * This widget provides a color 
 * <b>Role</b>:
 */
//-----------------------------------------------------------------------
class ExportedByVisuDialog CATVidCtlColorAbstractShape: public CATVidCtlColorPicker
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidCtlColorAbstractShape (CreateLetterFunc i_pCreateLetterFunc);
  virtual ~CATVidCtlColorAbstractShape ();

    /**
  * Sets a relative path to locate the cross hair icon
  * @param i_icon
  * The relative path to locate the ressource.
  */
  void SetCrossHairIcon( const CATUnicodeString &i_icon );
  /**
  * @return the relative path to locate the cross hair icon
  **/
  const CATUnicodeString & GetCrossHairIcon( void ) const;

  /**
  * Sets the dimension of the cross hair icon
  * @param i_dimension
  * The 2D point representing the dimension of the icon.
  */
  void SetCrossHairDimension( const CATMathPoint2Df &i_dimension);
  /**
  * @return the dimension of the cross hair icon
  */
  const CATMathPoint2Df & GetCrossHairDimension() const;

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlColorAbstractShape (CATVidCtlColorAbstractShape &);
  CATVidCtlColorAbstractShape& operator=(CATVidCtlColorAbstractShape&);

  //friend class l_CATVidCtlColorAbstractShape;
};

//-----------------------------------------------------------------------

#endif
