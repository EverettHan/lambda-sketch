/* -*-c++-*- */
#ifndef CATVisPropertiesPrivateValues_H
#define CATVisPropertiesPrivateValues_H
//
// COPYRIGHT DASSAULT SYSTEMES 1999
//

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATCORBATypes.h" 

#include "CATErrorDef.h" 

#include "BigLittle.h" 

/** @nodoc */
typedef struct
{
public:
  union
  {
    octet basic;
    struct
    {
#ifdef _ENDIAN_LITTLE
      unsigned char showSet   :  1;
      unsigned char pickSet   :  1;
      unsigned char layerSet  :  1;
      unsigned char show      :  2;
      unsigned char pick      :  1;
      unsigned char layerSup  :  2;
#else
      unsigned char layerSup  :  2;
      unsigned char pick      :  1;
      unsigned char show      :  2;
      unsigned char layerSet  :  1;
      unsigned char pickSet   :  1;
      unsigned char showSet   :  1;
#endif
    } extend;
  } uOctet;

  octet layer;

  union
  {
    octet basic;
    struct
    {
#ifdef _ENDIAN_LITTLE
      unsigned char lowIntSet         :  1;
      unsigned char lowInt	          :  1;
      unsigned char RenderingStyleSet :  1;
      unsigned char RenderingStyle	  :  4;
      unsigned char effectIDSet       :  1;
#else
      unsigned char effectIDSet       :  1;
      unsigned char RenderingStyle	  :  4;
      unsigned char RenderingStyleSet :  1;
      unsigned char lowInt	          :  1;
      unsigned char lowIntSet         :  1;
#endif
    } extend;
  } uOctet2;

  unsigned char effectID[16];

} sGlobalVPAttribut;

/** @nodoc */
typedef struct
{
public:
  union
  {
    octet basic;
    struct
    {
  #ifdef _ENDIAN_LITTLE
      unsigned char colorSet       :  1;
      unsigned char opacitySet     :  1;
      unsigned char symbolSet      :  1;
      unsigned char lineTypeSet    :  1;
      unsigned char widthSet       :  1;
      unsigned char inheritanceSet :  1;
      unsigned char padding        :  2;
  #else
      unsigned char padding        :  2;
      unsigned char inheritanceSet :  1;
      unsigned char widthSet       :  1;
      unsigned char lineTypeSet    :  1;
      unsigned char symbolSet      :  1;    
      unsigned char opacitySet     :  1;    
      unsigned char colorSet       :  1;
  #endif
    } extend;
  } uSets;

  octet red;
  octet green;
  octet blue;
  octet opacity;
  octet symbol;
  octet lineType;
  octet width;

  union
  {
    octet inheritance;
    struct
    {
  #ifdef _ENDIAN_LITTLE
      unsigned char colorInheritance       :  1;
      unsigned char opacityInheritance     :  1;
      unsigned char symbolInheritance      :  1;
      unsigned char lineTypeInheritance    :  1;
      unsigned char widthInheritance       :  1;
      unsigned char padding                :  3;
  #else
      unsigned char padding                :  3;
      unsigned char widthInheritance       :  1;
      unsigned char lineTypeInheritance    :  1;
      unsigned char symbolInheritance      :  1;    
      unsigned char opacityInheritance     :  1;    
      unsigned char colorInheritance       :  1;
  #endif
    } extend;
  } uInheritance;

} sVPAttribut;


#include "CATVisItf.h"

/**
* Base class for the CATVisPropertiesValues class.
* <b>Role</b>: Do not used this class. See @href CATVisPropertiesValues 
*/
class ExportedByCATVisItf CATVisPropertiesPrivateValues
{
public:

  /** @nodoc */
  CATVisPropertiesPrivateValues ();

  /** @nodoc */
  CATVisPropertiesPrivateValues (const CATVisPropertiesPrivateValues& value);

  /** @nodoc */
  void ResetAllValues ();

    /** @nodoc */
  inline void  SetSetOctet     (octet iSets) { _att.uSets.basic = iSets; };
    /** @nodoc */
  inline octet GetSetOctet     () { return _att.uSets.basic; };

    /** @nodoc */
  void         SetColorOctet   (octet iRed, octet iGreen, octet iBlue);
    /** @nodoc */
  inline int   IsColorOctetSet () { return _att.uSets.extend.colorSet; };
    /** @nodoc */
  inline octet GetRedOctet     () { return _att.red; };
    /** @nodoc */
  inline octet GetGreenOctet   () { return _att.green; };
    /** @nodoc */
  inline octet GetBlueOctet    () { return _att.blue; };

    /** @nodoc */
  void         SetOpacityOctet   (octet iOpacity);
    /** @nodoc */
  inline int   IsOpacityOctetSet () { return _att.uSets.extend.opacitySet; };
    /** @nodoc */
  inline octet GetOpacityOctet   () { return _att.opacity; };

    /** @nodoc */
  void         SetSymbolOctet   (octet iSymbol);
    /** @nodoc */
  inline int   IsSymbolOctetSet () { return _att.uSets.extend.symbolSet; };
    /** @nodoc */
  inline octet GetSymbolOctet   () { return _att.symbol; };

    /** @nodoc */
  void         SetLineTypeOctet   (octet iLineType);
    /** @nodoc */
  inline int   IsLineTypeOctetSet () { return _att.uSets.extend.lineTypeSet; };
    /** @nodoc */
  inline octet GetLineTypeOctet   () { return _att.lineType; };

    /** @nodoc */
  void         SetWidthOctet   (octet iWidth);
    /** @nodoc */
  inline int   IsWidthOctetSet () { return _att.uSets.extend.widthSet; };
    /** @nodoc */
  inline octet GetWidthOctet   () { return _att.width; };

    /** @nodoc */
  void         SetInheritanceOctet   (octet iInheritance);
    /** @nodoc */
  inline int   IsInheritanceOctetSet () { return _att.uSets.extend.inheritanceSet; };
    /** @nodoc */
  inline octet GetInheritanceOctet   () { return _att.uInheritance.inheritance; };
  /** @nodoc */
  inline int  IsShowOctetSet ()   { return _globalAtt.uOctet.extend.showSet; };
    /** @nodoc */
  inline int  IsPickOctetSet ()   { return _globalAtt.uOctet.extend.pickSet; };
    /** @nodoc */
  inline int  IsLayerOctetSet ()  { return _globalAtt.uOctet.extend.layerSet; };
  /** @nodoc */
  inline int  IsLowIntOctetSet ()  { return _globalAtt.uOctet2.extend.lowIntSet; };
  /** @nodoc */
  inline int  IsEffectIDSet ()  { return _globalAtt.uOctet2.extend.effectIDSet; };

  /** @nodoc */
  void  SetGlobalOctet (int iNumOctet, octet iOctet);
    /** @nodoc */
  octet GetGlobalOctet (int iNumOctet);

  
protected:
  sVPAttribut         _att;
  sGlobalVPAttribut   _globalAtt;

};


#endif
