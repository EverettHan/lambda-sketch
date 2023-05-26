#ifndef SWXUTVSPROFILEHELPER_H
#define SWXUTVSPROFILEHELPER_H


#include "SWXUtGeneral.h"


//Helper class to maniuplate Visual Studio profiling
//Create this object on the stack to profile just the
//function in which it is created
//
//Otherwise you can directly invoke ResumeProfile/SuspendProfile
//to enable and disable profile for the area of interest
class ExportedBySWXUtGeneral SWXUtVsProfileHelper 
{
public:

	SWXUtVsProfileHelper(bool iEnableProfile = true);

	~SWXUtVsProfileHelper();
	
private:

	bool mEnabledProfile;
};


ExportedBySWXUtGeneral void SWXUtVsHelperStartProfile();
ExportedBySWXUtGeneral void SWXUtVsHelperStopfile();
ExportedBySWXUtGeneral void SWXUtVsHelperAddCommentMark(const char* iComment);

#include "SWXUtVsProfileCommentHelper.h"

#endif //SWXUTVSPROFILEHELPER_H


