// COPYRIGHT Dassault Systemes 2004
#ifndef CATPLMCompassMode_H
#define CATPLMCompassMode_H

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>
#include <CATString.h>

/**
 * CATPLMCompassMode
 **/
typedef int PLMCompassMode;

// Obsolete defines for mode, please migrate to PLMCompassMode_*
#ifndef None
#define None	0
#endif
#define North	1
#define South	2
#define East	3
#define West	4

#define PLMCompassMode_None		0
#define PLMCompassMode_North	1
#define PLMCompassMode_South	2
#define PLMCompassMode_East		3
#define PLMCompassMode_West		4

#define PLMCompassMode_WestDesign		5		// Design objects for Live Shape
#define PLMCompassMode_Compass		6

class ExportedByCATAfrItf CATPLMCompassMode: public CATBaseUnknown
{
CATDeclareClass;
public:

    CATPLMCompassMode( PLMCompassMode iMode= PLMCompassMode_None, CATBoolean iSimulation= FALSE );

    
    void SetMode(PLMCompassMode iMode);
    PLMCompassMode GetMode() const;

    void SetSimulationMode(CATBoolean iSimulation);
    CATBoolean GetSimulationMode()const;


    CATPLMCompassMode (const CATPLMCompassMode &iCopy);
    CATPLMCompassMode& operator=(const CATPLMCompassMode&);

    CATBoolean operator==(const CATPLMCompassMode& i_right) const;

    CATBoolean operator!=(const CATPLMCompassMode& i_right) const;
	CATString GetIcon( void ) const;
private:

    PLMCompassMode  _Mode;
    CATBoolean      _Simulation;
};

#include <CATLISTP_Clean.h>
#define CATLISTP_Append
#define CATLISTP_RemoveAll
#include <CATLISTP_Declare.h>
CATLISTP_DECLARE( CATPLMCompassMode );
typedef CATLISTP( CATPLMCompassMode ) CATListOfCATPLMCompassMode;
#include <CATSYPDeclareBoxing.h>
CATSYP_DECLARE_BOXING( ExportedByCATAfrItf, CATPLMCompassMode );
////-----------------------------------------------------------------------
#include <CATSYPFactoryResult.h>

extern "C" ExportedByCATAfrItf 
CATSYPFactoryResult CATSYPCATPLMCompassModeFactory(const CATUnicodeString& i_string);
extern "C" ExportedByCATAfrItf 
HRESULT CATSYPCATPLMCompassModeSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif
