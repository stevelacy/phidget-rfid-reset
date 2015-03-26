
#include <stdio.h>
#include <phidget21.h>

int rfid_reset(int id)
{
  int result;
  const char *err;
  CPhidgetRFIDHandle rfid = id;
  CPhidgetRFID_create(&rfid);
  CPhidget_open((CPhidgetHandle)rfid, -1);

  //get the program to wait for an RFID device to be attached
  printf("Waiting for RFID to be attached....");
  if((result = CPhidget_waitForAttachment((CPhidgetHandle)rfid, 10000)))
  {
    CPhidget_getErrorDescription(result, &err);
    printf("Problem waiting for attachment: %s\n", err);
    return 0;
  }

  CPhidgetRFID_setAntennaOn(rfid, 1);

  //read RFID event data
  printf("Reset.....\n");

  return 0;
}

int main(int argc, char* argv[])
{
  rfid_reset(0);
  rfid_reset(1);
  return 0;
}

