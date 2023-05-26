#ifndef __CATOmyMTPlatformThread_v1
#define __CATOmyMTPlatformThread_v1

#include "stdlib.h"
#include "stdio.h"

#include "CATThreads.h"
#include "CATConstantsForThreads.h"
#include "CATOmyMTPlatform.h"
#include "CATSysTSUnicodeString.h"

class CATOmyTaskRunContext;
class CATOmyMTPlatformPrivate;
class CATOmyThreadPoolManager;

class ExportedByCATOmyMTPlatform CATOmyMTPlatformThread : public CATThreads {

  public:
    //constructeur
    CATOmyMTPlatformThread(char * NameBase, CATOmyMTPlatformPrivate * iPrivatePointer);

    // destructeur
    ~CATOmyMTPlatformThread(){};

    // pour récupérer l'id INTERNE du Thread. Ne pas confondre avec l'id du CATThreads.
    inline int GetId() {return _id;};

    // pointeur sur le contexte

    inline CATOmyTaskRunContext * GetContext(){return _pContext;};

    // retourne le nom interne du thread.
    CATSysTSUnicodeString GetName();


    void SetContext(CATOmyTaskRunContext *iMyContext);
    inline CATOmyMTPlatformPrivate & GetPrivatePlatformPointer(){return *_pPrivatePlatform;};

    // méthode appellée automatiquement lorsque l'on effectue un run() sur un thread
    // cf. code SYSTEM CATThreads
    CATThreadsReturnCode Begin(void *iMyArg);

  private: 

    // identifiant du thread
    int _id; 
    // compteur de thread
    static int _nbThread;
    // pointer vers le contexte du thread
    CATOmyTaskRunContext * _pContext;
    // label du thread
    CATSysTSUnicodeString _name;
    // pointeur vers la plateforme privée
    CATOmyMTPlatformPrivate * _pPrivatePlatform;

};

#endif

