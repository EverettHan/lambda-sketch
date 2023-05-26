#ifndef CATSWXVisuViewWatcher_H
#define CATSWXVisuViewWatcher_H

#include "CATVisFoundation.h"
#include "CATEventSubscriber.h"

class CATVizViewer;

/**
 * Class exists to watch for destruction of specific views and release
 * viewpoint editors that were created by SWX code.
 */
class ExportedByCATVisFoundation CATSWXVisuViewWatcher : public CATEventSubscriber
{
	CATDeclareClass;

public:
	static void ReleaseOnViewerDestruction(CATVizViewer* iVizViewer, CATBaseUnknown* iToRelease);

	void Viewpoint3DDestroyed( CATCallbackEvent ie, void *, CATNotification *iEvent, CATSubscriberData is, CATCallback icb);

private:
	CATSWXVisuViewWatcher() {}
};

#endif
