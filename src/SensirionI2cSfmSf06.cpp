/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 0.37.0
 * Product:       sfm_sf06
 * Model-Version: 1.5.0
 */
/*
 * Copyright (c) 2024, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "SensirionI2cSfmSf06.h"
#include <Arduino.h>

// make sure that we use the proper definition of NO_ERROR
#ifdef NO_ERROR
#undef NO_ERROR
#endif
#define NO_ERROR 0

static uint8_t communication_buffer[18] = {0};

SensirionI2cSfmSf06::SensirionI2cSfmSf06() {
}

float SensirionI2cSfmSf06::signalTemperature(int16_t temperatureRaw) {
    float temperature = 0.0;
    temperature = temperatureRaw / 200.0;
    return temperature;
}

float SensirionI2cSfmSf06::signalFlow(int16_t flowRaw, int16_t flowScaleFactor,
                                      int16_t flowOffset) {
    float flow = 0.0;
    float scaleFactor = (float)(flowScaleFactor);
    flow = (float)(flowRaw - (int32_t)(flowOffset)) / scaleFactor;
    return flow;
}

int16_t SensirionI2cSfmSf06::startO2ContinuousMeasurement() {
    int16_t localError = 0;
    localError =
        readScaleOffsetUnit(SFM_SF06_START_O2_CONTINUOUS_MEASUREMENT_CMD_ID,
                            _flowScaleFactor, _flowOffset, _flowUnit);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = llstartO2ContinuousMeasurement();
    return localError;
}

int16_t SensirionI2cSfmSf06::startAirContinuousMeasurement() {
    int16_t localError = 0;
    localError =
        readScaleOffsetUnit(SFM_SF06_START_AIR_CONTINUOUS_MEASUREMENT_CMD_ID,
                            _flowScaleFactor, _flowOffset, _flowUnit);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = llstartAirContinuousMeasurement();
    return localError;
}

int16_t SensirionI2cSfmSf06::startN2OContinuousMeasurement() {
    int16_t localError = 0;
    localError =
        readScaleOffsetUnit(SFM_SF06_START_N2O_CONTINUOUS_MEASUREMENT_CMD_ID,
                            _flowScaleFactor, _flowOffset, _flowUnit);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = llstartN2OContinuousMeasurement();
    return localError;
}

int16_t SensirionI2cSfmSf06::startCO2ContinuousMeasurement() {
    int16_t localError = 0;
    localError =
        readScaleOffsetUnit(SFM_SF06_START_CO2_CONTINUOUS_MEASUREMENT_CMD_ID,
                            _flowScaleFactor, _flowOffset, _flowUnit);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = llstartCO2ContinuousMeasurement();
    return localError;
}

int16_t
SensirionI2cSfmSf06::startN2OO2ContinuousMeasurement(uint16_t volumeFraction) {
    int16_t localError = 0;
    localError =
        readScaleOffsetUnit(SFM_SF06_START_N2O_O2_CONTINUOUS_MEASUREMENT_CMD_ID,
                            _flowScaleFactor, _flowOffset, _flowUnit);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = llstartN2OO2ContinuousMeasurement(volumeFraction);
    return localError;
}

int16_t
SensirionI2cSfmSf06::startCO2O2ContinuousMeasurement(uint16_t volumeFraction) {
    int16_t localError = 0;
    localError =
        readScaleOffsetUnit(SFM_SF06_START_CO2_O2_CONTINUOUS_MEASUREMENT_CMD_ID,
                            _flowScaleFactor, _flowOffset, _flowUnit);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = llstartCO2O2ContinuousMeasurement(volumeFraction);
    return localError;
}

int16_t
SensirionI2cSfmSf06::startAirO2ContinuousMeasurement(uint16_t volumeFraction) {
    int16_t localError = 0;
    localError =
        readScaleOffsetUnit(SFM_SF06_START_AIR_O2_CONTINUOUS_MEASUREMENT_CMD_ID,
                            _flowScaleFactor, _flowOffset, _flowUnit);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = llstartAirO2ContinuousMeasurement(volumeFraction);
    return localError;
}

int16_t SensirionI2cSfmSf06::readMeasurementDataRaw(int16_t& flow,
                                                    int16_t& temperature,
                                                    uint16_t& statusWord) {
    int16_t localError = 0;
    localError = llreadMeasurementData(flow, temperature, statusWord);
    return localError;
}

int16_t SensirionI2cSfmSf06::readMeasurementData(float& aFlow,
                                                 float& aTemperature,
                                                 uint16_t& aStatusWord) {
    int16_t rawFlow = 0;
    int16_t rawTemp = 0;
    uint16_t status = 0u;
    int16_t localError = 0;
    localError = readMeasurementDataRaw(rawFlow, rawTemp, status);
    if (localError != NO_ERROR) {
        return localError;
    }
    aFlow =
        SensirionI2cSfmSf06::signalFlow(rawFlow, _flowScaleFactor, _flowOffset);
    aTemperature = SensirionI2cSfmSf06::signalTemperature(rawTemp);
    aStatusWord = static_cast<uint16_t>(status);
    return localError;
}

int16_t SensirionI2cSfmSf06::updateConcentration(uint16_t volumeFraction) {
    int16_t localError = 0;
    localError = updateConcentrationSet(volumeFraction);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError = updateConcentrationActivate();
    return localError;
}

int16_t SensirionI2cSfmSf06::llstartO2ContinuousMeasurement() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3603, buffer_ptr, 2);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    delay(12);
    return localError;
}

int16_t SensirionI2cSfmSf06::llstartAirContinuousMeasurement() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3608, buffer_ptr, 2);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    return localError;
}

int16_t SensirionI2cSfmSf06::llstartN2OContinuousMeasurement() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3615, buffer_ptr, 2);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    delay(12);
    return localError;
}

int16_t SensirionI2cSfmSf06::llstartCO2ContinuousMeasurement() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x361e, buffer_ptr, 2);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    delay(12);
    return localError;
}

int16_t SensirionI2cSfmSf06::llstartAirO2ContinuousMeasurement(
    uint16_t volumeFraction) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3632, buffer_ptr, 5);
    localError |= txFrame.addUInt16(volumeFraction);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    delay(12);
    return localError;
}

int16_t SensirionI2cSfmSf06::llstartN2OO2ContinuousMeasurement(
    uint16_t volumeFraction) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3639, buffer_ptr, 5);
    localError |= txFrame.addUInt16(volumeFraction);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    delay(12);
    return localError;
}

int16_t SensirionI2cSfmSf06::llstartCO2O2ContinuousMeasurement(
    uint16_t volumeFraction) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3646, buffer_ptr, 5);
    localError |= txFrame.addUInt16(volumeFraction);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    delay(12);
    return localError;
}

int16_t SensirionI2cSfmSf06::llreadMeasurementData(int16_t& flow,
                                                   int16_t& temperature,
                                                   uint16_t& statusWord) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CRxFrame rxFrame(buffer_ptr, 9);
    localError = SensirionI2CCommunication::receiveFrame(_i2cAddress, 9,
                                                         rxFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError |= rxFrame.getInt16(flow);
    localError |= rxFrame.getInt16(temperature);
    localError |= rxFrame.getUInt16(statusWord);
    return localError;
}

int16_t SensirionI2cSfmSf06::updateConcentrationSet(uint16_t volumeFraction) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0xe17d, buffer_ptr, 5);
    localError |= txFrame.addUInt16(volumeFraction);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    return localError;
}

int16_t SensirionI2cSfmSf06::updateConcentrationActivate() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0xe000, buffer_ptr, 2);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    return localError;
}

int16_t SensirionI2cSfmSf06::stopContinuousMeasurement() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3ff9, buffer_ptr, 2);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    return localError;
}

int16_t SensirionI2cSfmSf06::configureAveraging(uint16_t averageWindow) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x366a, buffer_ptr, 5);
    localError |= txFrame.addUInt16(averageWindow);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    return localError;
}

int16_t SensirionI2cSfmSf06::readScaleOffsetUnit(uint16_t commandCode,
                                                 int16_t& flowScaleFactor,
                                                 int16_t& flowOffset,
                                                 uint16_t& flowUnit) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3661, buffer_ptr, 9);
    localError |= txFrame.addUInt16(commandCode);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    SensirionI2CRxFrame rxFrame(buffer_ptr, 9);
    localError = SensirionI2CCommunication::receiveFrame(_i2cAddress, 9,
                                                         rxFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError |= rxFrame.getInt16(flowScaleFactor);
    localError |= rxFrame.getInt16(flowOffset);
    localError |= rxFrame.getUInt16(flowUnit);
    return localError;
}

int16_t SensirionI2cSfmSf06::enterSleep() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0x3677, buffer_ptr, 2);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    return localError;
}

int16_t SensirionI2cSfmSf06::exitSleep() {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt8Command(0x0, buffer_ptr, 2);
    SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    return localError;
}

int16_t SensirionI2cSfmSf06::readProductIdentifier(uint32_t& productIdentifier,
                                                   uint8_t serialNumber[],
                                                   uint16_t serialNumberSize) {
    int16_t localError = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    SensirionI2CTxFrame txFrame =
        SensirionI2CTxFrame::createWithUInt16Command(0xe102, buffer_ptr, 18);
    localError =
        SensirionI2CCommunication::sendFrame(_i2cAddress, txFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    SensirionI2CRxFrame rxFrame(buffer_ptr, 18);
    localError = SensirionI2CCommunication::receiveFrame(_i2cAddress, 18,
                                                         rxFrame, *_i2cBus);
    if (localError != NO_ERROR) {
        return localError;
    }
    localError |= rxFrame.getUInt32(productIdentifier);
    localError |= rxFrame.getBytes((uint8_t*)serialNumber, serialNumberSize);
    return localError;
}

void SensirionI2cSfmSf06::begin(TwoWire& i2cBus, uint8_t i2cAddress) {
    _i2cBus = &i2cBus;
    _i2cAddress = i2cAddress;
}
