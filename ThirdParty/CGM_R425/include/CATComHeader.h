#ifndef  CATComHeader_H
#define  CATComHeader_H

#define SIZE_COMM_MSG_CLASS 64
#define SIZE_COMM_MSG_LIB 20
//#define SIZE_COMM_MSG_SENDER 64 // ajout du hostname = 256
#define SIZE_COMM_MSG_SENDER 320
#define SIZE_COMM_MSG_USER 64

extern "C" 
{
struct CATComHeader
{
  //-----------------------------------  ------------------------  ----    ----
  // Champs                               Commentaire              Size    Tot
  //-----------------------------------  ------------------------  ----    ----
  short VerNo;                           // No de version          [2]  => 2
  short HeadSize;					     // Taille Header          [2]  => 4
  char  SenderId[SIZE_COMM_MSG_SENDER];  // nom du sender          [64] => 68
  char MessageClass[SIZE_COMM_MSG_CLASS];// Type de message        [64] => 132
  char MessageLib[SIZE_COMM_MSG_LIB];    //Lib d'implementation    [20] => 142
  int MessageLen; //data + header		 // Message Length         [4]  => 146
  char SenderUserName[SIZE_COMM_MSG_USER];//User that send message [64] => 210
  //////////////////////////////////////////////////////////////////////////////

};
}
#endif
