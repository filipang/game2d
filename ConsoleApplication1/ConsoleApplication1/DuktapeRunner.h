#pragma once

#ifndef _DUKTAPE
#define _DUKTAPE

#include "duktape/duktape.h"

class DuktapeRunner
{
public:
	duk_context *_ctx;

public:
	DuktapeRunner();
	virtual ~DuktapeRunner();

public:
	void push_file_as_string(const char *filename);
	bool push_file_as_string_and_eval(const char *filename);
	
	static duk_ret_t native_print(duk_context *ctx);
	static duk_ret_t native_rand(duk_context *ctx);
	static duk_ret_t native_rand_range(duk_context *ctx);

	void run_duktape( const char* fctname );
};

#endif /*MGT_DUKTAPE*/