#ifndef CATCreateCSStreamToolGM_H
#define CATCreateCSStreamToolGM_H

class CATCSStreamTool;
class CATGeoFactory;

#include "StreamGM.h" 
#include "CATCSStreamToolGM.h" 

ExportedByStreamGM CATCSStreamTool* CATCreateCSStreamToolGM(CATCDSStreamMode iMode = smSTREAM);

#endif
