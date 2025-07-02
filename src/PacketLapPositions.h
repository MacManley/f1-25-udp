// File: PacketLapPositions.h
#ifndef PACKETLAPPOSITIONS_H
#define PACKETLAPPOSITIONS_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

class PacketLapPositionsData : public PHeader
{
public:
    PacketLapPositionsData();
    virtual ~PacketLapPositionsData();
    uint8_t m_numLaps(void);
    uint8_t m_lapStart(void);
    uint8_t m_lapPositionsData(int lapIndex, int carIdx);
    void push(char *receiveBuffer);

private:
    uint8_t m_numLaps_;
    uint8_t m_lapStart_;
    uint8_t m_lapPositionsData_[50][22]; //Players car only
};
#pragma pack(pop)

#endif