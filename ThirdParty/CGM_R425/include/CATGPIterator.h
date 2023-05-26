#ifndef CATGPIterator_h
#define CATGPIterator_h

// COPYRIGHT DASSAULT SYSTEMES 2002
/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */


#include "SGInfra.h"

class CATRep;
class CATGraphicPrimitive;

class ExportedBySGInfra CATGPIterator
{
public:
   CATGPIterator(CATRep & iRep);
	short int HasMoreElements();
	CATGraphicPrimitive * Next();
	void First();
private:
   unsigned int _index;
   CATRep & _rep;
};

#endif
