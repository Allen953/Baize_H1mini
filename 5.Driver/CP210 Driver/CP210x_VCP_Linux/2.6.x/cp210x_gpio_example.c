#include <iostream>
#include <fcntl.h>
#include <stropts.h>
#include <termios.h>

using namespace std;

#define TTY_DEVICE		"/dev/ttyUSB0"

#define IOCTL_GPIOGET		0x8000
#define IOCTL_GPIOSET		0x8001

int main()
{
	int fd;
	int result = 0;

	cout << "CP210x GPIO Example\n";
	fd = open(TTY_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1)
	{
		cout << "Error opening port " << TTY_DEVICE << endl;
		return -1;
	}

	unsigned long gpio;

	// Display the original GPIO value
	result = ioctl(fd, IOCTL_GPIOGET, &gpio);
	cout << "Original GPIO = " << hex << gpio << ", result = " << result << endl;

	// Now set GPIO, value defined as bit 0-15, mask, and bit 16-31, value:
	//
	//	Bit 0 = GPIO0 Mask
	//	Bit 1 = GPIO1 Mask
	//	Bit 2 = GPIO2 Mask
	//	Bit 3 = GPIO3 Mask
	//	Bit 4 = GPIO4 Mask
	//	Bit 5 = GPIO5 Mask
	//	Bit 6 = GPIO6 Mask
	//	Bit 7 = GPIO7 Mask
	//	Bit 8 = GPIO8 Mask
	//	Bit 9 = GPIO9 Mask
	//	Bit 10 = GPIO10 Mask
	//	Bit 11 = GPIO11 Mask
	//	Bit 12 = GPIO12 Mask
	//	Bit 13 = GPIO13 Mask
	//	Bit 14 = GPIO14 Mask
	//	Bit 15 = GPIO15 Mask
	//	Bit 16 = GPIO0 Value
	//	Bit 17 = GPIO1 Value
	//	Bit 18 = GPIO2 Value
	//	Bit 19 = GPIO3 Value
	//	Bit 20 = GPIO4 Value
	//	Bit 21 = GPIO5 Value
	//	Bit 22 = GPIO6 Value
	//	Bit 23 = GPIO7 Value
	//	Bit 24 = GPIO8 Value
	//	Bit 25 = GPIO9 Value
	//	Bit 26 = GPIO10 Value
	//	Bit 27 = GPIO11 Value
	//	Bit 28 = GPIO12 Value
	//	Bit 29 = GPIO13 Value
	//	Bit 30 = GPIO14 Value
	//	Bit 31 = GPIO15 Value
	//
	// Note: Each device supports a different number of GPIO -
	// check the data sheet for exact GPIO values available.
	// 
	// GPIO on CP2105 is exclusive to the COM port interface,
	// while on CP2108 all GPIO is accessible to any interface

	// Flip the GPIO state:
	// Reverse the bits, then shift left 8 bits
	// to declare the new values, then or in FF
	// to set the mask to write all values
	gpio = ~gpio;
	//gpio = gpio << 8;
	//gpio |= 0x00FF;
	gpio = gpio << 16;
	gpio |= 0xFFFF;
	result = ioctl(fd, IOCTL_GPIOSET, &gpio);
	cout << "GPIO to set = " << hex << gpio << ", result = " << result << endl;

	// Now check the new GPIO value
	result = ioctl(fd, IOCTL_GPIOGET, &gpio);
	cout << "New GPIO = " << hex << gpio << ", result = " << result << endl;

	close(fd);

	return 0;
}
