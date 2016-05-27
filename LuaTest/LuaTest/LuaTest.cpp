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

int cAdd(lua_State* L)
{
	//��Lջ��ȡ������Ϊ1����ֵ�������  
	int x = luaL_checkinteger(L, 1);
	//��Lջ��ȡ������Ϊ2����ֵ�������  
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

	//��ʼ��ȫ��L
	lua_State* L;
	L = luaL_newstate();
	//�򿪿�  
	luaL_openlibs(L);
	//�Ѻ���ѹ��ջ��  
	lua_pushcfunction(L, cAdd);
	//����ȫ��ADD  
	lua_setglobal(L, "ADD");
	luaL_loadfile(L, "test.lua");
	//��ȫ���  
	lua_pcall(L, 0, 0, 0);
	//push��lua����  
	lua_getglobal(L, "test");
	lua_pcall(L, 0, 0, 0);
	lua_close(L);

	getchar();

    return 0;
}
