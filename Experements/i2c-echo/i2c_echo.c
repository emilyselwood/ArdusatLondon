#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>


int main (int argc, char ** argv) {
  int file;
  int adapter_nr = 1; /* probably dynamically determined */
  char filename[20];
  
  snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
  file = open(filename, O_RDWR);
  if (file < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    printf("ARRRGGGGGGGG File open failed\n");
    return(1);
  }
  
  int addr = 0x04; /* The I2C address */

  if (ioctl(file, I2C_SLAVE, addr) < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    printf("ARRRGGGGGGGG ioctl failed\n");
    return(1);
  }
  
  char buf[10];
  while(1) {
    /* Using I2C Read, equivalent of i2c_smbus_read_byte(file) */
    int res = read(file, buf, 1);
    if (res != 1) {
      /* ERROR HANDLING: i2c transaction failed */
      printf("read failed !!!!!!%d\n", res);
    } else {
      /* buf[0] contains the read byte */
      putc(buf[0], stdin);
    }
  }
  return 0;
}