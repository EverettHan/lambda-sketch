/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 2000						                */
/*=======================================================================*/
/*                                                                       */
/*  CATComMessage                                                        */
/*                                                                        */
/*  Usage Notes: Public Async Messages                                  */
/*                                                                       */
/*=======================================================================*/
/*  Creation Oct	2000                                 jnm             */
/*=======================================================================*/
#ifndef _CATComMessage_H
#define _CATComMessage_H

#define CATComMsgMaxSize 50000

//////////////////////////////////////////////////////////////////////////////
// Macro pour l'instanciation par nom des messages
#define CATImplementAutoInstanciate(MyClassName) \
extern "C" DSYExport CATComMessage* FctCreate##MyClassName() \
	{ \
		return new MyClassName();\
    }
#include "DSYExport.h"
/////////////////////////////////////////////////////////////////////////









/////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "CATComServices.h"

#include "CATComFileType.h"
#include "CATErrorDef.h"
#include "CATComHeader.h"

class CATUnicodeString;

class ExportedByCATComServices CATComMessage
{

   public :

	  CATComMessage ();

      virtual ~CATComMessage () ;

	  //
	  virtual HRESULT BuildMessage(char* buf, int size);
	   //

	  // WARNING  these 2 methods returns internal data 
	  // Do not modify 
	  virtual HRESULT GetBuffer(char* buf , int& size);
	  virtual HRESULT PutBuffer(char* buf , int size);

	  void SetAsXML();
	  //



	  int GetSize();
	  //

	  HRESULT CheckSize();

	  int IsSplitted();

	  virtual HRESULT ReceiveSegment(char* buf, int size)=0;

	  //Post recpetion method
	  virtual HRESULT Execute()=0;

	  void Dump();

	  char*	GetSenderHostname() {	return _SenderHostname;};

	  HRESULT GetMessageClass(const char* & messageClass);

	  char* GetSenderUserName();
	  

    protected:

	 //Message ALLOCATION method
	 virtual void SetMessageLength(int length);
	 void SetMessageType(const char* classname, const char* lib, const char* SenderId);
	 void InitHeader();


	 HRESULT PutUnicodeString(const CATUnicodeString* );
	 HRESULT PutString(const char*, int);
	 HRESULT PutInt(int);

	 HRESULT GetUnicodeString(CATUnicodeString& );
	 HRESULT GetString(char*&, int&);
	 HRESULT GetInt(int &);

	 HRESULT PutFile(const char* fileName, CATComFileType ftype);
	 HRESULT GetFileHandle(const char* fileName, CATComFileType ftype,int RW, unsigned int& fd);
	 HRESULT GetFile(const char* dir, char*& fileName, int& file_size, CATComFileType& ftype); 	

	 int IntSize();
	 int StringSize(int bufsize);
	 int UnicodeSize(const CATUnicodeString* );
	 int FileSize(const char* fileName, CATComFileType ftype);
	 char*	GetSenderId() {	return _SenderId;};

	 
	  
   protected :

	 char* _cur_pos;
	 char* _buf;
	 int _size; // taille actuelle du message
	 int _control_size; // taille prevue a l'ecriture d'un message
				        // taille actuellement lue a la lecture

	 // A LA LECTURE on doit toujours avoir _control_size <= _size
	 // A L'ECRITURE on doit toujours avoir _control_size >= _size
	 int _cpt_buf;

	 unsigned int _splitted;

	 HRESULT _state;
	 unsigned int _XMLContent;


	 private :

	 struct CATComHeader head;
	 char _SenderId[SIZE_COMM_MSG_SENDER];
	 char _SenderHostname[256];

	
	 

};


#endif

