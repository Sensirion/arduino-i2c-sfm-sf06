/*
 * I2C-Generator: 0.3.0
 * Yaml Version: 1.1.0
 * Template Version: 0.7.0-78-g11fb280
 */
/*
 * Copyright (c) 2021, Sensirion AG
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

#include <Arduino.h>
#include <SensirionI2CSfmSf06.h>
#include <Wire.h>

SensirionI2CSfmSf06 sfmSf06;

void setup() {

    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    Wire.begin();

    uint16_t error;
    char errorMessage[256];

    /**
     * select the proper i2c address for your sensor
     * see datasheet of your sensor
     *
     */
    sfmSf06.begin(Wire, ADDR_SFM3119);

    error = sfmSf06.stopContinuousMeasurement();

    if (error) {
        Serial.print("Error trying to execute stopContinuousMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }

    uint32_t productIdentifier;
    uint8_t serialNumber[8];
    uint8_t serialNumberSize = 8;

    error = sfmSf06.readProductIdentifier(productIdentifier, serialNumber,
                                          serialNumberSize);

    if (error) {
        Serial.print("Error trying to execute readProductIdentifier(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("Product Identifer:");
        Serial.println(productIdentifier);
        Serial.print("Serial Number:");
        Serial.print("0x");
        for (size_t i = 0; i < serialNumberSize; i++) {
            uint8_t value = serialNumber[i];
            Serial.print(value < 16 ? "0" : "");
            Serial.print(value, HEX);
        }
        Serial.println();
    }

    sfmSf06.startO2ContinuousMeasurement();
    Serial.print("flow");
    Serial.print("\t");
    Serial.println("temperature");
}

void loop() {
    uint16_t error;
    char errorMessage[256];
    float flow = 0;
    float temperature = 0;
    uint16_t status = 0;

    // Read Measurement
    error = sfmSf06.readMeasurementData(flow, temperature, status);
    delay(1000);
    if (!error) {
        Serial.print(flow);
        Serial.print("\t");
        Serial.println(temperature);
    }
}
