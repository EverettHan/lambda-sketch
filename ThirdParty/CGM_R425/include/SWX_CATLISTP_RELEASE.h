#ifndef SWX_CATLISTP_RELEASE_H
#define SWX_CATLISTP_RELEASE_H

#define SWX_CATLISTP_RELEASE(_LIST_)\
{	\
	for (int _idx_ = 1; _idx_ <= (_LIST_).Size(); _idx_++)\
	{\
	    CATSysReleasePtr( (_LIST_)[_idx_] );      \
	}\
	(_LIST_).RemoveAll();\
}

#endif // SWX_CATLISTP_RELEASE_H
