**ZARCO** is a mobile robotic platform for education, research and real world applications. With this fully-featured omnidirectional three-wheeled robot, **ZARCO**’s range of applications includes exploration, surveillance, networked robotics and human-robot cooperation.

# 1. Install
To extend **ZARCO**’s functionalities, you must first connect to it and program it. **ZARCO** comes with an Arduino UNO and an OMNI-3MD controller so, to program it, you can simply download Arduino IDE, connect a USB cable to **ZARCO**’s board, and that’s it. 
Here is the installation process explained step-by-step:
* Go to https://www.arduino.cc/en/Main/Software and download the latest release of Arduino IDE
* Download the Omni3MD Arduino library [here](arduino/library/) and install it as any other Arduino library. The manual of this library is available in the following link: http://botnroll.com/omni3md/downloads/OMNI-3MD_Manual_Software%2817-10-2013%29.pdf 
* Connect to **ZARCO**’s Arduino UNO board using a USB cable
* Install any regular Arduino drivers if necessary (those are available in the Arduino IDE folder installed on your computer)

For high-level programming, and to further extend **ZARCO**’s functionalities, one can benefit from the ARM CPU BeagleBone Black (BBB) equipped on the platform. To have access to the BBB, simply follow the steps in http://beagleboard.org/getting-started. Once connected to the BBB through SSH, use the following login:
* username: ubuntu
* password: temppwd

For instance, the user can gain access to the installed camera (videodevice /dev/video0) through the BBB and use it for surveillance purposes (e.g., robot patrolling). **ZARCO**’s BBB uses the [Motion package](https://launchpad.net/ubuntu/trusty/+package/motion), which supports motion detection. **ZARCO**’s streaming video can be accessed directly through the network as http://BBB_IP:8081.

That's it - Enjoy!


# 2.	Quick start
After following the installation steps, test the [square.ino](arduino/examples/square/square.ino) example located in arduino/examples/ to make sure all libraries are adequately installed. If everything goes as expected, you should see **ZARCO** following a square trajectory.
