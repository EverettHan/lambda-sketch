//===================================================================
// COPYRIGHT Dassault 2010
//===================================================================
// SWXUtPacket.h: Packet passed between UI and model for interaction
//===================================================================

#ifndef SWXUtParameterReason_H
#define SWXUtParameterReason_H

enum SWXUtParameterReason 
{
	SWXUtReason_None = 0, // i.e. it's not changed
	SWXUtReason_Apply = 1,
	SWXUtReason_Preview = 2
};

#endif
