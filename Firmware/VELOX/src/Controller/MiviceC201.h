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

#ifndef MIVICEC201_H
#define MIVICEC201_H

#include <Arduino.h>

enum class commandType
{
  GET = 0x11,
  SET = 0x16
};

enum class GET
{
  Status = 0x08,
  Current = 0x0A,
  BatteryLevel = 0x11,
  WheelRPM = 0x20,
  Unknown_1 = 0x22,
  Voltage = 0x31,
  Unknown_2 = 0x60
};

enum class SET
{
  PAS = 0x0B,
  Light = 0x1A,
  MaxRPM = 0x1F
};

enum class PAS
{
  level_0 = 0x00,
  level_1 = 0x0C,
  level_2 = 0x02,
  level_3 = 0x03,
  walking = 0x06
};

enum class LIGHT
{
  Off = 0xF0,
  On = 0xF1
};

class MiviceC102Driver
{
public:
  MiviceC102Driver(HardwareSerial* serial) {m_serial = serial;};
  ~MiviceC102Driver() = default;

  void lightOn();
  void lightOff();

  void setPasLevel(PAS pasLevel);
  void setMaxSpeed(double speed);

  static byte calculateCRC(byte fullcommand [], size_t nCommands);
  static void calculateRPM(double speed, byte& b1, byte& b2);

private:
  void write(byte cmd[], size_t nBytes);
  HardwareSerial* m_serial;

};

#endif
