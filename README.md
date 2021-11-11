# QtMpu6050

QtSensors wrapper for the MPU6050 accelerometer/gyroscope/thermometer. Forked from [joseluiscd/QtMpu6050](https://github.com/joseluiscd/QtMpu6050)

### Dependency

    sudo apt-get install libi2c-dev cmake libqt5sensors5-dev 

### Build  

    mkdir build
    cd build 
    CMAKE_PREFIX_PATH=/opt/qt5 cmake ../
    make 
    
### Install 

    sudo cp libmpu6050.so /opt/qt5/plugins/sensors/libqtsensors_mpu6050.so
