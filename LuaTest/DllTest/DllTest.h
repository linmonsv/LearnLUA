/**

  PBOC 3.0 ¿â
  
*/

#ifndef _DLLTEST_
#define _DLLTEST_

#ifndef _WINDOWS
#define __stdcall
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int
__stdcall
DllVersion(char* sDate, char* sTime, char* sAuthor);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // _DLLTEST_

