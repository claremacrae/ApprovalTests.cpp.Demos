#include "ApprovalTests.hpp"
#include <gtest/gtest.h>
#include "GildedRose.h"

using namespace ApprovalTests;

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    // clang-format off
    return os
        << "name: " << obj.name
        << ", sellIn: " << obj.sellIn
        << ", quality: " << obj.quality;
    // clang-format on
}

TEST(GildedRoseApprovalTests, VerifyCombinations)
{
    std::vector<std::string> names{"Foo"};
    std::vector<int> sellIns{1};
    std::vector<int> qualities{1};

    CombinationApprovals::verifyAllCombinations(
        [](std::string name, int sellIn, int quality)
        {
            std::vector<Item> items = {Item(name, sellIn, quality)};
            GildedRose app(items);
            app.updateQuality();
            return items[0];
        },
        names,
        sellIns,
        qualities);
}
