#ifndef SWXUTVSPROFILECOMMENTHELPER_H
#define SWXUTVSPROFILECOMMENTHELPER_H


#include "SWXUtGeneral.h"


class ExportedBySWXUtGeneral SWXUtVsProfileCommentHelper 
{
public:

	SWXUtVsProfileCommentHelper(const char* iComment);
	~SWXUtVsProfileCommentHelper();
	
private:

	const char* mCommentString;
};




#endif //SWXUTVSPROFILECOMMENTHELPER_H






