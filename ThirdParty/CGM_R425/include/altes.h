#include "CATV4System.h"
#include "CATDataType.h"

extern "C" ExportedByCATV4System 
int altes(void *tab_, const int *ityp_, const int *lalloc_, CATINTPTR *iofset_, 
        int *indice_);

extern "C" ExportedByCATV4System 
int altes8(void *tab_, const int *ityp_, const CATINTPTR *lalloc_, CATINTPTR *iofset_, 
        CATINTPTR *indice_);

extern "C" ExportedByCATV4System 
int altes64(void *tab_, const CATINTPTR *ityp_, const CATINTPTR *lalloc_, CATINTPTR *iofset_, 
        CATINTPTR *indice_);
