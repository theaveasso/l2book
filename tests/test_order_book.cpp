#include "l2book/order_book.hpp"

#include <print>

static int g_failures = 0;
static_assert(sizeof(l2b::Order) == 24, "Order - check field ordering");

#define CHECK(expr)                                                      \
	do                                                                   \
	{                                                                    \
		if (!(expr))                                                     \
		{                                                                \
			std::println("FAIL {}:{}	{}", __FILE__, __LINE__, #expr); \
			++g_failures;                                                \
		}                                                                \
	} while (0)

int main()
{
	if (g_failures == 0)
	{
		std::println("ALL TESTS PASSED");
		return g_failures;
	}
	return g_failures;
}
