#ifndef MPU6050_H
#define MPU6050_H

#include <QAccelerometer>
#include <QGyroscope>
#include <QAmbientTemperatureSensor>
#include <QTimer>

#define MPU_I2C "/dev/i2c-5"
#define MPU_ADDRESS 0x68

#define MPU_ACCEL_XOUT 0x3b
#define MPU_ACCEL_YOUT 0x3d
#define MPU_ACCEL_ZOUT 0x3f

#define MPU_GYRO_XOUT 0x43
#define MPU_GYRO_YOUT 0x45
#define MPU_GYRO_ZOUT 0x47

#define MPU_TEMP 0x41

#define MPU_ACCEL_CONFIG 0x1C
#define MPU_GYRO_CONFIG 0x1B

#define MPU_POWER1 0x6b
#define MPU_POWER2 0x6c

#define ACCEL_SCALE 16384.0f
#define GYRO_SCALE 131.0f
#define GRAVITY 9.80665

class Mpu6050 : public QObject
{
    Q_OBJECT

public:
    Mpu6050();

    void start();
    void end();

    QAccelerometerReading *getAccelerometerReading();
    QGyroscopeReading *getGyroscopeReading();
    QAmbientTemperatureReading *getTemperatureReading();

public slots:
    void pollAccelerometer();
    void pollGyroscope();
    void pollTemperature();


private:
    QAccelerometerReading accelReading;
    QGyroscopeReading gyroReading;
    QAmbientTemperatureReading tempReading;

    int16_t readWord(unsigned char address);

    int fd;

};

#endif // MPU6050_H
