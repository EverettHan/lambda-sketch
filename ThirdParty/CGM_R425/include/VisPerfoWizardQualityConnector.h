//===================================================================
// COPYRIGHT Dassault Systemes 2019-07-22
//===================================================================
// VisPerfoWizardQualityConnector.h
// Header definition of class VisPerfoWizardQualityConnector
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2019-07-22 Creation : MPD5
//===================================================================

#ifndef VisPerfoWizardQualityConnector_H
#define VisPerfoWizardQualityConnector_H


#include "VisQualityData.h"
//class CATVizViewer;
class CATSupport;

class ExportedBySGInfra VisPerfoWizardQualityConnector
{
public:
	VisPerfoWizardQualityConnector();
	~VisPerfoWizardQualityConnector();
	void GetCurrentQuality(CATSupport& support, VisQuality::RenderMode iMode, VisQualityData &oData)const;
};

#endif

