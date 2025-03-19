#include <iostream>
struct TDRResult
{
    uint64_t          timestampInMilliseconds;   /// The timestamp for which the DR position was calculated.
    int       position;                  /// Dead-reckoning position and error estimation data.
    double       velocity;                  /// Heading, Speed and error estimation data.
    float positionStatus;            /// GnssData Quality
};
int main(int argc, char const *argv[])
{
    TDRResult mresult ;
    TDRResult mGnssResult;
    mGnssResult.timestampInMilliseconds = 100;
    mGnssResult.position = 200;
    mGnssResult.velocity = 34.4;
    mGnssResult.positionStatus = 3.0f;

    std::cout << mGnssResult.timestampInMilliseconds;

    mresult = mGnssResult;
    return 0;
}
