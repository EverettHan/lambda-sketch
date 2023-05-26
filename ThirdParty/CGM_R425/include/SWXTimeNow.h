
#ifndef SWXTimeNow_H
#define SWXTimeNow_H

#include <time.h>
#include <sys/timeb.h>
#include "SWXUtMinMax.h"


CATULONG32 SWXTimeNow()
{
	struct timeb t;
	ftime(&t);
	return CATULONG32(t.time*1000 + t.millitm);
}
void SWXDelayMe(int msecs = 100)
{
	msecs = SWXUtMinMax(0,msecs,5000);

	CATULONG32 t = SWXTimeNow();
	while(SWXTimeNow()-t < CATULONG32(msecs)) {};

}

#endif


