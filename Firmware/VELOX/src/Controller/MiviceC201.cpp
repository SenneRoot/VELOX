/*
 * VELOX - Velocity Enhancement Limit Override X
 * Copyright (c) 2023-2024 S.K.A. Root
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Contact:
 * - Email: senner@hotmail.nl
 * - GitHub: https://github.com/SenneRoot
 */

#include "MiviceC201.h"

byte MiviceC102Driver::calculateCRC(byte fullCommand [], size_t nCommands)
{
  byte res = 0x00;

  for(size_t i = 0; i < nCommands; ++i)
  {
    res += fullCommand[i];
  }

  return res;
};

void MiviceC102Driver::write(byte cmd[], size_t nBytes)
{
  for(size_t i; i < nBytes; ++i)
  {
    m_serial->write(cmd[i]);
  }
}

void MiviceC102Driver::lightOn()
{
  byte fullCommand[4];

  fullCommand[0] = static_cast<byte>(commandType::SET);
  fullCommand[1] = static_cast<byte>(SET::Light);
  fullCommand[2] = static_cast<byte>(LIGHT::On);

  fullCommand[3] = calculateCRC(fullCommand, 3);

  write(fullCommand, 4);
}

void MiviceC102Driver::lightOff()
{
  byte fullCommand[4];

  fullCommand[0] = static_cast<byte>(commandType::SET);
  fullCommand[1] = static_cast<byte>(SET::Light);
  fullCommand[2] = static_cast<byte>(LIGHT::Off);

  fullCommand[3] = calculateCRC(fullCommand, 3);

  write(fullCommand, 4);
}

void MiviceC102Driver::setPasLevel(PAS pasLevel)
{
  byte fullCommand[4];

  fullCommand[0] = static_cast<byte>(commandType::SET);
  fullCommand[1] = static_cast<byte>(SET::PAS);
  fullCommand[2] = static_cast<byte>(pasLevel);

  fullCommand[3] = calculateCRC(fullCommand, 3);

  write(fullCommand, 4);
}

void MiviceC102Driver::calculateRPM(double speed, byte& b1, byte& b2)
{
  unsigned int res = ceil((speed * 1000)/(2.18 * 60));
  b1 = res >> 8;   // shift the higher 8 bits
  b2 = res & 0xff; // mask the lower 8 bits
}

void MiviceC102Driver::setMaxSpeed(double speed)
{
  byte fullCommand[5];

  fullCommand[0] = static_cast<byte>(commandType::SET);
  fullCommand[1] = static_cast<byte>(SET::MaxRPM);
  calculateRPM(speed, fullCommand[2], fullCommand[3]);

  fullCommand[4] = calculateCRC(fullCommand, 4);

  write(fullCommand, 5);
}
