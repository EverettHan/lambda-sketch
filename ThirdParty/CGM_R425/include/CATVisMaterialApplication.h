// COPYRIGHT DASSAULT SYSTEMES 2007
//===================================================================
//
// CATVisMaterialApplication.h
// Header definition of CATVisMaterialApplication
//
//===================================================================
//
// Usage notes: Application properties of a CATGraphicMaterial,
//              used for 2-sided multitexturing purposes.
//
//===================================================================
//
//  April 2007                                          Creation: FOR
//===================================================================
#ifndef CATVisMaterialApplication_H
#define CATVisMaterialApplication_H



#include "CATVisMaterialSide.h"
#include "CATVizBaseIUnknown.h"
#include "SGInfra.h"

/**
* Class representing the application properties of a Material.
*
* <br><b>Role</b>: Holds the application properties of a Material such as the targetted texture coordinate set and the side of the face.
* <p>
*
* @href CATVisMaterialSide, CATGraphicMaterial
*/

//enum which defines which texture set we will use in the primitive



typedef enum 
{  
  TEX_COORD_SET_0,
  TEX_COORD_SET_1,
  TEX_COORD_SET_2,
  TEX_COORD_SET_3,
  TEX_COORD_SET_4,
  TEX_COORD_SET_5,
  TEX_COORD_SET_6,
  TEX_COORD_SET_7, 
} VisTexCoordSet;

//enum which defines the texture unit used
typedef enum 
{  
  CHANNEL_0,
  CHANNEL_1,
  CHANNEL_2,
  CHANNEL_3,
  CHANNEL_4,
  CHANNEL_5,
  CHANNEL_6,
  CHANNEL_7, 
} Channel;

class ExportedBySGInfra CATVisMaterialApplication : public CATVizBaseIUnknown
{

public:

  CATVisMaterialApplication();
  CATVisMaterialApplication( const Channel iChannel, VisTexCoordSet iTexCoordSet, const CATVisMaterialSide& iSide = CATVisFrontAndBackMaterial);

  const CATVisMaterialSide& GetSide() const;
  void SetSide(const CATVisMaterialSide& iSide);

  const Channel& GetChannel() const;
  void SetChannel(const Channel& iChannel);

  const VisTexCoordSet& GetTexCoordSet() const;
  void SetTexCoordSet(const VisTexCoordSet& iTexCoordSet);
  virtual ~CATVisMaterialApplication();

  CATVisMaterialApplication(const CATVisMaterialApplication &);
  CATVisMaterialApplication & operator=(const CATVisMaterialApplication &);

private:

  void Copy(const CATVisMaterialApplication &);

  CATVisMaterialSide _side;
  Channel _channel; //texture unit
  VisTexCoordSet _texCoordSet; //set of coordinates to use



};

#endif
