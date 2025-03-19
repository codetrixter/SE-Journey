#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<std::vector<double>> posList = {
        {34.050590, -118.247539},
        {34.050601, -118.247561},
        {34.050604, -118.247584}
    };
    //   posList[0].push_back(34.050532);
    //   posList[0].push_back(-118.247460);
    //   posList[1].push_back(34.050548);
    //   posList[1].push_back(-118.247479);
    //   posList[2].push_back(34.050563);
    //   posList[2].push_back(-118.247498);

    std::vector<std::vector<float>> gpsList = {
        {308.082794f, 25.606798f, 79.013000f},
        {305.179626f, 25.891199f, 78.747002f},
        {296.269775f, 23.587200f, 78.411003f}

    };
    //   gpsList[0].push_back(308.346680f);
    //   gpsList[0].push_back(24.004801f);
    //   gpsList[0].push_back(80.025002f);
    //   gpsList[1].push_back(311.136810f);
    //   gpsList[1].push_back(25.379999f);
    //   gpsList[1].push_back(79.862000f);
    //   gpsList[2].push_back(312.552307f);
    //   gpsList[2].push_back(25.642799f);
    //   gpsList[2].push_back(79.560997f);

      for(int i = 0; i < 3; i++)
      {
        std::cout << posList[i][0];
        std::cout << " ";
      }
    return 0;
}
