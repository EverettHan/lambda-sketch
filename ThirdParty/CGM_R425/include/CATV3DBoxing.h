#ifndef CATV3DBoxing_H
#define CATV3DBoxing_H

#include <CATSYPDeclareBoxing.h>
#include <CATV3DLay3DConstraints.h>
#include <CATV3DManipulatorParameters.h>
#include <CATV3DAdjustment.h>
#include <CATV3DOrientation.h>

CATSYP_DECLARE_BOXING( ExportedByVisuImmersive3D, CATV3DLay3DConstraints );
CATSYP_DECLARE_BOXING( ExportedByVisuImmersive3D, CATV3DManipulatorParameters );
CATSYP_DECLARE_BOXING( ExportedByVisuImmersive3D, CATV3DAdjustment);
CATSYP_DECLARE_BOXING( ExportedByVisuImmersive3D, CATV3DOrientation);

#endif

