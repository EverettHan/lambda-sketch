/* -*-c++-*- */

#ifndef CATModifyVisProperties_H
#define CATModifyVisProperties_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATModifyAttribut.h"

// interfaces
#include "CATIVisProperties.h"
#include "CATVisPropertiesValues.h"

// others
#include "CATPathElement.h"

/** @nodoc */
typedef union
{
  struct
  {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;
  } color;
  SymbolType   symbol;
  unsigned int lineType;
  unsigned int width;
  unsigned int pick;
  unsigned int inheritance;
} CATVisPropertyValue;

#include "CATVisItf.h"

/**
* Notification class to refresh the visualization. 
* <b>Role:</b>This notification does not delete the graphic representation, it only modifies
* the graphic attributes (Color, Show/noShow ...). This notification is faster than a <i>CATModify</i>. 
* <br>The specification tree is automatically updated.
*/
class ExportedByCATVisItf CATModifyVisProperties : public CATModify
{
  CATDeclareClass;
public:


  /**
  * Constructs a notification to refresh the visualization.
  * @param iObject
  * The object to revisualize.
  * @param iPath
  * The object path
  * @param iGeomType
  * The object geometric type
  * @param iPropertyType
  * the graphic property type associated with the object geometric type
  * @param iPropertyValue
  * The object which contains the graphic property.
  */
  CATModifyVisProperties(CATBaseUnknown               * iObject,
                         const CATPathElement         & iPath,
                         const CATVisGeomType           iGeomType,
                         const CATVisPropertyType       iPropertyType,
                         const CATVisPropertiesValues & iPropertyValue);

  virtual ~CATModifyVisProperties();

  /** @nodoc */
  inline CATPathElement           GetPathElement   () const;
    /** @nodoc */
  inline CATVisGeomType           GetGeomType      () const;
    /** @nodoc */
  inline CATVisPropertyType       GetPropertyType  () const;
    /** @nodoc */
  inline CATVisPropertiesValues   GetPropertyValue () const;

  enum CATUndoRedoState
  {
	  CATRedo,
	  CATUndo,
	  CATNone
  };

  /** @nodoc */
  inline void   SetUndoRedo (CATUndoRedoState state);
  /** @nodoc */
  inline void GetUndoRedoState (CATUndoRedoState& state) const;

  /** @nodoc */
  virtual CATModelNotification * Clone();

protected:
  CATPathElement           _path;
  CATVisGeomType           _geomType;
  CATVisPropertyType       _propertyType; 
  CATVisPropertiesValues   _propertyValue;
  CATUndoRedoState		   _undoRedoState;
};

  /** @nodoc */
inline CATPathElement           CATModifyVisProperties::GetPathElement() const
{
  return _path;
};
  /** @nodoc */
inline CATVisGeomType           CATModifyVisProperties::GetGeomType() const
{
  return _geomType;
};
  /** @nodoc */
inline CATVisPropertyType       CATModifyVisProperties::GetPropertyType() const
{
  return _propertyType;
};
  /** @nodoc */
inline CATVisPropertiesValues   CATModifyVisProperties::GetPropertyValue () const
{
  return _propertyValue;
};

  /** @nodoc */
inline void CATModifyVisProperties::GetUndoRedoState (CATUndoRedoState& state) const
{
	state  = _undoRedoState;
}

  /** @nodoc */
inline void   CATModifyVisProperties::SetUndoRedo (CATUndoRedoState state)
{
	_undoRedoState = state;
}

#endif // CATModifyVisProperties_H
