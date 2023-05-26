#ifndef CATComSidlTabPacket_H
#define CATComSidlTabPacket_H

#define PLMSidlDumpAndStat

#include "CATComSidl.h"
#include "CATErrorDef.h"
#include "CATAssert.h"
#include "CATSysCompress.h"
#include <string.h>
#ifdef PLMSidlDumpAndStat
#include <stdio.h>
#endif

#include "DSYSysFileLogging.h"

class ExportedByCATComSidl CATComSidlTabPacket
{
private:
	//structure interne 
	struct Packet
	{
		int		_IsCompressed;
		size_t	_Size;
		char*		_Data;
		int		nbInPrecedingPackets;
		size_t	_SizeZ;
		char*		_DataZ;
	};

	//classe pour gerer une liste de paquets comme s'il s'agissait d'un tableau d'octet
	//cette classe centralise tout ce qui concerne le decoupage et la compression des donnees Sidl
	//elle contient donc les 2 aspects:
	//     paquet => compression => stockage => acces aux paquets compresses  (envoi des donnees)
	//     paquets compresses => stockage => decompression => acces sequentiel aux octets (reception des donnees)
private:
	Packet				*_TabPacket;					//le tableau de paquet
	int					_nbPacket;					//le nombre de paquets
	int					_Pos;						//la position dans le pseudo tableau de byte
	int					_Length;					//la longueur du pseudo tableau de byte
	int					_Current;					//l'index du paquet courant = celui qui contient _Pos
	int					_CompressionTrigger;		//le seuil de declenschement de la compression

	char*				_WorkingBuffer;				//buffer de travail pour la compression. Ce buffer est alloue (et eventuellement agrandi) 1 fois
	int					_WorkingBufferSize;			//pour tous les paquets. Les donnees compressees seront ensuite dupliquees avec une allocation
										//de la taille juste necessaire ie tres inferieure a la taille de ce buffer
	DSYSysFileLogging	*_TraceFile;
#ifdef PLMSidlDumpAndStat
	//dump
	FILE*	_Fd;
	//statistiques
	FILE*_sFd;
	int _LastDumpedPacket;
#endif

public:
	CATComSidlTabPacket(int iCompressionTrigger=16384);
	~CATComSidlTabPacket();

	//reception
	int GetLength();
	int GetPos();
	HRESULT GetBytes(char* oData, unsigned int iLength, unsigned int * oLengthRead, DSYSysFileLogging *iTraceFile);
	HRESULT GetBytes(char* oData, unsigned int iLength, unsigned int * oLengthRead);
	HRESULT StoreReceivedData(const int IsCompressed, const char*iDataZ, int iSizeZ, int iSize);
	HRESULT uncompress(const char*srcZ, size_t sizeZ,size_t size, char**dsrc);

	//emission
	int GetNbPacket();
	int GetPacketSizeZ(int numPacket);
	int IsCompressed(int numPacket) ;
	int GetPacketSize(int numPacket);
	char* GetPacketDataZ(int numPacket);
	char* GetPacketData(int numPacket);
	HRESULT CompressDataAndStore(char*iData,int iSize);
	HRESULT compress(char*src,int size,char**csrc,size_t*clen);

#ifdef PLMSidlDumpAndStat
	void SetDumpFile(FILE*idf);
	FILE* GetDumpFile();
	void SetStatFile(FILE*idf);
	FILE* GetStatFile();
#endif
};


#endif
