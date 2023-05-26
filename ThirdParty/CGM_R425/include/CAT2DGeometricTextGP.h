#ifndef CAT2DGeometricTextGP_H
#define CAT2DGeometricTextGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "SGInfra.h"     
#include "CAT2DGeomTextStructures.h"
#include "CAT2DTextGP.h"
#include "CATUnicodeString.h"
class CATRender;
class CATFont;
class CATStreamer;

/**
* Class to create a dynamic graphic primitive of 2D geometric text.
* <b>Role</b>: 
* These Graphic primitives have a continuous zoom. 
* @see CAT2DAnnotationTextGP
*/ 
class ExportedBySGInfra CAT2DGeometricTextGP: public CAT2DTextGP
{
  friend class SGCGRStreamerFor2DGeometricTextGP;
  friend class SGCGRNodesFactoryA;
  friend class CAT2DGeometricTextGPHelper;

   CATDeclareClass;
 
   public:

      /**
      * Constructs a 2D geometric text Graphic primitive.
      * @param iPoint
      *	the position of the Graphic Primitive in a 2D space.
      * @param iString
      *	the string of characters which composes the text of 
      *	the 2D geometric text.
      * @param iHeight
      *	the Height of the 2D geometric text.
      *	<br><b>legal values</b>:
      *	the default value is 10.
      * @param iHorJustification
      *	the orthogonal justification of the 2D geometric text.
      *	<br><b>legal values</b>:
      *	<ul><li> 0 : normal</li>
      *	<li> 1 : centered</li>
      *	<li> 2 : opposite</li></ul>
      *	<br> NB : for a code page where characters are
      *			displayed in a directional
      *			way from left to right, normal = left
      *			and opposite = right
      * @param iVerJustification
      *	the vertical justification of the 2D geometric text.
      *	<br><b>legal values</b>:
      *	<ul><li> 0 : top</li>
      *	<li> 1 : cap</li>
      *	<li> 2 : half</li>
      *	<li> 3 : base</li>
      *	<li> 4 : bottom</li></ul>
      * @param iFont
      *	the font of the 2D geometric text.
      *	<br><b>legal values</b>:
      *	the default value is NULL. It represents the default font.
      * @param iPitch
      *	the pitch of the font.
      *	<br><b>legal values</b>:
      *	<ul><li> 0 : fixed</li>
      *	<li> 1 : variable</li></ul>
      * @param iPath
      *	the way where each character is drawn with respect to the last one drawn.
      *	<br><b>legal values</b>:
      *	<ul><li> 0 : left to right</li>
      *	<li> 1 : top to bottom</li>
      *	<li> 2 : right to left</li>
      *	<li> 3 : bottom to top</li></ul>
      *	<br> Exemple :
      *<pre>
      * 0:  TEST  | 1:  T   | 2:  TSET  | 3:  T
      *           |     E   |           |     S
      *           |     S   |           |     E
      *           |     T   |           |     T
      *</pre>
      * @param iOrientationAngle
      *	an angle in degree to rotate the 2D geometric text in the 2D plan.
      *	The inital angle is determined by <tt>iPath</tt>.
      * @param iSpacingFactor
      *	the space factor between each character of the <tt>iString</tt>.
      *	<br><b>legal values</b>:
      *	the default value is -10000.
      *	<br> it represents 1/7 for stroke font and 0 for type1 font.
      * @param iCompFactor
      *	the compression/extension factor of each character of the <tt>iString</tt>.
      *	<br><b>legal values</b>:
      *	the default value is 1. It means that there is no extension and no compression.
      * @param iSlantAngle
      *	slant angle in degrees. The slant transformation has the following matrix: <pre>
      *  +-                   -+
      *  ! 1  sin(iSlantAngle) !
      *  !                     !
      *  ! 0  cos(iSlantAngle) ! 
      *  +-                   -+</pre>
      *
      *	For example, when 0<<tt>iSlantAngle</tt><90 , it can be 
      *	considered as the composition of the two following 
      *	transformations:
      *	<ul><li>Y affinity with a cos(iSlantAngle) coefficient</li>
      *	<li>shear transformation ("transvection" or "cisaillement" in french) whose:
      *	<ul><li>X axis is the axis which each point is invariant</li>
      *	<li>top-right coefficient of the matrix is tangent(<tt>iSlantAngle</tt>)</li></li></ul>
      * @param iKerningEnable
      *  to apply the kerning value between pair of glyph. Only used for OpenType font.
      *	<br><b>legal values</b>:
      *	<ul><li> 0 : default value, no kerning value will be applied</li>
      *	<li> 1 : kerning value is applied (if the font is an OpenType font)</li></ul>
      * @param iTextVersion
      *  to apply the code enhancement to the text display.
      *	<br><b>legal values</b>:
      *	<ul><li> 0 : default value, no code enhancement will be applied</li>
      *	<li> xxyzz : enhancement is applied if the version is great or eqale to current version</li></ul>
      */
      CAT2DGeometricTextGP (const float iPoint[2],
                            const CATUnicodeString &iString,
                            const float iHeight=10.,
                            const int iHorJustification = 1,
                            const int iVerJustification = 3,
                            const int iPitch = 0,
                            const CATFont * iFont = NULL,
                            const int iPath = 0, 
                            const float iOrientationAngle = 0.f,
                            const float iSpacingFactor = -10000.f, 
                            const float iCompFactor = 1.f,
                            const float iSlantAngle = 0.f,
                            const int iKerningEnable = 0,
                            const unsigned int iTextVersion = 0xFFFFFFFF);

