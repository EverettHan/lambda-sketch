#ifndef _CATViewMacros_H
#define _CATViewMacros_H

#define CATImplementNotification( classname, notification )\
class CAT##classname##notification##Notification: public CATNotification\
{\
	CATDeclareClass;\
};\
CATImplementClass( CAT##classname##notification##Notification,\
				  Implementation,\
				  CATNotification,\
				  CATNull );\
CATNotification * classname::Get##notification##Notification(void)\
{\
	static CAT##classname##notification##Notification notif;\
	return &notif;\
}

#endif
