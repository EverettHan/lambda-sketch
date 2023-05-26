#ifndef RecordTools_h
#define RecordTools_h

extern "C" int RecordToolArgument();
extern "C" void DumpError(const int n,const char * postmsg = NULL);
extern "C" const char * GetSourceFile();
extern "C" const char * GetDestFile();
extern "C" const char * GetCmdArg(const int n);

#endif
