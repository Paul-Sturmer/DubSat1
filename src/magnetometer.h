/*
 * magnetometer.h
 *
 *  Created on: Apr 9, 2017
 *      Author: jeffc
 */

#ifndef MAGNETOMETER_H_
#define MAGNETOMETER_H_

#include "i2c_support.h"

#ifndef HW_MAGTOM
#warning  No magnetometer specified in HW_MAGTOM - defaulting to HMC5883L.
#define HW_MAGTOM  5883
#endif  /* HW_MGTOM */

#if HW_MAGTOM == 5883   // Honeywell HMC5883L
#include "HMC5883L_Magnetometer.h"
#elif HW_MAGTOM == 3110  // Freescale MAG3110
#error Not yet implemented.
#include "MAG3110_Magnetometer.h"
#else
#error Unknown - or no - magnetometer specified.  HW_MAGTOM to set valid type.
#endif  /* MAGNETOMETER */


typedef struct  {
    int16_t rawX;
    int16_t rawY;
    int16_t rawZ;
} MagnetometerData;


// Main entry points
void magInit();
MagnetometerData *magReadXZYData();



#endif /* MAGNETOMETER_H_ */
