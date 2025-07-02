// File: PacketLapPositions.cpp
#include "PacketLapPositions.h"
#include <cstring>

const int LAPPOSITIONS_BUFFER_SIZE = 1131;

PacketLapPositionsData::PacketLapPositionsData()
: PHeader()
{}

PacketLapPositionsData::~PacketLapPositionsData()
{}

void PacketLapPositionsData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, LAPPOSITIONS_BUFFER_SIZE);
}

uint8_t PacketLapPositionsData::m_lapPositionsData(int lapIndex, int carIdx)
{
        if (lapIndex < 50 && carIdx < 22) {
        return m_lapPositionsData_[lapIndex][carIdx];
        } else return {0};
}

uint8_t PacketLapPositionsData::m_numLaps(void)
{
        return m_numLaps_;
}


uint8_t PacketLapPositionsData::m_lapStart(void)
{
        return m_lapStart_;
}