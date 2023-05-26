#ifndef CATVidLayCircular_h
#define CATVidLayCircular_h

#include "VisuDialog.h"
#include "CATVidLaySideAttach.h"
#include "CATVidLayCollection.h"

class ExportedByVisuDialog CATVidLayCircularConstraints : public CATVidLaySideAttachConstraints {
	CATDeclareClass;

public:
	// Standard constructors and destructors
    // -------------------------------------
	CATVidLayCircularConstraints();
	CATVidLayCircularConstraints(const float& i_angle);
	~CATVidLayCircularConstraints();

	CATBoolean IsEqualTo(const CATVidLaySideAttachConstraints& i_constraints) const;
	/**
    * Copy the given constraints values.
    */
	void CopyFrom(const CATVidLaySideAttachConstraints& i_constraints);

	/**
    * @return The constraint angle.
    */
	INLINE float GetAngle() const { return _angle; }
	/**
    * @param i_angle 
	* The new constraint angle in degree.
	*
	* @c The angle can be > 360° or < 0°. It will be compute back between 0° and 360° during the layouting.
    */
	INLINE void SetAngle(const float& i_angle) { _angle = i_angle; }

	// Copy constructor and equal operator
	// -----------------------------------
	CATVidLayCircularConstraints(const CATVidLayCircularConstraints& i_original);
	CATVidLayCircularConstraints& operator=(const CATVidLayCircularConstraints& i_original);

	// Clone the constraint, in a virtual context
	// ------------------------------------------
	virtual CATVidLaySideAttachConstraints* Clone() const override;

private:
	/**
	*	The angle in degree for positioning the widget on the layout's circle. 0° is the right side of the circle.
	*	If angle > 360 or angle < 0 it will be automatically be computed back between 0° and 360° during the layouting.
	*/
	float _angle = 0.f;
	
};

inline int operator == (const CATVidLayCircularConstraints& i_constaints1, const CATVidLayCircularConstraints& i_constaints2)
{
	return (i_constaints1.GetAngle() == i_constaints2.GetAngle());
}

/**
 * This class defines a layout that allows to place controls around a circle with angle and radius positioning
 * 
 *
 * @see CATVidLaySideAttach
 * @see CATVidLayCollection
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLayCircular : public CATVidLaySideAttach {
	CATDeclareClass;

public:
    // Standard constructor
    // --------------------
	CATVidLayCircular();
	CATVidLayCircular(CATCommand* i_pParent, const CATString& i_pIdentifier);

    /**
    * Retrieves the cirular constraints associated to the given widget.
    * @return 1 if the constraints have been found for the given widget, 0 otherwise.
    */
	int GetConstraints(const CATVidWidget* i_pWidget, CATVidLayCircularConstraints& o_constraints) const;

	/**
    * @return the layout circle radius
    */
	INLINE float GetRadius() const { return _radius; }
	/**
    * @param i_radius 
	* The new layout circle radius
	*
	* @c Setting the radius to -1 will make the layout compute the radius automatically depending on
	* the widgets, their sizes and their constraint angles. By default the radius is set at -1.
    */
	INLINE void SetRadius(const float& i_radius) { _radius = i_radius; }

protected:
	// Copy constructor and equal operator
	// -----------------------------------
	CATVidLayCircular(CATVidLayCircular&);
	CATVidLayCircular& operator=(CATVidLayCircular&);

	void Layout();
	CATVidLayConstraints* CreateConstraints();

	float _radius = -1.f;
};
#endif // CATVidLayCircular_h
