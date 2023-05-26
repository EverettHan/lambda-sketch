#ifndef _CATPLMCompassFilterFactory_H
#define _CATPLMCompassFilterFactory_H

#include <CATBaseUnknown.h>
#include <CATPLMCompassModule.h>

/**
 * Factory services for PLM Compass filter
 **/
class ExportedByCATPLMCompass CATPLMCompassFilterFactory
{
public:
	/**
	 * Instanciate filter class
	 **/
	static CATBaseUnknown_var CreateFilter(void);
};

#endif
