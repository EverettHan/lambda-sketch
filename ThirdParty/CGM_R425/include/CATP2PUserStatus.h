#ifndef CATP2PUserStatus_h
#define CATP2PUserStatus_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * Possible status of P2P peer
 */
enum CATP2PUserStatus {
	CATP2PUserStatusActive = 0,
	CATP2PUserStatusAway = 1,
	CATP2PUserStatusDND = 2,
	CATP2PUserStatusIdle = 3,
	CATP2PUserStatusOnThePhone = 4,
	CATP2PUserStatusOffline = 5,
	CATP2PUserStatusUnknown = 6
};

#endif // CATP2PUserStatus_h
