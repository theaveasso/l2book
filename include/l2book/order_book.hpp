#pragma once

#include <cstdint>

namespace l2b
{

using OrderId  = std::uint64_t;
using Price    = std::int64_t;
using Quantity = std::uint32_t;

enum class Side : std::uint8_t
{
	Buy,
	Sell
};

enum class Type : std::uint8_t
{
	Limit,
	Market
};

struct Order
{
	OrderId  id    = 0;
	Price    price = 0;
	Quantity qty   = 0;
	Side     side  = Side::Buy;
	Type     type  = Type::Limit;
};

class OrderBook
{
  public:
	OrderBook() = default;

	[[nodiscard]] Quantity submit(const Order &);
	[[nodiscard]] bool     cancel(OrderId);
	[[nodiscard]] Price    bestBid() const;
	[[nodiscard]] Price    bestAsk() const;
};
}        // namespace l2b
