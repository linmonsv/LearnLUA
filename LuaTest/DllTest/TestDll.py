# -*- coding: UTF-8 -*-

from ctypes import *

dll=WinDLL("DllTest.dll")
sDate=c_char_p(b"/0")
sDate=create_string_buffer(1024)
sTime=c_char_p(b"/0")
sTime=create_string_buffer(1024)
sAuthor=c_char_p(b"/0")
sAuthor=create_string_buffer(1024)
result = dll.DllVersion(sDate, sTime, sAuthor)
print(result)
print(sDate.value, sTime.value, sAuthor.value)
