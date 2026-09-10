#include <iostream>
#include <string>

class ReportGenerator {
public:
    void generateReport(const std::string& type) {  //pdf 또는 html을 입력받고 그에 해당하는 문서를 생성한다.
        if (type == "PDF") {
            std::cout << "Generating PDF report..." << std::endl;
        }
        else if (type == "HTML") {
            std::cout << "Generating HTML report..." << std::endl;
        }
    }
};

int main() {
    ReportGenerator generator;
    generator.generateReport("PDF");
    generator.generateReport("HTML");

    return 0;
}