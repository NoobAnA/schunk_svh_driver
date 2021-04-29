# Schunk SVH driver
[![Build Status](https://travis-ci.org/fzi-forschungszentrum-informatik/schunk_svh_driver.svg?branch=master)](https://travis-ci.org/fzi-forschungszentrum-informatik/schunk_svh_driver)

This is the driver package for the SCHUNK SVH Five-Finger-Hand.
It was developed on behalf of SCHUNK Mobile Greifsysteme GmbH, Lauffen/Neckar, Germany
at the FZI Research Center for Information Technology in Karlsruhe, Germany.

The package contains the following core components:
- The low level hardware driver
- The ROS abstraction layer
- 3D model and kinematics description for visualization and grasp planning
These main components are distributed under a LGPL license.

Furthermore this package contains a build system and two libraries that are not
part of the SVH Driver but which are needed to build it:
- icmaker  (BSD License)
- icl_core (LGPL License)
- icl_comm (LGPL License)
These components were independently developed at the
FZI Research Center for Information Technology in Karlsruhe, Germany.

Also included is the TinyXML Library which was developed by
Lee Thomason (http://www.grinninglizard.com)
and which ships unter the zlib/libpng license.

See license folder for the license texts.



## ubuntu18.04更改

**占位符号问题：**

> ～/lwa4p_ws/src/schunk_svh_driver/src/driver_svh/src/driver_svh/SVHSerialInterface.cpp  第77行报错:
>
> /home/songshouan/lwa4p_ws/src/schunk_svh_driver/src/driver_svh/src/driver_svh/SVHSerialInterface.cpp: In member function ‘bool driver_svh::SVHSerialInterface::connect(const string&)’:
> /home/songshouan/lwa4p_ws/src/schunk_svh_driver/src/driver_svh/src/driver_svh/SVHSerialInterface.cpp:77:146: error: ‘_1’ was not declared in this scope
>    m_receive_thread.reset(new SVHReceiveThread(TimeSpan(0, 500000), m_serial_device, boost::bind(&SVHSerialInterface::receivedPacketCallback,this,_1,_2)));

将对应.cpp文件第77行

```c++
m_receive_thread.reset(new SVHReceiveThread(TimeSpan(0, 500000), m_serial_device, boost::bind(&SVHSerialInterface::receivedPacketCallback,this,_1,_2)));
```

更改为：

```c++
m_receive_thread.reset(new SVHReceiveThread(TimeSpan(0, 500000), m_serial_device, boost::bind(&SVHSerialInterface::receivedPacketCallback,this,boost::placeholders::_1,boost::placeholders::_2)));
```



> ~/lwa4p_ws/src/schunk_svh_driver/src/driver_svh/src/driver_svh/SVHController.cpp 第81行报错:
>
> /home/songshouan/lwa4p_ws/src/schunk_svh_driver/src/driver_svh/src/driver_svh/SVHController.cpp: In constructor ‘driver_svh::SVHController::SVHController()’:
> /home/songshouan/lwa4p_ws/src/schunk_svh_driver/src/driver_svh/src/driver_svh/SVHController.cpp:81:101: error: ‘_1’ was not declared in this scope
>    m_serial_interface(new SVHSerialInterface(boost::bind(&SVHController::receivedPacketCallback,this,_1,_2))),

将对应.cpp文件第81行

```c++
m_serial_interface(new SVHSerialInterface(boost::bind(&SVHController::receivedPacketCallback,this,_1,_2))),
```

更改为：

```c++
m_serial_interface(new SVHSerialInterface(boost::bind(&SVHController::receivedPacketCallback,this,boost::placeholders::_1,boost::placeholders::_2))),
```



