#include <curl/curl.h>

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <nlohmann/json.hpp>
#include <thread>
#include <unordered_map>
#include <vector>

using json = nlohmann::json;

class branchAnalysis {
   private:
    int compareVersions(const std::string& v1, const std::string& v2);
    std::vector<std::string> split(const std::string& s);
    json GetFromApi(std::string branchName);
    void FindDiff(const std::shared_ptr<json>& data1, const std::shared_ptr<json>& data2);
    bool isNumeric(const std::string& str);

   public:
    void executeAnalysis(std::string branch1, std::string branch2);
};