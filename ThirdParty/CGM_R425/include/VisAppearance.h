//===================================================================
// COPYRIGHT Dassault Systemes 2020-09-08
//===================================================================

#ifndef VisAppearance_H
#define VisAppearance_H

#include "SGInfra.h"
#include "CATVisColorf.h"

class ExportedBySGInfra VisAppearance
{
public:
  enum EType
  {
    eBasic, eGASLook, eTransparent,
    eClay, eWhiteMatPlaster, eGreyShinyPlastic,
    eCastAluminum, eMachinedAluminum,
    eCastSteel, eBrushedSteel, eMachinedStainlessSteel,
    eCopper,
    eBrass,
    eGenericPlastic, eGenericMetal, 
    eQAAutomation, // Internal Appearance for QA odt, do not use !
    eCount
  };

  VisAppearance();
  ~VisAppearance();

  bool operator==(const VisAppearance& iAppearance) const;
  bool operator!=(const VisAppearance& iAppearance) const;

  EType         Type;
  float         Shininess;
  CATVisColorf  Color;
  float         Opacity;
  bool          UseObjectColor;

  CATVisColorf  TrianglesColor;
  float         TrianglesOpacity;
};

//-----------------------------------------------------------------------

#endif
