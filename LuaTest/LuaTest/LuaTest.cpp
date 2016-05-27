// LuaTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<lua.hpp>

int luaAdd(lua_State *lua_state, int x, int y)
{
	int sum;
	//��ȡlua�����add�����������ŵ�lua��ջ��
	lua_getglobal(lua_state, "add");
	//��luaջ����ѹ����������
	lua_pushnumber(lua_state, x);
	lua_pushnumber(lua_state, y);
	//����lua����,�����2�ǲ����ĸ�����1�Ƿ���ֵ�ĸ���
	lua_call(lua_state, 2, 1);
	//��ջ����ȡ����ֵ,ע������Ĳ�����-1
	sum = lua_tointeger(lua_state, -1);
	//������ǰѷ���ֵ��ջ���õ�
	lua_pop(lua_state, 1);
	return sum;
}

int main()
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);

	luaL_dofile(l, "main.lua");

	cout << "5 + 7 = " << luaAdd(l, 5, 7) << endl;

	lua_close(l);
	getchar();

    return 0;
}

