#include <iostream>

struct Stats
{
    int ads;
    int clickedAds;
    double earningPerAd;

};

void getEarnings(const Stats& stats)
{
    std::cout << "Total Earnings are: $" << (stats.ads * (stats.clickedAds / 100.0) * stats.earningPerAd);
}

int main()
{
    Stats EarningDetails{};
    std::cout << "How many ads were watched?\n";
    std::cin >> EarningDetails.ads;

    std::cout << "What percentage of users clicked on an ad?\n";
    std::cin >> EarningDetails.clickedAds;

    std::cout << "The average earnings per clicked ad?\n";
    std::cin >> EarningDetails.earningPerAd;


    getEarnings(EarningDetails);
}