#ifndef _CATVisSceneGraphCompatibility_
#define _CATVisSceneGraphCompatibility_

#include "SGInfra.h"
#include "CATBoolean.h"

#define SCENEGRAPH_COMPATIBILITY_UV1 1
#define SCENEGRAPH_COMPATIBILITY_WILDCARD_2011 2

void ExportedBySGInfra DumpUVNonCompatibleStack();

CATBoolean ExportedBySGInfra CATGetUVImpactMode();
CATBoolean ExportedBySGInfra IsReadingAuthoringVisu();
void ExportedBySGInfra SetIsReadingAuthoringVisu(CATBoolean OnOff);

class ExportedBySGInfra CATVisLoadingAuthoringVisuSection
{
public:
  CATVisLoadingAuthoringVisuSection();
  ~CATVisLoadingAuthoringVisuSection();
protected:
  CATBoolean _previousValue;
};

class ExportedBySGInfra CATVisSceneGraphCompatibilitySection
{
public:
  CATVisSceneGraphCompatibilitySection(unsigned int level);
  ~CATVisSceneGraphCompatibilitySection();
protected:
  unsigned int _oldLevel;
};


#endif
