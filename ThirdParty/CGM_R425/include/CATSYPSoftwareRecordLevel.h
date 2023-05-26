#ifndef CATSYPSoftwareRecordLevel_H
#define CATSYPSoftwareRecordLevel_H

#include <UIVCoreTools.h>


/** 
 * Defines necessary functions for writing and reading the SoftwareRecordLevel for the given id when replaying an odt,
 * and testing if a given level is newer or older than the one stored.
 * 
 * @param id the id that will be used to identify the versionning. It must be unique. For example, it can be the name of your class.
 * @param i_currentLevelToRecord the last level. When recording a new odt, it will be the one stored.
 * 
 * It is advised to comment the different levels before the call to this macro.
 * 
 * @par Complete use example
 * @code
 * /**
 *  *The value of the "..." record level are :
 *  *    - 1: 2012-04-05 this version controls ...
 *  *    - 2: 2012-08-28 this version controls ...
 *  *    - 3: 2012-12-19 this version controls ...
 *  * /
 *  DEFINE_RECORD_LEVEL(MyClass, 3);
 *  
 *  class MyClass
 *  {
 *  public:
 *    MyClass::MyClass()
 *    {
 *       INIT_RECORD_LEVEL(MyClass);
 *    }
 *    
 *    void MyClass::DoStuff()
 *    {
 *      if(IS_VERSION_NEWER_OR_SAME_THAN(MyClass, 3){
 *        // new behaviour : after version 3
 *      }else if(IS_VERSION_OLDER_THAN(MyClass, 1){
 *        // very old behaviour : before (strictly) version 1
 *      }else{
 *        // old behaviour : version 1 & 2
 *      }
 *    //printf("Debug : version used %d", GET_VERSION(MyClass))
 *    }
 * @endcode
 * 
 * @see INIT_RECORD_LEVEL
 * @see IS_VERSION_OLDER_THAN
 * @see IS_VERSION_OLDER_OR_SAME_THAN
 * @see IS_VERSION_NEWER_THAN
 * @see IS_VERSION_NEWER_OR_SAME_THAN
 * @see GET_VERSION
 */
#define DEFINE_RECORD_LEVEL(id, i_currentLevelToRecord)\
  static struct{ int levelAtReplay; const int levelToRecord; CATBoolean levelToRecordInitialized;} _srl##id = {-1, (i_currentLevelToRecord), FALSE};\
  \
  int GetRecordLevel_##id()\
  {\
    if(_srl##id.levelAtReplay == -1)\
    {\
      /* called only once per id */\
      int recordLevel = s_GetRecordLevel((char*)#id);\
      if(recordLevel == -2)\
      {\
        /* we are not replaying, the level is equivalent to the lastest, given in parameter of DEFINE_RECORD_LEVEL */\
        _srl##id.levelAtReplay = i_currentLevelToRecord;\
      }else{\
        _srl##id.levelAtReplay = recordLevel;\
      }\
    }\
    return _srl##id.levelAtReplay;\
  }\
  \
  CATBoolean RecordLevel_##id##_IsOlderThan(int i_level)\
  {\
    int softwareRecordLevel = GetRecordLevel_##id();\
    return softwareRecordLevel < (i_level);\
  }\
  \
  CATBoolean RecordLevel_##id##_IsOlderOrSameThan(int i_level)\
  {\
    int softwareRecordLevel = GetRecordLevel_##id();\
    return softwareRecordLevel <= (i_level);\
  }\
  \
  CATBoolean RecordLevel_##id##_IsNewerThan(int i_level)\
  {\
    int softwareRecordLevel = GetRecordLevel_##id();\
    return softwareRecordLevel > (i_level);\
  }\
  \
  CATBoolean RecordLevel_##id##_IsNewerOrSameThan(int i_level)\
  {\
    int softwareRecordLevel = GetRecordLevel_##id();\
    return softwareRecordLevel >= (i_level);\
  }

/** 
 * Initializes the RecordLevel.
 * When in capture mode, this will call SetSoftwareRecordLevel with the level specified in the parameter of DEFINE_RECORD_LEVEL.
 * Even if you call this function multiple times, it will call SetSoftwareRecordLevel only once per id.
 */
#define INIT_RECORD_LEVEL(id)\
  do\
  {\
    if(!_srl##id.levelToRecordInitialized)\
    {\
      s_INIT_RECORD_LEVEL((char*)#id, _srl##id.levelToRecord);\
      _srl##id.levelToRecordInitialized = TRUE;\
    }\
  }while(0)

/**
 * Example of use : if(IS_VERSION_OLDER_THAN(My_ID, 3) ...
 * Returns :
 * - FALSE if this is not an odt replaying (interactive mode)
 * - TRUE if the record level for this id is strictly older than the level stored in SoftwareRecordLevel for this id.
 * - FALSE if the record level for this id is newer than, or equal to the level stored in SoftwareRecordLevel for this id.
 */
#define IS_VERSION_OLDER_THAN(id, i_level)\
  (RecordLevel_##id##_IsOlderThan((i_level)))

/**
 * Example of use : if(IS_VERSION_OLDER_OR_SAME_THAN(My_ID, 3) ...
 * Returns :
 * - TRUE if this is not an odt replaying (interactive mode) and the latest version is the same version as i_level
 * - FALSE if this is not an odt replaying (interactive mode) and the latest version is bigger than i_level
 * - TRUE if the record level for this id is older or the same than the level stored in SoftwareRecordLevel for this id.
 * - FALSE if the record level for this id is strictly newer than the level stored in SoftwareRecordLevel for this id.
 */
#define IS_VERSION_OLDER_OR_SAME_THAN(id, i_level)\
  (RecordLevel_##id##_IsOlderOrSameThan((i_level)))

/**
 * Example of use : if(IS_VERSION_NEWER_THAN(My_ID, 2) ...
 * Returns :
 * - TRUE if this is not an odt replaying (interactive mode)
 * - TRUE if the record level for this id is strictly newer than the level stored in SoftwareRecordLevel for this id.
 * - FALSE if the record level for this id is older or the same than the level stored in SoftwareRecordLevel for this id.
 */
#define IS_VERSION_NEWER_THAN(id, i_level)\
  (RecordLevel_##id##_IsNewerThan((i_level)))

/**
 * TODO DOC 
 * Example of use : if(IS_VERSION_NEWER_OR_SAME_THAN(My_ID, 2) ...
 * Returns :
 * - TRUE if this is not an odt replaying (interactive mode)
 * - TRUE if the record level for this id is newer or the same than the level stored in SoftwareRecordLevel for this id.
 * - FALSE if the record level for this id is strictly older than the level stored in SoftwareRecordLevel for this id.
 */
#define IS_VERSION_NEWER_OR_SAME_THAN(id, i_level)\
  (RecordLevel_##id##_IsNewerOrSameThan((i_level)))

/**
 * Example of use : int version = GET_VERSION(My_ID);
 * Returns :
 * - When replaying, the version stored in the .ver file of the record, for this id
 * - When replaying, 0 if such id does not exist in this file.
 * - If not replaying, the level given in parameter of DEFINE_RECORD_LEVEL, which is the highest current level.
 * 
 * @see CATRecord::GetSoftwareRecordLevel
 */
#define GET_VERSION(id)\
  GetRecordLevel_##id()



// ------------------------------------------------------------------------------

extern "C" ExportedByUIVCoreTools
int s_GetRecordLevel(char* id);

extern "C" ExportedByUIVCoreTools
void s_INIT_RECORD_LEVEL(char* id, int i_level);


#endif //CATSYPSoftwareRecordLevel_H
