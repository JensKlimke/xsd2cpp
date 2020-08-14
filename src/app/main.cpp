#include <fstream>
#include <xsd2cpp.h>

int main(int argc, char *argv[]) {

    using namespace xsd2cpp;

    if (argc < 6)
        throw std::invalid_argument("please provide file name");

    // create file name
    std::string filename(argv[1]);
    std::string outPathPublic(argv[2]);
    std::string outPathPrivate(argv[3]);
    std::string headerFilename(argv[4]);

    // create config
    xsd2cpp::Config config{};
    config.libKey = argv[5];
    config.libName = argv[6];
    config.year = argv[7];
    config.date = argv[8];
    config.owner = argv[9];
    config.email = argv[10];

    // create outputs
    std::string structHeaderFile = outPathPublic + "/" + config.libName + ".h";
    std::string headerFile = outPathPrivate + "/" + config.libName + ".hpp";
    std::string sourceFile = outPathPrivate + "/" + config.libName + ".cc";

    // create files
    std::fstream fsp(structHeaderFile, std::ios::out);
    std::fstream fsh(headerFile, std::ios::out);
    std::fstream fss(sourceFile, std::ios::out);

    // generate code
    xsd2cpp::xsd2cpp(filename, fsp, fsh, fss, headerFilename, config);

    // close streams
    fsp.close();
    fsh.close();
    fss.close();

    return 0;

}