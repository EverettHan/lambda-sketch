#ifndef CATVidLayConstraints_h
#define CATVidLayConstraints_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialog framework
#include "VisuDialog.h"

// UIVCoreTools framework
#include <UIVCoreToolsInline.h>

// System framework
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "UIVCoreToolsInline.h"

/**
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLayConstraints : public CATBaseUnknown
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  CATVidLayConstraints();
  virtual ~CATVidLayConstraints();

  // Copy constructor and equal operator
  CATVidLayConstraints (const CATVidLayConstraints &);
  CATVidLayConstraints& operator=(const CATVidLayConstraints&);

  /**
   * Clones the constraints.
   */
  virtual CATVidLayConstraints* Clone() const = 0; 

  virtual CATBoolean IsEqualTo(const CATVidLayConstraints& i_constraints) const;

  /**
   * Copy the given constraints values.
   */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints) = 0;

  /**
   * Specifies whether the position of the associated widget is limited to its parent bounding rectangle,
   * whatever its contraints are, or not.
   * By default this property is set to FALSE.
   */
  INLINE void SetConstraintUpdateAllowedFlag(const CATBoolean& i_constraintUpdateAllowedFlag)
  {
    _constraintUpdateAllowedFlag = i_constraintUpdateAllowedFlag;
  }
  INLINE CATBoolean GetConstraintUpdateAllowedFlag() const
  {
    return _constraintUpdateAllowedFlag;
  }

  /**
   * Specifies whether the position of the associated widget is limited to its parent restricted area,
   * whatever its contraints are, or not.
   * By default this property is set to FALSE.
   */
  INLINE void SetUseRestrictedAreaFlag(const CATBoolean& i_useRestrictedAreaFlag)
  {
    _useRestrictedAreaFlag = i_useRestrictedAreaFlag;
  }
  INLINE CATBoolean GetUseRestrictedAreaFlag() const
  {
    return _useRestrictedAreaFlag;
  }

  /**
   * Specifies whether the associated widget must have its dimension equal to its minimum dimension or not.
   * By default this property is set to FALSE.
   */
  INLINE void SetCompactFlag(CATBoolean i_compactFlag)
  {
    _compactFlag = i_compactFlag;
  }
  INLINE CATBoolean GetCompactFlag() const
  {
    return _compactFlag;
  }

  /**
   * Specifies whether the associated widget must have its height equal to its minimum height or not.
   * By default this property is set to FALSE.
   */
  INLINE void SetVerticallyCompactFlag(CATBoolean i_compactFlag)
  {
    _verticallyCompactFlag = i_compactFlag;
  }
  INLINE CATBoolean GetVerticallyCompactFlag() const
  {
    return _verticallyCompactFlag;
  }

  /**
   * Specifies whether the associated widget must have its width equal to its minimum height or not.
   * By default this property is set to FALSE.
   */
  INLINE void SetHorizontallyCompactFlag(CATBoolean i_compactFlag)
  {
    _horizontallyCompactFlag = i_compactFlag;
  }
  INLINE CATBoolean GetHorizontallyCompactFlag() const
  {
    return _horizontallyCompactFlag;
  }

	/**
	* Return the user preferred height of the associated widget. Its is calculated on user resize interaction.
	* The preferred height is lower than its parent height and heigher than the y minimum dimension. 
	* By default, its value is equal to -1.
	* @see GetUsePreferredDimensionFlag()
	*/
	INLINE float GetPreferredHeight() const {
		return _preferredHeight;
	}

	INLINE void SetPreferredHeight(float i_preferredHeight)
	{
		_preferredHeight = i_preferredHeight;
	}

	/**
	* Return the user preferred width of the associated widget. Its is calculated on user resize interaction.
	* The preferred width is lower than its parent width and heigher than the x minimum dimension. 
	* By default, its value is equal to -1.
	* @see GetUsePreferredDimensionFlag()
	*/
	INLINE float GetPreferredWidth() const {
		return _preferredWidth;
	}

	INLINE void SetPreferredWidth(float i_preferredWidth)
	{
		_preferredWidth = i_preferredWidth;
	}

	/**
	* Return whether if the preferred dimensions are calculated or not
	* @see GetPreferredHeight() 
	* @see GetPreferredWidth()
	*/
	INLINE CATBoolean GetUsePreferredDimensionFlag() const {
		return _usePreferredDimensionFlag;
	}

	/**
	* Sets whether if the preferred dimensions are calculated or not
	*/
	INLINE void SetUsePreferredDimensionFlag(CATBoolean i_preferredDimensionFlag) {
		_usePreferredDimensionFlag = i_preferredDimensionFlag;
	}

private:
  unsigned char _constraintUpdateAllowedFlag :1;
  unsigned char  _useRestrictedAreaFlag      :1;
  unsigned char  _compactFlag                :1;
  unsigned char  _verticallyCompactFlag      :1;
  unsigned char  _horizontallyCompactFlag    :1;
	unsigned char  _usePreferredDimensionFlag : 1;
	float _preferredHeight; 
	float _preferredWidth;
};

#endif // CATVidLayConstraints_h
