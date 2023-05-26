#ifndef __CATOmbDownwardData_H
#define __CATOmbDownwardData_H

#include "CATIOmbDownwardData.h"
#include "CATMainwin.h"
#include "CATOmbDWC.h"

//returns a CATIOmbDownwardData implementation 
ExportedByCATOmbDWC CATIOmbDownwardData& CATOmbGetDownwardData(const char* iLateType);


#endif