      /** @nodoc */
      CAT2DGeometricTextGP (const CATUnicodeString & iString,
                            const CAT2DGeomTextAttributeSet iAttributeSet,
                            const CATFont * iFont = NULL);

      /** @nodoc */
      CAT2DGeometricTextGP ();

      /** @nodoc */
      virtual ~CAT2DGeometricTextGP() ;
      
      //Streaming
      /** @nodoc */
      virtual void Stream(CATStreamer& str,int savetype=0);
      /** @nodoc */
      virtual void UnStream(CATStreamer& str);
      
      /**
      * Retrieves data about the 2D geometric text.
      * @param oCharCountPtr
      *	the number of characters of the string of the 2D geometric text.
      * @param oStringPtr
      *	the string of characters of the 2D geometric text.
      * @param oFontPtr
      *	the font used to display the 2D geometric text.
      * @param oGeomAttSetPtr
      *	the attribute set for the 2D geometric text (it contains the position, the pitch, the height,...).
      * @param oBoundingBoxPtr
      *	the bounding box for the 2D geometric text.
      */
      virtual void Get ( int* oCharCountPtr,
                         char** oStringPtr,
                         CATFont** oFontPtr,
                         CAT2DGeomTextAttributeSet* oGeomAttSetPtr,
                         CAT2DGeomTextBoundingBox* oBoundingBoxPtr );
      
      /**
      * Gets a 4-points bounding box (Parallelepiped) around the 2D geometric text.
      * @param oPoint
      *	four 2D points of the bounding box (0:x1 , 1:y1, 2:x2 , 3:y2,  4:x3 , 5:y3, 6:x4 , 7:y4 
      *	Caution: oPoint must be allocated by the calling service (length = 8))
      */
      virtual void GetBoundingBox( float* oPoint );// 0:x1 , 1:y1, 2:x2 , 3:y2, 4:x3 , 5:y3, 6:x4 , 7:y4 
                                                   // Caution: oPoint must be allocated by the calling service (length = 8) */
      
      /**
      * Retrieves data about the stroke 2D geometric text.
      * @param oCharCountPtr
      *	the number of characters of the string of the stroke 2D geometric text.
      * @param oStringPtr
      *	the string of characters of the stroke 2D geometric text.
      * @param oFontPtr
      *	the font used to display the stroke 2D geometric text.
      * @param oGeomAttSetPtr
      *	the attribute set for the stroke 2D geometric text (it contains the position, the pitch, the height,...).
      * @param oBoundingBoxPtr
      *	the bounding box for the stroke 2D geometric text.
      */
      virtual void GetStroke ( int* oCharCountPtr,
                               char** oStringPtr,
                               CATFont** oFontPtr,
                               CAT2DGeomTextAttributeSet* oGeomAttSetPtr,
                               CAT2DGeomTextBoundingBox* oBoundingBoxPtr);
      
#ifdef _WINDOWS_SOURCE
      /**
      * Retrieves GDI attributes.
      * @param oTrueTypeEquivalent
      *	the flag to know if an equivalent truetype 2D geometric text exists.
      *	Following attributs have a sense only if <tt>oTrueTypeEquivalent</tt> == 1 
	  * This function will set oTrueTypeEquivalent=1 only for Postscript/Type1 fonts
      *	<br><b>Legal values</b>:
      *	<ul><li> 0 : no TrueType equivalent exist.</li>
      *	<li> 1 : the TrueType equivalent exists.</li></ul>
      * @param oCellHeight
      *	the cell height in model coordinates to create the equivalent true type font.
      * @param oWidth
      *	equal to -1 (there's no utility here).
      * @param oEscapement
      *	the escapement in tenths of degrees to create the equivalent true type font.
      * @param oOrientation
      *	the orientation in tenths of degrees to create the equivalent true type font.
      * @param oWeight
      *	the Weight to create the equivalent true type font.
      * @param oItalicFlag
      *	the flag to specify if the equivalent true type font is an italic or not italic font.
      *	<br><b>Legal values</b>:
      *	<ul><li> 0 : the equivalent true type font is not an italic font.</li>
      *	<li> 1 : the equivalent true type font is an italic font.</li></ul>
      * @param oCharSet
      *	the character set to create the equivalent true type font.
      * @param oPitchAndFamily
      *	the PitchAndFamily to create the equivalent true type font.
      * @param oTypeFaceName
      *	the FaceName to create the equivalent true type font.
      * @param oAlignment
      *	the alignement (an attribute for SetTextAlign).
      * @param oExtraSpacing
      *	the extra spacing in model coordinates (an attribute for SetTextCharacterExtra).
      * @param oString
      *	the string to create the equivalent 2D geometric text.
      * @param oCharCount
      *	the number of characters of <tt>oString</tt>
      * @param oXPoint
      *	the X position in model coordinates of the equivalent D geometric text.
      * @param oYPoint
      *	the Y position in model coordinates of the equivalent D geometric text.
      */
      virtual void GetGDI ( int& oTrueTypeEquivalent,
                            float& oCellHeight,      
                            float& oWidth,          
                            int& oEscapement,       
                            int& oOrientation,      
                            int& oWeight,
                            int& oItalicFlag,       
                            int& oCharSet,
                            int& oPitchAndFamily, 
                            CATUnicodeString& oTypeFaceName,
                            unsigned int& oAlignment, 
                            float& oExtraSpacing,    
                            CATUnicodeString& oString,
                            int& oCharCount,
                            float& oXPoint, 
                            float& oYPoint);         
#endif

