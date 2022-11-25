#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#ifndef MBED_H
#include "mbed.h"
#define MBED_H
#endif

#define CAN_IER         (*((volatile unsigned long *)0x40006414))

#define BUFFER_SIZE     50
#define THROTTLE_MID    0x00
#define THROTTLE_RUN    0x01
#define THROTTLE_CHOKE  0x02

#define SYNC_ID         0x001       // message for bus sync
#define THROTTLE_ID     0x100       // 1by = throttle state (0x00, 0x01 or 0x02)
#define FLAGS_ID        0x101       // 1by
#define IMU_ACC_ID      0x200       // 8by = accelerometer data (3D) + timestamp
#define IMU_DPS_ID      0x201       // 8by = gyroscope data (3D) + timestamp 
#define SPEED_ID        0x300       // 4by = speed + timestamp
#define RPM_ID          0x304       // 4by = rpm + timestamp
#define TEMPERATURE_ID  0x400       // 4by = engine temp. + cvt temp. + timestamp
#define FUEL_ID         0x500       // 3by = fuel level + timestamp
#define LAT_ID          0x600       // 1by
#define LNG_ID          0x700       // 1by
#define SOC_ID          0x302
#define TEMP_CVT        0x401
#define VOLT_ID         0x502

typedef struct {
    int16_t acc_x;
    int16_t acc_y;
    int16_t acc_z;
    int16_t dps_x;
    int16_t dps_y;
    int16_t dps_z;
} imu_t;

typedef struct {
    imu_t imu; // 12 bytes
    uint16_t rpm; // 2 bytes
    uint16_t speed; // 2 bytes
    uint8_t temperature; // 1 bytes
    uint8_t flags;      // MSB - BOX | BUFFER FULL | NC | NC | FUEL_LEVEL | SERVO_ERROR | CHK | RUN - LSB // 8 bytes
    uint8_t soc; // 1 byte
    uint8_t cvt; // 1 byte
    uint8_t volt; // 1 byte
    int8_t lat; // 1 byte
    int8_t lng; // 1 byte 
    uint32_t timestamp; // 4 bytes
} packet_t; // 32

#endif
