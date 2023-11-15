#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "spending_history.h"

using namespace std;

TEST_CASE("Database is initialized correctly")
{
    SpendingHistory history;
    history.addReceipt(Company("Vinder"),        Money(100));
    history.addReceipt(Company("Wikibox"),       Money(200));
    history.addReceipt(Company("Tagcat"),        Money(300));
    history.addReceipt(Company("Thoughtbridge"), Money(400));
    history.addReceipt(Company("Wikibox"),       Money(500));
    history.addReceipt(Company("Kazu"),          Money(600));
    history.addReceipt(Company("Thoughtbridge"), Money(700));

    vector<TotalSpent> totals = history.getTotals();
    REQUIRE(totals.size() == 5);
    REQUIRE(totals[0] == TotalSpent(Company("Thoughtbridge"), Money(1100)));
    REQUIRE(totals[1] == TotalSpent(Company("Wikibox"),       Money(700)));
    REQUIRE(totals[2] == TotalSpent(Company("Kazu"),          Money(600)));
    REQUIRE(totals[3] == TotalSpent(Company("Tagcat"),        Money(300)));
    REQUIRE(totals[4] == TotalSpent(Company("Vinder"),        Money(100)));
}
