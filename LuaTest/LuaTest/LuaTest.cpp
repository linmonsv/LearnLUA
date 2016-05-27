// LuaTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<lua.hpp>

int luaAdd(lua_State *lua_state, int x, int y)
{
	int sum;
	//获取lua里面的add函数并把它放到lua的栈顶
	lua_getglobal(lua_state, "add");
	//往lua栈里面压入两个参数
	lua_pushnumber(lua_state, x);
	lua_pushnumber(lua_state, y);
	//调用lua函数,这里的2是参数的个数，1是返回值的个数
	lua_call(lua_state, 2, 1);
	//从栈顶读取返回值,注意这里的参数是-1
	sum = lua_tointeger(lua_state, -1);
	//最后我们把返回值从栈顶拿掉
	lua_pop(lua_state, 1);
	return sum;
}

int cAdd(lua_State* L)
{
	//从L栈中取出索引为1的数值，并检查  
	int x = luaL_checkinteger(L, 1);
	//从L栈中取出索引为2的数值，并检查  
	int y = luaL_checkinteger(L, 2);
	lua_pushnumber(L, x + y);
	return 1;
}

int main()
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);

	luaL_dofile(l, "main.lua");

	cout << "5 + 7 = " << luaAdd(l, 5, 7) << endl;

	lua_close(l);

	//初始化全局L
	lua_State* L;
	L = luaL_newstate();
	//打开库  
	luaL_openlibs(L);
	//把函数压入栈中  
	lua_pushcfunction(L, cAdd);
	//设置全局ADD  
	lua_setglobal(L, "ADD");
	luaL_loadfile(L, "test.lua");
	//安全检查  
	lua_pcall(L, 0, 0, 0);
	//push进lua函数  
	lua_getglobal(L, "test");
	lua_pcall(L, 0, 0, 0);
	lua_close(L);

	getchar();

    return 0;
}
