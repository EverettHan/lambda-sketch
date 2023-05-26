#ifndef SWXFOREACH_H
#define SWXFOREACH_H

// You don't care for index
#define SWX_FOREACH(_TYPE_, _ITEM_ , _LIST_)\
{	\
    int _size_##_ITEM_ = _LIST_.Size();	\
    for(int _idx_##_ITEM_=0; _idx_##_ITEM_<_size_##_ITEM_; ++_idx_##_ITEM_)	\
	{	\
    _TYPE_ _ITEM_ = static_cast<_TYPE_>(_LIST_[_idx_##_ITEM_+1]);

// You don't care for index
#define SWX_FOREACH_REVERSE(_TYPE_, _ITEM_ , _LIST_)\
{	\
    int _size_##_ITEM_ = _LIST_.Size();	\
    for(int _idx_##_ITEM_=_size_##_ITEM_-1; _idx_##_ITEM_>=0; --_idx_##_ITEM_)	\
	{	\
    _TYPE_ _ITEM_ = static_cast<_TYPE_>(_LIST_[_idx_##_ITEM_+1]);

// You supply variable for 0-based index
#define SWX_FOREACH_IDX(_TYPE_, _ITEM_ , _LIST_, _IDX_)\
{	\
	int _size_ = _LIST_.Size();	\
	for(_IDX_=0; _IDX_<_size_; ++_IDX_)	\
	{	\
		_TYPE_ _ITEM_ = static_cast<_TYPE_>(_LIST_[_IDX_+1]);

// You want to test pointers for NULL -sjr 3/23/12
#define SWX_FOREACH_CHK(_TYPE_, _ITEM_ , _LIST_)\
{	\
    int _size_##_ITEM_ = _LIST_.Size();	\
    for(int _idx_##_ITEM_=0; _idx_##_ITEM_<_size_##_ITEM_; ++_idx_##_ITEM_)	\
	{	\
    _TYPE_ _ITEM_ = static_cast<_TYPE_>(_LIST_[_idx_##_ITEM_+1]);\
	if(!_ITEM_) continue;

// You supply variable for 0-based index, and you want to check pointers for NULL -sjr 3/23/12
#define SWX_FOREACH_IDX_CHK(_TYPE_, _ITEM_ , _LIST_, _IDX_)\
{	\
	int _size_ = _LIST_.Size();	\
	for(_IDX_=0; _IDX_<_size_; ++_IDX_)	\
	{	\
		_TYPE_ _ITEM_ = static_cast<_TYPE_>(_LIST_[_IDX_+1]);\
	    if(!_ITEM_) continue;

#define SWX_FOREACH_END }}

#endif // SWXFOREACH_H