      /**
      * Retrieves applicative up values.
      *	This up values are independent of the content of the CAT2DGeometricText
      *	string: they are related to the whole font character set.
      *	If the font contains no symbol, the top and bottom values provided
      *	correspond to the maximum and minimum values of the font characters
      *	bounding box. If the font contains symbols, they are not taken into
      *	account.
      * @param oUpValues
      *	Up values ( <tt>oUpValues</tt> must be allocated by the  calling service)
      *	<br><b>Legal values</b>:
      *	<ul><li> 0 : base -> bottom</li>
      *	<li> 1 : base -> half</li>
      *	<li> 2 : base -> cap</li>
      *	<li> 3 : base -> top</li>
      *	<li> 4 : bottom -> top</li></ul>
      */
      void GetApplicativeUpValues(float oUpValues[5]); 
      
      
      /**
      * Sets the applicative picking rectangle.
      * This service is a dirty solution. The problem is that, currently, there is
      * no way, in Immediate draw, to know if the CATRender corresponds to a picking
      * or not. Consequently, the best solution (distinguish the picking case in
      * Immediate draw and let the application create a new applicative GP which
      * inherits from the CAT2DGeometricTextGP) cannot be implemented. Consequently
      * we are obliged:
      *  <ul><li>to put code in CATPickingRender::Draw2DGeometricText</li>
      *  <li>manage the applicative picking in the CAT2DGeometricTextGP itself</li></ul>
      * @param iAnchorToFirstAlgebraicValue
      *	if you consider the line which is along the 
      *	deplacement direction, and passes through the
      *	anchor point, oriented by the deplacement
      *	direction, this value is the algebraic value
      *	from the anchor point to the intersection with: 
      *	<ul><li>Path right case: left side of the rectangle </li>
      *	<li>path down case: up side of the rectangle</li>
      *	<li>Path left case: right side of the rectangle</li>
      *	<li>path up case: bottom side of the rectangle</li></ul>
      * @param iAnchorToSecondAlgebraicValue
      *	the same as <tt>iAnchorToFirstAlgebraicValue</tt>, except that you take the opposite side of the rectangle 
      * @param iAnchorToTransversalBottom
      *	consider the line which passes through the anchor
      *	point, perpendicular to the deplacement 
      *	direction, with an associated unitary vector, 
      *	oriented so that:<ul>
      *	<li>Path right case: the scalar product between
      *	the unitary vector and the up vector is
      *	positive </li>
      *	<li>path down case: the scalar product between
      *	the unitary vector and the base vector is
      *	positive </li>
      *	<li>Path left case: the scalar product between
      *	the unitary vector and the up vector is
      *	positive   </li>
      *	<li>path up case: the scalar product between
      *	the unitary vector and the base vector is
      *	positive </li></ul>
      *	Then, this value is the algebraic value, along 
      *	this line, from the anchor point to the 
      *	intersection of this line with the following
      *	side of the rectangle:
      *	<ul><li>Path right case: bottom</li>
      *	<li>path down case: left</li>
      *	<li>Path left case: bottom</li>
      *	<li>path up case: left</li></ul>
      * @param iAnchorToTransversalTop
      *	the same as <tt>iAnchorToTransversalBottom</tt>, except that you take the opposite side of the rectangle.
      */
      void SetApplicativePickingRectangle( float iAnchorToFirstAlgebraicValue, 
                                           float iAnchorToSecondAlgebraicValue,
                                           float iAnchorToTransversalBottom,
                                           float iAnchorToTransversalTop);
      
