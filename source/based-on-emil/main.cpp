#include "infra/stream/ConstructBinStream.hpp"
#include "infra/util/ConstructBin.hpp"
#include <iostream>

int main()
{
    std::cout << "Hello World\r\n";

    auto dataFirst(infra::ConstructBin().Repeat(10, 'a').Vector());

    auto firstCmd((infra::ConstructBin() << infra::TextStream([&](infra::TextOutputStream stream) {
                       stream << R"(AT+SQNSSENDEXT=1,)" << dataFirst.size();
                   })).String());

    std::cout << "firstCmd  :" << firstCmd << "\r\n";

    return 0;
}
