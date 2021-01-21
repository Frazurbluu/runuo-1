/* @file
 *
 * Copyright(c) 2016 UltimaLive
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#include "UltimaLiveUpdateLandBlockHandler.h"
#include "..\NetworkManager.h"

 /**
 * @brief UltimaLiveUpdateLandBlockHandler constructor
 */
UltimaLiveUpdateLandBlockHandler::UltimaLiveUpdateLandBlockHandler(NetworkManager* pManager)
  : BasePacketHandler(pManager)
{
  //do nothing
}

/**
 * @brief Decommutates UltimaLive Update Land Block packet
 *
 * @param pPacketData Pointer to packet data
 *
 * @return false (Do not forward packet on to client)
 */
bool UltimaLiveUpdateLandBlockHandler::handlePacket(uint8_t* pPacketData)
{                                                                             
  uint32_t blockNumber = ntohl(*reinterpret_cast<uint32_t*>(&pPacketData[1]));   
  uint8_t* pLandData = &pPacketData[5];
  uint8_t mapNumber =  static_cast<uint8_t>(ntohl(*reinterpret_cast<uint8_t*>(pPacketData + 200))); 

  m_pManager->onLandUpdate(mapNumber, blockNumber, pLandData);
  return false;
}
