#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WINDOWS
#include <windows.h>
#endif
#include <time.h>
#include "DllTest.h"

int
__stdcall
DllVersion(char* sDate, char* sTime, char* sAuthor)
{
  strcpy(sDate, __DATE__);
  strcpy(sTime, __TIME__);
  strcpy(sAuthor, "QFX");
  return 0;
}
