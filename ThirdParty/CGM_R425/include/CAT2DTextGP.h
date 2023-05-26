#ifndef CAT2DTextGP_H
#define CAT2DTextGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"
#include "CATDynamicGP.h"
#include "CATVisMacroForInterfaces.h"

class CATFont;
class CATUnicodeString;
class CATStreamer;

class IVisSG2DPrimitive;
class CAT2DTextGPIVisSG2DPrimitiveBOAImpl;

/**
* Class to create a dynamic graphic primitive of 2D text.
*/
class ExportedBySGInfra CAT2DTextGP : public CATDynamicGP
{
  friend class SGCGRStreamerFor2DTextGP;
  friend class SGCGRNodesFactoryA;
  friend class CAT2DGeometricTextGP;
 CATDeclareClass;
 CATVisDeclarePublicInterfaceAdhesion(CAT2DTextGP, IVisSG2DPrimitive, CAT2DTextGPIVisSG2DPrimitiveBOAImpl);
  
public:
  
    /**
   *@nodoc
   */
    virtual void Stream(CATStreamer& oStr,int iSavetype=0);

  /**
   * @nodoc
   */
    virtual void UnStream(CATStreamer& iStr);

  protected:
    
BEGIN_MIGRATE_GP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Do not derive this class" )
#endif
/**
* Constructs a 2D text Graphic primitive.
* @param iPoint
*	the position of the 2D text (XY).
* @param iString
*	the string of characters which composed the text of the 2D text Graphic primitive.
* @param iFont
*	the font used for the text.
*/
    CAT2DTextGP (const float iPoint[2], const CATUnicodeString &iString, const CATFont* iFont=NULL);

/**
* Constructs a default 2D text Graphic primitive.
*/
    CAT2DTextGP ();
END_MIGRATE_GP_CTOR

protected:
    virtual ~CAT2DTextGP();
/**
* @nodoc
*/
    float _Point[2];
    

/**
* @nodoc
*/
    int _CharCount;
    

/**
* @nodoc
*/
    unsigned short* _String;
    

/**
* @nodoc
*/
    CATFont* _Font;
};


#endif
