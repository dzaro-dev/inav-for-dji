/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include "platform.h"
#include "config/config_master.h"
#include "config/feature.h"
#include "io/serial.h"
#include "sensors/compass.h"
#include "fc/config.h"
#include "drivers/pwm_mapping.h"


void targetConfiguration(void)
{
    compassConfigMutable()->mag_align = CW0_DEG_FLIP;
    serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART4)].functionMask = FUNCTION_GPS;
    // serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART4)].gps_baudrateIndex = BAUD_115200;
    beeperConfigMutable()->pwmMode = true;

    // To improve backwards compatibility with INAV versions 6.x and older
    timerOverridesMutable(timer2id(TIM4))->outputMode = OUTPUT_MODE_MOTORS;
}