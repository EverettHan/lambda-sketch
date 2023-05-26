/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 2000						                */
/*=======================================================================*/
/*                                                                       */
/*  CATComConnexionType                                                       */
/*                                                                        */
/*  Usage Notes:                        */
/*                                                                       */
/*=======================================================================*/
/*  Creation Oct	2000                                 jnm             */
/*=======================================================================*/

#ifndef CATComConnexionType_H
#define CATComConnexionType_H
//
enum CATComConnexionType
{
	MQ,
	BB,
	LOCAL,
	LOCALBB,
	LOCALMQ,
	UNDEFINED
};
//
#define CLIENTQ	"CATBATMONITOR.OUTPUT"
#define SERVERQ "CATBATMONITOR.INPUT"
#define SERVERBATCHQ "CATBATMONITOR.SERVERBATCH"
#define BATCHQ	"BATCH.COMM"

#endif