      /**
      *	Reset the applicative picking rectangle.
      */
      void ResetApplicativePickingRectangle();
      
      
      /** @nodoc */
      static void sComputeBoundingBox(CAT2DGeomTextAttributeSet& iGeomAttSet,
                                      CAT2DGeomTextBoundingBox& iBoundingBox,
                                      float* oPoint);// 0:x1 , 1:y1, 2:x2 , 3:y2, 4:x3 , 5:y3, 6:x4 , 7:y4 
                                                     // Caution: oPoint must be allocated by the calling service (length = 8)
      
      
      
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif  
      /**
      * Draws the dynamic graphic primitive with a render.
      * @param iRender
      *	the render used to draw the dynamic graphic primitive.
      */
      virtual void Draw (CATRender& iRender) GP_FUNC_OVERRIDE_FINAL;
      
      
      
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override ImmediateDraw function.")
#endif  
      /**
      * Draws a 2D geometric text.
      * @param iRender
      *	the render used to draw the 2D geometric text.
      * @param iViewpoint
      *	the viewpoint used to draw the 2D geometric text.
      * @param iViewport
      *	the viewport used to draw the 2D geometric text.
      */
      virtual void ImmediateDraw (CATRender & iRender,const CATViewpoint* iViewpoint, const CATViewport* iViewport) GP_FUNC_OVERRIDE_FINAL;   
      
      /** @nodoc */
      float* _ApplicativePickingRectangle;
      
      /** @nodoc */
      int _ApplicativeMetricsFirstCharIndex; 
      
      /** @nodoc */
      int _ApplicativeMetricsSecondCharIndex;
          
      /** @nodoc */
      float* _ApplicativeMetricsFirstSide;
      
      /** @nodoc */
      float* _ApplicativeMetricsSecondSide;
      
      /**
      *	Sets the 2D geometric text background.
      *	This method allows to describe the background of the 2D geometric text.
      *	The background is a polygon filled with one color.
      *	@param iPoint
      *		Points which describe the polygon (they are 2D points).
      *		This is an array of float and its size is equal to two times the number of points (XYXYXY...).
      *		<br><b>Legal values</b>: the default value is NULL. It means there is no background available.
      *	@param iNb_point
      *		Number of 2D points.
      *		<br><b>Legal values</b>: the default value is 0. 	
      *	@param iColor
      *		table which describes the color of the background. The lenght of this 
      *		table is 3 (RGB).
      *		<br><b>Legal values</b>: the default value is NULL.
      */
      void SetTextBackground(float * iPoint=NULL, int iNb_point=0, int * iColor=NULL);
      
      /**
      *	Removes data about the 2D geometric text background.
      *	It initalizes to 0 all datas on the background.
      */
      void UnsetTextBackground();

      /**
      * @nodoc
      */
      virtual void Visit(CATIGPVisitor& iVisitor) const final;

//--------------------------------------------------------------------------

   protected:


      /** @nodoc */
      CAT2DGeomTextAttributeSet _AttributeSet;
      
      /** @nodoc */
      CAT2DGeomTextBoundingBox _BoundingBox;
      
      /** @nodoc */
      CAT2DGeomTextAttributeSet* _StrokeAttributeSetPtr;
      
      /** @nodoc */
      CAT2DGeomTextBoundingBox* _StrokeBoundingBoxPtr;
      
   private:
      
      float * _bkgPolygonPt;
      int     _textBkg, _nbBkgPolygonPt;
      int   * _bkgPolygonColor;
      float _textRatio;
      
      // Get 4 points font bounding box (rectangle, independante of the text string)
      virtual void GetFontBoundingBox( float* oPoint );// 0:x1 , 1:y1, 2:x2 , 3:y2, 4:x3 , 5:y3, 6:x4 , 7:y4 
                                                       // Caution: oPoint must be allocated by the calling service (length = 8)

      void InitWithAttributeSet(const CAT2DGeomTextAttributeSet iAttributeSet);

      // returns ( oPolylineList != nullptr , oTriPrimitiveList  = nullptr ) for not filled text
      // returns ( oPolylineList  = nullptr , oTriPrimitiveList != nullptr ) for filled text
      HRESULT GetTextMesh(CAT2DGeomTextPolylineList*& oPolylineList, CAT2DGeomTextTriPrimitiveList*& oTriPrimitiveList);
};

// CAT2DGeometricTextGP_H
#endif 
