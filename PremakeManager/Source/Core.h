#pragma once

#if defined(PREMAN_DEBUG)
	#include <cassert>
	#define PremanAssert(msg) assert(msg)
#endif