#ifndef CNextMobile_H
#define CNextMobile_H

#include "CATInteractiveApplication.h"

#if defined (__CATAfrAppliMobile)
#define ExportedByCATAfrAppliMobile DSYExport
#else
#define ExportedByCATAfrAppliMobile DSYImport
#endif
#include "DSYExport.h"

/**
 * Class to define a mobile application
 */
class ExportedByCATAfrAppliMobile CNextMobile : public CATInteractiveApplication
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iApplicationName the application name
	 */
	CNextMobile(const CATString& iApplicationName);

	/**
	 * Destructor
	 */
	virtual ~CNextMobile();

	/**
	 * Initialize licensing
	 * You can override this method if you don't want to use default CATLM::startupRepresentation mode
	 */
	virtual void InitializeLicensing();

	// CATInteractiveApplication
	virtual void BeginApplication();
	virtual int EndApplication();
};

#endif
