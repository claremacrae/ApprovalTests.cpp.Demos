#include "ApprovalTests.hpp"
#include <gtest/gtest.h>
#include "GildedRose.h"

using namespace ApprovalTests;

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
        << "name: " << obj.name
        << ", sellIn: " << obj.sellIn
        << ", quality: " << obj.quality;
}

TEST(GildedRoseApprovalTests, VerifyCombinations)
{
    std::vector<string> names { "Foo" };
    std::vector<int> sellIns { 1 };
    std::vector<int> qualities { 1 };

    CombinationApprovals::verifyAllCombinations(
                [](string name, int sellIn, int quality) {
                vector<Item> items = {Item(name, sellIn, quality)};
                GildedRose app(items);
                app.updateQuality();
                return items[0];
                },
                names, sellIns, qualities);
}
