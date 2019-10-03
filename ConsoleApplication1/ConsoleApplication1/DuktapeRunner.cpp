#define _CRT_SECURE_NO_WARNINGS

#include "DuktapeRunner.h"
#include <time.h>

DuktapeRunner::DuktapeRunner()
	: _ctx ( nullptr )
{
	_ctx = duk_create_heap_default();
	if (!_ctx) {
		printf("Failed to create a DuktapeRunner heap.\n");
		exit(1);
	}

	duk_push_global_object(_ctx);
	duk_push_c_function(_ctx, native_print, DUK_VARARGS);
	duk_put_prop_string(_ctx, -2, "print");
	duk_push_c_function(_ctx, native_rand, 0);
	duk_put_prop_string(_ctx, -2, "rand");
	duk_push_c_function(_ctx, native_rand_range, 2);
	duk_put_prop_string(_ctx, -2, "rand_range");

	srand( (unsigned int)time(NULL));
}
DuktapeRunner::~DuktapeRunner()
{
	duk_destroy_heap(_ctx);
}

void DuktapeRunner::push_file_as_string(const char *filename) 
{
	FILE *f;
	size_t len;
	char buf[16384];

	f = fopen(filename, "rb");
	if (f) {
		len = fread((void *)buf, 1, sizeof(buf), f);
		fclose(f);
		duk_push_lstring(_ctx, (const char *)buf, (duk_size_t)len);
	}
	else {
		duk_push_undefined(_ctx);
	}
}
bool DuktapeRunner::push_file_as_string_and_eval(const char *filename)
{
	push_file_as_string(filename);
	if (duk_peval(_ctx) != 0) {
		printf("Error running: %s\n", duk_safe_to_string(_ctx, -1));
		return false;
	}
	duk_pop(_ctx);  /* ignore result */
	return true;
}

//-------------------------------------------------------------------------------------

duk_ret_t DuktapeRunner::native_print( duk_context *ctx )
{
	duk_push_string(ctx, " ");
	duk_insert(ctx, 0);
	duk_join(ctx, duk_get_top(ctx) - 1);
	printf("%s", duk_to_string(ctx, -1));
	return 0;
}
duk_ret_t DuktapeRunner::native_rand(duk_context *ctx)
{
	int toret = rand();
	duk_push_number(ctx, toret);
	return 1;
}
duk_ret_t DuktapeRunner::native_rand_range(duk_context *ctx)
{
	int from = duk_require_int(ctx, 0);
	int to = duk_require_int(ctx, 1);

	int toret = rand() % ( to - from ) + from;
	duk_push_number(ctx, toret);
	return 1;

}

void DuktapeRunner::run_duktape( const char* fctname )
{
	duk_get_prop_string(_ctx, -1, fctname );
	if (duk_pcall(_ctx, 0) != 0) {
		printf("Error: %s\n", duk_safe_to_string(_ctx, -1));
	}
	const char *retstr = duk_safe_to_string(_ctx, -1);

	duk_pop(_ctx);  /* ignore result */
}