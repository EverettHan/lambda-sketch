// COPYRIGHT Dassault Systemes 2007
#ifndef CATPLMCompassWestToolbar_H
#define CATPLMCompassWestToolbar_H

#include <CATPLMCompassModule.h>
#include <CATBaseUnknown.h>

class CATPLMCompassWidgetTool;
class CATPLMCompass;

#include <CATLISTP_Clean.h>
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#include <CATLISTP_Declare.h>
CATLISTP_DECLARE( CATPLMCompassWidgetTool );
typedef CATLISTP( CATPLMCompassWidgetTool ) CATListOfWidgetTool;

/**
 * CATPLMCompassWestToolbar.
 * CATPLMCompassWestToolbar manages the toolbar in west quadrant 
 **/
class ExportedByCATPLMCompass CATPLMCompassWestToolbar : public CATBaseUnknown
{
public:
    CATDeclareClass;

	/**
	 * Constructor
	 **/
	CATPLMCompassWestToolbar( CATPLMCompass *father );
	/**
	 * Destructor
	 **/
	virtual ~CATPLMCompassWestToolbar( );
	/**
	 * Get 
	 **/
	const CATListOfWidgetTool &GetToolbar() const;
	const float GetToolbarHeight() const;
	const float GetToolbarWidth() const;
	/**
	 * Set
	 **/
	void SetToolbarHeight(float height){_toolbarh = height;}
	void SetToolbarWidth(float width){_toolbarw = width;}
	/**
	 * EmptyToolbar
	 */
	void EmptyToolbar( );
	/**
	 * UpdateToolbar
	 **/
	void UpdateToolbar(CATListOfCATUnicodeString *iplH = NULL);
	/**
	 * UpdateToolsVisibility
	 **/
	void UpdateToolsVisibility(int progressivePaint);
	/**
	 * ComputeToolbarWidthAndHeight
	 **/
	void ComputeToolbarSizeAndPosition( int xC, int yC, int r1 );
	/**
	 * WestToolbar geometry
	 **/
	inline void GetGeometry( float &ox, float &oy, float &ow, float &oh )
	{ ox = _toolbarx; oy = _toolbary; ow = _toolbarw; oh = _toolbarh; };

protected:
	CATListOfWidgetTool _toolbar;
	float _toolbarx, _toolbary;
	float _toolbarh, _toolbarw;
	CATPLMCompass *_father;
};

#endif
